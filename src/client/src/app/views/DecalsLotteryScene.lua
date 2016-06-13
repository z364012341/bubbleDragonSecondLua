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
function DecalsLotteryScene:createScene()
    local scene = cc.Scene:create()
    local layer = DecalsLotteryScene:create()
    scene:addChild(layer)
    return scene
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
    self.cards_background_ = cards_bg
end
function DecalsLotteryScene:addCards()
    local cards_show = DecalsLotteryCardsShow:create();
    cards_show:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    cards_show:setPosition(cc.p(self.cards_background_:getContentSize().width/2, self.cards_background_:getContentSize().height/2));
    self.cards_background_:addChild(cards_show);
end
function DecalsLotteryScene:onEnter()
    self.listener_ = {};
    local function updateTimesLabel( event )
        self.lottery_times_ = self.lottery_times_ + 1;
        self.lottery_times_label_:setString(tostring(self.lottery_times_));
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_AGAIN, updateTimesLabel));
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