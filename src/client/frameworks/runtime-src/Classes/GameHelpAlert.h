//*******************************************************************************
//������   : GameHelpAlert
//����     : <��Ϸ�������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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
