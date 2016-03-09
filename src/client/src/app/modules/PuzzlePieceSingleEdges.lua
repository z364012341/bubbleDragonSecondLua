--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图描边  单边

local PuzzlePieceSingleEdges = class("PuzzlePieceSingleEdges", function (direction, insideOrOutside)
    return cc.Node:create();
end)
-- local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
-- local PuzzlePieceSingleEdgesAnswer = require(PUZZLE_PIECE_ANSWER_PATH);

-- PuzzlePieceSingleEdges.LING_ANCHOR_POINT = PUZZLE_COMPONENT_ANCHOR; 
function PuzzlePieceSingleEdges:ctor(direction, insideOrOutside)
    printf("PuzzlePieceSingleEdges");
    self._edgesSprite = {};
    if insideOrOutside == PUZZLE_STENCIL_COMPONENT_PLAIN then
    	self._edgesSprite = GlobalFunction.createGameSpriteWithPath(PUZZLE_PLAIN_EDGES_PATH);
    else
    	self._edgesSprite = GlobalFunction.createGameSpriteWithPath(PUZZLE_NOT_PLAIN_EDGES_PATH);
    end
    self._edgesSprite:setAnchorPoint(PUZZLE_COMPONENT_ANCHOR);
    self._edgesSprite:getTexture():setAntiAliasTexParameters();
    self._edgesSprite:setRotation(GlobalFunction.getPuzzlePiecePositionWithRotation(direction, insideOrOutside));
    self:addChild(self._edgesSprite);
    self:setPosition(GlobalFunction.getPuzzlePiecePositionWithDirection(direction));
end

function PuzzlePieceSingleEdges:changeTexture(path)
    GlobalFunction.setGameSpriteTextureWithPath(path, self._edgesSprite);
end

return PuzzlePieceSingleEdges