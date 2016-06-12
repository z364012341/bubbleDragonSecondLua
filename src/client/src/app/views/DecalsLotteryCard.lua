--
-- Author: 黄泽昊
-- 作用: 贴纸的抽奖单卡

local DecalsLotteryCard = class("DecalsLotteryCard", function ()
    return cc.Node:create();
end)
local CARD_FRONT_PATH = "card_front.PNG";
local CARD_BACK_PATH = "card_back.PNG";
function DecalsLotteryCard:ctor()
    self:init();
end
function DecalsLotteryCard:init()
    self.card_front_ = GlobalFunction.createGameSpriteWithPath(CARD_FRONT_PATH);
    self:addChild(self.card_front_);

    self.card_back_ = GlobalFunction.createGameSpriteWithPath(CARD_BACK_PATH);
    self:addChild(self.card_back_);
end
function DecalsLotteryCard:setCardState(front_flag)
    self.card_front_:setVisible(front_flag);
    self.card_back_:setVisible(not front_flag);

end
return DecalsLotteryCard