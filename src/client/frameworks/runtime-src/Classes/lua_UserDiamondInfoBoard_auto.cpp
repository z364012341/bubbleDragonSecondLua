#include "lua_UserDiamondInfoBoard_auto.hpp"
#include "UserDiamondInfoBoard.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_UserDiamondInfoBoard_UserDiamondInfoBoard_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.UserDiamondInfoBoard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDiamondInfoBoard_UserDiamondInfoBoard_create'", nullptr);
            return 0;
        }
        bubble_second::UserDiamondInfoBoard* ret = bubble_second::UserDiamondInfoBoard::create();
        object_to_luaval<bubble_second::UserDiamondInfoBoard>(tolua_S, "bs.UserDiamondInfoBoard",(bubble_second::UserDiamondInfoBoard*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.UserDiamondInfoBoard:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDiamondInfoBoard_UserDiamondInfoBoard_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_UserDiamondInfoBoard_UserDiamondInfoBoard_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UserDiamondInfoBoard)");
    return 0;
}

int lua_register_UserDiamondInfoBoard_UserDiamondInfoBoard(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.UserDiamondInfoBoard");
    tolua_cclass(tolua_S,"UserDiamondInfoBoard","bs.UserDiamondInfoBoard","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"UserDiamondInfoBoard");
        tolua_function(tolua_S,"create", lua_UserDiamondInfoBoard_UserDiamondInfoBoard_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::UserDiamondInfoBoard).name();
    g_luaType[typeName] = "bs.UserDiamondInfoBoard";
    g_typeCast["UserDiamondInfoBoard"] = "bs.UserDiamondInfoBoard";
    return 1;
}
TOLUA_API int register_all_UserDiamondInfoBoard(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_UserDiamondInfoBoard_UserDiamondInfoBoard(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

