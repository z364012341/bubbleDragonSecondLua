--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图描边  单边

local PuzzlePieceSingleEdges = class("PuzzlePieceSingleEdges", function (direction, insideOrOutside)
    return cc.Node:create();
end)
-- local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
-- local PuzzlePieceSingleEdgesAnswer = require(PUZZLE_PIECE_ANSWER_PATH);

PuzzlePieceSingleEdges.LING_ANCHOR_POINT = PUZZLE_COMPONENT_ANCHOR; 
function PuzzlePieceSingleEdges:ctor(direction, insideOrOutside)
    printf("PuzzlePieceSingleEdges");
    local sp = {};
    if insideOrOutside == PUZZLE_STENCIL_COMPONENT_PLAIN then
    	sp = GlobalFunction.createGameSpriteWithPath(PUZZLE_PLAIN_EDGES_PATH);
    else
    	sp = GlobalFunction.createGameSpriteWithPath(PUZZLE_NOT_PLAIN_EDGES_PATH);
    end
    sp:setAnchorPoint(self.LING_ANCHOR_POINT);
    sp:getTexture():setAntiAliasTexParameters();

    if insideOrOutside == PUZZLE_STENCIL_COMPONENT_OUTSIDE then
        sp:setRotation(GlobalFunction.getPuzzlePiecePositionWithRotation(direction) + 180);
    else
        sp:setRotation(GlobalFunction.getPuzzlePiecePositionWithRotation(direction));
    end
    self:addChild(sp);
    self:setPosition(GlobalFunction.getPuzzlePiecePositionWithDirection(direction));

end

return PuzzlePieceSingleEdges