--
-- Author: 黄泽昊
-- 作用: 书页上的内容, 左右方向按钮啊之类的

local DecalsExhibitionNode = class("DecalsExhibitionNode", function (decals_type)
    return cc.Node:create();
end)
local DECALS_EXHIBITION_ALERT_CSB_PATH = "DecalsExhibitionNode.csb";
local LEFT_BUTTON_NAME = "Button_6";
local RIGHT_BUTTON_NAME = "Button_7";
local UNLOCK_BUTTON_NAME = "Button_10";
local USED_BUTTON_NAME = "Button_11";
local DecalsExhibitionPageView = require(DECALS_EXHIBITION_PAGEVIEW_PATH);
function DecalsExhibitionNode:ctor(decals_type)
    local function onNodeEvent(event)
        if event == "enter" then
            self:addExhibitionPageView();
        -- elseif event == "exit" then
        --     self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self.decals_type_ = decals_type;
    self:init();
end
function DecalsExhibitionNode:init()
    self:loadCSB();
    self:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function DecalsExhibitionNode:loadCSB()
    self.csb_node_ = cc.CSLoader:createNode(DECALS_EXHIBITION_ALERT_CSB_PATH);
    assert(self.csb_node_ );
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_ );
    self:addChild(self.csb_node_ );
    --self:addExhibitionPageView();
    self.csb_node_ :getChildByName(LEFT_BUTTON_NAME):addClickEventListener(function ( ... )
        self.exhibition_pageview_:scrollLeft();
        self:updataButton();        
    end);
    self.csb_node_ :getChildByName(RIGHT_BUTTON_NAME):addClickEventListener(function ( ... )
        self.exhibition_pageview_:scrollRight();
        self:updataButton();
    end);
    self.unlock_button_ = self.csb_node_ :getChildByName(UNLOCK_BUTTON_NAME);
    self.unlock_button_:addClickEventListener(function ( ... )
        if self.decals_type_ == DECALS_TYPE_CHARACTOR then
            self:getEventDispatcher():dispatchCustomEvent(POP_CHARACTOR_UNLOCK_ALERT);
        else
            self:getEventDispatcher():dispatchCustomEvent(POP_TREASURE_UNLOCK_ALERT);
        end
    end);

    self.used_button_ = self.csb_node_ :getChildByName(USED_BUTTON_NAME);
    self.used_button_:addClickEventListener(function ( ... )
        bs.UserDataManager:getInstance():setLastGameCharactorIndex(self.exhibition_pageview_:getCurrentPageIndex()+1);
        self:updataButton();
    end);
end
function DecalsExhibitionNode:addExhibitionPageView()
    if self.exhibition_pageview_ ~= nil then
       self.exhibition_pageview_:removeFromParent();
    end
    self.exhibition_pageview_ = DecalsExhibitionPageView:create(self.decals_type_);
    self.csb_node_ :addChild(self.exhibition_pageview_);
    self:updataButton();
end
function DecalsExhibitionNode:updataButton()
--pageview的0索引是第2个角色
    if self.decals_type_ == DECALS_TYPE_CHARACTOR then
        local pageview_cur_index = self.exhibition_pageview_:getCurrentPageIndex();
        if pageview_cur_index < bs.UserDataManager:getInstance():getGameCharactorUnlockNumble()-1 then
            self:usedStage();
        else
            self:unlockStage();
        end
        if pageview_cur_index == bs.UserDataManager:getInstance():getLastGameCharactorIndex()-1 then
            self:usingStage();
        end
    end
end
function DecalsExhibitionNode:unlockStage()
    self.unlock_button_:setVisible(true);
    self.used_button_:setVisible(false);
end
function DecalsExhibitionNode:usingStage()
--使用中状态
    self.unlock_button_:setVisible(false);
    self.used_button_:setVisible(true);
    self.used_button_:setEnabled(false);
end
function DecalsExhibitionNode:usedStage()
--使用状态
    self.unlock_button_:setVisible(false);
    self.used_button_:setVisible(true);
    self.used_button_:setEnabled(true);
end
return DecalsExhibitionNode