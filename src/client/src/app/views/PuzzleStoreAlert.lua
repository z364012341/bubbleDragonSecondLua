--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图游戏的暂停面板

local PuzzleStoreAlert = class("PuzzleStoreAlert", function ()
    return cc.Node:create();
end)
local STORE_CSB_PATH = "PuzzleStoreAlert.csb";
local CLOSE_BUTTON_NAME = "Button_1";
local LISTVIEW_NAME = "ListView_1";
function PuzzleStoreAlert:ctor()
    self:init();
end
function PuzzleStoreAlert:init()
    self:loadCSB();
    self:initListView();
    self:addMaskBackground();
end

function PuzzleStoreAlert:loadCSB()
    self.csb_node_ = cc.CSLoader:createNode(STORE_CSB_PATH);
    self:addChild(self.csb_node_);
    self.csb_node_:getChildByName(CLOSE_BUTTON_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_CONTINUE);
    end);

end
function PuzzleStoreAlert:initListView()
    -- body
end
function PuzzleStoreAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), MASK_ZORDER);
end

return PuzzleStoreAlert