--
-- Author: 黄泽昊
-- 功能: 拼图的选择pageview部分

local PuzzleSelectedShow = class("PuzzleSelectedShow", function (params)
    return cc.Node:create();
end)

function PuzzleSelectedShow:ctor(params)
    printf("PuzzleSelectedShow");

end

function PuzzleSelectedShow:addPuzzlePageview()
    -- body
end
return PuzzleSelectedShow