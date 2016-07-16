//*******************************************************************************
//������   : GameSignBoardAlert
//����     : <��Ϸÿ��ǩ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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