--
-- Author: 黄泽昊
-- 作用: 书页上的内容, 左右方向按钮啊之类的

local DecalsExhibitionNode = class("DecalsExhibitionNode", function ()
    return cc.Node:create();
end)
local DECALS_EXHIBITION_ALERT_CSB_PATH = "DecalsExhibitionNode.csb";
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
    csb_node:addChild(DecalsExhibitionPageView:create());
end
return DecalsExhibitionNode