--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图碎片
--[[params = 
	{
        index_x = 1, --拼图碎片的x索引
        index_y = 1, --拼图碎片的y索引
        path = "puzzle_1.png",    --底板的资源路径
        left = PUZZLE_STENCIL_COMPONENT_INSIDE,    --左边凹凸方向
        right = PUZZLE_STENCIL_COMPONENT_OUTSIDE,   --右边凹凸方向
        top = PUZZLE_STENCIL_COMPONENT_PLAIN,     --上边凹凸方向
        bottom = PUZZLE_STENCIL_COMPONENT_PLAIN  --下边凹凸方向
    }
]]
local PuzzlePiece = class("PuzzlePiece", function (params)
    --dump(params);
    return cc.Node:create();
end)
local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
local PuzzleStencil = require(PUZZLE_STENCIL_PATH);
local PuzzlePieceEdges = require(PUZZLE_PIECE_EDGES_PATH);
local PuzzlePieceShadow = require(PUZZLE_PIECE_SHADOW_PATH);
--local PuzzlePiecesCollection = require(PUZZLE_PIECES_COLLECTION_PATH);
function PuzzlePiece:ctor(params)
    printf("PuzzlePiece");
    self:addTouchEvent();
    self:addClippingNode(params);
    self:addPuzzlePieceEdges(params)
    self:addPuzzlePieceShadow(params);
    --self:setScale(0.5);
end

function PuzzlePiece:addTouchEvent()
    local listener = cc.EventListenerTouchOneByOne:create();
    listener:setSwallowTouches(true);
    listener:registerScriptHandler(self.onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN);
    listener:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED);
    listener:registerScriptHandler(self.onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self);
end

function PuzzlePiece.onTouchBegan(touch, event)
    --printf("PuzzlePiece onTouchBegan");
    if PuzzlePiece.isTouchOnPuzzle(touch, event) then
        local node = event:getCurrentTarget();
        node._shadow:shadowGo();
        node:setLocalZOrder(require(PUZZLE_PIECES_COLLECTION_PATH):getZOrderNumble());
        return true;
    end
    return false;
end

function PuzzlePiece.onTouchMoved(touch, event)
    --printf("PuzzlePiece onTouchMoved");
    local node = event:getCurrentTarget();
    local dis = touch:getDelta()
    local zoomScale = node:getParent():getParent():getScale();
    node:setPositionX(node:getPositionX() + dis.x/zoomScale);
    node:setPositionY(node:getPositionY() + dis.y/zoomScale);
end

function PuzzlePiece.onTouchEnded(touch, event)
    --printf("PuzzlePiece onTouchEnded");
    event:getCurrentTarget()._shadow:shadowBack();
    if event:getCurrentTarget():isToucnOnAnswer() then
        event:getCurrentTarget():moveToAnswer();
    end
end

function PuzzlePiece.isTouchOnPuzzle(touch, event)
    local node = event:getCurrentTarget();
    return cc.pGetDistance(node:convertTouchToNodeSpace(touch), cc.p(0, 0)) < PUZZLE_STENCIL_WIDTH / 2;
end

function PuzzlePiece:isToucnOnAnswer()
    local puzzlePoint = self:getParent():convertToWorldSpace(cc.p(self:getPosition()));
    local answer = self:getPuzzlePieceAnswer();
    local answerPoint = answer:getParent():convertToWorldSpace(cc.p(answer:getPosition()));
    return cc.pGetDistance(puzzlePoint, answerPoint) < 90;
end

function PuzzlePiece:moveToAnswer()
    local answer = self:getPuzzlePieceAnswer();
    local answerPoint = answer:getParent():convertToWorldSpace(cc.p(answer:getPosition()));
    self:setPosition(self:getParent():convertToNodeSpace(answerPoint));
    self._shadow:removeFromParent();
    cc.Director:getInstance():getEventDispatcher():removeEventListenersForTarget(self);
end

function PuzzlePiece:setPuzzlePieceAnswer(answer)
    self._answer = answer;
end

function PuzzlePiece:getPuzzlePieceAnswer()
    return self._answer;
end

function PuzzlePiece:addClippingNode(params)
    local clippingNode = cc.ClippingNode:create(PuzzleStencil:create(params.left, params.right, params.top, params.bottom));
    clippingNode:addChild(PuzzleBottomPlate:create(params.index_x, params.index_y, params.path));
    clippingNode:setAlphaThreshold(0.0);
    self:addChild(clippingNode);
end

function PuzzlePiece:addPuzzlePieceEdges(params)
    self:addChild(PuzzlePieceEdges:create(params.left, params.right, params.top, params.bottom));
end

function PuzzlePiece:addPuzzlePieceShadow(params)
    self._shadow = PuzzlePieceShadow:create(params.left, params.right, params.top, params.bottom);
    self:addChild(self._shadow, -1);
end

return PuzzlePiece