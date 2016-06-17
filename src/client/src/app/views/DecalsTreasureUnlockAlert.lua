--
-- Author: 黄泽昊
-- 作用: 宝物贴纸解锁面板

local DecalsTreasureUnlockAlert = class("DecalsTreasureUnlockAlert", function ()
    return cc.Node:create();
end)
local DECALS_CHARACTOR_UNLOCK_ALERT_CSB_PATH = "DecalsTreasureUnlockAlert.csb";
local DecalsLotteryScene = require(DECALS_LOTTERY_SCENE_PATH);
function DecalsTreasureUnlockAlert:ctor()
    self:init();
end
function DecalsTreasureUnlockAlert:init()
    self:loadCSB();
    self:addMaskBackground();
end

function DecalsTreasureUnlockAlert:loadCSB()
    local csb_node = cc.CSLoader:createNode(DECALS_CHARACTOR_UNLOCK_ALERT_CSB_PATH);
    self:addChild(csb_node);
    bs.ButtonEffectController:setButtonsZoomScale(csb_node);

    csb_node:getChildByName("closeButton"):addClickEventListener(function ( ... )
        self:removeFromParent();
    end);
    csb_node:getChildByName("Button_8"):addClickEventListener(function ( ... )
        cc.Director:getInstance():replaceScene(require(PUZZLE_SELECTED_SCENE_PATH):createScene());
    end);
    csb_node:getChildByName("Button_8_0"):addClickEventListener(function ( ... )
        cc.Director:getInstance():pushScene(DecalsLotteryScene:createScene(DECALS_TYPE_TREASEURE));
    end);
end
function DecalsTreasureUnlockAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), -1);
end

return DecalsTreasureUnlockAlert