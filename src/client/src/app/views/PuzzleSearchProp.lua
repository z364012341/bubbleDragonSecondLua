--
-- Author: 黄泽昊
-- 功能: 答案搜索道具

local PuzzleSearchProp = class("PuzzleSearchProp", function ()
    return cc.Node:create();
end)
local PuzzlePropsBackground = require(PUZZLE_PROPS_BACKGROUND_PATH);
local PuzzlePropCoolingTimerComponent = require(PUZZLE_PROP_COOLING_TIMER_COMPONENT_PATH);
local PROP_SEARCH_PATH = "daoju1.PNG";
local PROP_SEARCH_COOLING_GRAY_PATH = "search_gray.png";
local PROP_SEARCH_TIME = 10;
function PuzzleSearchProp:ctor()
	local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    -- self.selfisCooling_ = false;
    self:init();
end
function PuzzleSearchProp:init()
    self:addChild(PuzzlePropsBackground:create(EVENT_USE_SEARCH_PROP, EVENT_END_SEARCH_PROP, PROP_SEARCH_TIME));
    self:addChild(GlobalFunction.createGameSpriteWithPath(PROP_SEARCH_PATH));
    local numble_label = bs.PropsNumbleShow:create();
    self:addChild(numble_label, 1);
end

function PuzzleSearchProp:onEnter()
    self.listener_ = {};

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_SEARCH_PROP, function ( event )
	    local timer = PuzzlePropCoolingTimerComponent:create(PROP_SEARCH_COOLING_GRAY_PATH, PROP_SEARCH_TIME);
	    timer:setPosition(cc.p(-3, 4))
	    self:addChild(timer);
    end));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleSearchProp:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleSearchProp