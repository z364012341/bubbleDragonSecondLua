-- Author: 黄泽昊
-- 作用: 贴纸的展示的背景

local DecalsExhibitionBackground = class("DecalsExhibitionBackground", function (col, row, decals_type)
    return cc.Node:create();
end)
local CHARACTOR_BACKGROUND_PATH = "decals_bg.png";
local DECALS_PORTRAIT_LINE_PATH = "charactor_line.png";
local DECALS_HORIZONTAL_LINE_PATH = "decals_horizontal_line.png";
local DECALS_CHARACTOR_BACKGROUND_COLOR = cc.c4b(255, 166, 166, 255);
local DECALS_TREASURE_BACKGROUND_COLOR = cc.c4b(213, 162, 245, 255);
local DECALS_WIDTH = 400;
local DECALS_HEIGHT = 640;
function DecalsExhibitionBackground:ctor(col, row, decals_type)
    printf(col, row);
    assert(col==1 or col == 2);
    self.col_ = col;
    self.row_ = row;
    self.decals_type_ = decals_type;
    self:init(col, row);
end
function DecalsExhibitionBackground:init(col, row, decals_type)
    self:addBackground();
    self:addIndexLabel(col, row);
    self:addLine();
    -- self:addDecal(1,1);
    -- self:addDecal(2,1);
    -- self:addDecal(1,2);
    -- self:addDecal(2,2);
    -- self:addDecal(1,3);
    -- self:addDecal(2,3);
end
function DecalsExhibitionBackground:addDecalsWithData(table_data)
    dump(table_data);
    local path = table_data.path;
    for _,numble in ipairs(table_data.goods) do
        self:addDecal(path, numble)
    end
end
function DecalsExhibitionBackground:addBackground()
    local bg = GlobalFunction.createGameSpriteWithPath(CHARACTOR_BACKGROUND_PATH);
    self:addChild(bg);

    local color = self.decals_type_ == DECALS_TYPE_CHARACTOR and DECALS_CHARACTOR_BACKGROUND_COLOR or DECALS_TREASURE_BACKGROUND_COLOR;
    dump(self.decals_type_);
    self.background_ = cc.LayerColor:create(color, DECALS_WIDTH, DECALS_HEIGHT);
    self.background_:setPosition(cc.p((bg:getContentSize().width-DECALS_WIDTH)/2, (bg:getContentSize().height-DECALS_HEIGHT)/2));
    bg:addChild(self.background_);


end
function DecalsExhibitionBackground:addLine()
    if self.col_ == 2 then
        local line = GlobalFunction.createGameSpriteWithPath(DECALS_PORTRAIT_LINE_PATH);
        self.background_:addChild(line);
        line:setPosition(cc.p(DECALS_WIDTH/2, DECALS_HEIGHT/2));
    end

    local row_offset = DECALS_HEIGHT/self.row_;
    for i=1,self.row_-1 do
        local line = GlobalFunction.createGameSpriteWithPath(DECALS_HORIZONTAL_LINE_PATH);
        self.background_:addChild(line);
        line:setPosition(cc.p(DECALS_WIDTH/2, row_offset*i));
    end
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
function DecalsExhibitionBackground:addDecal(path, numble)
    local index = bs.DecalsFactory:getInstance():convertDecalNumbleToIndex(numble, path);
    local sp = bs.DecalsFactory:getInstance():createDecal(path, index.x, index.y);
    sp:setPosition(self:getPositionWithIndex(index.x, index.y));
    self.background_:addChild(sp, 1);
end
return DecalsExhibitionBackground