--
-- Author: 黄泽昊
-- 作用: 贴纸的抽奖单卡

local DecalsLotteryCard = class("DecalsLotteryCard", function ()
    return cc.Node:create();
end)
local CARD_FRONT_PATH = "card_front.PNG";
local CARD_BACK_PATH = "card_back.PNG";
function DecalsLotteryCard:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);

    self.touch_enabled_ = false;
    self.isSelectedCard_ = false;
    self:init();
    self:addTouchEvent();
end
function DecalsLotteryCard:init()
    self.card_front_ = GlobalFunction.createGameSpriteWithPath(CARD_FRONT_PATH);
    self:addChild(self.card_front_);
    self.card_front_:setVisible(true);

    self.card_back_ = GlobalFunction.createGameSpriteWithPath(CARD_BACK_PATH);
    self:addChild(self.card_back_);
    self.card_back_:setVisible(false);

end

function DecalsLotteryCard:setCardState(front_flag, touch_enabled)
    if touch_enabled == nil then
        touch_enabled = true;
    end
    self.isFront_ = front_flag;
    self:runSelectEffect(not self.isFront_ and touch_enabled);
end
function DecalsLotteryCard:runSelectEffect(touch_enabled)
    local callfunc = cc.CallFunc:create(function ()
        self.card_front_:setVisible(self.isFront_);
        self.card_back_:setVisible(not self.isFront_);
    end)
    local orbitFront = cc.OrbitCamera:create(DECALS_LOTTERY_CARD_FLIPX_DURATION,1,0,0,-180,0,0);
    local orbitBack = cc.OrbitCamera:create(DECALS_LOTTERY_CARD_FLIPX_DURATION,1,0,-180,-180,0,0);
    self:runAction(self.card_front_:isVisible() and orbitFront or orbitBack);
    self:runAction(cc.Sequence:create(cc.DelayTime:create(DECALS_LOTTERY_CARD_FLIPX_DURATION/2), callfunc));
    self:runAction(cc.Sequence:create(cc.DelayTime:create(DECALS_LOTTERY_CARD_FLIPX_DURATION), cc.CallFunc:create(function (  )
        self:setCardTouchEnabled(touch_enabled);
    end)));
end
function DecalsLotteryCard:isCardFront()
    return self.isFront_;
end
function DecalsLotteryCard:addTouchEvent()
    self.touch_listener_ = cc.EventListenerTouchOneByOne:create();
    self.touch_listener_:setSwallowTouches(true);
    local function onTouchBegan(touch, event)
        if not self.touch_enabled_ then
            return false;
        end
        local touch_point = self.card_back_:convertTouchToNodeSpace(touch);
        local size = self.card_back_:getContentSize();
        if touch_point.x >= 0 and touch_point.x <= size.width and touch_point.y >= 0 and touch_point.y <= size.height  then
            self:selectCard();
            return true;
        end
        return false;
    end
    self.touch_listener_:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(self.touch_listener_, self);
end

function DecalsLotteryCard:selectCard()
    self.isSelectedCard_ = true;
    self:setCardState(true);
    self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_SELECT_CARD);
end
function DecalsLotteryCard:turnOverFrontDelay()
    local duration = DECALS_LOTTERY_CARD_FLIPX_DURATION*1.5
    if not self:isCardFront() then
        self:runAction(cc.Sequence:create(cc.DelayTime:create(duration), cc.CallFunc:create(function ()
            self:setCardState(true);
        end), nil));
    else
        self:runAction(cc.Sequence:create(cc.DelayTime:create(duration+DECALS_LOTTERY_CARD_FLIPX_DURATION), cc.CallFunc:create(function ()
            self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_REMOVE_CARD);
        end), nil));
    end
end
function DecalsLotteryCard:selectEnd()
    self:turnOverFrontDelay();
    self:setCardTouchEnabled(false);
end
function DecalsLotteryCard:selectBegin(point)
    if point == nil then
        self:setCardState(false);
        return;
    else
        self:setCardState(false, false);
    end
    self:runAction(cc.Sequence:create(cc.DelayTime:create(DECALS_LOTTERY_CARD_FLIPX_DURATION+CARDS_MOVETO_CENTER_DURATION),
     cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION, cc.p(0,0)), cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION, point), cc.CallFunc:create(function ()
        self:setCardTouchEnabled(true);
    end)));
end
function DecalsLotteryCard:setCardTouchEnabled(flag)
    self.touch_enabled_ = flag;
end
function DecalsLotteryCard:isSelectedCard()
    return self.isSelectedCard_;
end
function DecalsLotteryCard:onEnter()
    self.listener_ = {};
    local function selectBegin( event )
        self:selectBegin();
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_BEGIN, selectBegin));
    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function DecalsLotteryCard:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return DecalsLotteryCard