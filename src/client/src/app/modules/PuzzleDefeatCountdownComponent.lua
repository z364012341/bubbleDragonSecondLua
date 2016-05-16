--
-- Author: 黄泽昊
-- 功能: 失败倒计时组件

local PuzzleDefeatCountdownComponent = class("PuzzleDefeatCountdownComponent", function ()
    return cc.Node:create();
end)

function PuzzleDefeatCountdownComponent:ctor()
	self.initail_time_ = 900;
	self.time_consuming_ = self.initail_time_ ;
	local function onNodeEvent(event)
        if event == "enter" then
        	self:getEventDispatcher():dispatchEvent(GlobalFunction.createCustomEvent(EVENT_UPDATE_TIME_LABEL, self.time_consuming_));
    	end
    end
    self:registerScriptHandler(onNodeEvent);

	self:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1), cc.CallFunc:create(function ()
		self.time_consuming_ = self.time_consuming_ - 1;
		self:getEventDispatcher():dispatchEvent(GlobalFunction.createCustomEvent(EVENT_UPDATE_TIME_LABEL, self.time_consuming_));
		if self.time_consuming_ == 0 then
			self:stopAllActions(); 
			cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUZZLE_GAME_DEFEAT);
		end 
	end), nil)));
end
function PuzzleDefeatCountdownComponent:getTimeConsuming()
	 return self.initail_time_ - self.time_consuming_;
end
function PuzzleDefeatCountdownComponent:getRemainTime()
	return self.time_consuming_;
end
return PuzzleDefeatCountdownComponent