--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图描边

local PuzzlePieceEdges = class("PuzzlePieceEdges", function (left, right, top, bottom)
    return cc.Node:create();
end)
local PuzzlePieceSingleEdges = require(PUZZLE_PIECE_SINGLE_EDGES_PATH);

function PuzzlePieceEdges:ctor(left, right, top, bottom)
    printf("PuzzlePieceEdges");
    self:addEdged(left, right, top, bottom);
    self:setScale(PUZZLE_STENCIL_WIDTH / PUZZLE_STENCIL_LENGTH);
end

function PuzzlePieceEdges:addEdged(left, right, top, bottom)
    self:addSingleEdged(PUZZLE_COMPONENT_LEFT, left);
    self:addSingleEdged(PUZZLE_COMPONENT_RIGHT, right);
    self:addSingleEdged(PUZZLE_COMPONENT_TOP, top);
    self:addSingleEdged(PUZZLE_COMPONENT_BOTTOM, bottom);
end

function PuzzlePieceEdges:addSingleEdged(direction, insideOrOutside)
    self:addChild(PuzzlePieceSingleEdges:create(direction, insideOrOutside));
end

return PuzzlePieceEdges