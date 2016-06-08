--
-- Author: 黄泽昊
-- 作用: 选择pageview

local DecalsExhibitionPageView = class("DecalsExhibitionPageView", function ()
    return cc.Node:create();
end)
local PAGEVIEW_CONTENT_SIZE = cc.size(425, 664);
local DecalsExhibitionBackground = require(DECALS_EXHIBITION_BACKGROUND_PATH);
function DecalsExhibitionPageView:ctor()
    -- local function onNodeEvent(event)
    --     if event == "enter" then
    --         self:onEnter();
    --     elseif event == "exit" then
    --         self:onExit();
    --     end
    -- end
    self:init();
end
function DecalsExhibitionPageView:init()
    local pageview= ccui.PageView:create();

    pageview:setContentSize(PAGEVIEW_CONTENT_SIZE);
    local decalsData = bs.UserDataManager:getInstance():getCharactorDecalsData();
    dump(bs.DecalsFactory:getInstance():getDecalsCharactorData());
    for i,v in ipairs(bs.DecalsFactory:getInstance():getDecalsCharactorData()) do
        pageview:addPage(self:createPageWithData(v.x, v.y, decalsData[i]));
    end
    pageview:setCurrentPageIndex(0);
    pageview:setPosition(cc.p(pageview:getContentSize().width/-2, pageview:getContentSize().height/-3));
    --pageview:setTouchEnabled(false);
    self.pageview_ = pageview;
    self:addChild(self.pageview_);
end
function DecalsExhibitionPageView:createPageWithData(x, y, table_data)
    local layout = ccui.Layout:create();
    layout:setContentSize(PAGEVIEW_CONTENT_SIZE);
    local bg = DecalsExhibitionBackground:create(x,y);
    --dump(table_data);
    if table_data ~= nil then
        bg:addDecalsWithData(table_data);
    end
    bg:setPosition(cc.p(layout:getContentSize().width/2, layout:getContentSize().height/2));
    layout:addChild(bg);
    return layout;
end
function DecalsExhibitionPageView:scrollLeft()
    self.pageview_:setCurrentPageIndex(self.pageview_:getCurrentPageIndex()-1);
end
function DecalsExhibitionPageView:scrollRight()
    self.pageview_:setCurrentPageIndex(self.pageview_:getCurrentPageIndex()+1);
end
-- function DecalsExhibitionPageView:onEnter()
--     self.listener_ = {};
--     local function scrollLeft( event )
--         self.current_pageview_:scrollLeft();
--     end
--     table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_SELECTED_SCROLL_LEFT, scrollLeft));

--     local function scrollRight( event )
--         self.current_pageview_:scrollRight();
--     end
--     table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_SELECTED_SCROLL_RIGHT, scrollRight));

--     for _, listener in ipairs(self.listener_) do
--         self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
--     end
-- end
-- function DecalsExhibitionPageView:onExit()
--     local eventDispatcher = self:getEventDispatcher();
--     for _, listener in ipairs(self.listener_) do
--         eventDispatcher:removeEventListener(listener);
--     end
-- end
return DecalsExhibitionPageView