--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图游戏的暂停面板

local PuzzleGameDefeatAlert = class("PuzzleGameDefeatAlert", function ()
    return cc.Node:create();
end)
local PUZZLE_DEFEAT_ALERT_CSB_PATH = "PuzzleDefeatAlert.csb";
local RETURN_BUTTON_NODE_NAME = "returnButton";
local REPLAY_BUTTON_NODE_NAME = "replayButton";
local MASK_ZORDER = -1;
local SCREEN_SHOT_ZORDER = MASK_ZORDER-1;
function PuzzleGameDefeatAlert:ctor()
    self:init();
end
function PuzzleGameDefeatAlert:init()
    self:loadCSB();
    self:addMaskBackground();
end
function PuzzleGameDefeatAlert:loadCSB()
    self.csb_node_ = cc.CSLoader:createNode(PUZZLE_DEFEAT_ALERT_CSB_PATH);
    self:addChild(self.csb_node_);
    self.csb_node_:getChildByName(RETURN_BUTTON_NODE_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_RETURN);
    end);
    self.csb_node_:getChildByName(REPLAY_BUTTON_NODE_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_REPLAY);
    end);
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_);
end
function PuzzleGameDefeatAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), MASK_ZORDER);
end

function PuzzleGameDefeatAlert:getCsbNode()
    return self.csb_node_;
end
return PuzzleGameDefeatAlert