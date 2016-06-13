--
-- Author: 黄泽昊
-- 作用: 贴纸的抽奖单卡

local DecalsLotteryCard = class("DecalsLotteryCard", function ()
    return cc.Node:create();
end)
local CARD_FRONT_PATH = "card_front.PNG";
local CARD_BACK_PATH = "card_back.PNG";
function DecalsLotteryCard:ctor()
    self.isSelectedCard_ = false;
    self:init();
    self:addTouchEvent();
    self:setCardState(false);
end
function DecalsLotteryCard:init()
    self.card_front_ = GlobalFunction.createGameSpriteWithPath(CARD_FRONT_PATH);
    self:addChild(self.card_front_);

    self.card_back_ = GlobalFunction.createGameSpriteWithPath(CARD_BACK_PATH);
    self:addChild(self.card_back_);

end
function DecalsLotteryCard:setCardState(front_flag)
    self.isFront_ = front_flag;
    self.card_front_:setVisible(front_flag);
    self.card_back_:setVisible(not front_flag);

end
function DecalsLotteryCard:isCardFront()
    return self.isFront_;
end
function DecalsLotteryCard:addTouchEvent()
    self.touch_listener_ = cc.EventListenerTouchOneByOne:create();
    self.touch_listener_:setSwallowTouches(true);
    local function onTouchBegan(touch, event)
        local touch_point = self.card_back_:convertTouchToNodeSpace(touch);
        local size = self.card_back_:getContentSize();
        if touch_point.x >= 0 and touch_point.x <= size.width and touch_point.y >= 0 and touch_point.y <= size.height then
            self:selectCard();
            return true;
        end
        return false;
    end
    self.touch_listener_:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN);
    -- self.touch_listener_:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED);
    -- self.touch_listener_:registerScriptHandler(self.onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(self.touch_listener_, self);
end
-- function DecalsLotteryCard:removeTouchEvent()
--     cc.Director:getInstance():getEventDispatcher():removeEventListener(self.touch_listener_);
-- end
function DecalsLotteryCard:selectCard()
    self.isSelectedCard_ = true;
    self:setCardState(true);
    self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_SELECT_CARD);
    self:runAction(cc.Sequence:create(cc.DelayTime:create(2), cc.CallFunc:create(function ()
        self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_AGAIN);
        -- self:removeFromParent();
    end), nil));
end
function DecalsLotteryCard:turnOverFrontDelay()
    self:runAction(cc.Sequence:create(cc.DelayTime:create(1), cc.CallFunc:create(function ()
        self:setCardState(true);
    end), nil));
end
function DecalsLotteryCard:selectEnd()
    self.touch_listener_:setEnabled(false);
    if not self:isCardFront() then
        self:turnOverFrontDelay();
    end
end
function DecalsLotteryCard:selectBegin()
    self.touch_listener_:setEnabled(true);
    self:setCardState(false);
end
function DecalsLotteryCard:isSelectedCard()
    return self.isSelectedCard_;
end
return DecalsLotteryCard