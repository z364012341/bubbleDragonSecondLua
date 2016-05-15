--
-- Author: 黄泽昊
-- 功能: 失败倒计时组件

local PuzzleDefeatCountdownComponent = class("PuzzleDefeatCountdownComponent", function ()
    return cc.Node:create();
end)
function PuzzleDefeatCountdownComponent:ctor()
	local time = 10;
	self:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1), cc.CallFunc:create(function ()
		time = time - 1;
		dump(time);
		if time == 0 then
			self:stopAllActions(); 
			cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUZZLE_GAME_DEFEAT);
		end 
	end), nil)));
end

return PuzzleDefeatCountdownComponent