--
-- Author: 黄泽昊
-- 作用: 选择pageview

local DecalsExhibitionPageView = class("DecalsExhibitionPageView", function ()
    return cc.Node:create();
end)
local PAGEVIEW_CONTENT_SIZE = cc.size(425, 664);
local DecalsExhibitionBackground = require(DECALS_EXHIBITION_BACKGROUND_PATH);
function DecalsExhibitionPageView:ctor()
    self:init();
end
function DecalsExhibitionPageView:init()
    local pageview= ccui.PageView:create();

    pageview:setContentSize(PAGEVIEW_CONTENT_SIZE);

    for _,v in ipairs(bs.UserDataManager:getInstance():getCharactorDecalsData()) do
        pageview:addPage(self:createPageWithData(v));
    end

    -- pageview:addPage(self:createPageWithData());
    -- pageview:addPage(self:createPageWithData());
    pageview:setCurrentPageIndex(0);
    pageview:setPosition(cc.p(pageview:getContentSize().width/-2, pageview:getContentSize().height/-3));
    --pageview:setTouchEnabled(false);
    self.pageview_ = pageview;
    self:addChild(self.pageview_);
end
function DecalsExhibitionPageView:createPageWithData(table_data)
    local layout = ccui.Layout:create();
    layout:setContentSize(PAGEVIEW_CONTENT_SIZE);
    local bg = DecalsExhibitionBackground:create(2,3);
    --dump(table_data);
    --if #table_data ~= 0 then
    bg:addDecalsWithData(table_data);
    --end
    bg:setPosition(cc.p(layout:getContentSize().width/2, layout:getContentSize().height/2));
    layout:addChild(bg);
    return layout;
end
return DecalsExhibitionPageView