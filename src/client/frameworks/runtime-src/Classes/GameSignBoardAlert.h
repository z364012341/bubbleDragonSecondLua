//*******************************************************************************
//类名称   : GameSignBoardAlert
//功能     : <游戏每日签到面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SIGN_BOARD_ALERT_H_
#define _GAME_SIGN_BOARD_ALERT_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameSignBoardAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameSignBoardAlert);
        ~GameSignBoardAlert();
    private:
        GameSignBoardAlert();
        bool init();
        void initTodayBoard();
        bool isNeedSignIn();
        void addSignInReward();
    private:
        cocos2d::Node* csb_node_ = nullptr;
        int sign_day_ = 0;
    };
}
#endif 