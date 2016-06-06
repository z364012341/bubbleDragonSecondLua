-- Author: 黄泽昊
-- 作用: 贴纸的展示的背景

local DecalsExhibitionBackground = class("DecalsExhibitionBackground", function (col, row)
    return cc.Node:create();
end)
local CHARACTOR_BACKGROUND_PATH = "decals_charactor_bg.png";
local DECALS_LINE_PATH = "charactor_line.png";
function DecalsExhibitionBackground:ctor(col, row)
    assert(col==1 or col == 2);
    self:init(col, row);
end
function DecalsExhibitionBackground:init(col, row)
    self.col_ = col;
    self.row_ = row;
    self:addBackground(col);
    self:addIndexLabel(col, row);
end
function DecalsExhibitionBackground:addBackground(col)
    local bg = GlobalFunction.createGameSpriteWithPath(CHARACTOR_BACKGROUND_PATH);
    self:addChild(bg);
    if col == 2 then
        local line = GlobalFunction.createGameSpriteWithPath(DECALS_LINE_PATH);
        bg:addChild(line);
        line:setPosition(cc.p(bg:getContentSize().width/2, bg:getContentSize().height/2));
    end
    self.background_ = bg;
end
function DecalsExhibitionBackground:addIndexLabel(col, row)
    local numble = 1;
    for i=1,row do
        for j=1,col do
            local index_label = bs.ExhibitionNumble:create(numble);
            self.background_:addChild(index_label);
            index_label:setPosition(self:getPositionWithIndex(j, i));
            numble = numble + 1;
        end
    end
end
function DecalsExhibitionBackground:getPositionWithIndex(x, y)
    return cc.p(self.background_:getContentSize().width/self.col_*(x-0.5), self.background_:getContentSize().height/self.row_*(self.row_-y+0.5));
end
return DecalsExhibitionBackground