--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图游戏的暂停面板

local PuzzleGamePauseAlert = class("PuzzleGamePauseAlert", function ()
    return cc.Node:create();
end)
local PUZZLE_GAME_PAUSE_ALERT_CSB_PATH = "PuzzlePauseAlert.csb";
local CONTINUE_BUTTON_NODE_NAME = "Node_1";
function PuzzleGamePauseAlert:ctor()
    self:init();
end
function PuzzleGamePauseAlert:init()
    self:loadCSB();
    self:addMaskBackground();
end
function PuzzleGamePauseAlert:loadCSB()
    self.csb_node_ = cc.CSLoader:createNode(PUZZLE_GAME_PAUSE_ALERT_CSB_PATH);
    self:addChild(self.csb_node_);
    self.continue_button_ = bs.GameStartButton:createButtonContinueForm();
    self.csb_node_:getChildByName(CONTINUE_BUTTON_NODE_NAME):addChild(self.continue_button_);
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_);
end
function PuzzleGamePauseAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), -1);
end
function PuzzleGamePauseAlert:setContinueButtonCallback(callback)
    self.continue_button_:getStartButton():addClickEventListener(callback);
end
return PuzzleGamePauseAlert