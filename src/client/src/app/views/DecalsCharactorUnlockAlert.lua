--
-- Author: 黄泽昊
-- 作用: 人物贴纸解锁面板

local DecalsCharactorUnlockAlert = class("DecalsCharactorUnlockAlert", function ()
    return cc.Node:create();
end)
local DECALS_CHARACTOR_UNLOCK_ALERT_CSB_PATH = "DecalsCharactorUnlockAlert.csb";
local DecalsLotteryScene = require(DECALS_LOTTERY_SCENE_PATH);
function DecalsCharactorUnlockAlert:ctor()
    self:init();
end
function DecalsCharactorUnlockAlert:init()
    self:loadCSB();
    self:addMaskBackground();
end

function DecalsCharactorUnlockAlert:loadCSB()
    local csb_node = cc.CSLoader:createNode(DECALS_CHARACTOR_UNLOCK_ALERT_CSB_PATH);
    self:addChild(csb_node);
    bs.ButtonEffectController:setButtonsZoomScale(csb_node);

    csb_node:getChildByName("closeButton"):addClickEventListener(function ( ... )
        self:removeFromParent();
    end);
    csb_node:getChildByName("Button_8"):addClickEventListener(function ( ... )
        cc.Director:getInstance():replaceScene(bs.GameStageSelectionScene:createScene());
    end);
    csb_node:getChildByName("Button_8_0"):addClickEventListener(function ( ... )
        cc.Director:getInstance():pushScene(DecalsLotteryScene:createScene(DECALS_TYPE_CHARACTOR));
    end);
end
function DecalsCharactorUnlockAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), -1);
end

return DecalsCharactorUnlockAlert