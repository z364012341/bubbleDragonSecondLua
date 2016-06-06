--
-- Author: 黄泽昊
-- 作用: 选择pageview

local DecalsExhibitionAlert = class("DecalsExhibitionAlert", function ()
    return cc.Node:create();
end)
local DECALS_EXHIBITION_ALERT_CSB_PATH = "DecalsBookLayer.csb";
--local DECALS_EXHIBITION_NODE_NAME = "FileNode_1";
local DECALS_BOOK_BACKGROUND_NODE_NAME = "FileNode_2";
local DECALS_BOOK_CHARACTOR_BACKGROUND_NAME = "book_bg_1";
local DecalsExhibitionNode = require(DECALS_EXHIBITION_NODE_PATH);
function DecalsExhibitionAlert:ctor()
    self:init();
end
function DecalsExhibitionAlert:init()
    self:addChild(bs.GameAlertMask:create(), -1);
    self:loadCSB();
    self:addCharactorExhibition();
end
function DecalsExhibitionAlert:loadCSB()
    local csb_node = cc.CSLoader:createNode(DECALS_EXHIBITION_ALERT_CSB_PATH);
    assert(csb_node);
    bs.ButtonEffectController:setButtonsZoomScale(csb_node);
    self:addChild(csb_node);
    --csb_node:getChildByName(DECALS_EXHIBITION_NODE_NAME):setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    csb_node:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName("charactor_lab"):setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    local treasure_button = csb_node:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName("treasure_lag");
    treasure_button:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom() * treasure_button:getScaleX());
    local return_button = csb_node:getChildByName("return_button");
    return_button:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom() * return_button:getScaleX());
    return_button:addClickEventListener(function ( ... )
        self:removeFromParent();
    end);
    csb_node:getChildByName("lottery_button"):setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    self.csb_node_ = csb_node;

end
function DecalsExhibitionAlert:addCharactorExhibition()
    local charactor_bg = self.csb_node_:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName(DECALS_BOOK_CHARACTOR_BACKGROUND_NAME)
    local node = DecalsExhibitionNode:create();
    node:setPosition(cc.p(charactor_bg:getContentSize().width/2, charactor_bg:getContentSize().height/2));
    charactor_bg:addChild(node);
end
return DecalsExhibitionAlert