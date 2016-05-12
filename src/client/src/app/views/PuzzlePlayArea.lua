--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 

local PuzzlePlayArea = class("PuzzlePlayArea", function ()
    return cc.Node:create();
end)
local PuzzlePlayAreaInnerContainer = require(PUZZLE_PLAY_AREA_INNER_CONTAINER);
local PUZZLE_AREA_EDGE_PATH = "pintudi.PNG";
function PuzzlePlayArea:ctor()
    --printf("PuzzlePlayArea");
    self:init();
end

function PuzzlePlayArea:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzlePlayArea:create()
    scene:addChild(layer)
    return scene
end
function PuzzlePlayArea:init()
    local win_clip = cc.ClippingNode:create(self:getBackgroundColorLayer());
    self:addChild(win_clip);
    local background = self:getBackgroundColorLayer();
    self:addChild(background, -1); 
    local puzzle_win = PuzzlePlayAreaInnerContainer:create();
    puzzle_win:setPosition(cc.p(background:getPosition()));
    win_clip:addChild(puzzle_win);
    self:addAreaWindowsEdge();
end

function PuzzlePlayArea:getBackgroundColorLayer()
    local colorLayer = cc.LayerColor:create(PUZZLE_SHOW_LAYER_COLOR_C4B, 656, 805);
    colorLayer:setPosition(cc.p(colorLayer:getContentSize().width/-2, colorLayer:getContentSize().height/-2));
    return colorLayer;
end

function PuzzlePlayArea:addAreaWindowsEdge()
    self.win_edge_ = GlobalFunction.createGameSpriteWithPath(PUZZLE_AREA_EDGE_PATH);
    self:addChild(self.win_edge_, 1);
    local listener = cc.EventListenerTouchOneByOne:create();
    listener:setSwallowTouches(true);
    local function onTouchBegan(touch, event)
        if cc.rectContainsPoint(self.win_edge_:getBoundingBox(), self.win_edge_:getParent():convertTouchToNodeSpace(touch)) then
            return false;
        end
        return true;
    end
    listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN);
    --listener:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED);
    --listener:registerScriptHandler(self.onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self.win_edge_);
end
function PuzzlePlayArea:getThumbnail()
    --local size = self.win_edge_:getContentSize();
    --local x, y = self:getPosition();
    local size = cc.Director:getInstance():getVisibleSize();
    local puzzleRender = cc.RenderTexture:create(size.width, size.height, cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888, 0x88F0);
    puzzleRender:beginWithClear(0.0, 0.0, 0.0, 0.0); 
    --puzzleRender:setPosition(size.width/2, size.height/2);
    self:visit(); 
    puzzleRender:endToLua();
    --self:setPosition(cc.p(x, y));
    local render_sp = cc.Sprite:createWithTexture(puzzleRender:getSprite():getTexture());
    render_sp:setFlippedY(true);
    render_sp:setContentSize(size);
    return render_sp;
end
return PuzzlePlayArea