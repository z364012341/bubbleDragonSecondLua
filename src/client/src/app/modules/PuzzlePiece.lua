--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图碎片
--[[
	{
        index_x = 0, --拼图碎片的x索引
        index_y = 0, --拼图碎片的y索引
        path = "puzzle_1.png",    --底板的资源路径
        left = PUZZLE_STENCIL_COMPONENT_INSIDE,    --左边凹凸方向
        right = PUZZLE_STENCIL_COMPONENT_OUTSIDE,   --右边凹凸方向
        top = PUZZLE_STENCIL_COMPONENT_PLAIN,     --上边凹凸方向
        bottom = PUZZLE_STENCIL_COMPONENT_PLAIN  --下边凹凸方向
    }
]]
local PuzzlePiece = class("PuzzlePiece", function (params)
	dump(params)
    return cc.ClippingNode:create(require(PUZZLE_STENCIL_PATH):create(params.left, 
    	params.right, params.top, params.bottom));
end)
local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);

function PuzzlePiece:ctor(params)
    printf("PuzzlePiece");
    self:addChild(PuzzleBottomPlate:create(params.index_x, params.index_y, params.path));
    self:setAlphaThreshold(0.00);
end

function PuzzlePiece:getPosWithIndex(index_x, index_y)
	local posX = PUZZLE_STENCIL_WIDTH * (0.5 + index_x);
	local posY = PUZZLE_STENCIL_HEIGHT * (0.5 + index_y);
	return -1*posX, -1*posY;
end
return PuzzlePiece