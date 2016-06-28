#include "lua_GameBuyStoreMannager_auto.hpp"
#include "GameBuyStoreMannager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameBuyStoreMannager_GameBuyStoreMannager_buyProps(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameBuyStoreMannager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameBuyStoreMannager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameBuyStoreMannager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_buyProps'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.GameBuyStoreMannager:buyProps");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_buyProps'", nullptr);
            return 0;
        }
        cobj->buyProps(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameBuyStoreMannager:buyProps",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_buyProps'.",&tolua_err);
#endif

    return 0;
}
int lua_GameBuyStoreMannager_GameBuyStoreMannager_isBuyPuzzleNewbiwGift(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameBuyStoreMannager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameBuyStoreMannager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameBuyStoreMannager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_isBuyPuzzleNewbiwGift'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_isBuyPuzzleNewbiwGift'", nullptr);
            return 0;
        }
        bool ret = cobj->isBuyPuzzleNewbiwGift();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameBuyStoreMannager:isBuyPuzzleNewbiwGift",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_isBuyPuzzleNewbiwGift'.",&tolua_err);
#endif

    return 0;
}
int lua_GameBuyStoreMannager_GameBuyStoreMannager_getRandomLotteryAwardWihtoutDecals(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameBuyStoreMannager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_getRandomLotteryAwardWihtoutDecals'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = bubble_second::GameBuyStoreMannager::getRandomLotteryAwardWihtoutDecals();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameBuyStoreMannager:getRandomLotteryAwardWihtoutDecals",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_getRandomLotteryAwardWihtoutDecals'.",&tolua_err);
#endif
    return 0;
}
int lua_GameBuyStoreMannager_GameBuyStoreMannager_getRandomLotteryAwardIncludeCharactorDecals(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameBuyStoreMannager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_getRandomLotteryAwardIncludeCharactorDecals'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = bubble_second::GameBuyStoreMannager::getRandomLotteryAwardIncludeCharactorDecals();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameBuyStoreMannager:getRandomLotteryAwardIncludeCharactorDecals",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_getRandomLotteryAwardIncludeCharactorDecals'.",&tolua_err);
#endif
    return 0;
}
int lua_GameBuyStoreMannager_GameBuyStoreMannager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameBuyStoreMannager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_getInstance'", nullptr);
            return 0;
        }
        bubble_second::GameBuyStoreMannager* ret = bubble_second::GameBuyStoreMannager::getInstance();
        object_to_luaval<bubble_second::GameBuyStoreMannager>(tolua_S, "bs.GameBuyStoreMannager",(bubble_second::GameBuyStoreMannager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameBuyStoreMannager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameBuyStoreMannager_GameBuyStoreMannager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_GameBuyStoreMannager_GameBuyStoreMannager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameBuyStoreMannager)");
    return 0;
}

int lua_register_GameBuyStoreMannager_GameBuyStoreMannager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameBuyStoreMannager");
    tolua_cclass(tolua_S,"GameBuyStoreMannager","bs.GameBuyStoreMannager","",nullptr);

    tolua_beginmodule(tolua_S,"GameBuyStoreMannager");
        tolua_function(tolua_S,"buyProps",lua_GameBuyStoreMannager_GameBuyStoreMannager_buyProps);
        tolua_function(tolua_S,"isBuyPuzzleNewbiwGift",lua_GameBuyStoreMannager_GameBuyStoreMannager_isBuyPuzzleNewbiwGift);
        tolua_function(tolua_S,"getRandomLotteryAwardWihtoutDecals", lua_GameBuyStoreMannager_GameBuyStoreMannager_getRandomLotteryAwardWihtoutDecals);
        tolua_function(tolua_S,"getRandomLotteryAwardIncludeCharactorDecals", lua_GameBuyStoreMannager_GameBuyStoreMannager_getRandomLotteryAwardIncludeCharactorDecals);
        tolua_function(tolua_S,"getInstance", lua_GameBuyStoreMannager_GameBuyStoreMannager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameBuyStoreMannager).name();
    g_luaType[typeName] = "bs.GameBuyStoreMannager";
    g_typeCast["GameBuyStoreMannager"] = "bs.GameBuyStoreMannager";
    return 1;
}
TOLUA_API int register_all_GameBuyStoreMannager(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameBuyStoreMannager_GameBuyStoreMannager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

