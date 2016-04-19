--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图答案描边  单边

local PuzzlePieceAnswerSingleEdges = class("PuzzlePieceAnswerSingleEdges", function (direction, insideOrOutside)
    return cc.Node:create();
end)
-- local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
local PuzzlePieceSingleEdges = require(PUZZLE_PIECE_SINGLE_EDGES_PATH);

-- PuzzlePieceAnswerSingleEdges.LING_ANCHOR_POINT = PUZZLE_COMPONENT_ANCHOR; 
function PuzzlePieceAnswerSingleEdges:ctor(direction, insideOrOutside)
    printf("PuzzlePieceAnswerSingleEdges");
    --local path = insideOrOutside == PUZZLE_STENCIL_COMPONENT_PLAIN and 
    --  PUZZLE_PIECE_ANSWER_SINGLE_EDGES_PLAIN_PATH or PUZZLE_PIECE_ANSWER_SINGLE_EDGES_NOT_PLAIN_PATH;
    local singleEdges = PuzzlePieceSingleEdges:create(direction, insideOrOutside);
    singleEdges:changeTextureColor(cc.c3b(231, 213, 186)); 
    --singleEdges._edgesSprite:setAnchorPoint({x = 5/189, y = 0.5}); 
    self:addChild(singleEdges);
end

return PuzzlePieceAnswerSingleEdges