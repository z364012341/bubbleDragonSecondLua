--
-- Author: 黄泽昊
-- 作用: 选择pageview下面的点

local PuzzleSelectedPageViewPoint = class("PuzzleSelectedPageViewPoint", function (numble)
    return cc.Node:create();
end)
local POINT_BACKGROUND_PATH = "fanyediandi.PNG";
local POINT_CURRENT_INDEX_PATH = "fanyedian.PNG";
local POINT_X_DElTA = 30;
function PuzzleSelectedPageViewPoint:ctor(numble)
    self.points_ = {};
    self.move_delay_time_ = 0.5;
    self:init(numble);
end
function PuzzleSelectedPageViewPoint:init( numble )
    for i=0, numble-1 do
        local point = GlobalFunction.createGameSpriteWithPath(POINT_BACKGROUND_PATH);
        point:setPositionX(i*POINT_X_DElTA-POINT_X_DElTA*(numble-1)/2);
        self:addChild(point);
        self.points_[i]=point;
    end
    self.current_point_ = GlobalFunction.createGameSpriteWithPath(POINT_CURRENT_INDEX_PATH);
    self:setCurrentPointPosition(0);
    self:addChild(self.current_point_);
end
function PuzzleSelectedPageViewPoint:scrollToPage(pageview)
    self.current_point_:stopAllActions();
    self.current_point_:runAction(cc.Sequence:create(cc.DelayTime:create(self.move_delay_time_), cc.CallFunc:create(function ()
        if self.points_[pageview:getCurrentPageIndex()] ~= nil then
            self:setCurrentPointPosition(pageview:getCurrentPageIndex());
        end
    end), nil));

end
function PuzzleSelectedPageViewPoint:setCurrentPointPosition( index )
    self.current_point_:setPosition(cc.p(self.points_[index]:getPosition()));
end
function PuzzleSelectedPageViewPoint:setPointMoveDelayTime(time)
    self.move_delay_time_ = time;
end
return PuzzleSelectedPageViewPoint