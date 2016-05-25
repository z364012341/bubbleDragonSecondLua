--
-- Author: 黄泽昊
-- 作用: 拼图游戏的商城面板

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
    --self:initListView();
end
function PuzzleStoreAlert:initListView()
    local listView = self.csb_node_:getChildByName(LISTVIEW_NAME);
    listView:setScrollBarEnabled(false);
    --dump(bs.PuzzleStoreItemFactory:getInstance():getItemTotal());
    for i = 1,bs.PuzzleStoreItemFactory:getInstance():getItemTotal() do
        local custom_item = ccui.Layout:create()
        local layer = bs.PuzzleStoreItemFactory:getInstance():createItemWithIndex(i-1);
        --layer:setScale(0.8);
        custom_item:setContentSize(layer:getContentSize())
        custom_item:addChild(layer);
        listView:pushBackCustomItem(custom_item)
    end
end
function PuzzleStoreAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), -1);
end

return PuzzleStoreAlert