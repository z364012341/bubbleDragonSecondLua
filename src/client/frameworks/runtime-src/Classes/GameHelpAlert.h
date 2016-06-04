//*******************************************************************************
//类名称   : GameHelpAlert
//功能     : <游戏帮助面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_HELP_ALERT_H_
#define _GAME_HELP_ALERT_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameHelpAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameHelpAlert);
        ~GameHelpAlert();
    private:
        GameHelpAlert();
        bool init();
        void loadCSB();
    };
}
#endif //_GAME_HELP_ALERT_H_
