//*******************************************************************************
//类名称   : GameDefeatAlert
//功能     : <游戏失败弹出面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_DEFEAT_ALERT_H_
#define _GAME_DEFEAT_ALERT_H_
#include "cocos2d.h"
//#include "GameBaseAlert.h"
namespace bubble_second {
    class GameDefeatAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameDefeatAlert);
        ~GameDefeatAlert();
        
    private:
        GameDefeatAlert();
        bool init();
        void loadCSB();
    private:
        cocos2d::Node* csb_node_ = nullptr;
    };
}
#endif //_GAME_DEFEAT_ALERT_H_