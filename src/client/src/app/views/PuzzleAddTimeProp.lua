--
-- Author: 黄泽昊
-- 功能: 增加时间道具

local PuzzleAddTimeProp = class("PuzzleAddTimeProp", function ()
    return cc.Node:create();
end)
local PuzzlePropsBackground = require(PUZZLE_PROPS_BACKGROUND_PATH);
local PROP_ADD_TIME_PATH = "daoju3.PNG";
function PuzzleAddTimeProp:ctor()
    self:init();
end
function PuzzleAddTimeProp:init()
    --dump(PuzzlePropsBackground:create(EVENT_USE_ADD_TIME_PROP, ".,.", 0));
    self:addChild(PuzzlePropsBackground:create(EVENT_USE_ADD_TIME_PROP, ".,.", 0));
    self:addChild(GlobalFunction.createGameSpriteWithPath(PROP_ADD_TIME_PATH));
end


return PuzzleAddTimeProp