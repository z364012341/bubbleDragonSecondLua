//*******************************************************************************
//类名称   : GameAudioController
//功能     : <游戏声音控制>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_AUDIO_CONTROLLER_H_
#define _GAME_AUDIO_CONTROLLER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameAudioController
    {
    public:
        GETINSTANCE_FUNC(GameAudioController);
        ~GameAudioController();
        void loadAudioFile();
    private:
        GameAudioController();

    };
}
#endif