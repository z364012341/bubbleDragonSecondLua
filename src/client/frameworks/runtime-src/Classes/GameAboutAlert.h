//*******************************************************************************
//������   : GameAboutAlert
//����     : <��Ϸ�������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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
