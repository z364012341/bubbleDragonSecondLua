--
-- Author: 黄泽昊
-- 功能: 答案搜索道具

local PuzzleSearchProp = class("PuzzleSearchProp", function ()
    return cc.Node:create();
end)
local PuzzlePropsBackground = require(PUZZLE_PROPS_BACKGROUND_PATH);
local BACKGROUND_PATH = "daojudi.PNG";
local PROP_SEARCH_PATH = "daoju1.PNG";
function PuzzleSearchProp:ctor()
    self:init();
end
function PuzzleSearchProp:init()
    self:addChild(PuzzlePropsBackground:create(EVENT_USE_SEARCH_PROP));
    self:addChild(GlobalFunction.createGameSpriteWithPath(PROP_SEARCH_PATH));
end
return PuzzleSearchProp