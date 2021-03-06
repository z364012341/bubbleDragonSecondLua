--
-- Author: 黄泽昊
-- 作用: 选择pageview

local DecalsExhibitionPageView = class("DecalsExhibitionPageView", function (decals_type)
    return cc.Node:create();
end)
local PAGEVIEW_CONTENT_SIZE = cc.size(425, 664);
local DecalsExhibitionBackground = require(DECALS_EXHIBITION_BACKGROUND_PATH);
local PuzzleSelectedPageViewPoint = require(PUZZLE_SELECTED_PAGEVIEW_POINT_PATH);
function DecalsExhibitionPageView:ctor(decals_type)
    -- local function onNodeEvent(event)
    --     if event == "enter" then
    --         self:onEnter();
    --     elseif event == "exit" then
    --         self:onExit();
    --     end
    -- end
    self.decals_type_ = decals_type;
    self:init();
end
function DecalsExhibitionPageView:init()
    local pageview= ccui.PageView:create();

    pageview:setContentSize(PAGEVIEW_CONTENT_SIZE);
    local decalsData = bs.UserDataManager:getInstance():getDecalsData(self.decals_type_);
    local charactorData = bs.DecalsFactory:getInstance():getDecalsDataWithType(self.decals_type_);
    -- if self.decals_type_ == DECALS_TYPE_CHARACTOR then
    --     decalsData = bs.UserDataManager:getInstance():getCharactorDecalsData();
    --     charactorData = bs.DecalsFactory:getInstance():getDecalsCharactorData();
    -- else
    --     decalsData = bs.UserDataManager:getInstance():getTreasureDecalsData();
    --     charactorData = bs.DecalsFactory:getInstance():getDecalsTreasureData();
    -- end


    self:addPageViewPoints(#charactorData);
    for i,v in ipairs(charactorData) do
        pageview:addPage(self:createPageWithData(v.x, v.y, decalsData[i]));
    end
    pageview:setCurrentPageIndex(0);
    pageview:setPosition(cc.p(pageview:getContentSize().width/-2, pageview:getContentSize().height/-3));
    self.pageview_ = pageview;
    self:addChild(self.pageview_);
end
function DecalsExhibitionPageView:addPageViewPoints(numble)
    self.pageview_points = PuzzleSelectedPageViewPoint:create(numble);
    self.pageview_points:setPointMoveDelayTime(0);
    self.pageview_points:setPosition(cc.p(0, -460));
    self:addChild(self.pageview_points);
end
function DecalsExhibitionPageView:createPageWithData(x, y, table_data)
    local layout = ccui.Layout:create();
    layout:setContentSize(PAGEVIEW_CONTENT_SIZE);
    local bg = DecalsExhibitionBackground:create(x, y, self.decals_type_);
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
    self:updataPageViewPointsIndex();
end
function DecalsExhibitionPageView:scrollRight()
    self.pageview_:setCurrentPageIndex(self.pageview_:getCurrentPageIndex()+1);
    self:updataPageViewPointsIndex();
end
function DecalsExhibitionPageView:updataPageViewPointsIndex()
    self.pageview_points:scrollToPage(self.pageview_);
end
function DecalsExhibitionPageView:getCurrentPageIndex()
    return self.pageview_:getCurrentPageIndex();
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