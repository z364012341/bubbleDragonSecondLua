--
-- Author: 黄泽昊
-- 作用: 贴纸的展示类

local DecalsLotteryCardsShow = class("DecalsLotteryCardsShow", function ()
    return cc.Node:create();
end)
local DecalsLotteryCard = require(DECALS_LOTTERY_CARD_PATH);
function DecalsLotteryCardsShow:ctor()
	local function onNodeEvent(event)
	    if event == "enter" then
	        self:onEnter();
	    elseif event == "exit" then
	        self:onExit();
	    end
	end
    self:registerScriptHandler(onNodeEvent);
	self.cards_ = {};
    self:init();
end
local CARD_POS_Y = 150;
local CARD_SIX_POS_X = 223;
local CARD_FOUR_POS_X = 148;
local SIX_CARDS_POINTS = {cc.p(-CARD_SIX_POS_X, CARD_POS_Y),cc.p(0, CARD_POS_Y),cc.p(CARD_SIX_POS_X, CARD_POS_Y),
							cc.p(-CARD_SIX_POS_X, -CARD_POS_Y),cc.p(0, -CARD_POS_Y),cc.p(CARD_SIX_POS_X, -CARD_POS_Y)};
local FOUR_CARDS_POINTS = {cc.p(-CARD_FOUR_POS_X, CARD_POS_Y),cc.p(CARD_FOUR_POS_X, CARD_POS_Y),
							cc.p(-CARD_FOUR_POS_X, -CARD_POS_Y), cc.p(CARD_FOUR_POS_X, -CARD_POS_Y)};
local TWO_CARDS_POINTS = {cc.p(-CARD_FOUR_POS_X, 0),cc.p(CARD_FOUR_POS_X, 0)};
local CARDS_POINTS = {[6] = SIX_CARDS_POINTS, [4]=FOUR_CARDS_POINTS, [2] = TWO_CARDS_POINTS};
function DecalsLotteryCardsShow:init()
	for _,point in ipairs(CARDS_POINTS[6]) do
		local card = DecalsLotteryCard:create();
		card:setPosition(point);
		self:addChild(card);
		table.insert(self.cards_, card);
	end
end
function DecalsLotteryCardsShow:lotteryAgain()
	self:removeSelectedCard();
	self:removeRandomCard();
	for i,card in ipairs(self.cards_) do
		card:selectBegin();
		card:runAction(cc.Sequence:create(cc.MoveTo:create(0.5, cc.p(0,0)), cc.MoveTo:create(0.5, CARDS_POINTS[#self.cards_][i]), nil));
	end
end
function DecalsLotteryCardsShow:removeSelectedCard()
	for i,card in ipairs(self.cards_) do
		if card:isSelectedCard() then
			self:removeCard(i);
			return;
		end
	end
end
function DecalsLotteryCardsShow:removeRandomCard()
	local index = math.random(1, #self.cards_);
	self:removeCard(index);
end
function DecalsLotteryCardsShow:removeCard(index)
	assert(self.cards_[index]);
	self.cards_[index]:removeFromParent();
	table.remove(self.cards_, index);
end
function DecalsLotteryCardsShow:onEnter()
    self.listener_ = {};
    local function selectCardCallback( event )
    	for _,card in ipairs(self.cards_) do
    		card:selectEnd();
    	end
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_SELECT_CARD, selectCardCallback));

    local function lotteryAgain( event )
    	self:lotteryAgain();
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_AGAIN, lotteryAgain));
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