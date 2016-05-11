--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 

local PuzzlePlayArea = class("PuzzlePlayArea", function ()
    return cc.Node:create();
end)
local PuzzlePlayWinLayer = require(PUZZLE_PLAY_WIN_LAYER_PATH);
local PUZZLE_AREA_EDGE_PATH = "pintudi.PNG";
function PuzzlePlayArea:ctor()
    --printf("PuzzlePlayArea");
    self:init();
end

function PuzzlePlayArea:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzlePlayArea:create()
    scene:addChild(layer)
    return scene
end
function PuzzlePlayArea:init()
    local win_clip = cc.ClippingNode:create(self:getBackgroundColorLayer());

    self:addChild(win_clip);
    self:addChild(GlobalFunction.createGameSpriteWithPath(PUZZLE_AREA_EDGE_PATH), 1);
    local background = self:getBackgroundColorLayer();
    self:addChild(background, -1);
    local puzzle_win = PuzzlePlayWinLayer:create();
    puzzle_win:setPosition(cc.p(background:getPosition()));
    win_clip:addChild(puzzle_win);
    --local size = cc.Director:getInstance():getVisibleSize();
    --self:setPosition(cc.p(size.width/2, size.height/2));
end
function PuzzlePlayArea:getBackgroundColorLayer()
    local colorLayer = cc.LayerColor:create(PUZZLE_SHOW_LAYER_COLOR_C4B, 656, 805);
    colorLayer:setPosition(cc.p(colorLayer:getContentSize().width/-2, colorLayer:getContentSize().height/-2));
    return colorLayer;
end
return PuzzlePlayArea