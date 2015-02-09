
cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")

require "config"
require "cocos.init"

local function hello()
    local args = {}
    local sigs = "()V"
    local luaj = require "cocos.cocos2d.luaj"
    local className = "org/cocos2dx/lua/AppActivity"
    local ok,ret  = luaj.callStaticMethod(className,"hello",args,sigs)
    if ok then
        return ret
    end
end

local function main()
    require("app.MyApp"):create():run()
    hello()
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
