//*******************************************************************************
//������   : GameExitAlert
//����     : <��Ϸ�˳�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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