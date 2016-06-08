--
-- Author: 黄泽昊
-- 作用: 书页上的内容, 左右方向按钮啊之类的

local DecalsExhibitionNode = class("DecalsExhibitionNode", function ()
    return cc.Node:create();
end)
local DECALS_EXHIBITION_ALERT_CSB_PATH = "DecalsExhibitionNode.csb";
local LEFT_BUTTON_NAME = "Button_6";
local RIGHT_BUTTON_NAME = "Button_7";
local DecalsExhibitionPageView = require(DECALS_EXHIBITION_PAGEVIEW_PATH);
function DecalsExhibitionNode:ctor()
    self:init();
end
function DecalsExhibitionNode:init()
    self:loadCSB();
    self:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function DecalsExhibitionNode:loadCSB()
    local csb_node = cc.CSLoader:createNode(DECALS_EXHIBITION_ALERT_CSB_PATH);
    assert(csb_node);
    bs.ButtonEffectController:setButtonsZoomScale(csb_node);
    self:addChild(csb_node);
    local exhibition_pageview = DecalsExhibitionPageView:create();
    csb_node:addChild(exhibition_pageview);
    csb_node:getChildByName(LEFT_BUTTON_NAME):addClickEventListener(function ( ... )
        exhibition_pageview:scrollLeft();
    end);
    csb_node:getChildByName(RIGHT_BUTTON_NAME):addClickEventListener(function ( ... )
        exhibition_pageview:scrollRight();
    end);
end

return DecalsExhibitionNode