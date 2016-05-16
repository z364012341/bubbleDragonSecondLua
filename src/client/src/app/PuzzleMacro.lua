cc.exports.PUZZLE_STENCIL_COMPONENT_PATH = "app.modules.PuzzleStencilComponent";
cc.exports.PUZZLE_STENCIL_PATH = "app.modules.PuzzleStencil";
cc.exports.PUZZLE_BOTTOM_PLATE_PATH = "app.modules.PuzzleBottomPlate";
cc.exports.PUZZLE_PIECE_PATH = "app.modules.PuzzlePiece";
cc.exports.PUZZLE_PIECES_COLLECTION_PATH = "app.modules.PuzzlePiecesCollection";
cc.exports.PUZZLE_PIECE_ANSWER_PATH = "app.modules.PuzzlePieceAnswer";
cc.exports.PUZZLE_PIECE_SINGLE_EDGES_PATH = "app.modules.PuzzlePieceSingleEdges";
cc.exports.PUZZLE_PIECE_EDGES_PATH = "app.modules.PuzzlePieceEdges";
cc.exports.PUZZLE_PIECE_SHADOW_PATH = "app.modules.PuzzlePieceShadow";
cc.exports.PUZZLE_PIECE_ANSWER_SINGLE_EDGES_PATH = "app.modules.PuzzlePieceAnswerSingleEdges";
cc.exports.PUZZLE_DEFEAT_COUNTDOWN_COMPONENT_PATH = "app.modules.PuzzleDefeatCountdownComponent";
cc.exports.PUZZLE_VICTORY_COUNTDOWN_COMPONENT_PATH = "app.modules.PuzzleVictoryCountdownComponent";

cc.exports.PUZZLE_PLAY_AREA_INNER_CONTAINER = "app.views.PuzzlePlayAreaInnerContainer";
cc.exports.PUZZLE_SELECTED_SHOW_PATH = "app.views.PuzzleSelectedShow";
cc.exports.PUZZLE_SELECTED_SCENE_PATH = "app.views.PuzzleSelectedScene";
cc.exports.PUZZLE_PIECES_SCROLLVIEW_PATH = "app.views.PuzzlePiecesScrollView";
cc.exports.PUZZLE_GAME_PAUSE_ALERT_PATH = "app.views.PuzzleGamePauseAlert";
cc.exports.PUZZLE_PLAY_SCENE_PATH = "app.views.PuzzlePlayScene";
cc.exports.PUZZLE_PLAY_AREA_PATH = "app.views.PuzzlePlayArea";
cc.exports.PUZZLE_GAME_DEFEAT_ALERT_PATH = "app.views.PuzzleGameDefeatAlert";
cc.exports.PUZZLE_GAME_VICTORY_ALERT_PATH = "app.views.PuzzleGameVictoryAlert";
cc.exports.PUZZLE_TIME_DISPLAY_PATH = "app.views.PuzzleTimeDisplay";

cc.exports.EVENT_PUZZLE_ANSWER_LOAD = "event_puzzle_answer_load";
cc.exports.EVENT_PUSH_ANSWERS_THUMBNAIL = "event_push_answers_thumbnail";
cc.exports.EVENT_CHANGE_PAGEVIEW_TYPE = "event_change_pageview_type";
cc.exports.EVENT_PUZZLE_SELECTED_SCROLL_LEFT = "event_puzzle_selected_scroll_left";
cc.exports.EVENT_PUZZLE_SELECTED_SCROLL_RIGHT = "event_puzzle_selected_scroll_right";
cc.exports.EVENT_PAUSE = "event_pause";
cc.exports.EVENT_REPLAY = "event_replay";
cc.exports.EVENT_RETURN = "event_return";
cc.exports.EVENT_CONTINUE = "event_continue";
cc.exports.EVENT_PUZZLE_GAME_DEFEAT = "event_puzzle_game_defeat";
cc.exports.EVENT_PUZZLE_ANSWER_ADD = "event_puzzle_answer_add";
cc.exports.EVENT_PUZZLE_GAME_VICTORY = "event_puzzle_game_victory";
cc.exports.EVENT_UPDATE_TIME_LABEL = "event_update_time_label";


cc.exports.PUZZLE_STENCIL_MAINBODY_PATH = "puzzleStencil_1.png";
cc.exports.PUZZLE_COMPONENT_PATH = "puzzleStencil_2.png";
cc.exports.PUZZLE_PLAIN_EDGES_PATH = "edges_2.png";
cc.exports.PUZZLE_NOT_PLAIN_EDGES_PATH = "edges_1.png";
cc.exports.PUZZLE_PIECE_SHADOW_FULL_PATH = "puzzle_shadow_1.png"; 
cc.exports.PUZZLE_PIECE_SHADOW_LACK_PATH = "puzzle_shadow_2.png"; 
cc.exports.PUZZLE_PIECE_SHADOW_COMPONENT_PATH = "puzzle_shadow_3.png"; 
--cc.exports.PUZZLE_PIECE_ANSWER_SINGLE_EDGES_PLAIN_PATH = "edges_2.png";
--cc.exports.PUZZLE_PIECE_ANSWER_SINGLE_EDGES_NOT_PLAIN_PATH = "edges_1.png";

cc.exports.PUZZLE_COMPONENT_LEFT = "component_left";
cc.exports.PUZZLE_COMPONENT_RIGHT = "component_right";
cc.exports.PUZZLE_COMPONENT_TOP = "component_top";
cc.exports.PUZZLE_COMPONENT_BOTTOM = "component_bottom";
--cc.exports.PUZZLE_COMPONENT_ANCHOR = "component_anchor";
cc.exports.PUZZLE_COMPONENT_ROTATION = "component_rotation";
cc.exports.PUZZLE_COMPONENT_POSITION = "component_position";
--cc.exports.PUZZLE_COMPONENT_ROTATION_INSIDE = "component_rotation_inside";
--cc.exports.PUZZLE_COMPONENT_ROTATION_OUTSIDE = "component_rotation_outside";
cc.exports.PUZZLE_STENCIL_WIDTH = 240;
cc.exports.PUZZLE_STENCIL_HEIGHT = PUZZLE_STENCIL_WIDTH;
cc.exports.PUZZLE_STENCIL_LENGTH = 588;
cc.exports.PUZZLE_COMPONENT_ANCHOR = {x = 0, y = 0.5};
cc.exports.PUZZLE_EDGES_ANCHOR = {x = 5/189, y = 0.5};
cc.exports.PUZZLE_PIECE_SHADOW_ANCHOR = {x = 0.5, y = 1};
cc.exports.PUZZLE_PIECE_SHADOW_OFFSET_POSITION = {x = 20, y = -20};
cc.exports.PUZZLE_PIECE_SCALE = PUZZLE_STENCIL_WIDTH / PUZZLE_STENCIL_LENGTH;

cc.exports.PUZZLE_STENCIL_COMPONENT_INSIDE = "component_inside";
cc.exports.PUZZLE_STENCIL_COMPONENT_OUTSIDE = "component_outside";
cc.exports.PUZZLE_STENCIL_COMPONENT_PLAIN = "component_plain";
cc.exports.PUZZLE_PIECES_COLLECTION_INDEX_START = 1;
cc.exports.PUZZLE_PLAY_SCENE_ZOOM_SCALE_MIN = 0.3;
cc.exports.PUZZLE_PLAY_SCENE_ZOOM_SCALE_MAX = 1.7;
cc.exports.PUZZLE_INITIAL_SIZE = cc.size(976, 1464);
cc.exports.PUZZLE_SHOW_LAYER_COLOR_C4B = cc.c4b(70, 48, 61, 255);

cc.exports.puzzle = {
	PUZZLE_DIRECTIOIN_RANDOM = {
		PUZZLE_STENCIL_COMPONENT_INSIDE,
		PUZZLE_STENCIL_COMPONENT_OUTSIDE,
		--PUZZLE_STENCIL_COMPONENT_PLAIN
	},
	PUZZLE_DIRECTIOIN_TO_RELATIVE = {
		[PUZZLE_STENCIL_COMPONENT_INSIDE] = PUZZLE_STENCIL_COMPONENT_OUTSIDE,
		[PUZZLE_STENCIL_COMPONENT_OUTSIDE] = PUZZLE_STENCIL_COMPONENT_INSIDE,
		[PUZZLE_STENCIL_COMPONENT_PLAIN] = PUZZLE_STENCIL_COMPONENT_PLAIN
	},
	PUZZLE_COMPONENT_DIRECTION_TO_DATA = {
	    [PUZZLE_COMPONENT_LEFT] = {[PUZZLE_COMPONENT_ROTATION] = 0, [PUZZLE_COMPONENT_POSITION] = {x = PUZZLE_STENCIL_LENGTH/-2, y = 0}},
	    [PUZZLE_COMPONENT_RIGHT] = {[PUZZLE_COMPONENT_ROTATION] = 180, [PUZZLE_COMPONENT_POSITION] = {x = PUZZLE_STENCIL_LENGTH/2, y = 0}},
	    [PUZZLE_COMPONENT_TOP] = {[PUZZLE_COMPONENT_ROTATION] = 90, [PUZZLE_COMPONENT_POSITION] = {x = 0, y = PUZZLE_STENCIL_LENGTH/2}},
	    [PUZZLE_COMPONENT_BOTTOM] = {[PUZZLE_COMPONENT_ROTATION] = -90, [PUZZLE_COMPONENT_POSITION] = {x = 0, y = PUZZLE_STENCIL_LENGTH/-2}}
	},
	PUZZLE_PIECE_SHADOW_DIRECTION_TO_DATA = {
        [PUZZLE_COMPONENT_LEFT] =  90, [PUZZLE_COMPONENT_RIGHT] = -90, [PUZZLE_COMPONENT_TOP] = 180, [PUZZLE_COMPONENT_BOTTOM] = 0
	},
	PUZZLE_PIECE_SHADOW_DIRECTION_TO_PATH = {
	   [PUZZLE_STENCIL_COMPONENT_PLAIN] = PUZZLE_PIECE_SHADOW_FULL_PATH,
	   [PUZZLE_STENCIL_COMPONENT_OUTSIDE] = PUZZLE_PIECE_SHADOW_FULL_PATH,
	   [PUZZLE_STENCIL_COMPONENT_INSIDE] = PUZZLE_PIECE_SHADOW_LACK_PATH  
	}
}