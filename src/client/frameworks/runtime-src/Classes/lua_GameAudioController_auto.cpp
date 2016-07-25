#include "lua_GameAudioController_auto.hpp"
#include "GameAudioController.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameAudioController_GameAudioController_playDecalsShuffleContactBorderEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playDecalsShuffleContactBorderEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playDecalsShuffleContactBorderEffect'", nullptr);
            return 0;
        }
        cobj->playDecalsShuffleContactBorderEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playDecalsShuffleContactBorderEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playDecalsShuffleContactBorderEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameTopEliminateMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameTopEliminateMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameTopEliminateMusic'", nullptr);
            return 0;
        }
        cobj->playGameTopEliminateMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameTopEliminateMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameTopEliminateMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_setBackgroundMusicEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_setBackgroundMusicEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "bs.GameAudioController:setBackgroundMusicEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_setBackgroundMusicEnabled'", nullptr);
            return 0;
        }
        cobj->setBackgroundMusicEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:setBackgroundMusicEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_setBackgroundMusicEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameVictoryLotteryEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryEffect'", nullptr);
            return 0;
        }
        cobj->playGameVictoryLotteryEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameVictoryLotteryEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameStageCellSecondMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameStageCellSecondMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameStageCellSecondMusic'", nullptr);
            return 0;
        }
        cobj->playGameStageCellSecondMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameStageCellSecondMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameStageCellSecondMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameStageCellFirstMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameStageCellFirstMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameStageCellFirstMusic'", nullptr);
            return 0;
        }
        cobj->playGameStageCellFirstMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameStageCellFirstMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameStageCellFirstMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playPuzzleFindAnswerEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playPuzzleFindAnswerEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playPuzzleFindAnswerEffect'", nullptr);
            return 0;
        }
        cobj->playPuzzleFindAnswerEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playPuzzleFindAnswerEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playPuzzleFindAnswerEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameCompletedTaskFlyEndEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameCompletedTaskFlyEndEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameCompletedTaskFlyEndEffect'", nullptr);
            return 0;
        }
        cobj->playGameCompletedTaskFlyEndEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameCompletedTaskFlyEndEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameCompletedTaskFlyEndEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playSkillColorBombBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playSkillColorBombBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playSkillColorBombBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playSkillColorBombBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playSkillColorBombBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playSkillColorBombBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playContactAddBubbleNumbleBubbleEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playContactAddBubbleNumbleBubbleEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playContactAddBubbleNumbleBubbleEffect'", nullptr);
            return 0;
        }
        cobj->playContactAddBubbleNumbleBubbleEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playContactAddBubbleNumbleBubbleEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playContactAddBubbleNumbleBubbleEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameRescueAnimalMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameRescueAnimalMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameRescueAnimalMusic'", nullptr);
            return 0;
        }
        cobj->playGameRescueAnimalMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameRescueAnimalMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameRescueAnimalMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameVictoryLotteryGiftPopEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryGiftPopEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryGiftPopEffect'", nullptr);
            return 0;
        }
        cobj->playGameVictoryLotteryGiftPopEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameVictoryLotteryGiftPopEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryGiftPopEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playStageCellBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playStageCellBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.GameAudioController:playStageCellBackgroundMusic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playStageCellBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->playStageCellBackgroundMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playStageCellBackgroundMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playStageCellBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playContactScoreWidgetEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playContactScoreWidgetEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playContactScoreWidgetEffect'", nullptr);
            return 0;
        }
        cobj->playContactScoreWidgetEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playContactScoreWidgetEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playContactScoreWidgetEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_loadAudioFile(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_loadAudioFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_loadAudioFile'", nullptr);
            return 0;
        }
        cobj->loadAudioFile();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:loadAudioFile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_loadAudioFile'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playAddTenBubblePropUsedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playAddTenBubblePropUsedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playAddTenBubblePropUsedEffect'", nullptr);
            return 0;
        }
        cobj->playAddTenBubblePropUsedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playAddTenBubblePropUsedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playAddTenBubblePropUsedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGamePuzzleSelectedSceneMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGamePuzzleSelectedSceneMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGamePuzzleSelectedSceneMusic'", nullptr);
            return 0;
        }
        cobj->playGamePuzzleSelectedSceneMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGamePuzzleSelectedSceneMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGamePuzzleSelectedSceneMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playPuzzleUsedSearchPropEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedSearchPropEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedSearchPropEffect'", nullptr);
            return 0;
        }
        cobj->playPuzzleUsedSearchPropEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playPuzzleUsedSearchPropEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedSearchPropEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playEnterPropsAnimationEndEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playEnterPropsAnimationEndEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playEnterPropsAnimationEndEffect'", nullptr);
            return 0;
        }
        cobj->playEnterPropsAnimationEndEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playEnterPropsAnimationEndEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playEnterPropsAnimationEndEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playColorBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playColorBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playColorBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playColorBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playColorBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playColorBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameWindmillMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameWindmillMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameWindmillMusic'", nullptr);
            return 0;
        }
        cobj->playGameWindmillMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameWindmillMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameWindmillMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playPuzzleVictoryGiftPopEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playPuzzleVictoryGiftPopEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playPuzzleVictoryGiftPopEffect'", nullptr);
            return 0;
        }
        cobj->playPuzzleVictoryGiftPopEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playPuzzleVictoryGiftPopEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playPuzzleVictoryGiftPopEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartPopEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartPopEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartPopEffect'", nullptr);
            return 0;
        }
        cobj->playGameVictoryLotteryStartPopEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameVictoryLotteryStartPopEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartPopEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playContactRainbowsealBubbleEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playContactRainbowsealBubbleEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playContactRainbowsealBubbleEffect'", nullptr);
            return 0;
        }
        cobj->playContactRainbowsealBubbleEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playContactRainbowsealBubbleEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playContactRainbowsealBubbleEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playSkillStavesBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playSkillStavesBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playSkillStavesBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playSkillStavesBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playSkillStavesBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playSkillStavesBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playDecalsSelectedCardEndEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playDecalsSelectedCardEndEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playDecalsSelectedCardEndEffect'", nullptr);
            return 0;
        }
        cobj->playDecalsSelectedCardEndEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playDecalsSelectedCardEndEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playDecalsSelectedCardEndEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameVictoryStartTurnOnEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameVictoryStartTurnOnEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameVictoryStartTurnOnEffect'", nullptr);
            return 0;
        }
        cobj->playGameVictoryStartTurnOnEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameVictoryStartTurnOnEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameVictoryStartTurnOnEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playPuzzleVictoryEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playPuzzleVictoryEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playPuzzleVictoryEffect'", nullptr);
            return 0;
        }
        cobj->playPuzzleVictoryEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playPuzzleVictoryEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playPuzzleVictoryEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartFlyEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartFlyEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartFlyEffect'", nullptr);
            return 0;
        }
        cobj->playGameVictoryLotteryStartFlyEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameVictoryLotteryStartFlyEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartFlyEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playStageUnlockEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playStageUnlockEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playStageUnlockEffect'", nullptr);
            return 0;
        }
        cobj->playStageUnlockEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playStageUnlockEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playStageUnlockEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playRainbowsealBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playRainbowsealBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playRainbowsealBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playRainbowsealBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playRainbowsealBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playRainbowsealBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameWoodenhammerAttackEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameWoodenhammerAttackEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameWoodenhammerAttackEffect'", nullptr);
            return 0;
        }
        cobj->playGameWoodenhammerAttackEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameWoodenhammerAttackEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameWoodenhammerAttackEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playBombBombBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playBombBombBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playBombBombBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playBombBombBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playBombBombBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playBombBombBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playPuzzleUsedAddTimePropEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedAddTimePropEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedAddTimePropEffect'", nullptr);
            return 0;
        }
        cobj->playPuzzleUsedAddTimePropEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playPuzzleUsedAddTimePropEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedAddTimePropEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playPropBigBombBombBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playPropBigBombBombBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playPropBigBombBombBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playPropBigBombBombBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playPropBigBombBombBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playPropBigBombBombBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playPuzzleUsedBigEyesPropEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedBigEyesPropEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedBigEyesPropEffect'", nullptr);
            return 0;
        }
        cobj->playPuzzleUsedBigEyesPropEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playPuzzleUsedBigEyesPropEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playPuzzleUsedBigEyesPropEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playStageButtonEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playStageButtonEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playStageButtonEffect'", nullptr);
            return 0;
        }
        cobj->playStageButtonEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playStageButtonEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playStageButtonEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGamePuzzlePlaySceneMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGamePuzzlePlaySceneMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGamePuzzlePlaySceneMusic'", nullptr);
            return 0;
        }
        cobj->playGamePuzzlePlaySceneMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGamePuzzlePlaySceneMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGamePuzzlePlaySceneMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playDecalsChangeCardStateEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playDecalsChangeCardStateEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playDecalsChangeCardStateEffect'", nullptr);
            return 0;
        }
        cobj->playDecalsChangeCardStateEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playDecalsChangeCardStateEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playDecalsChangeCardStateEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameDestroyRainbowsealMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameDestroyRainbowsealMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameDestroyRainbowsealMusic'", nullptr);
            return 0;
        }
        cobj->playGameDestroyRainbowsealMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameDestroyRainbowsealMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameDestroyRainbowsealMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameStartEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameStartEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameStartEffect'", nullptr);
            return 0;
        }
        cobj->playGameStartEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameStartEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameStartEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playContactBarrelBottomEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playContactBarrelBottomEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playContactBarrelBottomEffect'", nullptr);
            return 0;
        }
        cobj->playContactBarrelBottomEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playContactBarrelBottomEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playContactBarrelBottomEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameLaunchMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameLaunchMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameLaunchMusic'", nullptr);
            return 0;
        }
        cobj->playGameLaunchMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameLaunchMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameLaunchMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playContactBarrelHeadEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playContactBarrelHeadEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playContactBarrelHeadEffect'", nullptr);
            return 0;
        }
        cobj->playContactBarrelHeadEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playContactBarrelHeadEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playContactBarrelHeadEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playContactBlackHoleBubbleEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playContactBlackHoleBubbleEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playContactBlackHoleBubbleEffect'", nullptr);
            return 0;
        }
        cobj->playContactBlackHoleBubbleEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playContactBlackHoleBubbleEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playContactBlackHoleBubbleEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playMutiplesealBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playMutiplesealBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playMutiplesealBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playMutiplesealBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playMutiplesealBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playMutiplesealBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameStageCellThirdMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameStageCellThirdMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameStageCellThirdMusic'", nullptr);
            return 0;
        }
        cobj->playGameStageCellThirdMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameStageCellThirdMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameStageCellThirdMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playStageTypeBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playStageTypeBackgroundMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        StageType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.GameAudioController:playStageTypeBackgroundMusic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playStageTypeBackgroundMusic'", nullptr);
            return 0;
        }
        cobj->playStageTypeBackgroundMusic(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playStageTypeBackgroundMusic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playStageTypeBackgroundMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playAimingLinePropUsedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playAimingLinePropUsedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playAimingLinePropUsedEffect'", nullptr);
            return 0;
        }
        cobj->playAimingLinePropUsedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playAimingLinePropUsedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playAimingLinePropUsedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playDarkCloudBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playDarkCloudBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playDarkCloudBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playDarkCloudBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playDarkCloudBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playDarkCloudBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playSkillDyingBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playSkillDyingBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playSkillDyingBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playSkillDyingBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playSkillDyingBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playSkillDyingBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playAddSpecialPropUsedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playAddSpecialPropUsedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playAddSpecialPropUsedEffect'", nullptr);
            return 0;
        }
        cobj->playAddSpecialPropUsedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playAddSpecialPropUsedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playAddSpecialPropUsedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playPropColorBombBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playPropColorBombBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playPropColorBombBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playPropColorBombBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playPropColorBombBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playPropColorBombBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playSkillBigBombBombBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playSkillBigBombBombBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playSkillBigBombBombBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playSkillBigBombBombBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playSkillBigBombBombBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playSkillBigBombBombBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playLightningBubbleEliminatedEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playLightningBubbleEliminatedEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playLightningBubbleEliminatedEffect'", nullptr);
            return 0;
        }
        cobj->playLightningBubbleEliminatedEffect();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playLightningBubbleEliminatedEffect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playLightningBubbleEliminatedEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_playGameStageCellFourthMusic(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAudioController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAudioController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAudioController_GameAudioController_playGameStageCellFourthMusic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_playGameStageCellFourthMusic'", nullptr);
            return 0;
        }
        cobj->playGameStageCellFourthMusic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAudioController:playGameStageCellFourthMusic",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_playGameStageCellFourthMusic'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAudioController_GameAudioController_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameAudioController",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAudioController_GameAudioController_getInstance'", nullptr);
            return 0;
        }
        bubble_second::GameAudioController* ret = bubble_second::GameAudioController::getInstance();
        object_to_luaval<bubble_second::GameAudioController>(tolua_S, "bs.GameAudioController",(bubble_second::GameAudioController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameAudioController:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAudioController_GameAudioController_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_GameAudioController_GameAudioController_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameAudioController)");
    return 0;
}

int lua_register_GameAudioController_GameAudioController(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameAudioController");
    tolua_cclass(tolua_S,"GameAudioController","bs.GameAudioController","",nullptr);

    tolua_beginmodule(tolua_S,"GameAudioController");
        tolua_function(tolua_S,"playDecalsShuffleContactBorderEffect",lua_GameAudioController_GameAudioController_playDecalsShuffleContactBorderEffect);
        tolua_function(tolua_S,"playGameTopEliminateMusic",lua_GameAudioController_GameAudioController_playGameTopEliminateMusic);
        tolua_function(tolua_S,"setBackgroundMusicEnabled",lua_GameAudioController_GameAudioController_setBackgroundMusicEnabled);
        tolua_function(tolua_S,"playGameVictoryLotteryEffect",lua_GameAudioController_GameAudioController_playGameVictoryLotteryEffect);
        tolua_function(tolua_S,"playGameStageCellSecondMusic",lua_GameAudioController_GameAudioController_playGameStageCellSecondMusic);
        tolua_function(tolua_S,"playGameStageCellFirstMusic",lua_GameAudioController_GameAudioController_playGameStageCellFirstMusic);
        tolua_function(tolua_S,"playPuzzleFindAnswerEffect",lua_GameAudioController_GameAudioController_playPuzzleFindAnswerEffect);
        tolua_function(tolua_S,"playGameCompletedTaskFlyEndEffect",lua_GameAudioController_GameAudioController_playGameCompletedTaskFlyEndEffect);
        tolua_function(tolua_S,"playSkillColorBombBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playSkillColorBombBubbleEliminatedEffect);
        tolua_function(tolua_S,"playContactAddBubbleNumbleBubbleEffect",lua_GameAudioController_GameAudioController_playContactAddBubbleNumbleBubbleEffect);
        tolua_function(tolua_S,"playGameRescueAnimalMusic",lua_GameAudioController_GameAudioController_playGameRescueAnimalMusic);
        tolua_function(tolua_S,"playGameVictoryLotteryGiftPopEffect",lua_GameAudioController_GameAudioController_playGameVictoryLotteryGiftPopEffect);
        tolua_function(tolua_S,"playStageCellBackgroundMusic",lua_GameAudioController_GameAudioController_playStageCellBackgroundMusic);
        tolua_function(tolua_S,"playContactScoreWidgetEffect",lua_GameAudioController_GameAudioController_playContactScoreWidgetEffect);
        tolua_function(tolua_S,"loadAudioFile",lua_GameAudioController_GameAudioController_loadAudioFile);
        tolua_function(tolua_S,"playAddTenBubblePropUsedEffect",lua_GameAudioController_GameAudioController_playAddTenBubblePropUsedEffect);
        tolua_function(tolua_S,"playGamePuzzleSelectedSceneMusic",lua_GameAudioController_GameAudioController_playGamePuzzleSelectedSceneMusic);
        tolua_function(tolua_S,"playPuzzleUsedSearchPropEffect",lua_GameAudioController_GameAudioController_playPuzzleUsedSearchPropEffect);
        tolua_function(tolua_S,"playEnterPropsAnimationEndEffect",lua_GameAudioController_GameAudioController_playEnterPropsAnimationEndEffect);
        tolua_function(tolua_S,"playColorBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playColorBubbleEliminatedEffect);
        tolua_function(tolua_S,"playGameWindmillMusic",lua_GameAudioController_GameAudioController_playGameWindmillMusic);
        tolua_function(tolua_S,"playPuzzleVictoryGiftPopEffect",lua_GameAudioController_GameAudioController_playPuzzleVictoryGiftPopEffect);
        tolua_function(tolua_S,"playGameVictoryLotteryStartPopEffect",lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartPopEffect);
        tolua_function(tolua_S,"playContactRainbowsealBubbleEffect",lua_GameAudioController_GameAudioController_playContactRainbowsealBubbleEffect);
        tolua_function(tolua_S,"playSkillStavesBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playSkillStavesBubbleEliminatedEffect);
        tolua_function(tolua_S,"playDecalsSelectedCardEndEffect",lua_GameAudioController_GameAudioController_playDecalsSelectedCardEndEffect);
        tolua_function(tolua_S,"playGameVictoryStartTurnOnEffect",lua_GameAudioController_GameAudioController_playGameVictoryStartTurnOnEffect);
        tolua_function(tolua_S,"playPuzzleVictoryEffect",lua_GameAudioController_GameAudioController_playPuzzleVictoryEffect);
        tolua_function(tolua_S,"playGameVictoryLotteryStartFlyEffect",lua_GameAudioController_GameAudioController_playGameVictoryLotteryStartFlyEffect);
        tolua_function(tolua_S,"playStageUnlockEffect",lua_GameAudioController_GameAudioController_playStageUnlockEffect);
        tolua_function(tolua_S,"playRainbowsealBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playRainbowsealBubbleEliminatedEffect);
        tolua_function(tolua_S,"playGameWoodenhammerAttackEffect",lua_GameAudioController_GameAudioController_playGameWoodenhammerAttackEffect);
        tolua_function(tolua_S,"playBombBombBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playBombBombBubbleEliminatedEffect);
        tolua_function(tolua_S,"playPuzzleUsedAddTimePropEffect",lua_GameAudioController_GameAudioController_playPuzzleUsedAddTimePropEffect);
        tolua_function(tolua_S,"playPropBigBombBombBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playPropBigBombBombBubbleEliminatedEffect);
        tolua_function(tolua_S,"playPuzzleUsedBigEyesPropEffect",lua_GameAudioController_GameAudioController_playPuzzleUsedBigEyesPropEffect);
        tolua_function(tolua_S,"playStageButtonEffect",lua_GameAudioController_GameAudioController_playStageButtonEffect);
        tolua_function(tolua_S,"playGamePuzzlePlaySceneMusic",lua_GameAudioController_GameAudioController_playGamePuzzlePlaySceneMusic);
        tolua_function(tolua_S,"playDecalsChangeCardStateEffect",lua_GameAudioController_GameAudioController_playDecalsChangeCardStateEffect);
        tolua_function(tolua_S,"playGameDestroyRainbowsealMusic",lua_GameAudioController_GameAudioController_playGameDestroyRainbowsealMusic);
        tolua_function(tolua_S,"playGameStartEffect",lua_GameAudioController_GameAudioController_playGameStartEffect);
        tolua_function(tolua_S,"playContactBarrelBottomEffect",lua_GameAudioController_GameAudioController_playContactBarrelBottomEffect);
        tolua_function(tolua_S,"playGameLaunchMusic",lua_GameAudioController_GameAudioController_playGameLaunchMusic);
        tolua_function(tolua_S,"playContactBarrelHeadEffect",lua_GameAudioController_GameAudioController_playContactBarrelHeadEffect);
        tolua_function(tolua_S,"playContactBlackHoleBubbleEffect",lua_GameAudioController_GameAudioController_playContactBlackHoleBubbleEffect);
        tolua_function(tolua_S,"playMutiplesealBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playMutiplesealBubbleEliminatedEffect);
        tolua_function(tolua_S,"playGameStageCellThirdMusic",lua_GameAudioController_GameAudioController_playGameStageCellThirdMusic);
        tolua_function(tolua_S,"playStageTypeBackgroundMusic",lua_GameAudioController_GameAudioController_playStageTypeBackgroundMusic);
        tolua_function(tolua_S,"playAimingLinePropUsedEffect",lua_GameAudioController_GameAudioController_playAimingLinePropUsedEffect);
        tolua_function(tolua_S,"playDarkCloudBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playDarkCloudBubbleEliminatedEffect);
        tolua_function(tolua_S,"playSkillDyingBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playSkillDyingBubbleEliminatedEffect);
        tolua_function(tolua_S,"playAddSpecialPropUsedEffect",lua_GameAudioController_GameAudioController_playAddSpecialPropUsedEffect);
        tolua_function(tolua_S,"playPropColorBombBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playPropColorBombBubbleEliminatedEffect);
        tolua_function(tolua_S,"playSkillBigBombBombBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playSkillBigBombBombBubbleEliminatedEffect);
        tolua_function(tolua_S,"playLightningBubbleEliminatedEffect",lua_GameAudioController_GameAudioController_playLightningBubbleEliminatedEffect);
        tolua_function(tolua_S,"playGameStageCellFourthMusic",lua_GameAudioController_GameAudioController_playGameStageCellFourthMusic);
        tolua_function(tolua_S,"getInstance", lua_GameAudioController_GameAudioController_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameAudioController).name();
    g_luaType[typeName] = "bs.GameAudioController";
    g_typeCast["GameAudioController"] = "bs.GameAudioController";
    return 1;
}
TOLUA_API int register_all_GameAudioController(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameAudioController_GameAudioController(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

