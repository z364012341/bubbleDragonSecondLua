
local PuzzleStencil = class("PuzzleStencil", function ()
    return cc.Node:create();
end)
local PuzzleStencilComponent = require(PUZZLE_STENCIL_COMPONENT_PATH);

PuzzleStencil.componentInsideOrOutsideToHandle = {
    [PUZZLE_STENCIL_COMPONENT_INSIDE] = PuzzleStencil.addInsideComponent, 
    [PUZZLE_STENCIL_COMPONENT_OUTSIDE] = PuzzleStencil.addOutsideComponent,
    [PUZZLE_STENCIL_COMPONENT_PLAIN] = PuzzleStencil.addOutsideComponent,
}


function PuzzleStencil:ctor()
    printf("PuzzleStencil");
    self:initPuzzleComponent();
end

function PuzzleStencil:initPuzzleComponent()
    self:addChild(cc.Sprite:create(PUZZLE_STENCIL_MAINBODY_PATH));
    self:addOutsideComponent(PUZZLE_COMPONENT_LEFT);
end

function PuzzleStencil:addOutsideComponent(componentDirection)
    self:addChild(PuzzleStencilComponent:create(componentDirection, PUZZLE_COMPONENT_ROTATION_OUTSIDE))
    self:addPlainComponent(componentDirection)
end

function PuzzleStencil:addInsideComponent(componentDirection)
    --self:addChild(PuzzleStencilComponent:create(componentDirection))
end

function PuzzleStencil:addPlainComponent(componentDirection)
    self:addChild(PuzzleStencilComponent:create(componentDirection))
end
return PuzzleStencil