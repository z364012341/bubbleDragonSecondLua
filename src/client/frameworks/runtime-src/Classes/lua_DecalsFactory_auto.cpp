#include "lua_DecalsFactory_auto.hpp"
#include "DecalsFactory.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_DecalsFactory_DecalsFactory_getDecalsMaxIndexWithPath(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::DecalsFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.DecalsFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::DecalsFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DecalsFactory_DecalsFactory_getDecalsMaxIndexWithPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.DecalsFactory:getDecalsMaxIndexWithPath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DecalsFactory_DecalsFactory_getDecalsMaxIndexWithPath'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getDecalsMaxIndexWithPath(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.DecalsFactory:getDecalsMaxIndexWithPath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DecalsFactory_DecalsFactory_getDecalsMaxIndexWithPath'.",&tolua_err);
#endif

    return 0;
}
int lua_DecalsFactory_DecalsFactory_convertDecalNumbleToIndex(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::DecalsFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.DecalsFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::DecalsFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DecalsFactory_DecalsFactory_convertDecalNumbleToIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.DecalsFactory:convertDecalNumbleToIndex");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "bs.DecalsFactory:convertDecalNumbleToIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DecalsFactory_DecalsFactory_convertDecalNumbleToIndex'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->convertDecalNumbleToIndex(arg0, arg1);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.DecalsFactory:convertDecalNumbleToIndex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DecalsFactory_DecalsFactory_convertDecalNumbleToIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_DecalsFactory_DecalsFactory_getDecalsCharactorData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::DecalsFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.DecalsFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::DecalsFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DecalsFactory_DecalsFactory_getDecalsCharactorData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DecalsFactory_DecalsFactory_getDecalsCharactorData'", nullptr);
            return 0;
        }
        cocos2d::ValueVector ret = cobj->getDecalsCharactorData();
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.DecalsFactory:getDecalsCharactorData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DecalsFactory_DecalsFactory_getDecalsCharactorData'.",&tolua_err);
#endif

    return 0;
}
int lua_DecalsFactory_DecalsFactory_createDecal(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::DecalsFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.DecalsFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::DecalsFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DecalsFactory_DecalsFactory_createDecal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.DecalsFactory:createDecal");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "bs.DecalsFactory:createDecal");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "bs.DecalsFactory:createDecal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DecalsFactory_DecalsFactory_createDecal'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->createDecal(arg0, arg1, arg2);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.DecalsFactory:createDecal",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DecalsFactory_DecalsFactory_createDecal'.",&tolua_err);
#endif

    return 0;
}
int lua_DecalsFactory_DecalsFactory_loadDecalsData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::DecalsFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.DecalsFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::DecalsFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DecalsFactory_DecalsFactory_loadDecalsData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DecalsFactory_DecalsFactory_loadDecalsData'", nullptr);
            return 0;
        }
        cobj->loadDecalsData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.DecalsFactory:loadDecalsData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DecalsFactory_DecalsFactory_loadDecalsData'.",&tolua_err);
#endif

    return 0;
}
int lua_DecalsFactory_DecalsFactory_createDecalWithNumble(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::DecalsFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.DecalsFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::DecalsFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DecalsFactory_DecalsFactory_createDecalWithNumble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.DecalsFactory:createDecalWithNumble");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "bs.DecalsFactory:createDecalWithNumble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DecalsFactory_DecalsFactory_createDecalWithNumble'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->createDecalWithNumble(arg0, arg1);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.DecalsFactory:createDecalWithNumble",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DecalsFactory_DecalsFactory_createDecalWithNumble'.",&tolua_err);
#endif

    return 0;
}
int lua_DecalsFactory_DecalsFactory_getTreasureCharactorData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::DecalsFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.DecalsFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::DecalsFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DecalsFactory_DecalsFactory_getTreasureCharactorData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DecalsFactory_DecalsFactory_getTreasureCharactorData'", nullptr);
            return 0;
        }
        cocos2d::ValueVector ret = cobj->getTreasureCharactorData();
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.DecalsFactory:getTreasureCharactorData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DecalsFactory_DecalsFactory_getTreasureCharactorData'.",&tolua_err);
#endif

    return 0;
}
int lua_DecalsFactory_DecalsFactory_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.DecalsFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DecalsFactory_DecalsFactory_getInstance'", nullptr);
            return 0;
        }
        bubble_second::DecalsFactory* ret = bubble_second::DecalsFactory::getInstance();
        object_to_luaval<bubble_second::DecalsFactory>(tolua_S, "bs.DecalsFactory",(bubble_second::DecalsFactory*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.DecalsFactory:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DecalsFactory_DecalsFactory_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_DecalsFactory_DecalsFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DecalsFactory)");
    return 0;
}

int lua_register_DecalsFactory_DecalsFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.DecalsFactory");
    tolua_cclass(tolua_S,"DecalsFactory","bs.DecalsFactory","",nullptr);

    tolua_beginmodule(tolua_S,"DecalsFactory");
        tolua_function(tolua_S,"getDecalsMaxIndexWithPath",lua_DecalsFactory_DecalsFactory_getDecalsMaxIndexWithPath);
        tolua_function(tolua_S,"convertDecalNumbleToIndex",lua_DecalsFactory_DecalsFactory_convertDecalNumbleToIndex);
        tolua_function(tolua_S,"getDecalsCharactorData",lua_DecalsFactory_DecalsFactory_getDecalsCharactorData);
        tolua_function(tolua_S,"createDecal",lua_DecalsFactory_DecalsFactory_createDecal);
        tolua_function(tolua_S,"loadDecalsData",lua_DecalsFactory_DecalsFactory_loadDecalsData);
        tolua_function(tolua_S,"createDecalWithNumble",lua_DecalsFactory_DecalsFactory_createDecalWithNumble);
        tolua_function(tolua_S,"getTreasureCharactorData",lua_DecalsFactory_DecalsFactory_getTreasureCharactorData);
        tolua_function(tolua_S,"getInstance", lua_DecalsFactory_DecalsFactory_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::DecalsFactory).name();
    g_luaType[typeName] = "bs.DecalsFactory";
    g_typeCast["DecalsFactory"] = "bs.DecalsFactory";
    return 1;
}
TOLUA_API int register_all_DecalsFactory(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_DecalsFactory_DecalsFactory(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

