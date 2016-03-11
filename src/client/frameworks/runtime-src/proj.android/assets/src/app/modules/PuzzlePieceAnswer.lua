--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的答案类

local PuzzlePieceAnswer = class("PuzzlePieceAnswer", function (params)
    return cc.Node:create();
end)

local PuzzleStencil = require(PUZZLE_STENCIL_PATH);
local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);

function PuzzlePieceAnswer:ctor(params)
    printf("PuzzlePieceAnswer");
    self:addTexture(params.left, params.right, params.top, params.bottom);
    self:initPosition(params.index_x, params.index_y, params.path);
    --self:setScale(0.8);
end

function PuzzlePieceAnswer:addTexture(left, right, top, bottom)
	local stencilNode = PuzzleStencil:create(left, right, top, bottom);
	self:addChild(stencilNode);
end

function PuzzlePieceAnswer:initPosition(index_x, index_y, path)
	local plate = PuzzleBottomPlate:create(index_x, index_y, path); 
	self:setPositionX(plate:getPositionX()*-1);
	self:setPositionY(plate:getPositionY()*-1);
end
return PuzzlePieceAnswer