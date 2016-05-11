--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 拼图的滚动区域

local PuzzlePiecesScrollView = class("PuzzlePiecesScrollView", function (puzzleTable)
    return cc.Node:create();
end)
local PUZZLE_PIECES_DESK_HEIGHT = 250;
local PUZZLE_PIECES_POS_Y = 110;
local PUZZLE_PIECES_INITIAL_POS_X = 150;
local PUZZLE_PIECES_SCALE = 0.55;

function PuzzlePiecesScrollView:ctor(puzzleTable)
	self.puzzle_table_ = puzzleTable;
	self:init(puzzleTable);
end

function PuzzlePiecesScrollView:init(puzzleTable)
	local pos_x = PUZZLE_PIECES_INITIAL_POS_X;
	local scrollView = ccui.ScrollView:create();
	scrollView:setPosition(0, 0);
	scrollView:setContentSize(cc.size(cc.Director:getInstance():getVisibleSize().width, PUZZLE_PIECES_DESK_HEIGHT));
	scrollView:setBounceEnabled(true);
	scrollView:setScrollBarEnabled(false);
	scrollView:setDirection(cc.SCROLLVIEW_DIRECTION_HORIZONTAL);
	for _, puzzle in ipairs(puzzleTable) do
		puzzle:setPosition(cc.p(pos_x, PUZZLE_PIECES_POS_Y));
		puzzle:setScale(PUZZLE_PIECES_SCALE);
		pos_x = pos_x + PUZZLE_STENCIL_WIDTH;
		scrollView:addChild(puzzle);
		puzzle:setPuzzlePieceMoveNode(self);
	end
	scrollView:setInnerContainerSize(cc.size(pos_x, PUZZLE_PIECES_DESK_HEIGHT));
	self:addChild(scrollView);
	self:setContentSize(scrollView:getContentSize());
end

function PuzzlePiecesScrollView:moveOutPuzzlePiece(puzzle)
	--local index = 0;
	for i,v in ipairs(self.puzzle_table_) do
		if v == puzzle then
			table.remove(self.puzzle_table_, i);
			--index = i;
			self:adjustPuzzlePiecesPosition();
			return;
		end
	end
			
	-- for i=index,#self.puzzle_table_ do
	-- 	local x = PUZZLE_STENCIL_WIDTH*(i-1) + PUZZLE_PIECES_INITIAL_POS_X;
	-- 	self.puzzle_table_[i]:stopAllActions();
	-- 	self.puzzle_table_[i]:runAction(cc.MoveTo:create(0.5, cc.p(x, PUZZLE_PIECES_POS_Y)));
	-- end
end

function PuzzlePiecesScrollView:adjustPuzzlePiecesPosition()
	for i,v in ipairs(self.puzzle_table_) do
		local x = PUZZLE_STENCIL_WIDTH*(i-1) + PUZZLE_PIECES_INITIAL_POS_X;
		self.puzzle_table_[i]:stopAllActions();
		self.puzzle_table_[i]:runAction(cc.MoveTo:create(0.5, cc.p(x, PUZZLE_PIECES_POS_Y)));
	end
end

function PuzzlePiecesScrollView:insertPuzzlePiece(puzzle)
	printf("11111111");
end
return PuzzlePiecesScrollView