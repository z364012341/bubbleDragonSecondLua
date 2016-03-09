--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 

local PuzzlePlayScene = class("PuzzlePlayScene", function ()
    return cc.Layer:create();
end)

function PuzzlePlayScene:ctor()
    printf("PuzzlePlayScene");
    local collection = require(PUZZLE_PIECES_COLLECTION_PATH):create("puzzle_1.png")
    local puzzleNode = collection:getPuzzleNode();
    puzzleNode:setPosition(300, 300);
    self:addChild(puzzleNode);

    local answerNode = collection:getAnswerNode();
    answerNode:setPosition(0, 300);
    self:addChild(answerNode, -1);
    self:addBackMenu();
--[[
    local clippingNode = require(PUZZLE_PIECE_PATH):create({
        index_x = 1, --拼图碎片的x索引
        index_y = 2, --拼图碎片的y索引
        path = "puzzle_1.png",    --底板的资源路径
        left = PUZZLE_STENCIL_COMPONENT_INSIDE,    --左边凹凸方向
        right = PUZZLE_STENCIL_COMPONENT_OUTSIDE,   --右边凹凸方向
        top = PUZZLE_STENCIL_COMPONENT_PLAIN,     --上边凹凸方向
        bottom = PUZZLE_STENCIL_COMPONENT_PLAIN  --下边凹凸方向
    });
    clippingNode:setPosition(300, 300);
    self:addChild(clippingNode);
--]]
end

function PuzzlePlayScene:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzlePlayScene:create()
    scene:addChild(layer)
    return scene
end

function PuzzlePlayScene:addBackMenu()
    local item = cc.MenuItemSprite:create(cc.Sprite:create("001.png"), cc.Sprite:create("001.png"));
    item:registerScriptTapHandler(function (event)
       cc.Director:getInstance():replaceScene(bs.GameStageSelectionScene:createScene());
    end);
    local menu = cc.Menu:create();
    menu:addChild(item);
    menu:setPosition(0, 0);
    self:addChild(menu);
end
return PuzzlePlayScene