cc.exports.setSpriteTexture = function (sp, path)
	sp:setTexture(path);
end

cc.exports.PUZZLE_STENCIL_COMPONENT_PATH = "app.modules.PuzzleStencilComponent";
cc.exports.PUZZLE_STENCIL_PATH = "app.modules.PuzzleStencil";
cc.exports.PUZZLE_BOTTOM_PLATE_PATH = "app.modules.PuzzleBottomPlate";
cc.exports.PUZZLE_PIECE_PATH = "app.modules.PuzzlePiece";

cc.exports.PUZZLE_STENCIL_MAINBODY_PATH = "puzzleStencil_1.png";
cc.exports.PUZZLE_COMPONENT_PATH = "puzzleStencil_2.png";
cc.exports.PUZZLE_COMPONENT_LEFT = "component_left";
cc.exports.PUZZLE_COMPONENT_RIGHT = "component_right";
cc.exports.PUZZLE_COMPONENT_TOP = "component_top";
cc.exports.PUZZLE_COMPONENT_BOTTOM = "component_bottom";
cc.exports.PUZZLE_COMPONENT_ANCHOR = "component_anchor";
cc.exports.PUZZLE_COMPONENT_ROTATION = "component_rotation";
cc.exports.PUZZLE_COMPONENT_POSITION = "component_position";
cc.exports.PUZZLE_COMPONENT_ROTATION_INSIDE = "component_rotation_inside";
cc.exports.PUZZLE_COMPONENT_ROTATION_OUTSIDE = "component_rotation_outside";
cc.exports.PUZZLE_STENCIL_WIDTH = 240;
cc.exports.PUZZLE_STENCIL_HEIGHT = 240;
cc.exports.PUZZLE_COMPONENT_ANCHOR = {x = 0, y = 0.5};
-- cc.exports.PUZZLE_COMPONENT_DIRECTION_TO_DATA = {
--         [PUZZLE_COMPONENT_LEFT] = {[PUZZLE_COMPONENT_ANCHOR] = {x = 0, y = 0.5},[PUZZLE_COMPONENT_ROTATION] = 0, [PUZZLE_COMPONENT_POSITION] = {x = PUZZLE_STENCIL_WIDTH/-2, y = 0}},
--         [PUZZLE_COMPONENT_RIGHT] = {[PUZZLE_COMPONENT_ANCHOR] = {x = 1, y = 0.5}, [PUZZLE_COMPONENT_ROTATION] = 180, [PUZZLE_COMPONENT_POSITION] = {x = PUZZLE_STENCIL_WIDTH/2, y = 0}},
--         [PUZZLE_COMPONENT_TOP] = {[PUZZLE_COMPONENT_ANCHOR] = {x = 0.5, y = 1}, [PUZZLE_COMPONENT_ROTATION] = 90, [PUZZLE_COMPONENT_POSITION] = {x = 0, y = PUZZLE_STENCIL_HEIGHT/2}},
--         [PUZZLE_COMPONENT_BOTTOM] = {[PUZZLE_COMPONENT_ANCHOR] = {x = 0.5, y = 0}, [PUZZLE_COMPONENT_ROTATION] = -90, [PUZZLE_COMPONENT_POSITION] = {x = 0, y = PUZZLE_STENCIL_HEIGHT/-2}}
--     };
cc.exports.PUZZLE_STENCIL_COMPONENT_INSIDE = "component_inside";
cc.exports.PUZZLE_STENCIL_COMPONENT_OUTSIDE = "component_outside";
cc.exports.PUZZLE_STENCIL_COMPONENT_PLAIN = "component_plain";