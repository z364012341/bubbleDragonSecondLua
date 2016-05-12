--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的layer, 最下面的那层

local PuzzlePlayAreaInnerContainer = class("PuzzlePlayAreaInnerContainer", function ()
    return cc.Node:create();
end)
local PUZZLE_PLAY_SCENE_ZOOM_SCALE_PER_NUMBLE = 0.02;
function PuzzlePlayAreaInnerContainer:ctor()
    --printf("PuzzlePlayAreaInnerContainer");
    local collection = require(PUZZLE_PIECES_COLLECTION_PATH):create("puzzle_1.png")
    local puzzleNode = collection:getPuzzleNode();
    --puzzleNode:setPosition(200, 200);
    --puzzleNode:setScale(0.6);
    --self:addChild(puzzleNode);

    self.answerNode_ = collection:getAnswerNode();
    local event = cc.EventCustom:new(EVENT_PUZZLE_ANSWER_LOAD);
    event._usedata = puzzleNode;
    self:getEventDispatcher():dispatchEvent(event);
    --answerNode:setPosition(0, 300);
    --answerNode:setScale(0.6);
    self:addChild(self.answerNode_, -1);
    self:addBackMenu();
    self:addTouchesListerner();
--[[
    local clippingNode = require(PUZZLE_PIECE_PATH):create({
        index_x = 1, --拼图碎片的x索引
        index_y = 2, --拼图碎片的y索引
        path = "puzzle_1.png",    --底板的资源路径
        left = PUZZLE_STENCIL_COMPONENT_INSIDE,    --左边凹凸方向
        right = PUZZLE_STENCIL_COMPONENT_OUTSIDE,   --右边凹凸方向
        top = PUZZLE_STENCIL_COMPONENT_PLAIN,     --上边凹凸方向
        bottom = PUZZLE_STENCIL_COMPONENT_PLAIN  --下边凹凸方向
    });
    clippingNode:setPosition(300, 300);
    self:addChild(clippingNode);
--]]
end

-- function PuzzlePlayAreaInnerContainer:createScene()
--     local scene = cc.Scene:create()
--     local layer = PuzzlePlayAreaInnerContainer:create()
--     scene:addChild(layer)
--     return scene
-- end

function PuzzlePlayAreaInnerContainer:addBackMenu()
    local item = cc.MenuItemSprite:create(cc.Sprite:create("001.png"), cc.Sprite:create("001.png"));
    item:registerScriptTapHandler(function (event)
        cc.Director:getInstance():replaceScene(bs.GameStageSelectionScene:createScene());
    end);
    local menu = cc.Menu:create();
    menu:addChild(item);
    menu:setPosition(0, 0);
    self:addChild(menu);
    --self:setScale(0.6);
end

function PuzzlePlayAreaInnerContainer:addTouchesListerner()
    local listener = cc.EventListenerTouchAllAtOnce:create();
    --listener:setSwallowTouches(true);
    --listener:registerScriptHandler(self.onTouchBegan,cc.Handler.EVENT_TOUCHES_BEGAN);
    listener:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCHES_MOVED);
    --listener:registerScriptHandler(self.onTouchEnded,cc.Handler.EVENT_TOUCHES_ENDED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self);


    local mouseListener = cc.EventListenerMouse:create();
    mouseListener:registerScriptHandler(function(event)
        self:setScale(math.max(0.1, self:getScale() + event:getScrollY()*-0.1));
    end,cc.Handler.EVENT_MOUSE_SCROLL);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(mouseListener, self);
end

function PuzzlePlayAreaInnerContainer.onTouchBegan(touches, event)
    --printf("PuzzlePlayAreaInnerContainer onTouchBegan");
    -- printf(#touches);
    -- if #touches > 1 then

    -- end
    --return false;
    -- local layer = event:getCurrentTarget();
    -- dump(layer.answerNode_:getBoundingBox());
    -- if cc.rectContainsPoint(layer.answerNode_:getBoundingBox(), layer.answerNode_:getParent():convertTouchToNodeSpace(touches[1])) then

    --     return true;
    -- else
    --     return false
    -- end
end

function PuzzlePlayAreaInnerContainer.onTouchMoved(touches, event)
    -- local layer = event:getCurrentTarget();
    -- if cc.rectContainsPoint(layer.answerNode_:getBoundingBox(), layer.answerNode_:getParent():convertTouchToNodeSpace(touches[1])) then
    --     return;
    -- end
    if #touches == 1 then
        event:getCurrentTarget():touchToMove(touches);
        return;
    end 
    event:getCurrentTarget():pinchToZoom(touches);
    -- local dis1 = cc.pGetDistance(touches[1]:getPreviousLocation(), touches[2]:getPreviousLocation());
    -- local dis2 = cc.pGetDistance(touches[1]:getLocation(), touches[2]:getLocation());
    -- local target = event:getCurrentTarget();
    -- local middlePoint = cc.pMidpoint(touches[1]:getPreviousLocation(), touches[2]:getPreviousLocation());
    -- local pointInLayer = target:convertToNodeSpace(middlePoint);
    -- target:setScale(target:calculateZoomScale(dis1, dis2));
    -- local pointAfterScale = target:convertToWorldSpace(pointInLayer);
    -- local newPoint = cc.pAdd(cc.pSub(middlePoint, pointAfterScale), cc.p(target:getPosition()));
    -- target:setPosition(newPoint);
end

-- function PuzzlePlayAreaInnerContainer.onTouchEnded(touches, event)
--     --printf("PuzzlePiece onTouchEnded");
-- end

function PuzzlePlayAreaInnerContainer:calculateZoomScale(preDistance, locDistance)
    local scale = self:getScale();
    if locDistance>preDistance then
        scale = scale + PUZZLE_PLAY_SCENE_ZOOM_SCALE_PER_NUMBLE;
    else
        scale = scale - PUZZLE_PLAY_SCENE_ZOOM_SCALE_PER_NUMBLE;
    end 
    scale = math.min(scale, PUZZLE_PLAY_SCENE_ZOOM_SCALE_MAX);
    scale = math.max(scale, PUZZLE_PLAY_SCENE_ZOOM_SCALE_MIN);
    return scale;
end

function PuzzlePlayAreaInnerContainer:pinchToZoom(touches)
    local dis1 = cc.pGetDistance(touches[1]:getPreviousLocation(), touches[2]:getPreviousLocation());
    local dis2 = cc.pGetDistance(touches[1]:getLocation(), touches[2]:getLocation());
    --local target = event:getCurrentTarget();
    local middlePoint = cc.pMidpoint(touches[1]:getPreviousLocation(), touches[2]:getPreviousLocation());
    local pointInLayer = self:convertToNodeSpace(middlePoint);
    self:setScale(self:calculateZoomScale(dis1, dis2));
    local pointAfterScale = self:convertToWorldSpace(pointInLayer);
    local newPoint = cc.pAdd(cc.pSub(middlePoint, pointAfterScale), cc.p(self:getPosition()));
    self:setPosition(newPoint);
end

function PuzzlePlayAreaInnerContainer:touchToMove(touches)
    local dis = touches[1]:getDelta()
    local zoomScale = self:getScale();
    self:setPositionX(self:getPositionX() + dis.x);
    self:setPositionY(self:getPositionY() + dis.y);
end
return PuzzlePlayAreaInnerContainer