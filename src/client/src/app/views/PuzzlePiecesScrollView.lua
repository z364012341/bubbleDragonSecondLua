--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 拼图的滚动区域

local PuzzlePiecesScrollView = class("PuzzlePiecesScrollView", function (puzzleTable)
    return cc.Node:create();
end)
local PUZZLE_PIECES_DESK_HEIGHT = 270;
local PUZZLE_PIECES_POS_Y = 110;
local PUZZLE_PIECES_INITIAL_POS_X = 100;
local PUZZLE_PIECES_POS_X_DELTA = 185;
local PUZZLE_PIECES_SCALE = 0.55;
local PUZZLE_PIECES_MOVE_DURATION = 0.3;

function PuzzlePiecesScrollView:ctor(puzzleTable)
	self.puzzle_table_ = puzzleTable;
	self:init();
end

function PuzzlePiecesScrollView:init()
	self.scrollView_ = ccui.ScrollView:create();
	self.scrollView_:setPosition(0, 0);
	self.scrollView_:setContentSize(cc.size(cc.Director:getInstance():getVisibleSize().width,
		PUZZLE_PIECES_DESK_HEIGHT*bs.SmartScaleController:getInstance():getPlayAreaZoom()));
	self.scrollView_:setBounceEnabled(true);
	self.scrollView_:setScrollBarEnabled(false);
	self.scrollView_:setDirection(cc.SCROLLVIEW_DIRECTION_HORIZONTAL);
	for i, puzzle in ipairs(self.puzzle_table_) do
		puzzle:setPosition(self:getPuzzlePiecePositionWithIndex(i));
		puzzle:setScale(PUZZLE_PIECES_SCALE);
		--pos_x = pos_x + PUZZLE_PIECES_POS_X_DELTA;
		self.scrollView_:addChild(puzzle);
		puzzle:setPuzzlePieceMoveNode(self);
	end
	self:adjustScrollViewInnerContainerSize();
	self.scrollView_:addEventListener(function ( pSender,  eventType)
		pSender:getInnerContainer():setPositionY(0);
	end);

	self:addChild(self.scrollView_);
	self:setContentSize(self.scrollView_:getContentSize());
end

function PuzzlePiecesScrollView:moveOutPuzzlePiece(puzzle)
	for i,v in ipairs(self.puzzle_table_) do
		if v == puzzle then
			table.remove(self.puzzle_table_, i);
			--index = i;
			--self:adjustPuzzlePiecesPosition();
			return;
		end
	end

	-- for i=index,#self.puzzle_table_ do
	-- 	local x = PUZZLE_STENCIL_WIDTH*(i-1) + PUZZLE_PIECES_INITIAL_POS_X;
	-- 	self.puzzle_table_[i]:stopAllActions();
	-- 	self.puzzle_table_[i]:runAction(cc.MoveTo:create(0.5, cc.p(x, PUZZLE_PIECES_POS_Y)));
	-- end
end

function PuzzlePiecesScrollView:calculatePuzzlePiecePositionX( index )
	return PUZZLE_PIECES_POS_X_DELTA*(index-1) + PUZZLE_PIECES_INITIAL_POS_X;
end

function PuzzlePiecesScrollView:getPuzzlePiecePositionWithIndex( index )
	return cc.p(self:calculatePuzzlePiecePositionX(index), PUZZLE_PIECES_POS_Y);
end
function PuzzlePiecesScrollView:adjustPuzzlePiecesPosition()

	for i,v in ipairs(self.puzzle_table_) do
		local x = PUZZLE_STENCIL_WIDTH*(i-1) + PUZZLE_PIECES_INITIAL_POS_X;
		self.puzzle_table_[i]:stopAllActions();
		self.puzzle_table_[i]:runAction(cc.MoveTo:create(PUZZLE_PIECES_MOVE_DURATION, self:getPuzzlePiecePositionWithIndex(i)));
	end
	self:adjustScrollViewInnerContainerSize();

end
function PuzzlePiecesScrollView:adjustScrollViewInnerContainerSize()
	local inner_width = self:calculatePuzzlePiecePositionX(#self.puzzle_table_) + PUZZLE_PIECES_POS_X_DELTA/2;
	local point = cc.p(self.scrollView_:getInnerContainerPosition());
	self.scrollView_:setInnerContainerSize(cc.size(inner_width, PUZZLE_PIECES_DESK_HEIGHT));
	self.scrollView_:setInnerContainerPosition(point);
	local inner_min_pos_x = -inner_width+self.scrollView_:getContentSize().width;
	if point.x < inner_min_pos_x and #self.puzzle_table_ > 3 then
		self.scrollView_:getInnerContainer():stopAllActions();
		self.scrollView_:getInnerContainer():runAction(cc.MoveTo:create(PUZZLE_PIECES_MOVE_DURATION, cc.p(inner_min_pos_x, 0)));
	elseif point.x > 0 then
		self.scrollView_:scrollToLeft(PUZZLE_PIECES_MOVE_DURATION, false);
	end
	-- if point.x > 0 then
	-- 	self.scrollView_:scrollToLeft(PUZZLE_PIECES_MOVE_DURATION, false);
	-- elseif point.x < inner_min_pos_x and #self.puzzle_table_ < 4 then
	-- 	self.scrollView_:getInnerContainer():stopAllActions();
	-- 	self.scrollView_:getInnerContainer():runAction(cc.MoveTo:create(PUZZLE_PIECES_MOVE_DURATION, cc.p(inner_min_pos_x, 0)));
	-- end
end
function PuzzlePiecesScrollView:insertPuzzlePiece( puzzle )
	local point = self.scrollView_:getInnerContainer():convertToNodeSpace(puzzle:getParent():convertToWorldSpace(cc.p(puzzle:getPosition())));
	puzzle:retain();
	puzzle:removeFromParent();
	puzzle:setPosition(point);
	self.scrollView_:addChild(puzzle);
	puzzle:release();
	if self:insertPuzzleToTable(puzzle) ~= true or #self.puzzle_table_ == 0 then
		table.insert(self.puzzle_table_, puzzle);
	end
end

function PuzzlePiecesScrollView:insertPuzzleToTable( puzzle )

	for i,v in ipairs(self.puzzle_table_) do
		if puzzle:getPositionX() < v:getPositionX() then
			table.insert(self.puzzle_table_, i,  puzzle);

			return true
		end
	end
	return false;
end
return PuzzlePiecesScrollView