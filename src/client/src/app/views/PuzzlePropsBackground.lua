--
-- Author: 黄泽昊
-- 功能: 道具背景组件

local PuzzlePropsBackground = class("PuzzlePropsBackground", function ( event_name)
    return cc.Node:create();
end)
local BACKGROUND_PATH = "daojudi.PNG";
function PuzzlePropsBackground:ctor(event_name)
    self:init(event_name);
end
function PuzzlePropsBackground:init(event_name)
    self.event_name_ = event_name;
    local menuItem = cc.MenuItemSprite:create(GlobalFunction.createGameSpriteWithPath(BACKGROUND_PATH), 
        GlobalFunction.createGameSpriteWithPath(BACKGROUND_PATH));
    menuItem:setPosition(cc.p(0, 0));
    menuItem:registerScriptTapHandler(function ( sender )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(self.event_name_);
    end)
    local menu = cc.Menu:create();
    menu:setPosition(cc.p(0, 0));
    menu:addChild(menuItem);
    self:addChild(menu);
end
return PuzzlePropsBackground