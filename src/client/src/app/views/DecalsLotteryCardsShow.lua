--
-- Author: 黄泽昊
-- 作用: 贴纸的展示类

local DecalsLotteryCardsShow = class("DecalsLotteryCardsShow", function(decals_type)
    return cc.Node:create();
end )
local DecalsLotteryCard = require(DECALS_LOTTERY_CARD_PATH);
local CARDS_SHUFFLE_RANGE_PERCENT = { [6] = 1, [4] = 0.8, [2] = 0.6 };
function DecalsLotteryCardsShow:ctor(decals_type)
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self.decals_type_ = decals_type;
    self.cards_ = { };
    self:init();
end
local CARD_POS_Y = 150;
local CARD_SIX_POS_X = 223;
local CARD_FOUR_POS_X = 148;
local SIX_CARDS_POINTS = {
    cc.p(- CARD_SIX_POS_X,CARD_POS_Y),cc.p(0,CARD_POS_Y),cc.p(CARD_SIX_POS_X,CARD_POS_Y),
    cc.p(- CARD_SIX_POS_X,- CARD_POS_Y),cc.p(0,- CARD_POS_Y),cc.p(CARD_SIX_POS_X,- CARD_POS_Y)
};
local FOUR_CARDS_POINTS = {
    cc.p(- CARD_FOUR_POS_X,CARD_POS_Y),cc.p(CARD_FOUR_POS_X,CARD_POS_Y),
    cc.p(- CARD_FOUR_POS_X,- CARD_POS_Y),cc.p(CARD_FOUR_POS_X,- CARD_POS_Y)
};
local TWO_CARDS_POINTS = { cc.p(- CARD_FOUR_POS_X, 0), cc.p(CARD_FOUR_POS_X, 0) };
local CARDS_POINTS = { [6] = SIX_CARDS_POINTS, [4] = FOUR_CARDS_POINTS, [2] = TWO_CARDS_POINTS };
function DecalsLotteryCardsShow:init()
    local numble = math.random(1, #CARDS_POINTS[6]);
    for i, point in ipairs(CARDS_POINTS[6]) do
        local card = DecalsLotteryCard:create();
        card:setPosition(point);
        self:addChild(card);
        table.insert(self.cards_, card);
        if i == numble then
            card:addDecalItem(self.decals_type_);
        else
            card:addRandomAwardItem();
        end
    end

end
-- function DecalsLotteryCardsShow:lotteryBegin( )
-- 	for _,card in ipairs(self.cards_) do
-- 		card:selectBegin();
-- 	end
-- end
function DecalsLotteryCardsShow:lotteryAgain()
    -- self:removeSelectedCard();
    -- self:removeRandomCard();
    GlobalFunction.shuffleTable(self.cards_);

    for i, card in ipairs(self.cards_) do
        card:selectBegin(CARDS_POINTS[#self.cards_][i]);
    end
end
function DecalsLotteryCardsShow:removeTwoCards()
    local selected_card = self:findAndRemoveSelectedCard();
    selected_card:setLocalZOrder(2);
    selected_card:runAction(cc.RepeatForever:create(cc.RotateBy:create(0.5, 360)));

    -- local end_point = GlobalFunction.getVisibleCenterPosition();
    local end_point = selected_card:getParent():convertToNodeSpace(cc.p(cc.Director:getInstance():getVisibleSize().width, 0));
    local bezier_table = { cc.p(selected_card:getPosition()), cc.p(300, selected_card:getPositionY()), end_point };
    local ease_bezier = cc.EaseSineIn:create(cc.BezierTo:create(0.75, bezier_table));
    selected_card:runAction(cc.ScaleTo:create(0.75, 0.2));
    selected_card:runAction(cc.Sequence:create(ease_bezier, cc.CallFunc:create( function()
        selected_card:removeFromParent();
        local rm_index = self:getRandomRemoveCardIndex();
        local rm_card = self.cards_[rm_index];
        table.remove(self.cards_, rm_index);
        --GlobalFunction.shuffleTable(self.cards_);
        for i, card in ipairs(self.cards_) do
            card:runAction(cc.Sequence:create(cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION, cc.p(0, 0)), cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION, CARDS_POINTS[#self.cards_][i]), nil));
        end
        rm_card:runAction(cc.Sequence:create(cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION, cc.p(0, 0)), cc.CallFunc:create( function()
            rm_card:removeFromParent();
        end )));
        self:runAction(cc.Sequence:create(cc.DelayTime:create(CARDS_MOVETO_CENTER_DURATION * 2), cc.CallFunc:create( function()
            self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_AGAIN_BEGIN);
        end )));
    end )));
end
function DecalsLotteryCardsShow:getRandomRemoveCardIndex()
    local index = 0;
    while true do
        index = math.random(1, #self.cards_);
        if not self.cards_[index]:isDecalCard() then
            break;
        end
    end
    return index;
end
function DecalsLotteryCardsShow:isLotteryEnd()
    return #self.cards_ == 2;
end
function DecalsLotteryCardsShow:getCardsShuffleRangePercent()
    return CARDS_SHUFFLE_RANGE_PERCENT[#self.cards_];
end
function DecalsLotteryCardsShow:findAndRemoveSelectedCard()
    for i, card in ipairs(self.cards_) do
        if card:isSelectedCard() then
            table.remove(self.cards_, i);
            return card;
        end
    end
end

-- function DecalsLotteryCardsShow:removeCard(index)
-- 	assert(self.cards_[index]);
-- 	self.cards_[index]:removeFromParent();
-- 	table.remove(self.cards_, index);
-- end
function DecalsLotteryCardsShow:onEnter()
    self.listener_ = { };
    local function selectCardCallback(event)
        for _, card in ipairs(self.cards_) do
            card:selectEnd();
        end
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_SELECT_CARD, selectCardCallback));

    local function lotteryAgain(event)
        self:lotteryAgain();
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_AGAIN, lotteryAgain));

    local function lotteryRemoveTwoCard(event)
        if self:isLotteryEnd() then
            self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_END);
            return;
        end
        self:removeTwoCards();
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_REMOVE_CARD, lotteryRemoveTwoCard));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function DecalsLotteryCardsShow:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return DecalsLotteryCardsShow