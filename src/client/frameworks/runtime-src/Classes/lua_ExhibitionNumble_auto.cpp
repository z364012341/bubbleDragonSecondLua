#include "lua_ExhibitionNumble_auto.hpp"
#include "ExhibitionNumble.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_ExhibitionNumble_ExhibitionNumble_setString(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::ExhibitionNumble* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.ExhibitionNumble",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::ExhibitionNumble*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ExhibitionNumble_ExhibitionNumble_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.ExhibitionNumble:setString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ExhibitionNumble_ExhibitionNumble_setString'", nullptr);
            return 0;
        }
        cobj->setString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.ExhibitionNumble:setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ExhibitionNumble_ExhibitionNumble_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_ExhibitionNumble_ExhibitionNumble_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.ExhibitionNumble",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ExhibitionNumble_ExhibitionNumble_create'", nullptr);
            return 0;
        }
        bubble_second::ExhibitionNumble* ret = bubble_second::ExhibitionNumble::create();
        object_to_luaval<bubble_second::ExhibitionNumble>(tolua_S, "bs.ExhibitionNumble",(bubble_second::ExhibitionNumble*)ret);
        return 1;
    }
    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.ExhibitionNumble:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ExhibitionNumble_ExhibitionNumble_create'", nullptr);
            return 0;
        }
        bubble_second::ExhibitionNumble* ret = bubble_second::ExhibitionNumble::create(arg0);
        object_to_luaval<bubble_second::ExhibitionNumble>(tolua_S, "bs.ExhibitionNumble",(bubble_second::ExhibitionNumble*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.ExhibitionNumble:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ExhibitionNumble_ExhibitionNumble_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_ExhibitionNumble_ExhibitionNumble_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ExhibitionNumble)");
    return 0;
}

int lua_register_ExhibitionNumble_ExhibitionNumble(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.ExhibitionNumble");
    tolua_cclass(tolua_S,"ExhibitionNumble","bs.ExhibitionNumble","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"ExhibitionNumble");
        tolua_function(tolua_S,"setString",lua_ExhibitionNumble_ExhibitionNumble_setString);
        tolua_function(tolua_S,"create", lua_ExhibitionNumble_ExhibitionNumble_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::ExhibitionNumble).name();
    g_luaType[typeName] = "bs.ExhibitionNumble";
    g_typeCast["ExhibitionNumble"] = "bs.ExhibitionNumble";
    return 1;
}
TOLUA_API int register_all_ExhibitionNumble(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_ExhibitionNumble_ExhibitionNumble(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

