--
-- Author: 黄泽昊
-- 功能: 拼图抽奖界面

local PuzzleLotteryAlert = class("PuzzleLotteryAlert", function ()
    return cc.Node:create();
end)
local LOTTERY_ANIMATION_NAME = "pintulibao";
local PARTICLE_1_PATH = "particle/pintulibao1guang.plist";
local PARTICLE_2_PATH = "particle/pintulibao2guang.plist";
local PARTICLE_FLYING_PATH = "particle/daojulizi.plist";
local GIFT_PROP_BACKGROUND_PATH = "libaoguang_0001_1.png";
local GIFT_PROP_FLYING_TIME = 1;

function PuzzleLotteryAlert:ctor()
    self:runAction(cc.Sequence:create(cc.DelayTime:create(0.5), cc.CallFunc:create(function (  )
        self:init();
    end), nil));
    --self:init();
    self:addChild(bs.GameAlertMask:createTransparentMask(), -1);
end
function PuzzleLotteryAlert:init()
    self:addChild(bs.GameAlertMask:create(), -1);
    local armature = ccs.Armature:create(LOTTERY_ANIMATION_NAME);
    --armature:setScale(1.5);
    --armature:addChild(bs.GameAlertMask:create());
    --armature:setPosition(cc.p(cc.Director:getInstance():getVisibleSize().width/2, cc.Director:getInstance():getVisibleSize().height*0.4));
    self:addChild(armature);
    armature:getAnimation():playWithIndex(0);
    -- armature:getAnimation():setMovementEventCallFunc(function ( armature, movementType, movementID)
    --     self:removeFromParent();
    -- end);
    self:runAction(cc.Sequence:create(cc.DelayTime:create(0.875), cc.CallFunc:create(function ()
        local particle1 = cc.ParticleSystemQuad:create(PARTICLE_1_PATH);
        particle1:setPosition(cc.p(0,0));
        particle1:setScale(2);
        self:addChild(particle1);
        local particle2 = cc.ParticleSystemQuad:create(PARTICLE_2_PATH);
        particle2:setPosition(cc.p(0,0));
        particle2:setScale(2);
        self:addChild(particle2);
        self:popGiftProp();
    end),cc.DelayTime:create(1), cc.CallFunc:create(function ()
        self:propFly();
    end), nil));
end
function PuzzleLotteryAlert:popGiftProp()
    local prop_sp = bs.SpriteTextureController:getInstance():createGameSpriteWithPath("daoju2.PNG");
    self:addChild(prop_sp, 1);
    prop_sp:setScale(0.1);
    prop_sp:runAction(cc.Sequence:create(cc.ScaleTo:create(0.2, 4.5), cc.ScaleTo:create(0.1, 3.5), nil));
    self.gigt_prop_ = prop_sp;

    local bg = bs.SpriteTextureController:getInstance():createGameSpriteWithPath(GIFT_PROP_BACKGROUND_PATH);
    self:addChild(bg);
    bg:setScale(2);
    bg:setOpacity(0);
    bg:runAction(cc.FadeIn:create(2));
    bg:runAction(cc.RepeatForever:create(cc.RotateBy:create(4, 360)));
    self.prop_background_ = bg;

    bs.GameAudioController:getInstance():playPuzzleVictoryGiftPopEffect();
end
function PuzzleLotteryAlert:propFly()
    --道具往右下角飞
    self.prop_background_:removeFromParent();
    local end_point = GlobalFunction.getVisibleCenterPosition();
    local table = {cc.p(self.gigt_prop_:getPosition()), cc.p(300,100),cc.p(end_point.x*0.9, end_point.y*-0.9)};
    local ease_bezier = cc.EaseSineIn:create(cc.BezierTo:create(GIFT_PROP_FLYING_TIME, table));
    self.gigt_prop_:runAction(cc.Sequence:create(ease_bezier, cc.CallFunc:create(function ()
        self:removeFromParent();
    end) , nil));
    local scale = cc.ScaleTo:create(GIFT_PROP_FLYING_TIME, 0.1);
    self.gigt_prop_:runAction(scale);

    --道具飞行的拖尾粒子
    local fly_particle = cc.ParticleSystemQuad:create(PARTICLE_FLYING_PATH);
    fly_particle:setPosition(cc.p(0,0));
    fly_particle:setScale(10);
    self:addChild(fly_particle);
    fly_particle:runAction(ease_bezier:clone());
    fly_particle:runAction(scale:clone());
end
return PuzzleLotteryAlert