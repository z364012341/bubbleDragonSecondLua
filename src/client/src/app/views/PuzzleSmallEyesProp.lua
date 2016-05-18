--
-- Author: 黄泽昊
-- 功能: 小眼睛道具

local PuzzleSmallEyesProp = class("PuzzleSmallEyesProp", function ()
    return cc.Node:create();
end)
local PROP_TEXTURE_PATH = "anniuchakan.PNG";
local PROP_PROGRESS_TIMER_PATH = "small_eyes_gray.png";
local COOLING_SEQUENCE_TAG = 123
function PuzzleSmallEyesProp:ctor()
    self:init();
end
function PuzzleSmallEyesProp:init()
    self:addPropButton();
end
function PuzzleSmallEyesProp:addPropButton()
    local menuItem = cc.MenuItemSprite:create(GlobalFunction.createGameSpriteWithPath(PROP_TEXTURE_PATH), 
        GlobalFunction.createGameSpriteWithPath(PROP_TEXTURE_PATH));
    menuItem:setPosition(cc.p(0, 0));
    menuItem:registerScriptTapHandler(function ( sender )
        if self:getActionByTag(COOLING_SEQUENCE_TAG) ~= nil then
            return;
        end
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_USE_SMALL_EYES);
        self:propCooling();
    end)
    local menu = cc.Menu:create();
    menu:setPosition(cc.p(0, 0));
    menu:addChild(menuItem);
    self:addChild(menu);
end
function PuzzleSmallEyesProp:propCooling()

    local progressTimer = cc.ProgressTimer:create(GlobalFunction.createGameSpriteWithPath(PROP_PROGRESS_TIMER_PATH));
    progressTimer:setReverseProgress(true);
    progressTimer:setPercentage(100);
    progressTimer:setPosition(cc.p(-4, 4));
    self:addChild(progressTimer); 

    local percent_seq = cc.Sequence:create(cc.CallFunc:create(function ()
        progressTimer:setPercentage(progressTimer:getPercentage()-1);
    end), cc.DelayTime:create(PROP_SMALL_EYES_TIME*2/100), nil);
    local seq = cc.Sequence:create(cc.Repeat:create(percent_seq, 100), cc.CallFunc:create(function ()
        progressTimer:removeFromParent();
    end));
    seq:setTag(COOLING_SEQUENCE_TAG);
    self:runAction(seq); 
end
return PuzzleSmallEyesProp