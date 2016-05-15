--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 

local PuzzlePlayScene = class("PuzzlePlayScene", function ()
    return cc.Layer:create();
end)
local PuzzlePlayArea = require(PUZZLE_PLAY_AREA_PATH);
local PuzzlePiecesScrollView = require(PUZZLE_PIECES_SCROLLVIEW_PATH);
local PuzzleGamePauseAlert = require(PUZZLE_GAME_PAUSE_ALERT_PATH);
local PuzzleSelectedScene = require(PUZZLE_SELECTED_SCENE_PATH);
local PuzzleDefeatCountdownComponent = require(PUZZLE_DEFEAT_COUNTDOWN_COMPONENT_PATH);
local PuzzleGameDefeatAlert = require(PUZZLE_GAME_DEFEAT_ALERT_PATH);

local PUZZLE_PLAY_SCENE_CSB_PATH = "PuzzlePlayLayer.csb";
local CSB_DESK_NAME = "pintutaizi_2";
local PAUSE_BUTTON_NAME = "Button_1";
local BACKGROUND_NAME = "pintubeijing02_1";
local THUMBNAIL_POS_NODE_NAME = "thumbnail_pos";
local PUZZLE_PIECES_SCROLLVIEW_ZORDER = 1;
local PUZZLE_PLAY_AREA_ZORDER = -1;
local BACKGROUND_ZORDER = PUZZLE_PLAY_AREA_ZORDER-1;
function PuzzlePlayScene:ctor()
    --printf("PuzzlePlayScene");
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
    	end
    	self:registerScriptHandler(onNodeEvent);
    end
    self:registerScriptHandler(onNodeEvent);
    self:init();
end

function PuzzlePlayScene:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzlePlayScene:create()
    scene:addChild(layer)
    return scene
end
function PuzzlePlayScene:init()
	self:loadCsb();
	self:initPauseButton();
	self:initZOrder();
	self.countdown_ = PuzzleDefeatCountdownComponent:create();
	self:addChild(self.countdown_);
end
function PuzzlePlayScene:loadCsb()
    self.csb_node_ = cc.CSLoader:createNode(PUZZLE_PLAY_SCENE_CSB_PATH);
    self:addChild(self.csb_node_);
    self.csb_node_:getChildByName(CSB_DESK_NAME):setScaleY(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function PuzzlePlayScene:initPauseButton()
	local size = cc.Director:getInstance():getVisibleSize();
	local button = self.csb_node_:getChildByName(PAUSE_BUTTON_NAME);
	button:setPosition(cc.p(size.width*0.92, size.height*0.95));
	bs.ButtonEffectController:setButtonZoomScale(button);
	button:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
	button:addClickEventListener(function (...)
		self:popPauseAlert();
    end);
end
function PuzzlePlayScene:initZOrder()
	self.csb_node_:getChildByName(BACKGROUND_NAME):setLocalZOrder(BACKGROUND_ZORDER);
end
function PuzzlePlayScene:addPuzzlePlayArea()
	self.puzzle_area_ = PuzzlePlayArea:create();
    self.csb_node_:addChild(self.puzzle_area_, PUZZLE_PLAY_AREA_ZORDER);
    self.puzzle_area_:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    local size = cc.Director:getInstance():getVisibleSize();
    self.puzzle_area_:setPosition(cc.p(size.width/2, size.height*0.6));
end
function PuzzlePlayScene:addPuzzleScrollView( puzzleTable )
	self.csb_node_:addChild(PuzzlePiecesScrollView:create(puzzleTable), PUZZLE_PIECES_SCROLLVIEW_ZORDER);
end
function PuzzlePlayScene:onEnter()
	self.listener_ = {};
	local function addPuzzleAnswer( event )
		self:addPuzzleScrollView(event._usedata);
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_ANSWER_LOAD, addPuzzleAnswer));

	local function gameContinue( event )
		cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUSH_ANSWERS_THUMBNAIL);
    	self.alert_:removeFromParent();
    	self.alert_ = nil;
    	self.screen_sp_:removeFromParent();
    	self.countdown_:resume();
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_CONTINUE, gameContinue));

	local function gameReturn( event )
        cc.Director:getInstance():replaceScene(PuzzleSelectedScene:createScene());
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_RETURN, gameReturn));

	local function gameRePlay( event )
        cc.Director:getInstance():replaceScene(self:createScene());
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_REPLAY, gameRePlay));

	local function gameDefeat( event )
        self:popDefeatAlert();
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_GAME_DEFEAT, gameDefeat));

    local function gameVictory( event )
        self:popDefeatAlert();
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_GAME_VICTORY, gameVictory));

    for _, listener in ipairs(self.listener_) do
    	self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
	self:addPuzzlePlayArea();
end
function PuzzlePlayScene:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
    	eventDispatcher:removeEventListener(listener);
    end
end
function PuzzlePlayScene:popPauseAlert()
	self.countdown_:pause();
	self:popAlert(PuzzleGamePauseAlert);
end
function PuzzlePlayScene:popDefeatAlert()
	self:popAlert(PuzzleGameDefeatAlert);
end
function PuzzlePlayScene:popAlert( alert_class )
    cc.utils:captureScreen(function ( succeed, outputFile )
    	if succeed then
    		self.screen_sp_ = cc.Sprite:create(outputFile);
			self.screen_sp_:setPosition(GlobalFunction.getVisibleCenterPosition());
			self.screen_sp_:setScale(cc.Director:getInstance():getOpenGLView():getDesignResolutionSize().width / self.screen_sp_:getContentSize().width);
			self:addChild(self.screen_sp_);

			self.alert_ = alert_class:create();

			local thumbnail = self.puzzle_area_:getThumbnail();
			thumbnail:setScale(0.55);
			thumbnail:setPosition(cc.p(self.alert_:getCsbNode():getChildByName(THUMBNAIL_POS_NODE_NAME):getPosition()));
			self.alert_:addChild(thumbnail);
			self.alert_:setPosition(GlobalFunction.getVisibleCenterPosition());
		    self:addChild(self.alert_);
	    end
    end, "ScreenShot.png");
end
return PuzzlePlayScene