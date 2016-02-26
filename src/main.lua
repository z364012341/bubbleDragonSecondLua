
cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")
cc.FileUtils:getInstance():addSearchPath("res/ui/", false);
cc.FileUtils:getInstance():addSearchPath("res/ui/daochu/", false);

require "config"
require "cocos.init"


print("111111111111111111111111111111111111111111111111111111111111")

local function main()
    --require("app.MyApp"):create():run()
    --local hello = bs.LoadingScene:createScene()
    --sceneGame:addChild(hello)
    --release_print(bubble_second);
    local sceneGame = bs.LoadingScene:createScene();
    cc.Director:getInstance():runWithScene(sceneGame);
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
