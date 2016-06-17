--
-- Author: 黄泽昊
-- 作用: 选择pageview

local DecalsExhibitionAlert = class("DecalsExhibitionAlert", function ()
    return cc.Node:create();
end)
local DecalsLotteryScene = require(DECALS_LOTTERY_SCENE_PATH);
local DecalsCharactorUnlockAlert = require(DECALS_CHARACTOR_UNLOCK_ALERT_PATH);
local DecalsTreasureUnlockAlert = require(DECALS_TREASURE_UNLOCK_ALERT_PATH);
local DECALS_EXHIBITION_ALERT_CSB_PATH = "DecalsBookLayer.csb";
--local DECALS_EXHIBITION_NODE_NAME = "FileNode_1";
local DECALS_BOOK_BACKGROUND_NODE_NAME = "FileNode_2";
local DECALS_BOOK_CHARACTOR_BACKGROUND_NAME = "book_bg_1";
local DECALS_BOOK_TREASURE_BACKGROUND_NAME = "book_bg_1_0";
local LAB_BUTTON_UNSELECTED_SCALE = 0.8;
local DecalsExhibitionNode = require(DECALS_EXHIBITION_NODE_PATH);
function DecalsExhibitionAlert:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self.decals_type_ = DECALS_TYPE_CHARACTOR;
    self:init();
end
function DecalsExhibitionAlert:init()
    self:addChild(bs.GameAlertMask:create(), -1);
    self:loadCSB();
end
function DecalsExhibitionAlert:loadCSB()
    local csb_node = cc.CSLoader:createNode(DECALS_EXHIBITION_ALERT_CSB_PATH);
    assert(csb_node);
    self.csb_node_ = csb_node;
    self:addCharactorExhibition();
    self:addTreasureExhibition();

    bs.ButtonEffectController:setButtonsZoomScale(csb_node);
    self:addChild(csb_node);
    --csb_node:getChildByName(DECALS_EXHIBITION_NODE_NAME):setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    csb_node:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):setScaleY(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    csb_node:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):setPositionY(cc.Director:getInstance():getVisibleSize().height*0.13);
    local charactor_button = csb_node:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName("charactor_lab");
    local treasure_button = csb_node:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName("treasure_lag");
    --charactor_button:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    charactor_button:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    charactor_button:addClickEventListener(function ( ... )
        -- self.charactor_background_:setVisible(true);
        self.decals_type_ = DECALS_TYPE_CHARACTOR;
        self:setExhibitionDisplay(true);
        self:changeButtonSelectedScale(charactor_button);
        self:changeButtonUnselectedScale(treasure_button);
    end);


    treasure_button:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom() * treasure_button:getScaleX());
    self:changeButtonUnselectedScale(treasure_button);
    treasure_button:addClickEventListener(function ( ... )
        -- self.charactor_background_:setVisible(false);
        self.decals_type_ = DECALS_TYPE_TREASEURE;
        self:setExhibitionDisplay(false);
        self:changeButtonSelectedScale(treasure_button);
        self:changeButtonUnselectedScale(charactor_button);
    end);

    local return_button = csb_node:getChildByName("return_button");
    -- return_button:setPosition(cc.p(cc.Director:getInstance():getVisibleSize().width*0.11, cc.Director:getInstance():getVisibleSize().height*0.06));
    return_button:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom() * return_button:getScale());
    return_button:addClickEventListener(function ( ... )
        self:removeFromParent();
    end);

    local lottery_button = csb_node:getChildByName("lottery_button");
    lottery_button:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    lottery_button:addClickEventListener(function ( ... )
        cc.Director:getInstance():pushScene(DecalsLotteryScene:createScene(self.decals_type_));
    end);

end
function DecalsExhibitionAlert:addCharactorExhibition()
    local charactor_bg = self.csb_node_:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName(DECALS_BOOK_CHARACTOR_BACKGROUND_NAME)
    local node = DecalsExhibitionNode:create(DECALS_TYPE_CHARACTOR);
    node:setPosition(cc.p(charactor_bg:getContentSize().width/2, charactor_bg:getContentSize().height/2));
    charactor_bg:addChild(node);
    self.charactor_background_ = charactor_bg;

    self.charactor_label_ = self.csb_node_:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName("charactor_label_8");
    self.charactor_label_:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function DecalsExhibitionAlert:addTreasureExhibition()
    local treasure_bg = self.csb_node_:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName(DECALS_BOOK_TREASURE_BACKGROUND_NAME)
    local node = DecalsExhibitionNode:create(DECALS_TYPE_TREASEURE);
    node:setPosition(cc.p(treasure_bg:getContentSize().width/2, treasure_bg:getContentSize().height/2));
    treasure_bg:addChild(node);
    self.treasure_background_ = treasure_bg;

    self.treasure_label_ = self.csb_node_:getChildByName(DECALS_BOOK_BACKGROUND_NODE_NAME):getChildByName("treasure_label");
    self.treasure_label_:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function DecalsExhibitionAlert:changeButtonUnselectedScale(button)
    button:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom() * LAB_BUTTON_UNSELECTED_SCALE);
    button:setScaleY(LAB_BUTTON_UNSELECTED_SCALE);
end
function DecalsExhibitionAlert:changeButtonSelectedScale(button)
    button:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    button:setScaleY(1);
end
function DecalsExhibitionAlert:setExhibitionDisplay(charactor_flag)
    local visibleSize = cc.Director:getInstance():getVisibleSize();
    local render = cc.RenderTexture:create(visibleSize.width, visibleSize.height, cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888, 0x88F0);
    render:beginWithClear(0.0, 0.0, 0.0, 0.0);
    (charactor_flag and self.treasure_background_ or self.charactor_background_):visit();
    render:endToLua();
    local node = cc.NodeGrid:create();
    local render_sp = cc.Sprite:createWithTexture(render:getSprite():getTexture());
    render_sp:setFlippedY(true);
    node:addChild(render_sp);
    render_sp:setAnchorPoint(cc.p(0,0));
    node:runAction(cc.Sequence:create(cc.PageTurn3D:create(1, cc.size(15,10)), cc.CallFunc:create(function ()
        node:removeFromParent();
    end) , nil));
    self.charactor_background_:getParent():addChild(node);

    self.charactor_background_:setVisible(charactor_flag);
    self.charactor_label_:setVisible(charactor_flag);
    self.treasure_label_:setVisible(not  charactor_flag);
    self.treasure_background_:setVisible(not  charactor_flag);
end
function DecalsExhibitionAlert:onEnter()
    self.listener_ = {};
    table.insert(self.listener_, cc.EventListenerCustom:create(POP_CHARACTOR_UNLOCK_ALERT, function ( event )
        local alert = DecalsCharactorUnlockAlert:create();
        alert:setPosition(GlobalFunction.getVisibleCenterPosition());
        self:addChild(alert);
    end));
    table.insert(self.listener_, cc.EventListenerCustom:create(POP_TREASURE_UNLOCK_ALERT, function ( event )
        local alert = DecalsTreasureUnlockAlert:create();
        alert:setPosition(GlobalFunction.getVisibleCenterPosition());
        self:addChild(alert);
    end));
    -- local function lotteryEnd( event )
    --     self.button_node_:setVisible(false);
    -- end
    -- table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_DECALS_LOTTERY_END, lotteryEnd));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function DecalsExhibitionAlert:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return DecalsExhibitionAlert