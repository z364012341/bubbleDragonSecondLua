#include "lua_GamePropsCostTag_auto.hpp"
#include "GamePropsCostTag.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GamePropsCostTag_GamePropsCostTag_canPay(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GamePropsCostTag* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GamePropsCostTag",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GamePropsCostTag*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GamePropsCostTag_GamePropsCostTag_canPay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GamePropsCostTag_GamePropsCostTag_canPay'", nullptr);
            return 0;
        }
        bool ret = cobj->canPay();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GamePropsCostTag:canPay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GamePropsCostTag_GamePropsCostTag_canPay'.",&tolua_err);
#endif

    return 0;
}
int lua_GamePropsCostTag_GamePropsCostTag_pay(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GamePropsCostTag* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GamePropsCostTag",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GamePropsCostTag*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GamePropsCostTag_GamePropsCostTag_pay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GamePropsCostTag_GamePropsCostTag_pay'", nullptr);
            return 0;
        }
        cobj->pay();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GamePropsCostTag:pay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GamePropsCostTag_GamePropsCostTag_pay'.",&tolua_err);
#endif

    return 0;
}
int lua_GamePropsCostTag_GamePropsCostTag_getSelectedState(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GamePropsCostTag* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GamePropsCostTag",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GamePropsCostTag*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GamePropsCostTag_GamePropsCostTag_getSelectedState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GamePropsCostTag_GamePropsCostTag_getSelectedState'", nullptr);
            return 0;
        }
        bool ret = cobj->getSelectedState();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GamePropsCostTag:getSelectedState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GamePropsCostTag_GamePropsCostTag_getSelectedState'.",&tolua_err);
#endif

    return 0;
}
int lua_GamePropsCostTag_GamePropsCostTag_changeSelectedState(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GamePropsCostTag* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GamePropsCostTag",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GamePropsCostTag*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GamePropsCostTag_GamePropsCostTag_changeSelectedState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GamePropsCostTag_GamePropsCostTag_changeSelectedState'", nullptr);
            return 0;
        }
        cobj->changeSelectedState();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GamePropsCostTag:changeSelectedState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GamePropsCostTag_GamePropsCostTag_changeSelectedState'.",&tolua_err);
#endif

    return 0;
}
int lua_GamePropsCostTag_GamePropsCostTag_createDecalsLotteryContinueTag(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GamePropsCostTag",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GamePropsCostTag_GamePropsCostTag_createDecalsLotteryContinueTag'", nullptr);
            return 0;
        }
        bubble_second::GamePropsCostTag* ret = bubble_second::GamePropsCostTag::createDecalsLotteryContinueTag();
        object_to_luaval<bubble_second::GamePropsCostTag>(tolua_S, "bs.GamePropsCostTag",(bubble_second::GamePropsCostTag*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GamePropsCostTag:createDecalsLotteryContinueTag",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GamePropsCostTag_GamePropsCostTag_createDecalsLotteryContinueTag'.",&tolua_err);
#endif
    return 0;
}
int lua_GamePropsCostTag_GamePropsCostTag_createWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GamePropsCostTag",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.GamePropsCostTag:createWithKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GamePropsCostTag_GamePropsCostTag_createWithKey'", nullptr);
            return 0;
        }
        bubble_second::GamePropsCostTag* ret = bubble_second::GamePropsCostTag::createWithKey(arg0);
        object_to_luaval<bubble_second::GamePropsCostTag>(tolua_S, "bs.GamePropsCostTag",(bubble_second::GamePropsCostTag*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GamePropsCostTag:createWithKey",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GamePropsCostTag_GamePropsCostTag_createWithKey'.",&tolua_err);
#endif
    return 0;
}
int lua_GamePropsCostTag_GamePropsCostTag_createDecalsLotteryBeginTag(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GamePropsCostTag",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GamePropsCostTag_GamePropsCostTag_createDecalsLotteryBeginTag'", nullptr);
            return 0;
        }
        bubble_second::GamePropsCostTag* ret = bubble_second::GamePropsCostTag::createDecalsLotteryBeginTag();
        object_to_luaval<bubble_second::GamePropsCostTag>(tolua_S, "bs.GamePropsCostTag",(bubble_second::GamePropsCostTag*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GamePropsCostTag:createDecalsLotteryBeginTag",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GamePropsCostTag_GamePropsCostTag_createDecalsLotteryBeginTag'.",&tolua_err);
#endif
    return 0;
}
int lua_GamePropsCostTag_GamePropsCostTag_constructor(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GamePropsCostTag* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GamePropsCostTag_GamePropsCostTag_constructor'", nullptr);
            return 0;
        }
        cobj = new bubble_second::GamePropsCostTag();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"bs.GamePropsCostTag");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GamePropsCostTag:GamePropsCostTag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_GamePropsCostTag_GamePropsCostTag_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_GamePropsCostTag_GamePropsCostTag_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GamePropsCostTag)");
    return 0;
}

int lua_register_GamePropsCostTag_GamePropsCostTag(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GamePropsCostTag");
    tolua_cclass(tolua_S,"GamePropsCostTag","bs.GamePropsCostTag","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GamePropsCostTag");
        tolua_function(tolua_S,"new",lua_GamePropsCostTag_GamePropsCostTag_constructor);
        tolua_function(tolua_S,"canPay",lua_GamePropsCostTag_GamePropsCostTag_canPay);
        tolua_function(tolua_S,"pay",lua_GamePropsCostTag_GamePropsCostTag_pay);
        tolua_function(tolua_S,"getSelectedState",lua_GamePropsCostTag_GamePropsCostTag_getSelectedState);
        tolua_function(tolua_S,"changeSelectedState",lua_GamePropsCostTag_GamePropsCostTag_changeSelectedState);
        tolua_function(tolua_S,"createDecalsLotteryContinueTag", lua_GamePropsCostTag_GamePropsCostTag_createDecalsLotteryContinueTag);
        tolua_function(tolua_S,"createWithKey", lua_GamePropsCostTag_GamePropsCostTag_createWithKey);
        tolua_function(tolua_S,"createDecalsLotteryBeginTag", lua_GamePropsCostTag_GamePropsCostTag_createDecalsLotteryBeginTag);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GamePropsCostTag).name();
    g_luaType[typeName] = "bs.GamePropsCostTag";
    g_typeCast["GamePropsCostTag"] = "bs.GamePropsCostTag";
    return 1;
}
TOLUA_API int register_all_GamePropsCostTag(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GamePropsCostTag_GamePropsCostTag(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

