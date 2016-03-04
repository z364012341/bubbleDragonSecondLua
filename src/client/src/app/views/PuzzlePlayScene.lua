--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 

local PuzzlePlayScene = class("PuzzlePlayScene", function ()
    return cc.Layer:create();
end)

function PuzzlePlayScene:ctor()
    printf("PuzzlePlayScene");

    -- local stencil_1 = cc.Sprite:create("puzzleStencil_1.png");
    -- local PuzzleStencilComponent = require(PUZZLE_STENCIL_COMPONENT_PATH);
    -- local stencil_2 = PuzzleStencilComponent:create(PUZZLE_COMPONENT_LEFT);
    -- local stencil_node = require(PUZZLE_STENCIL_PATH):create(PUZZLE_STENCIL_COMPONENT_INSIDE, 
    --     PUZZLE_STENCIL_COMPONENT_OUTSIDE, PUZZLE_STENCIL_COMPONENT_PLAIN, PUZZLE_STENCIL_COMPONENT_PLAIN);
----[[
    local clippingNode = require(PUZZLE_PIECE_PATH):create({
        index_x = 0, --拼图碎片的x索引
        index_y = 1, --拼图碎片的y索引
        path = "puzzle_1.png",    --底板的资源路径
        left = PUZZLE_STENCIL_COMPONENT_INSIDE,    --左边凹凸方向
        right = PUZZLE_STENCIL_COMPONENT_OUTSIDE,   --右边凹凸方向
        top = PUZZLE_STENCIL_COMPONENT_PLAIN,     --上边凹凸方向
        bottom = PUZZLE_STENCIL_COMPONENT_PLAIN  --下边凹凸方向
    });
    clippingNode:setPosition(300, 300);
    self:addChild(clippingNode);
--]]
end

function PuzzlePlayScene:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzlePlayScene:create()
    scene:addChild(layer)
    return scene
end

return PuzzlePlayScene