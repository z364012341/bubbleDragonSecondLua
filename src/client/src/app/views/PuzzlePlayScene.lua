
local PuzzlePlayScene = class("PuzzlePlayScene", function ()
    return cc.Layer:create();
end)

function PuzzlePlayScene:ctor()
    printf("PuzzlePlayScene");

    local stencil_1 = cc.Sprite:create("puzzleStencil_1.png");
    local PuzzleStencilComponent = require(PUZZLE_STENCIL_COMPONENT_PATH);
    local stencil_2 = PuzzleStencilComponent:create(PUZZLE_COMPONENT_LEFT);
    local stencil_node = require(PUZZLE_STENCIL_PATH):create();
    -- cc.Node:create();
    -- stencil_node:addChild(stencil_1);
    -- stencil_node:addChild(stencil_2);
    -- stencil_node:addChild(PuzzleStencilComponent:create(PUZZLE_COMPONENT_TOP, PUZZLE_COMPONENT_ROTATION_OUTSIDE));

    --stencil_node:setPosition(100, 100);
    local clippingNode = cc.ClippingNode:create(stencil_node);
    clippingNode:addChild(cc.Sprite:create("puzzle_1.png"));
    clippingNode:setPosition(300,300);
    clippingNode:setAlphaThreshold(0.00);
    self:addChild(clippingNode);
end

function PuzzlePlayScene:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzlePlayScene:create()
    scene:addChild(layer)
    return scene
end

return PuzzlePlayScene