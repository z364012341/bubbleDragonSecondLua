//*******************************************************************************
//类名称   : GameAboutAlert
//功能     : <游戏关于面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_ABOUT_ALERT_H_
#define _GAME_ABOUT_ALERT_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameAboutAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameAboutAlert);
        ~GameAboutAlert();
    private:
        GameAboutAlert();
        void loadCSB();
        bool init();
    };
}
#endif //_GAME_ABOUT_ALERT_H_
