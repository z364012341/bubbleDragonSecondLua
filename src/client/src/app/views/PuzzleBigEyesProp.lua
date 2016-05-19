--
-- Author: 黄泽昊
-- 功能: 大眼睛道具

local PuzzleBigEyesProp = class("PuzzleBigEyesProp", function ()
    return cc.Node:create();
end)
local PuzzlePropsBackground = require(PUZZLE_PROPS_BACKGROUND_PATH);
local PROP_BIG_EYES_PATH = "daoju2.PNG"
local USING_PARTICLE_PATH = "particle/daojuguang2.plist";
function PuzzleBigEyesProp:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self:init();
end
function PuzzleBigEyesProp:init()
    self:addChild(PuzzlePropsBackground:create(EVENT_USE_BIG_EYES_PROP), -1);
    self:addChild(GlobalFunction.createGameSpriteWithPath(PROP_BIG_EYES_PATH), 1);
end

function PuzzleBigEyesProp:onEnter()
    self.listener_ = {};

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_BIG_EYES_PROP, function ( event )
        printf("EVENT_USE_BIG_EYES_PROP");
        -- local particle = cc.ParticleSystemQuad:create(USING_PARTICLE_PATH);
        -- particle:setScale(2);
        -- particle:setPosition(cc.p(0,0));
        -- self:addChild(particle);
    end));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleBigEyesProp:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleBigEyesProp