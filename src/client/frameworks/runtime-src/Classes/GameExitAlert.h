//*******************************************************************************
//类名称   : GameExitAlert
//功能     : <游戏退出弹窗>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_EXIT_ALERT_H_
#define _GAME_EXIT_ALERT_H_
#include "cocos2d.h"

namespace bubble_second {
    class GameExitAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameExitAlert);
        ~GameExitAlert();
    private:
        GameExitAlert();
        bool init();
    };
}
#endif