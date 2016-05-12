--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图选择界面

local PuzzleSelectedScene = class("PuzzleSelectedScene", function ()
    return cc.Layer:create();
end)
local PuzzleSelectedShow = require(PUZZLE_SELECTED_SHOW_PATH);
local PUZZLE_SELECTED_SCENE_CSB_PATH = "PuzzleSelectionLayer.csb";
local PUZZLE_SHOW_NODE_NAME = "Node_1";
local BACK_BUTTON_NAME = "backButton";
local PAGEVIEW_POSITION_NODE_NAME = "pagePos";
local COLOR_LAYER_WIDTH = 470;
local COLOR_LAYER_HEIGHT = 700;

function PuzzleSelectedScene:ctor()
    --printf("PuzzleSelectedScene");
    self:init();
end

function PuzzleSelectedScene:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzleSelectedScene:create()
    scene:addChild(layer)
    return scene
end

function PuzzleSelectedScene:init()
    self.csb_node_ = cc.CSLoader:createNode(PUZZLE_SELECTED_SCENE_CSB_PATH);
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_);
    local size = cc.Director:getInstance():getVisibleSize();
    self.csb_node_:getChildByName(PUZZLE_SHOW_NODE_NAME):setPosition(cc.p(size.width/2, size.height*0.55));
    self.csb_node_:getChildByName(PUZZLE_SHOW_NODE_NAME):setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    self:addChild(self.csb_node_);
    local colorLayer = cc.LayerColor:create(PUZZLE_SHOW_LAYER_COLOR_C4B, COLOR_LAYER_WIDTH, COLOR_LAYER_HEIGHT);
    --colorLayer:setScale(bs.SmartScaleController:getInstance():getFixedHeightZoom());
    colorLayer:setPosition(cc.p(colorLayer:getContentSize().width/-2, colorLayer:getContentSize().height/-2));
    self.csb_node_:getChildByName(PUZZLE_SHOW_NODE_NAME):addChild(colorLayer, -1);

    self:initBackButton();
    self:addPageView();
    self:addStartButton();
end

function PuzzleSelectedScene:addPageView()
    local puzzle_show = PuzzleSelectedShow:create();
    puzzle_show:setScale(0.4126);
    self.csb_node_:getChildByName(PUZZLE_SHOW_NODE_NAME):getChildByName(PAGEVIEW_POSITION_NODE_NAME):addChild(puzzle_show);
end
function PuzzleSelectedScene:initBackButton()
    local size = cc.Director:getInstance():getVisibleSize();
    local button = self.csb_node_:getChildByName(BACK_BUTTON_NAME);
    button:setPosition(cc.p(size.width*0.09, size.height*0.93));
    button:addClickEventListener(function ( ... )
        cc.Director:getInstance():replaceScene(bs.GameStageSelectionScene:createScene());
    end);
end
function PuzzleSelectedScene:addStartButton()
    local button = bs.GameStartButton:createButtonStartForm();
    local size = cc.Director:getInstance():getVisibleSize();
    button:setPosition(cc.p(size.width*0.5, size.height*0.1));
    self.csb_node_:addChild(button);
    button:getStartButton():addClickEventListener(function ( ... )
        cc.Director:getInstance():replaceScene(require(PUZZLE_PLAY_SCENE_PATH):createScene());
    end);
end
return PuzzleSelectedScene