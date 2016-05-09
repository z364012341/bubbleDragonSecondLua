--
-- Author: 黄泽昊
-- 功能: 拼图的选择pageview部分

local PuzzleSelectedShow = class("PuzzleSelectedShow", function (params)
    return cc.Node:create();
end)

function PuzzleSelectedShow:ctor(params)
    printf("PuzzleSelectedShow");
    self:addPuzzlePageview();
end

function PuzzleSelectedShow:addPuzzlePageview()
    self.pageview_ = ccui.PageView:create();
    pageview_:setContentSize(cc.size(976, 1464));
    self:addChild(self.pageview_);
    local layout = ccui.Layout:create();
    layout:addChild(GlobalFunction.createGameSpriteWithPath("puzzle_1.png"));
    self.pageview_:addPage(layout);
end
return PuzzleSelectedShow