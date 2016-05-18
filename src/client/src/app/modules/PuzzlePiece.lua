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
--local numble = 0
function PuzzlePiece:ctor(params)
    --printf("PuzzlePiece");
    self:addTouchEvent();
    self:initPuzzleRenderTexture(params);
    self:addPuzzlePieceShadow(params);
end

function PuzzlePiece:initPuzzleRenderTexture(params)
    self.node_ = cc.Node:create();
    self:addChild(self.node_);

    self:addClippingNode(params);
    self:addPuzzlePieceEdges(params)
    --GL_DEPTH24_STENCIL8 = 0x88F0
    local puzzleRender = cc.RenderTexture:create(400, 400, cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888, 0x88F0);
    puzzleRender:beginWithClear(0.0, 0.0, 0.0, 0.0); 
    self.node_:setPosition(200, 200);
    self.node_:visit(); 
    puzzleRender:endToLua();
    local render_sp = cc.Sprite:createWithTexture(puzzleRender:getSprite():getTexture());
    render_sp:setScaleY(-1);
    self:addChild(render_sp);
    self.node_:removeFromParent();
end

function PuzzlePiece:addTouchEvent()
    self.touch_listener_ = cc.EventListenerTouchOneByOne:create();
    self.touch_listener_:setSwallowTouches(false);
    self.touch_listener_:registerScriptHandler(self.onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN);
    self.touch_listener_:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED);
    self.touch_listener_:registerScriptHandler(self.onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(self.touch_listener_, self);
end

function PuzzlePiece.onTouchBegan(touch, event)
    --printf("PuzzlePiece onTouchBegan");
    if PuzzlePiece.isTouchOnPuzzle(touch, event) then
        local puzzle = event:getCurrentTarget();
        puzzle:setLocalZOrder(require(PUZZLE_PIECES_COLLECTION_PATH):getZOrderNumble());
        puzzle:retain();
        local point = puzzle._moveNode:convertToNodeSpace(puzzle:getParent():convertToWorldSpace(cc.p(puzzle:getPosition())));
        puzzle:removeFromParent();
        puzzle._moveNode:addChild(puzzle);
        puzzle:setPosition(point);
        puzzle:release();
        puzzle._shadow:shadowGo();
        puzzle._moveNode:moveOutPuzzlePiece(puzzle);
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
    local puzzle = event:getCurrentTarget();
    puzzle._shadow:shadowBack();
    local isOnMoveNode = puzzle.isTouchOnMoveNode(touch, event);
    if puzzle:isToucnOnAnswer() then
        puzzle:moveToAnswer();
    elseif isOnMoveNode then
        puzzle._moveNode:insertPuzzlePiece(puzzle);
    end
    puzzle.touch_listener_:setSwallowTouches(not isOnMoveNode);
    puzzle._moveNode:adjustPuzzlePiecesPosition();
    --dump(puzzle._moveNode:getBoundingBox());
    --dump(touch:getLocationInView());
end

function PuzzlePiece.isTouchOnPuzzle(touch, event)
    local node = event:getCurrentTarget();
    return cc.pGetDistance(node:convertTouchToNodeSpace(touch), cc.p(0, 0)) < PUZZLE_STENCIL_WIDTH / 2;
end

function PuzzlePiece.isTouchOnMoveNode(touch, event)
    local puzzle = event:getCurrentTarget();
    return cc.rectContainsPoint(puzzle._moveNode:getBoundingBox(), puzzle._moveNode:getParent():convertTouchToNodeSpace(touch));
end
function PuzzlePiece:isToucnOnAnswer()
    local puzzlePoint = self:getParent():convertToWorldSpace(cc.p(self:getPosition()));
    local answerPoint = self:getPuzzlePieceAnswer():convertToNodeSpace(puzzlePoint);
    return cc.pGetDistance(cc.p(0,0), answerPoint) < PUZZLE_STENCIL_WIDTH;
end

function PuzzlePiece:moveToAnswer()
    local answer = self:getPuzzlePieceAnswer();
    --local answerPoint = answer:getParent():convertToWorldSpace(cc.p(answer:getPosition()));
    --self:setPosition(self:getParent():convertToNodeSpace(answerPoint));
    self._shadow:removeFromParent();
    --self:setLocalZOrder(0);
    self:retain();
    self:removeFromParent();
    answer:getParent():addChild(self);
    self:setPosition(cc.p(answer:getPosition()));
    self:release();
    self:setScale(1);
    cc.Director:getInstance():getEventDispatcher():removeEventListenersForTarget(self);
    cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUZZLE_ANSWER_ADD);
end

function PuzzlePiece:setPuzzlePieceAnswer(answer)
    self._answer = answer;
end

function PuzzlePiece:setPuzzlePieceMoveNode(node)
    self._moveNode = node;
end

function PuzzlePiece:getPuzzlePieceAnswer()
    return self._answer;
end

function PuzzlePiece:addClippingNode(params)
    local clippingNode = cc.ClippingNode:create(PuzzleStencil:create(params.left, params.right, params.top, params.bottom));
    clippingNode:addChild(PuzzleBottomPlate:create(params.index_x, params.index_y, params.path));
    clippingNode:setAlphaThreshold(0.0);
    self.node_:addChild(clippingNode);
end

function PuzzlePiece:addPuzzlePieceEdges(params)
    self.node_:addChild(PuzzlePieceEdges:create(params.left, params.right, params.top, params.bottom));
end

function PuzzlePiece:addPuzzlePieceShadow(params)
    self._shadow = PuzzlePieceShadow:create(params.left, params.right, params.top, params.bottom);
    self:addChild(self._shadow, -1);
end

return PuzzlePiece