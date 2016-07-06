--
-- Author: 黄泽昊
-- 作用: 贴纸的抽奖场景

local DecalsLotteryScene = class("DecalsLotteryScene", function (decals_type)
    return cc.Layer:create();
end)
local DecalsLotteryCardsShow = require(DECALS_LOTTERY_CARDS_SHOW_PATH);
local DECALS_LATTERY_SCENE_CSB_PATH = "DecalsLotteryLayer.csb";
local CARDS_BACKGROUND_NAME = "Image_1";
local BACKGROUND_TOP_UI_NAME = "lottery_top_4";
local BUTTON_NODE_NAME = "buttonNode";
function DecalsLotteryScene:createScene(decals_type)
    local scene = cc.Scene:create();
    local layer = DecalsLotteryScene:create(decals_type);
    scene:addChild(layer);
    return scene;
end
function DecalsLotteryScene:ctor(decals_type)
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self.decals_type_ = decals_type;
    self:init();
end

function DecalsLotteryScene:init()
    self.lottery_times_ = 1;
    self:loadCSB();
    self:addCards();
    self:addUserInfoBoard();
    --self:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function DecalsLotteryScene:addUserInfoBoard()
    self:addChild(bs.UserCoinInfoBoard:create());
    local node = bs.UserDiamondInfoBoard:create()
    self:addChild(node);
    self.cab_node_:getChildByName("lottery_label_1"):setPositionY(node:getPositionY());
end
function DecalsLotteryScene:loadCSB()
    local csb_node = cc.CSLoader:createNode(DECALS_LATTERY_SCENE_CSB_PATH);
    assert(csb_node);
    self.cab_node_ = csb_node;

    bs.ButtonEffectController:setButtonsZoomScale(csb_node);
    self:addChild(csb_node);



    local return_button = csb_node:getChildByName("Button_1");
    -- return_button:setPosition(cc.p(cc.Director:getInstance():getVisibleSize().width*0.11, cc.Director:getInstance():getVisibleSize().height*0.06));
    return_button:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom() * return_button:getScale());
    return_button:addClickEventListener(function ( ... )
        cc.Director:getInstance():popScene();
    end);

    local cards_bg = csb_node:getChildByName(CARDS_BACKGROUND_NAME);
    self.cards_background_ = cards_bg;
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
    local begin_cost =  bs.GamePropsCostTag:createDecalsLotteryBeginTag();
    self.lottery_begin_button:addClickEventListener(function (...)
        if begin_cost:canPay() then
            begin_cost:pay();
            self:lotteryBegin();
        end
    end);
    self:addCostTag(self.lottery_begin_button, begin_cost);

    self.lottery_again_begain_button = button_node:getChildByName("Button_2_0_0");
    local again_cost = bs.GamePropsCostTag:createDecalsLotteryContinueTag();
    self.lottery_again_begain_button:addClickEventListener(function (...)
        if again_cost:canPay() then
            again_cost:pay();
            self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_AGAIN);
            self.lottery_again_begain_button:setVisible(false);
        end
    end);
    self:addCostTag(self.lottery_again_begain_button, again_cost);

    self.free_change_award_button_ = button_node:getChildByName("Button_2_0");
    self.free_change_award_button_:addClickEventListener(function (...)
        self.lottery_begin_button:setEnabled(false);
        self.free_change_award_button_:setEnabled(false);
        self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_CHANGE_AWARD_CARD_BEGIN);
    end);
end
function DecalsLotteryScene:lotteryBegin()
    --self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_BEGIN);
    self.cards_show_:lotteryAgain();
    self.free_shuffle_button:setVisible(false);
    self.lottery_begin_button:setVisible(false);
end
function DecalsLotteryScene:addCards()
    local cards_show = DecalsLotteryCardsShow:create(self.decals_type_);
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

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_CHANGE_AWARD_CARD_END, function ( event )
        self.lottery_begin_button:setEnabled(true);
        self.free_change_award_button_:setEnabled(true);
    end));
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
function DecalsLotteryScene:addCostTag(button, cost_tag)
    local sp = button:getRendererNormal();
    cost_tag:setPosition(cc.p(sp:getContentSize().width/2, 50));
    sp:addChild(cost_tag);
end
return DecalsLotteryScene