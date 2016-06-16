--
-- Author: 黄泽昊
-- 作用: 贴纸的抽奖场景

local DecalsLotteryScene = class("DecalsLotteryScene", function ()
    return cc.Layer:create();
end)
local DecalsLotteryCardsShow = require(DECALS_LOTTERY_CARDS_SHOW_PATH);
local DECALS_LATTERY_SCENE_CSB_PATH = "DecalsLotteryLayer.csb";
local CARDS_BACKGROUND_NAME = "Image_1";
local BACKGROUND_TOP_UI_NAME = "lottery_top_4";
local BUTTON_NODE_NAME = "buttonNode";

function DecalsLotteryScene:createScene()
    local scene = cc.Scene:create();
    local layer = DecalsLotteryScene:create();
    scene:addChild(layer);
    return scene;
end
function DecalsLotteryScene:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self:init();
end
function DecalsLotteryScene:init()
    self.lottery_times_ = 1;
    self:loadCSB();
    self:addCards();
    --self:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function DecalsLotteryScene:loadCSB()
    local csb_node = cc.CSLoader:createNode(DECALS_LATTERY_SCENE_CSB_PATH);
    assert(csb_node);
    --self.cab_node_ = csb_node;

    bs.ButtonEffectController:setButtonsZoomScale(csb_node);
    self:addChild(csb_node);

    csb_node:getChildByName("lottery_label_1"):setPositionY(cc.Director:getInstance():getVisibleSize().height*0.9667);

    local return_button = csb_node:getChildByName("Button_1");
    -- return_button:setPosition(cc.p(cc.Director:getInstance():getVisibleSize().width*0.11, cc.Director:getInstance():getVisibleSize().height*0.06));
    return_button:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom() * return_button:getScale());
    return_button:addClickEventListener(function ( ... )
        cc.Director:getInstance():popScene();
    end);

    local cards_bg = csb_node:getChildByName(CARDS_BACKGROUND_NAME);
    cards_bg:setPositionY(cc.Director:getInstance():getVisibleSize().height*0.3);
    local bg_height = cards_bg:getContentSize().height*bs.SmartScaleController:getInstance():getPlayAreaZoom();
    cards_bg:setContentSize(cc.size(cards_bg:getContentSize().width, bg_height));

    cards_bg:getChildByName(BACKGROUND_TOP_UI_NAME):setPositionY(bg_height);
    self.lottery_times_label_ = cards_bg:getChildByName(BACKGROUND_TOP_UI_NAME):getChildByName("BitmapFontLabel_1");
    self.lottery_times_label_:setString(tostring(self.lottery_times_));

    local button_node = csb_node:getChildByName(BUTTON_NODE_NAME);
    button_node:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    button_node:setPositionY(cc.Director:getInstance():getVisibleSize().height*0.161);
    self.button_node_ = button_node;
    self.free_shuffle_button = button_node:getChildByName("Button_2_0");
    self.lottery_begin_button = button_node:getChildByName("Button_2");
    self.lottery_begin_button:addClickEventListener(function (...)
        self:lotteryBegin();
    end);
    self.lottery_again_begain_button = button_node:getChildByName("Button_2_0_0");
    self.lottery_again_begain_button:addClickEventListener(function (...)
        self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_AGAIN);
        self.lottery_again_begain_button:setVisible(false);
    end);
    self.cards_background_ = cards_bg;
end
function DecalsLotteryScene:lotteryBegin()
    --self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_BEGIN);
    self.cards_show_:lotteryAgain();
    self.free_shuffle_button:setVisible(false);
    self.lottery_begin_button:setVisible(false);
end
function DecalsLotteryScene:addCards()
    local cards_show = DecalsLotteryCardsShow:create();
    cards_show:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    cards_show:setPosition(cc.p(self.cards_background_:getContentSize().width/2, self.cards_background_:getContentSize().height/2));
    self.cards_show_ = cards_show;
    self.cards_background_:addChild(cards_show);
end
function DecalsLotteryScene:onEnter()
    self.listener_ = {};
    local function updateTimesLabel( event )
        self.lottery_times_ = self.lottery_times_ + 1;
        self.lottery_times_label_:setString(tostring(self.lottery_times_));
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_AGAIN, updateTimesLabel));

    local function lotteryAgainBegin( event )
        self.lottery_again_begain_button:setVisible(true);
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_AGAIN_BEGIN, lotteryAgainBegin));

    -- local function lotteryEnd( event )
    --     self.button_node_:setVisible(false);
    -- end
    -- table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_END, lotteryEnd));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function DecalsLotteryScene:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end

return DecalsLotteryScene