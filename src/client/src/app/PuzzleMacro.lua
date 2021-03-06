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
cc.exports.PUZZLE_GAME_PLAY_TIMER_COMPONENT_PATH = "app.modules.PuzzleGamePlayTimerComponent";

cc.exports.PUZZLE_PLAY_AREA_INNER_CONTAINER = "app.views.PuzzlePlayAreaInnerContainer";
--local PuzzleSelectedShow = require(PUZZLE_SELECTED_SHOW_PATH);
cc.exports.PUZZLE_SELECTED_SHOW_PATH = "app.views.PuzzleSelectedShow";
--local PuzzleSelectedScene = require(PUZZLE_SELECTED_SCENE_PATH);
cc.exports.PUZZLE_SELECTED_SCENE_PATH = "app.views.PuzzleSelectedScene";
cc.exports.PUZZLE_PIECES_SCROLLVIEW_PATH = "app.views.PuzzlePiecesScrollView";
cc.exports.PUZZLE_GAME_PAUSE_ALERT_PATH = "app.views.PuzzleGamePauseAlert";
cc.exports.PUZZLE_PLAY_SCENE_PATH = "app.views.PuzzlePlayScene";
--local PuzzlePlayArea = require(PUZZLE_PLAY_AREA_PATH);
cc.exports.PUZZLE_PLAY_AREA_PATH = "app.views.PuzzlePlayArea";
cc.exports.PUZZLE_GAME_DEFEAT_ALERT_PATH = "app.views.PuzzleGameDefeatAlert";
cc.exports.PUZZLE_GAME_VICTORY_ALERT_PATH = "app.views.PuzzleGameVictoryAlert";
cc.exports.PUZZLE_TIME_DISPLAY_PATH = "app.views.PuzzleTimeDisplay";
cc.exports.PUZZLE_SMALL_EYES_PROP_PATH = "app.views.PuzzleSmallEyesProp";
cc.exports.PUZZLE_PROPS_BACKGROUND_PATH = "app.views.PuzzlePropsBackground";
cc.exports.PUZZLE_SEARCH_PROP_PATH = "app.views.PuzzleSearchProp";
cc.exports.PUZZLE_PROP_COOLING_TIMER_COMPONENT_PATH = "app.views.PuzzlePropCoolingTimerComponent";
cc.exports.PUZZLE_BIG_EYES_PROP_PATH = "app.views.PuzzleBigEyesProp";
cc.exports.PUZZLE_ADD_TIME_PROP_PATH = "app.views.PuzzleAddTimeProp";
cc.exports.PUZZLE_SELECTED_PAGEVIEW_POINT_PATH = "app.views.PuzzleSelectedPageViewPoint";
cc.exports.PUZZLE_SELECTED_PAGEVIEW_PATH = "app.views.PuzzleSelectedPageView";
--local PuzzleStoreAlert = require(PUZZLE_STORE_ALERT_PATH);
cc.exports.PUZZLE_STORE_ALERT_PATH = "app.views.PuzzleStoreAlert";
--local PuzzleStartScene = require(PUZZLE_START_SCENE_PATH);
cc.exports.PUZZLE_START_SCENE_PATH = "app.views.PuzzleStartScene";
--local PuzzleLotteryAlert = require(PUZZLE_LOTTERY_ALERT_PATH);
cc.exports.PUZZLE_LOTTERY_ALERT_PATH = "app.views.PuzzleLotteryAlert";
--local DecalsExhibitionBackground = require(DECALS_EXHIBITION_BACKGROUND_PATH);
cc.exports.DECALS_EXHIBITION_BACKGROUND_PATH = "app.views.DecalsExhibitionBackground";
--local DecalsExhibitionPageView = require(DECALS_EXHIBITION_PAGEVIEW_PATH);
cc.exports.DECALS_EXHIBITION_PAGEVIEW_PATH = "app.views.DecalsExhibitionPageView";
--local DecalsExhibitionAlert = require(DECALS_EXHIBITION_ALERT_PATH);
cc.exports.DECALS_EXHIBITION_ALERT_PATH = "app.views.DecalsExhibitionAlert";
--local DecalsExhibitionNode = require(DECALS_EXHIBITION_NODE_PATH);
cc.exports.DECALS_EXHIBITION_NODE_PATH = "app.views.DecalsExhibitionNode";
--local DecalsLotteryScene = require(DECALS_LOTTERY_SCENE_PATH);
cc.exports.DECALS_LOTTERY_SCENE_PATH = "app.views.DecalsLotteryScene";
--local DecalsLotteryCard = require(DECALS_LOTTERY_CARD_PATH);
cc.exports.DECALS_LOTTERY_CARD_PATH = "app.views.DecalsLotteryCard";
--local DecalsLotteryCardsShow = require(DECALS_LOTTERY_CARDS_SHOW_PATH);
cc.exports.DECALS_LOTTERY_CARDS_SHOW_PATH = "app.views.DecalsLotteryCardsShow";
--local DecalsCharactorUnlockAlert = require(DECALS_CHARACTOR_UNLOCK_ALERT_PATH);
cc.exports.DECALS_CHARACTOR_UNLOCK_ALERT_PATH = "app.views.DecalsCharactorUnlockAlert";
--local DecalsTreasureUnlockAlert = require(DECALS_TREASURE_UNLOCK_ALERT_PATH);
cc.exports.DECALS_TREASURE_UNLOCK_ALERT_PATH = "app.views.DecalsTreasureUnlockAlert";

cc.exports.EVENT_PUZZLE_ANSWER_LOAD = "event_puzzle_answer_load";
cc.exports.EVENT_PUSH_ANSWERS_THUMBNAIL = "event_push_answers_thumbnail";
cc.exports.EVENT_CHANGE_PAGEVIEW_TYPE = "event_change_pageview_type";
cc.exports.EVENT_PUZZLE_SELECTED_SCROLL_LEFT = "event_puzzle_selected_scroll_left";
cc.exports.EVENT_PUZZLE_SELECTED_SCROLL_RIGHT = "event_puzzle_selected_scroll_right";
cc.exports.EVENT_PAUSE = "event_pause";
cc.exports.EVENT_REPLAY = "event_replay";
cc.exports.EVENT_RETURN = "event_return";
cc.exports.EVENT_VICTORY_RETURN = "event_victory_return";
cc.exports.EVENT_CONTINUE = "event_continue";
cc.exports.EVENT_PUZZLE_GAME_DEFEAT = "event_puzzle_game_defeat";
cc.exports.EVENT_PUZZLE_ANSWER_ADD = "event_puzzle_answer_add";
cc.exports.EVENT_PUZZLE_GAME_VICTORY = "event_puzzle_game_victory";
cc.exports.EVENT_UPDATE_TIME_LABEL = "event_update_time_label";
cc.exports.EVENT_USE_SMALL_EYES = "event_use_small_eyes";
cc.exports.EVENT_TOUCH_SEARCH_PROP = "event_touch_search_prop";
cc.exports.EVENT_USE_SEARCH_PROP = "event_use_search_prop";
cc.exports.EVENT_END_SEARCH_PROP = "event_end_search_prop";
cc.exports.EVENT_USE_BIG_EYES_PROP = "event_use_big_eyes_prop";
cc.exports.EVENT_TOUCH_BIG_EYES_PROP = "event_touch_big_eyes_prop";
cc.exports.EVENT_TOUCH_ADD_TIME_PROP = "event_touch_add_time_prop";
cc.exports.EVENT_USE_ADD_TIME_PROP = "event_use_add_time_prop";
cc.exports.EVENT_PUZZLE_TOUCH = "event_puzzle_touch";
cc.exports.EVENT_ADJUST_PUZZLE_PIECES_SCALE = "event_adjust_puzzle_pieces_scale";
cc.exports.EVENT_POP_PUZZLE_STORE_ALERT = "event_pop_game_store";
cc.exports.EVENT_DECALS_LOTTERY_SELECT_CARD = "event_decals_lottery_select_card";
cc.exports.EVENT_DECALS_LOTTERY_AGAIN = "event_decals_lottery_again";
cc.exports.EVENT_DECALS_LOTTERY_AGAIN_BEGIN = "event_decals_lottery_again_begin";
-- cc.exports.EVENT_DECALS_LOTTERY_BEGIN = "event_decals_lottery_begin";
cc.exports.EVENT_DECALS_LOTTERY_REMOVE_CARD = "event_decals_lottery_remove_card";
cc.exports.EVENT_DECALS_LOTTERY_CHANGE_AWARD_CARD_BEGIN = "event_decals_lottery_change_award_card_begin";
cc.exports.EVENT_DECALS_LOTTERY_CHANGE_AWARD_CARD_END = "event_decals_lottery_change_award_card_end";
cc.exports.POP_CHARACTOR_UNLOCK_ALERT = "pop_charactor_unlock_alert";
cc.exports.POP_TREASURE_UNLOCK_ALERT = "pop_treasure_unlock_alert";
cc.exports.EVENT_DECALS_LOTTERY_END = "event_decals_lottery_end"; -- 贴纸抽奖结束
-- cc.exports.EVENT_ANSWER_ZOOM_IN_ACTION = "event_answer_zoom_in_action";

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
cc.exports.PUZZLE_STENCIL_WIDTH = 120;
cc.exports.PUZZLE_STENCIL_HEIGHT = PUZZLE_STENCIL_WIDTH;
cc.exports.PUZZLE_STENCIL_LENGTH = 588;
cc.exports.PUZZLE_COMPONENT_ANCHOR = {x = 0, y = 0.5};
cc.exports.PUZZLE_EDGES_ANCHOR = {x = 5/189, y = 0.5};
cc.exports.PUZZLE_PIECE_SHADOW_ANCHOR = {x = 0.5, y = 1};
cc.exports.PUZZLE_PIECE_SHADOW_OFFSET_POSITION = {x = 20, y = -20};
cc.exports.PUZZLE_PIECE_SCALE = PUZZLE_STENCIL_WIDTH / PUZZLE_STENCIL_LENGTH;
cc.exports.PUZZLE_PIECE_RAISED_WIDTH = 184 * PUZZLE_PIECE_SCALE
cc.exports.PROP_SMALL_EYES_TIME = 2;

cc.exports.PUZZLE_ALERT_THUMBNAIL_SCALE = 0.56

cc.exports.PUZZLE_STENCIL_COMPONENT_INSIDE = "component_inside";
cc.exports.PUZZLE_STENCIL_COMPONENT_OUTSIDE = "component_outside";
cc.exports.PUZZLE_STENCIL_COMPONENT_PLAIN = "component_plain";
cc.exports.PUZZLE_PIECES_COLLECTION_INDEX_START = 1;
cc.exports.PUZZLE_PLAY_SCENE_ZOOM_SCALE_MIN = 0.3;
cc.exports.PUZZLE_PLAY_SCENE_ZOOM_SCALE_MAX = 1.7;
cc.exports.PUZZLE_INITIAL_SIZE = cc.size(976, 1464);
cc.exports.PUZZLE_SHOW_LAYER_COLOR_C4B = cc.c4b(70, 48, 61, 255);
cc.exports.PUZZLE_PROPS_NUMBLE_LABEL_POSITION = cc.p(35, -35);

cc.exports.DECALS_LOTTERY_CARD_FLIPX_DURATION = 0.75;
cc.exports.CARDS_MOVETO_CENTER_DURATION = 0.3;


cc.exports.DECALS_TYPE_CHARACTOR = bs.UserDataManager:getDecalsCharactorKey();
cc.exports.DECALS_TYPE_TREASEURE = bs.UserDataManager:getDecalsTreasureKey();

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
cc.exports.TREASURE_MAP_PAGEVIEW_NAME = "treasure_map_pageview";
cc.exports.LANDSCAPE_PAGEVIEW_NAME = "landscape_pageview";
cc.exports.PAGEVIEW_INITAIL_DATA = {
	[TREASURE_MAP_PAGEVIEW_NAME] = {
		PAGE_PATH = {"puzzle_treasure_map (1).jpg", "puzzle_treasure_map (2).jpg", "puzzle_treasure_map (3).jpg", "puzzle_treasure_map (4).jpg",
		"puzzle_treasure_map (5).jpg","puzzle_treasure_map (6).jpg", "puzzle_treasure_map (7).jpg", "puzzle_treasure_map (8).jpg",
		"puzzle_treasure_map (9).jpg","puzzle_treasure_map (10).jpg", "puzzle_treasure_map (11).jpg", "puzzle_treasure_map (12).jpg"},
		VISIBLE = false;
	},
	[LANDSCAPE_PAGEVIEW_NAME] = {
		PAGE_PATH = {"puzzle_landscape (1).jpg", "puzzle_landscape (2).jpg", "puzzle_landscape (3).jpg","puzzle_landscape (4).jpg",
		 "puzzle_landscape (5).jpg", "puzzle_landscape (6).jpg","puzzle_landscape (7).jpg", "puzzle_landscape (8).jpg", "puzzle_landscape (9).jpg",
		 "puzzle_landscape (10).jpg", "puzzle_landscape (11).jpg", "puzzle_landscape (12).jpg"},
		VISIBLE = true;
	},
}
-- cc.exports.DECALS_BACKGROUND_DATA = {
-- 	CHARACTOR_DECALS = {{path = "decals (1).png", x = 1, y = 3},{path = "decals (1).png",x = 2, y = 3},{path = "decals (1).png",x = 2, y = 3}}
-- };