--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 

local PuzzlePlayArea = class("PuzzlePlayArea", function ()
    return cc.Node:create();
end)
local PuzzlePlayAreaInnerContainer = require(PUZZLE_PLAY_AREA_INNER_CONTAINER);
local PUZZLE_AREA_EDGE_PATH = "pintudi.PNG";
local COLOR_LAYER_WIDTH = 656;
local COLOR_LAYER_HEIGHT = 805;

function PuzzlePlayArea:ctor()
    --printf("PuzzlePlayArea");
    self:init();
end

-- function PuzzlePlayArea:createScene()
--     local scene = cc.Scene:create()
--     local layer = PuzzlePlayArea:create()
--     scene:addChild(layer)
--     return scene
-- end
function PuzzlePlayArea:init()

    local background = self:getBackgroundColorLayer();
    self:addChild(background, -1); 
    self:initPlayArea();
    self:addAreaWindowsEdge();
end
function PuzzlePlayArea:initPlayArea()
    local win_clip = cc.ClippingNode:create(self:getBackgroundColorLayer());
    self:addChild(win_clip);
    self.play_area_ = PuzzlePlayAreaInnerContainer:create();
    win_clip:addChild(self.play_area_);
    --local area_size = self.play_area_:getContentSize();
    --local scale_numble = math.min(COLOR_LAYER_WIDTH/area_size.width, COLOR_LAYER_HEIGHT/area_size.height)*0.9;
    self.play_area_:setScale(self:calculatePuzzleScale());
end
function PuzzlePlayArea:calculatePuzzleScale()
    --return GlobalFunction.calculateMinSizeScale(cc.size(COLOR_LAYER_WIDTH, COLOR_LAYER_HEIGHT), self.play_area_:getContentSize())*0.96;
    return self:calculatePuzzleScaleWithSize(self.play_area_:getContentSize());
end
function PuzzlePlayArea:calculatePuzzleScaleWithSize(size)
    return GlobalFunction.calculateMinSizeScale(cc.size(COLOR_LAYER_WIDTH, COLOR_LAYER_HEIGHT), size)*0.96;
    --return math.min(COLOR_LAYER_WIDTH/self.play_area_:getContentSize().width, COLOR_LAYER_HEIGHT/self.play_area_:getContentSize().height)*0.96;
end
function PuzzlePlayArea:getBackgroundColorLayer()
    local colorLayer = cc.LayerColor:create(PUZZLE_SHOW_LAYER_COLOR_C4B, COLOR_LAYER_WIDTH, COLOR_LAYER_HEIGHT);
    colorLayer:setPosition(cc.p(colorLayer:getContentSize().width/-2, colorLayer:getContentSize().height/-2));
    return colorLayer;
end
function PuzzlePlayArea:createWindowsEdge()
    return GlobalFunction.createGameSpriteWithPath(PUZZLE_AREA_EDGE_PATH);
end
function PuzzlePlayArea:addAreaWindowsEdge()
    local win_edge = self:createWindowsEdge();
    self:addChild(win_edge, 1);
    local listener = cc.EventListenerTouchOneByOne:create();
    listener:setSwallowTouches(true);
    local function onTouchBegan(touch, event)
        if cc.rectContainsPoint(win_edge:getBoundingBox(), win_edge:getParent():convertTouchToNodeSpace(touch)) then
            return false;
        end
        return true;
    end
    listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN);
    --listener:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED);
    --listener:registerScriptHandler(self.onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, win_edge);
end
function PuzzlePlayArea:getThumbnail()
    -- --local size = win_edge:getContentSize();
    -- --local x, y = self:getPosition();
    -- local size = cc.Director:getInstance():getVisibleSize();
    -- local puzzleRender = cc.RenderTexture:create(size.width, size.height, cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888, 0x88F0);
    -- puzzleRender:beginWithClear(0.0, 0.0, 0.0, 0.0); 
    -- self:visit(); 
    -- puzzleRender:endToLua();
    -- local render_sp = cc.Sprite:createWithTexture(puzzleRender:getSprite():getTexture());
    -- render_sp:setFlippedY(true);
    -- render_sp:setContentSize(size);

    ----[[
    local color_layer = self:getBackgroundColorLayer();
    local node = cc.Node:create();
    node:addChild(color_layer);
    --local thumbnail = self.play_area_:getAnswersThumbnail();
    local thumbnail = self:getThumbnailWithoutBackground();
    --thumbnail:retain();
    --thumbnail:removeFromParent();
    thumbnail:setScale(self:calculatePuzzleScale());
    local thumbnail_x = thumbnail:getContentSize().width*thumbnail:getScale()/-2;
    local thumbnail_y = thumbnail:getContentSize().height*thumbnail:getScale()/-2;
    thumbnail:setPosition(cc.p(thumbnail_x, thumbnail_y));
    node:addChild(thumbnail, 1);
    --thumbnail:release();
    node:addChild(self:createWindowsEdge());

    return node;
    --]]
end

function PuzzlePlayArea:getThumbnailWithoutBackground()
    local node = cc.Node:create();
    local thumbnail = self.play_area_:getAnswersThumbnail();
    thumbnail:retain();
    thumbnail:removeFromParent();
    node:addChild(thumbnail);
    thumbnail:release();
    return node;
end
function PuzzlePlayArea:getAnswersThumbnail()
    -- local bg = GlobalFunction.createGameSpriteWithPath(ANSWER_FLASH_BACKGROUND);
    -- local answer_size = self.answerNode_:getContentSize();
    -- bg:setScale(answer_size.width / ANSWER_FLASH_INNER_SIZE.width*0.8, self.answerNode_:getContentSize().height / ANSWER_FLASH_INNER_SIZE.height*0.8);
    -- self.answerNode_:addChild(bg);
    -- self.answerNode_:runAction(cc.Sequence:create(cc.ScaleBy:create(2, 2), cc.CallFunc:create(function (  )
    --     printf("111111111");
    -- end)));
    --self.play_area_:
    return self.play_area_:getAnswersThumbnail()
end
return PuzzlePlayArea