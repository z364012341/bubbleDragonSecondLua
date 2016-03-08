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
    return cc.ClippingNode:create(require(PUZZLE_STENCIL_PATH):create(params.left, 
    	params.right, params.top, params.bottom));
end)
local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
-- local PuzzlePieceAnswer = require(PUZZLE_PIECE_ANSWER_PATH);

function PuzzlePiece:ctor(params)
    printf("PuzzlePiece");
    self:setAlphaThreshold(0.1);
    self:addTouchEvent();

    local plate = PuzzleBottomPlate:create(params.index_x, params.index_y, params.path); 
    self:addChild(plate);
    self:setScale(0.25);
    -- self._answer = PuzzlePieceAnswer:create(params.left, params.right, params.top, params.bottom);
    -- self._answer:setPosition(-plate:getPositionX(), -plate:getPositionY());
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
    return PuzzlePiece.isTouchOnPuzzle(touch, event);
end

function PuzzlePiece.onTouchMoved(touch, event)
    --printf("PuzzlePiece onTouchMoved");
    local node = event:getCurrentTarget();
    node:setPosition(node:getParent():convertTouchToNodeSpace(touch));
end

function PuzzlePiece.onTouchEnded(touch, event)
    --printf("PuzzlePiece onTouchEnded");
end

function PuzzlePiece.isTouchOnPuzzle(touch, event)
    local node = event:getCurrentTarget();
    return cc.pGetDistance(node:convertTouchToNodeSpace(touch), cc.p(0, 0)) < PUZZLE_STENCIL_WIDTH/2;
end

function PuzzlePiece:setPuzzlePieceAnswer(answer)
    self._answer = answer;
end

function PuzzlePiece:getPuzzlePieceAnswer()
    return self._answer;
end

return PuzzlePiece