--
-- Author: 黄泽昊
-- 作用: 贴纸的抽奖单卡

local DecalsLotteryCard = class("DecalsLotteryCard", function ()
    return cc.Node:create();
end)
-- local DecalsLotteryScene = require(DECALS_LOTTERY_SCENE_PATH);
local CARD_FRONT_PATH = "card_front.PNG";
local CARD_BACK_PATH = "card_back.PNG";
local CARD_SHUFFLE_MOVE_SPEED = 4000;
local SELECT_ARMATURE_NAME = "c";
local SELECT_ANIMATION_1_NAME = "fanpai-01";
local SELECT_ANIMATION_2_NAME = "fanpai-02";

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
    self.is_decal_card_ = false;
    self:init();
    self:addTouchEvent();
end
function DecalsLotteryCard:onEnter()
    self.listener_ = {};
    local function changeAward( event )
        self:changeAward();
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_CHANGE_AWARD_CARD_BEGIN, changeAward));
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
        local touch_point = self.card_back_:getParent():convertTouchToNodeSpace(touch);
        local size = self.card_back_:getContentSize();
        if cc.rectContainsPoint(self.card_back_:getBoundingBox(), touch_point)  then
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
    if self:isDecalCard() then
        bs.DecalsFactory:getInstance():saveNextDecal(self.decals_type_);
    else
        bs.UserDataManager:getInstance():addPropsNumbleWithKey(self.award_key_, self.award_numble_);
    end
    self:runAction(cc.Sequence:create(cc.DelayTime:create(DECALS_LOTTERY_CARD_FLIPX_DURATION), cc.CallFunc:create(function ()
        local armature_1 = ccs.Armature:create(SELECT_ARMATURE_NAME);
        self:addChild(armature_1, 1);
        armature_1:getAnimation():play(SELECT_ANIMATION_1_NAME);
        local armature_2 = ccs.Armature:create(SELECT_ARMATURE_NAME);
        self:addChild(armature_2, -1);
        armature_2:getAnimation():play(SELECT_ANIMATION_2_NAME);
    end)));
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
            -- for _,armature in ipairs(self.select_armatures_) do
            --     armature:removeFromParent();
            -- end
        end), nil));
    end
end
function DecalsLotteryCard:selectEnd()
    self:turnOverFrontDelay();
    self:setCardTouchEnabled(false);
end
function DecalsLotteryCard:selectBegin(point)
    -- if point == nil then
        -- self:setCardState(false);
        --return;
    -- else
    self:setCardState(false, false);
    -- end
    self:runAction(cc.Sequence:create(cc.DelayTime:create(DECALS_LOTTERY_CARD_FLIPX_DURATION+CARDS_MOVETO_CENTER_DURATION),
      --[[cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION,cc.p(0,0)), cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION, point),]] cc.CallFunc:create(function ()
        --self:setCardTouchEnabled(true);
        self:playShuffleEffect(point);
    end)));
end
function DecalsLotteryCard:playShuffleEffect(end_point)
    local bg_size = self:getParent():getParent():getContentSize();
    local card_size = self.card_front_:getContentSize();
    local percent = self:getParent():getCardsShuffleRangePercent();
    local max_x = (bg_size.width - card_size.width*bs.SmartScaleController:getInstance():getPlayAreaZoom())/2*percent;
    local max_y = (bg_size.height - card_size.height*bs.SmartScaleController:getInstance():getPlayAreaZoom())/2*0.9*percent;
    local min_x = -max_x;
    local min_y = -max_y;
    local point_select = {function ()
        return cc.p(math.random(min_x, max_x), min_y);
    end,
    function ()
        return cc.p(math.random(min_x, max_x), max_y);
    end,
    function ()
        return cc.p(min_x, math.random(min_y, max_y));
    end,
    function ()
        return cc.p(max_x, math.random(min_y, max_y));
    end}

    local move_func = nil;
    local shuffle_move_seq = nil;
    move_func = function ()
        local next_point = point_select[math.random(1, #point_select)]();
        -- local distance = cc.pGetDistance(cc.p(self:getPosition()), next_point);
        local duration = cc.pGetDistance(cc.p(self:getPosition()), next_point)/CARD_SHUFFLE_MOVE_SPEED;
        shuffle_move_seq = cc.Sequence:create(cc.MoveTo:create(duration, next_point), cc.CallFunc:create(function ()
            move_func();
        end));
        self:runAction(shuffle_move_seq);
    end
    move_func();
    self:runAction(cc.Sequence:create(cc.DelayTime:create(1),
        cc.CallFunc:create(function ()
            self:stopAction(shuffle_move_seq);
        end),
        cc.MoveTo:create(0.1, cc.p(0,0)),
        cc.MoveTo:create(0.3, end_point),
        cc.CallFunc:create(function ()
            self:setCardTouchEnabled(true);
        end))
    );
end
-- function DecalsLotteryCard:calculateNextPointDuration(next_point)
--     return cc.pGetDistance(cc.p(self:getPosition()), next_point)/CARD_SHUFFLE_MOVE_SPEED
-- end
-- function DecalsLotteryCard:getMoveToNextPointAction(next_point)
--     return cc.MoveTo:create(self:calculateNextPointDuration(next_point), next_point);
-- end
function DecalsLotteryCard:setCardTouchEnabled(flag)
    self.touch_enabled_ = flag;
end
function DecalsLotteryCard:isSelectedCard()
    return self.isSelectedCard_;
end
function DecalsLotteryCard:addDecalItem(decals_type)
    self:setLocalZOrder(1);
--    local item = nil;
--    if decals_type == DECALS_TYPE_CHARACTOR then
--        item = bs.DecalsFactory:getInstance():createCharactorNextDecal();
--    else
--        item = bs.DecalsFactory:getInstance():createTreasureNextDecal();
--    end
    self.decals_type_ = decals_type;
    local item = bs.DecalsFactory:getInstance():createNextDecalWithType(decals_type);
    item:setScale(self.card_front_:getContentSize().width/item:getContentSize().width*0.75*item:getScale());
    item:setPosition(cc.p(self.card_front_:getContentSize().width/2, self.card_front_:getContentSize().height/2));
    self.card_front_:addChild(item);

    self.is_decal_card_ = true;
end
function DecalsLotteryCard:addRandomAwardItem()
    local award_data = bs.GameBuyStoreMannager:getRandomLotteryAwardWihtoutDecals();
    -- local award_data = DECALS_LOTTERY_AWARDS[math.random(1, #DECALS_LOTTERY_AWARDS)];
    for key,numble in pairs(award_data) do
        self.award_key_ = key;
        self.award_numble_ = numble;
        local node = bs.GameLotteryAwardItem:create(key, numble);
        self.award_node_ = node;
        node:setPosition(cc.p(self.card_front_:getContentSize().width/2, self.card_front_:getContentSize().height*0.55));
        self.card_front_:addChild(node);

        local item = node:getAwardSprite();
        item:setScale(self.card_front_:getContentSize().width/item:getContentSize().width*0.35);
        --item:setAnchorPoint(cc.p(0.5, 0));
        --item:setPosition(cc.p(0, 50));
        --node:addChild(item);

        -- local label = bs.SpriteTextureController:getInstance():createWhitePurpleFnt(tostring(numble));
        -- label:setScale(0.6);
        -- label:setPosition(cc.p(0, -25));
        -- node:addChild(label);
    end
end
function DecalsLotteryCard:isDecalCard()
    return self.is_decal_card_;
end
function DecalsLotteryCard:changeAward()
    local point = cc.p(self:getPosition());
    self:runAction(cc.Sequence:create(cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION, cc.p(0,0)), cc.CallFunc:create(function (  )
        if not self:isDecalCard() then
            self.award_node_:removeFromParent();
            self:addRandomAwardItem();
        end
    end), cc.DelayTime:create(0.5), cc.MoveTo:create(CARDS_MOVETO_CENTER_DURATION, point), cc.CallFunc:create(function (  )
        if self:isDecalCard() then
            self:getEventDispatcher():dispatchCustomEvent(EVENT_DECALS_LOTTERY_CHANGE_AWARD_CARD_END);
        end
    end)));
end
return DecalsLotteryCard