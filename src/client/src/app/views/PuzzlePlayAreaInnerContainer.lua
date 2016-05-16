--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的layer, 最下面的那层

local PuzzlePlayAreaInnerContainer = class("PuzzlePlayAreaInnerContainer", function ()
    return cc.Node:create();
end)
local PUZZLE_PLAY_SCENE_ZOOM_SCALE_PER_NUMBLE = 0.02;
local ANSWERS_NODE_ZORDER = -1;
function PuzzlePlayAreaInnerContainer:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
        self:registerScriptHandler(onNodeEvent);
    end
    self:registerScriptHandler(onNodeEvent);
    local collection = require(PUZZLE_PIECES_COLLECTION_PATH):create(require(PUZZLE_SELECTED_SHOW_PATH):getSelectedPicturePath())
    local puzzleNode = collection:getPuzzleNode();

    self:getEventDispatcher():dispatchEvent(GlobalFunction.createCustomEvent(EVENT_PUZZLE_ANSWER_LOAD, puzzleNode));
    self.answerNode_ = collection:getAnswerNode();
    -- local event = cc.EventCustom:new(EVENT_PUZZLE_ANSWER_LOAD);
    -- event._userData = puzzleNode;
    -- event:setUserData(puzzleNode);

    self:addChild(self.answerNode_, ANSWERS_NODE_ZORDER);
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

function PuzzlePlayAreaInnerContainer:addTouchesListerner()
    local listener = cc.EventListenerTouchAllAtOnce:create();
    listener:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCHES_MOVED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self);
    local mouseListener = cc.EventListenerMouse:create();
    mouseListener:registerScriptHandler(function(event)
        self:setScale(math.max(0.1, self:getScale() + event:getScrollY()*-0.1));
    end,cc.Handler.EVENT_MOUSE_SCROLL);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(mouseListener, self);
end
function PuzzlePlayAreaInnerContainer.onTouchMoved(touches, event)
    if #touches == 1 then
        event:getCurrentTarget():touchToMove(touches);
        return;
    end 
    event:getCurrentTarget():pinchToZoom(touches);
end

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
function PuzzlePlayAreaInnerContainer:getAnswersThumbnail()
    self.answerNode_:retain();
    self:saveAnswerNodeData();
    self.answerNode_:removeFromParent();
    return self.answerNode_;
end
function PuzzlePlayAreaInnerContainer:pushAnswersThumbnail()
    self.answerNode_:retain();
    self.answerNode_:removeFromParent();
    self.answerNode_:setScale(self.answer_node_scale_save_);
    self.answerNode_:setPosition(self.answer_node_pos_save_);
    self:addChild(self.answerNode_, ANSWERS_NODE_ZORDER);
    self.answerNode_:release();
end
function PuzzlePlayAreaInnerContainer:saveAnswerNodeData()
    self.answer_node_pos_save_ = cc.p(self.answerNode_:getPosition());
    self.answer_node_scale_save_ = self.answerNode_:getScale();
end

function PuzzlePlayAreaInnerContainer:onEnter()
    local function pushAnswersThumbnail( event )
        self:pushAnswersThumbnail();
    end
    self._listener1 = cc.EventListenerCustom:create(EVENT_PUSH_ANSWERS_THUMBNAIL, pushAnswersThumbnail);
    self:getEventDispatcher():addEventListenerWithFixedPriority(self._listener1, 1);
end
function PuzzlePlayAreaInnerContainer:onExit()
    local eventDispatcher = self:getEventDispatcher();
    eventDispatcher:removeEventListener(self._listener1);
end
return PuzzlePlayAreaInnerContainer