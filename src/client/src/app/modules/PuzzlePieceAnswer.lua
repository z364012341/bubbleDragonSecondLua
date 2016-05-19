--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的答案类

local PuzzlePieceAnswer = class("PuzzlePieceAnswer", function (params)
    return cc.Node:create();
end)

local PuzzlePieceSingleEdges = require(PUZZLE_PIECE_ANSWER_SINGLE_EDGES_PATH);
-- local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);

function PuzzlePieceAnswer:ctor(params)
    --printf("PuzzlePieceAnswer");
    self:addAnswerEdges(params.left, params.right, params.top, params.bottom);
    self:initPosition(params.index_x, params.index_y, params.path);
    self:setScale(PUZZLE_PIECE_SCALE);
end

function PuzzlePieceAnswer:addAnswerEdges(left, right, top, bottom)
    self.edges_table_ = {};
    self:addSingleEdges(PUZZLE_COMPONENT_LEFT, left);
    self:addSingleEdges(PUZZLE_COMPONENT_RIGHT, right);
    self:addSingleEdges(PUZZLE_COMPONENT_TOP, top);
    self:addSingleEdges(PUZZLE_COMPONENT_BOTTOM, bottom);
end

function PuzzlePieceAnswer:addSingleEdges(direction, insideOrOutside)
	local node = PuzzlePieceSingleEdges:create(direction, insideOrOutside);
    table.insert(self.edges_table_, node);
	self:addChild(node);
end

function PuzzlePieceAnswer:initPosition(index_x, index_y)
	local posX = PUZZLE_STENCIL_WIDTH * (-0.5 + index_x);
	local posY = PUZZLE_STENCIL_HEIGHT * (-0.5 + index_y);
	self:setPosition(posX, posY);
end
-- function PuzzlePieceAnswer:blink()
--     --self:setBlendFunc(gl.ZERO,gl.ONE_MINUS_SRC_ALPHA)
--     --printf(#self.edges_table_);
--     for _, edge in ipairs(self.edges_table_) do
--         --printf(_, edge);
--         edge:blink();
--     end
-- end
-- function PuzzlePieceAnswer:noBlink()
--     for _, edge in ipairs(self.edges_table_) do
--         edge:noBlink();
--     end
-- end
return PuzzlePieceAnswer