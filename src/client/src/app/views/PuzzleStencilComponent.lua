
local PuzzleStencilComponent = class("PuzzleStencilComponent", function (direction, insideOrOutside)
    return cc.Node:create();
end)

PuzzleStencilComponent.PUZZLE_COMPONENT_DIRECTION_TO_DATA = {
    [PUZZLE_COMPONENT_LEFT] = {[PUZZLE_COMPONENT_ROTATION] = 0, [PUZZLE_COMPONENT_POSITION] = {x = PUZZLE_STENCIL_WIDTH/-2, y = 0}},
    [PUZZLE_COMPONENT_RIGHT] = {[PUZZLE_COMPONENT_ROTATION] = 180, [PUZZLE_COMPONENT_POSITION] = {x = PUZZLE_STENCIL_WIDTH/2, y = 0}},
    [PUZZLE_COMPONENT_TOP] = {[PUZZLE_COMPONENT_ROTATION] = 90, [PUZZLE_COMPONENT_POSITION] = {x = 0, y = PUZZLE_STENCIL_HEIGHT/2}},
    [PUZZLE_COMPONENT_BOTTOM] = {[PUZZLE_COMPONENT_ROTATION] = -90, [PUZZLE_COMPONENT_POSITION] = {x = 0, y = PUZZLE_STENCIL_HEIGHT/-2}}
};

function PuzzleStencilComponent:ctor(direction, insideOrOutside)
    printf("PuzzleStencilComponent");
    self:addPuzzleComponent(direction, insideOrOutside);
end

function PuzzleStencilComponent:addPuzzleComponent(direction, insideOrOutside)
    local spData = self.PUZZLE_COMPONENT_DIRECTION_TO_DATA[direction];
    assert(spData);
    local sp = cc.Sprite:create(PUZZLE_COMPONENT_PATH);
    sp:setAnchorPoint(PUZZLE_COMPONENT_ANCHOR);

    if insideOrOutside == PUZZLE_COMPONENT_ROTATION_OUTSIDE then
        sp:setRotation(spData[PUZZLE_COMPONENT_ROTATION]+180);
    else
        sp:setRotation(spData[PUZZLE_COMPONENT_ROTATION]);
    end

    sp:setPosition(spData[PUZZLE_COMPONENT_POSITION]);
    self:addChild(sp);
end

return PuzzleStencilComponent