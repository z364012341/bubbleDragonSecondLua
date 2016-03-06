-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的生成类
-- 索引坐标从左下角开始(1,1)
local PuzzlePiecesCollection = class("PuzzlePiecesCollection", function (puzzlePath)
    return cc.Node:create();
end)
-- PuzzlePiecesCollection.PUZZLE_DIRECTIOIN_RANDOM = {
-- 	PUZZLE_STENCIL_COMPONENT_INSIDE,
-- 	PUZZLE_STENCIL_COMPONENT_OUTSIDE,
-- 	PUZZLE_STENCIL_COMPONENT_PLAIN
-- }
-- PuzzlePiecesCollection.PUZZLE_DIRECTIOIN_TO_RELATIVE = {
-- 	[PUZZLE_STENCIL_COMPONENT_INSIDE] = PUZZLE_STENCIL_COMPONENT_OUTSIDE,
-- 	[PUZZLE_STENCIL_COMPONENT_OUTSIDE] = PUZZLE_STENCIL_COMPONENT_INSIDE,
-- 	[PUZZLE_STENCIL_COMPONENT_PLAIN] = PUZZLE_STENCIL_COMPONENT_PLAIN
-- }
function PuzzlePiecesCollection:ctor(puzzlePath)
    printf("PuzzlePiecesCollection");
    self._relativeDirection = {};
    self:initIndexMax(GlobalFunction.createGameSpriteWithPath(puzzlePath):getContentSize());
    --printf(indexMaxX);
    --printf(indexMaxY);
    for indexY = 1, self._indexMaxX do
    	for indexX = 1, self._indexMaxY do
		    local clippingNode = require(PUZZLE_PIECE_PATH):create({
		        index_x = indexX, --拼图碎片的x索引
		        index_y = indexY, --拼图碎片的y索引
		        path = puzzlePath,    --底板的资源路径
		        left = self:calculateLaftDirection(indexX),    --左边凹凸方向
		        right = self:calculateRightDirection(indexX),   --右边凹凸方向
		        top = self:calculateTopDirection(indexX, indexY),    --上边凹凸方向
		        bottom = self:calculateBottomDirection(indexX, indexY),  --下边凹凸方向
		    });
		    self:addChild(clippingNode);
    	end
    end
end

function PuzzlePiecesCollection:initIndexMax(size)
    self._indexMaxX = math.floor(size.width/PUZZLE_STENCIL_WIDTH);
    self._indexMaxY = math.floor(size.height/PUZZLE_STENCIL_HEIGHT);
end

function PuzzlePiecesCollection:calculateLaftDirection(indexX)
	printf("PuzzlePiecesCollection:calculateRightDirection");
	if indexX == PUZZLE_PIECES_COLLECTION_INDEX_START then
		return PUZZLE_STENCIL_COMPONENT_PLAIN;
	else
		return self:getRelativeDirection(self._relativeDirection.right);
	end
end

function PuzzlePiecesCollection:calculateRightDirection(indexX)
	local result = self:getMaxIndexDirection(indexX, self._indexMaxX);
	self._relativeDirection.right = result;
	return result;
end

function PuzzlePiecesCollection:calculateTopDirection(indexX, indexY)
	local result = self:getMaxIndexDirection(indexY, self._indexMaxY);
	if self._relativeDirection[indexX] == nil then
		self._relativeDirection[indexX] = {};
	end
	self._relativeDirection[indexX][indexY] = result;
	return result;
end

function PuzzlePiecesCollection:getMaxIndexDirection(index, indexMax)
	if index == indexMax then
		return PUZZLE_STENCIL_COMPONENT_PLAIN;
	else
		return self:getRandomDirection();
	end
end

function PuzzlePiecesCollection:calculateBottomDirection(indexX, indexY)
	if indexY == PUZZLE_PIECES_COLLECTION_INDEX_START then
		return PUZZLE_STENCIL_COMPONENT_PLAIN;
	else
		return self:getRelativeDirection(self._relativeDirection[indexX][indexY-1]);
	end
end

function PuzzlePiecesCollection:getRandomDirection()
	return puzzle.PUZZLE_DIRECTIOIN_RANDOM[math.random(1, #puzzle.PUZZLE_DIRECTIOIN_RANDOM)];
end

function PuzzlePiecesCollection:getRelativeDirection(relativeDirection)
	return puzzle.PUZZLE_DIRECTIOIN_TO_RELATIVE[relativeDirection];
end
return PuzzlePiecesCollection