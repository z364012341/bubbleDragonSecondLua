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
		--self:screenShoot();
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
	local function addPuzzleAnswer( event )
		--printf("111111111111111111");
		self:addPuzzleScrollView(event._usedata);
	end
    self._listener1 = cc.EventListenerCustom:create(EVENT_PUZZLE_ANSWER_LOAD, addPuzzleAnswer);
    self:getEventDispatcher():addEventListenerWithFixedPriority(self._listener1, 1);
	self:addPuzzlePlayArea();
end
function PuzzlePlayScene:onExit()
    local eventDispatcher = self:getEventDispatcher();
    eventDispatcher:removeEventListener(self._listener1);
end
function PuzzlePlayScene:popPauseAlert()
	-- local screen_sp = self:getScreenShot();
	-- --dump(screen_sp);
	-- screen_sp:setPosition(GlobalFunction.getVisibleCenterPosition());
	-- self:addChild(screen_sp);

	-- local alert = PuzzleGamePauseAlert:create();
	-- alert:setContinueButtonCallback(function (...)
 --    	alert:removeFromParent();
	-- end);

	-- --local callfunc = cc.CallFunc:create(function ()
	-- 	local thumbnail = self.puzzle_area_:getThumbnail();
	-- 	thumbnail:setScale(0.65);
	-- 	thumbnail:setPositionY(40);
	-- 	alert:addChild(thumbnail, -1);
	-- 	alert:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
	-- 	alert:setPosition(GlobalFunction.getVisibleCenterPosition());
	--     self:addChild(alert);
	-- --end);
	-- --self:runAction(cc.Sequence:create(cc.DelayTime:create(0.01), callfunc, nil));
    cc.utils:captureScreen(function ( succeed, outputFile )
    	if succeed then
    		local screen_sp = cc.Sprite:create(outputFile);
			screen_sp:setPosition(GlobalFunction.getVisibleCenterPosition());
			screen_sp:setScale(cc.Director:getInstance():getOpenGLView():getDesignResolutionSize().width / screen_sp:getContentSize().width);
			self:addChild(screen_sp);

			local alert = PuzzleGamePauseAlert:create();
			alert:setContinueButtonCallback(function (...)
				cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUSH_ANSWERS_THUMBNAIL);
		    	alert:removeFromParent();
		    	screen_sp:removeFromParent();
			end);
			alert:setReturnButtonCallback(function (...)
        		cc.Director:getInstance():replaceScene(PuzzleSelectedScene:createScene());
			end);
			alert:setReplayButtonCallback(function (...)
        		cc.Director:getInstance():replaceScene(self:createScene());
			end);
			local thumbnail = self.puzzle_area_:getThumbnail();
			thumbnail:setScale(0.55);
			thumbnail:setPosition(cc.p(alert:getCsbNode():getChildByName(THUMBNAIL_POS_NODE_NAME):getPosition()));
			alert:addChild(thumbnail);
			--alert:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
			alert:setPosition(GlobalFunction.getVisibleCenterPosition());
		    self:addChild(alert);
	    end
    end, "ScreenShot.png");
end
-- function PuzzlePlayScene:getScreenShot()
--     local size = cc.Director:getInstance():getVisibleSize();
--     local puzzleRender = cc.RenderTexture:create(size.width, size.height, cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888, 0x88F0);
--     puzzleRender:beginWithClear(0.0, 0.0, 0.0, 0.0); 
--     self.csb_node_:visit(); 
--     puzzleRender:endToLua();
--     local render_sp = cc.Sprite:createWithTexture(puzzleRender:getSprite():getTexture());
--     render_sp:setFlippedY(true);
--     --render_sp:setScale(1/bs.SmartScaleController:getInstance():getPlayAreaZoom());
--     --self:addChild(render_sp, SCREEN_SHOT_ZORDER);
--     --cc.utils:captureScreen(function (succeed, outputFile)
--     	-- body
--     --end, "screenShoot.png")
--     --puzzleRender:saveToFile("ScreenShot.png")

--     return render_sp;
-- end
-- function PuzzlePlayScene:screenShoot()
--     cc.utils:captureScreen(function ( succeed, outputFile )
--     	if succeed then
--     		local screen_sp = cc.Sprite:create(outputFile);
-- 			screen_sp:setPosition(GlobalFunction.getVisibleCenterPosition());
-- 			self:addChild(screen_sp);

-- 			local alert = PuzzleGamePauseAlert:create();
-- 			alert:setContinueButtonCallback(function (...)
-- 		    	alert:removeFromParent();
-- 			end);

-- 			local thumbnail = self.puzzle_area_:getThumbnail();
-- 				thumbnail:setScale(0.65);
-- 				thumbnail:setPositionY(40);
-- 				alert:addChild(thumbnail, -1);
-- 				alert:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
-- 				alert:setPosition(GlobalFunction.getVisibleCenterPosition());
-- 			    self:addChild(alert);
-- 	    	end
--     end, "ScreenShot.png");
-- end
return PuzzlePlayScene