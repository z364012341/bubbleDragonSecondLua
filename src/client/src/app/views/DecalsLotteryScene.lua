--
-- Author: 黄泽昊
-- 作用: 贴纸的抽奖场景

local DecalsLotteryScene = class("DecalsLotteryScene", function ()
    return cc.Layer:create();
end)
local DECALS_LATTERY_SCENE_CSB_PATH = "DecalsLotteryLayer.csb";
function DecalsLotteryScene:createScene()
    local scene = cc.Scene:create()
    local layer = DecalsLotteryScene:create()
    scene:addChild(layer)
    return scene
end
function DecalsLotteryScene:ctor()
    self:init();
end
function DecalsLotteryScene:init()
    self:loadCSB();
    --self:setScaleX(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function DecalsLotteryScene:loadCSB()
    local csb_node = cc.CSLoader:createNode(DECALS_LATTERY_SCENE_CSB_PATH);
    assert(csb_node);
    bs.ButtonEffectController:setButtonsZoomScale(csb_node);
    self:addChild(csb_node);

    local return_button = csb_node:getChildByName("Button_1");
    -- return_button:setPosition(cc.p(cc.Director:getInstance():getVisibleSize().width*0.11, cc.Director:getInstance():getVisibleSize().height*0.06));
    return_button:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom() * return_button:getScale());
    return_button:addClickEventListener(function ( ... )
        cc.Director:getInstance():popScene();
    end);

    local cards_bg = csb_node:getChildByName("Image_1");
    cards_bg:setPositionY(cc.Director:getInstance():getVisibleSize().height*0.3);
    local bg_height = cards_bg:getContentSize().height*bs.SmartScaleController:getInstance():getPlayAreaZoom();
    cards_bg:setContentSize(cc.size(cards_bg:getContentSize().width, bg_height));

    cards_bg:getChildByName("lottery_top_4"):setPositionY(bg_height);
end

return DecalsLotteryScene