#include "lua_UserCoinInfoBoard_auto.hpp"
#include "UserCoinInfoBoard.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_UserCoinInfoBoard_UserCoinInfoBoard_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.UserCoinInfoBoard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserCoinInfoBoard_UserCoinInfoBoard_create'", nullptr);
            return 0;
        }
        bubble_second::UserCoinInfoBoard* ret = bubble_second::UserCoinInfoBoard::create();
        object_to_luaval<bubble_second::UserCoinInfoBoard>(tolua_S, "bs.UserCoinInfoBoard",(bubble_second::UserCoinInfoBoard*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.UserCoinInfoBoard:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserCoinInfoBoard_UserCoinInfoBoard_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_UserCoinInfoBoard_UserCoinInfoBoard_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UserCoinInfoBoard)");
    return 0;
}

int lua_register_UserCoinInfoBoard_UserCoinInfoBoard(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.UserCoinInfoBoard");
    tolua_cclass(tolua_S,"UserCoinInfoBoard","bs.UserCoinInfoBoard","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"UserCoinInfoBoard");
        tolua_function(tolua_S,"create", lua_UserCoinInfoBoard_UserCoinInfoBoard_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::UserCoinInfoBoard).name();
    g_luaType[typeName] = "bs.UserCoinInfoBoard";
    g_typeCast["UserCoinInfoBoard"] = "bs.UserCoinInfoBoard";
    return 1;
}
TOLUA_API int register_all_UserCoinInfoBoard(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_UserCoinInfoBoard_UserCoinInfoBoard(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

