--
-- Author: 黄泽昊
-- 功能: 拼图的选择pageview部分

local PuzzleSelectedShow = class("PuzzleSelectedShow", function (params)
    return cc.Node:create();
end)

function PuzzleSelectedShow:ctor(params)
    --printf("PuzzleSelectedShow");
    self:addPuzzlePageview();
end

function PuzzleSelectedShow:addPuzzlePageview()
    self.pageview_ = ccui.PageView:create();
    self.pageview_:setContentSize(PUZZLE_INITIAL_SIZE);
    --self.pageview_:setScale(0.4126);
    self:addChild(self.pageview_);
    local layout = ccui.Layout:create();
    local sp = GlobalFunction.createGameSpriteWithPath("puzzle_1.png");
    sp:setAnchorPoint(cc.p(0, 0));
    layout:addChild(sp);
    --layout:setContentSize(cc.size(976, 1464));
    self.pageview_:addPage(layout);
end
return PuzzleSelectedShow