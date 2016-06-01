//*******************************************************************************
//������   : GameDefeatAlert
//����     : <��Ϸʧ�ܵ������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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