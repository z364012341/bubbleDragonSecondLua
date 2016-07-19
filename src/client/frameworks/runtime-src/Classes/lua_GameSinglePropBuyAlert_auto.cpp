#include "lua_GameSinglePropBuyAlert_auto.hpp"
#include "GameSinglePropBuyAlert.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameSinglePropBuyAlert_GameSinglePropBuyAlert_createWithPropKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameSinglePropBuyAlert",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.GameSinglePropBuyAlert:createWithPropKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameSinglePropBuyAlert_GameSinglePropBuyAlert_createWithPropKey'", nullptr);
            return 0;
        }
        bubble_second::GameSinglePropBuyAlert* ret = bubble_second::GameSinglePropBuyAlert::createWithPropKey(arg0);
        object_to_luaval<bubble_second::GameSinglePropBuyAlert>(tolua_S, "bs.GameSinglePropBuyAlert",(bubble_second::GameSinglePropBuyAlert*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameSinglePropBuyAlert:createWithPropKey",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameSinglePropBuyAlert_GameSinglePropBuyAlert_createWithPropKey'.",&tolua_err);
#endif
    return 0;
}
static int lua_GameSinglePropBuyAlert_GameSinglePropBuyAlert_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameSinglePropBuyAlert)");
    return 0;
}

int lua_register_GameSinglePropBuyAlert_GameSinglePropBuyAlert(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameSinglePropBuyAlert");
    tolua_cclass(tolua_S,"GameSinglePropBuyAlert","bs.GameSinglePropBuyAlert","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GameSinglePropBuyAlert");
        tolua_function(tolua_S,"createWithPropKey", lua_GameSinglePropBuyAlert_GameSinglePropBuyAlert_createWithPropKey);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameSinglePropBuyAlert).name();
    g_luaType[typeName] = "bs.GameSinglePropBuyAlert";
    g_typeCast["GameSinglePropBuyAlert"] = "bs.GameSinglePropBuyAlert";
    return 1;
}
TOLUA_API int register_all_GameSinglePropBuyAlert(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameSinglePropBuyAlert_GameSinglePropBuyAlert(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

