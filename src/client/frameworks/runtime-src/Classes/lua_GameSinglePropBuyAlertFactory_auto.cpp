#include "lua_GameSinglePropBuyAlertFactory_auto.hpp"
#include "GameSinglePropBuyAlertFactory.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_createGameSinglePropBuyAlert(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameSinglePropBuyAlertFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameSinglePropBuyAlertFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameSinglePropBuyAlertFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_createGameSinglePropBuyAlert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_createGameSinglePropBuyAlert'", nullptr);
            return 0;
        }
        bubble_second::GameSinglePropBuyAlert* ret = cobj->createGameSinglePropBuyAlert();
        object_to_luaval<bubble_second::GameSinglePropBuyAlert>(tolua_S, "bs.GameSinglePropBuyAlert",(bubble_second::GameSinglePropBuyAlert*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameSinglePropBuyAlertFactory:createGameSinglePropBuyAlert",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_createGameSinglePropBuyAlert'.",&tolua_err);
#endif

    return 0;
}
int lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_popGameSinglePropBuyAlertWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameSinglePropBuyAlertFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameSinglePropBuyAlertFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameSinglePropBuyAlertFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_popGameSinglePropBuyAlertWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.GameSinglePropBuyAlertFactory:popGameSinglePropBuyAlertWithKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_popGameSinglePropBuyAlertWithKey'", nullptr);
            return 0;
        }
        cobj->popGameSinglePropBuyAlertWithKey(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameSinglePropBuyAlertFactory:popGameSinglePropBuyAlertWithKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_popGameSinglePropBuyAlertWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameSinglePropBuyAlertFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_getInstance'", nullptr);
            return 0;
        }
        bubble_second::GameSinglePropBuyAlertFactory* ret = bubble_second::GameSinglePropBuyAlertFactory::getInstance();
        object_to_luaval<bubble_second::GameSinglePropBuyAlertFactory>(tolua_S, "bs.GameSinglePropBuyAlertFactory",(bubble_second::GameSinglePropBuyAlertFactory*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameSinglePropBuyAlertFactory:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameSinglePropBuyAlertFactory)");
    return 0;
}

int lua_register_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameSinglePropBuyAlertFactory");
    tolua_cclass(tolua_S,"GameSinglePropBuyAlertFactory","bs.GameSinglePropBuyAlertFactory","",nullptr);

    tolua_beginmodule(tolua_S,"GameSinglePropBuyAlertFactory");
        tolua_function(tolua_S,"createGameSinglePropBuyAlert",lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_createGameSinglePropBuyAlert);
        tolua_function(tolua_S,"popGameSinglePropBuyAlertWithKey",lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_popGameSinglePropBuyAlertWithKey);
        tolua_function(tolua_S,"getInstance", lua_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameSinglePropBuyAlertFactory).name();
    g_luaType[typeName] = "bs.GameSinglePropBuyAlertFactory";
    g_typeCast["GameSinglePropBuyAlertFactory"] = "bs.GameSinglePropBuyAlertFactory";
    return 1;
}
TOLUA_API int register_all_GameSinglePropBuyAlertFactory(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameSinglePropBuyAlertFactory_GameSinglePropBuyAlertFactory(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

