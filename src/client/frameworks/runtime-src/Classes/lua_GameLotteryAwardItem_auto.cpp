#include "lua_GameLotteryAwardItem_auto.hpp"
#include "GameLotteryAwardItem.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameLotteryAwardItem_GameLotteryAwardItem_getAwardSprite(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameLotteryAwardItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameLotteryAwardItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameLotteryAwardItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameLotteryAwardItem_GameLotteryAwardItem_getAwardSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameLotteryAwardItem_GameLotteryAwardItem_getAwardSprite'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getAwardSprite();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameLotteryAwardItem:getAwardSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameLotteryAwardItem_GameLotteryAwardItem_getAwardSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_GameLotteryAwardItem_GameLotteryAwardItem_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameLotteryAwardItem",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.GameLotteryAwardItem:create");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "bs.GameLotteryAwardItem:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameLotteryAwardItem_GameLotteryAwardItem_create'", nullptr);
            return 0;
        }
        bubble_second::GameLotteryAwardItem* ret = bubble_second::GameLotteryAwardItem::create(arg0, arg1);
        object_to_luaval<bubble_second::GameLotteryAwardItem>(tolua_S, "bs.GameLotteryAwardItem",(bubble_second::GameLotteryAwardItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameLotteryAwardItem:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameLotteryAwardItem_GameLotteryAwardItem_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_GameLotteryAwardItem_GameLotteryAwardItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameLotteryAwardItem)");
    return 0;
}

int lua_register_GameLotteryAwardItem_GameLotteryAwardItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameLotteryAwardItem");
    tolua_cclass(tolua_S,"GameLotteryAwardItem","bs.GameLotteryAwardItem","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GameLotteryAwardItem");
        tolua_function(tolua_S,"getAwardSprite",lua_GameLotteryAwardItem_GameLotteryAwardItem_getAwardSprite);
        tolua_function(tolua_S,"create", lua_GameLotteryAwardItem_GameLotteryAwardItem_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameLotteryAwardItem).name();
    g_luaType[typeName] = "bs.GameLotteryAwardItem";
    g_typeCast["GameLotteryAwardItem"] = "bs.GameLotteryAwardItem";
    return 1;
}
TOLUA_API int register_all_GameLotteryAwardItem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameLotteryAwardItem_GameLotteryAwardItem(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

