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
    end);
    self.csb_node_ :getChildByName(RIGHT_BUTTON_NAME):addClickEventListener(function ( ... )
        self.exhibition_pageview_:scrollRight();
    end);
    self.csb_node_ :getChildByName(UNLOCK_BUTTON_NAME):addClickEventListener(function ( ... )
        if self.decals_type_ == DECALS_TYPE_CHARACTOR then
            self:getEventDispatcher():dispatchCustomEvent(POP_CHARACTOR_UNLOCK_ALERT);
        else
            self:getEventDispatcher():dispatchCustomEvent(POP_TREASURE_UNLOCK_ALERT);
        end
    end);
end
function DecalsExhibitionNode:addExhibitionPageView()
    if self.exhibition_pageview_ ~= nil then
       self.exhibition_pageview_:removeFromParent();
    end
    self.exhibition_pageview_ = DecalsExhibitionPageView:create(self.decals_type_);
    self.csb_node_ :addChild(self.exhibition_pageview_);

end

return DecalsExhibitionNode