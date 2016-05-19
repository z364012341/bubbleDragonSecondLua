--
-- Author: 黄泽昊
-- 功能: 失败倒计时组件

local PuzzleDefeatCountdownComponent = class("PuzzleDefeatCountdownComponent", function ()
    return cc.Node:create();
end)
local ADD_TIME_NUMBLE = 20;
function PuzzleDefeatCountdownComponent:ctor()
	self.initail_time_ = 233;
	self.time_consuming_ = self.initail_time_ ;
   	local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);

	self:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1), cc.CallFunc:create(function ()
		self.time_consuming_ = self.time_consuming_ - 1;
		--self:getEventDispatcher():dispatchEvent(GlobalFunction.createCustomEvent(EVENT_UPDATE_TIME_LABEL, self.time_consuming_));
		self:updateTimeLabel();
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
function PuzzleDefeatCountdownComponent:updateTimeLabel()
    self:getEventDispatcher():dispatchEvent(GlobalFunction.createCustomEvent(EVENT_UPDATE_TIME_LABEL, self.time_consuming_));
end
function PuzzleDefeatCountdownComponent:onEnter()
	self:updateTimeLabel();
    self.listener_ = {};

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_ADD_TIME_PROP, function ( event )
		self.time_consuming_ = self.time_consuming_+ADD_TIME_NUMBLE;
		self:updateTimeLabel();
    end));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleDefeatCountdownComponent:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleDefeatCountdownComponent