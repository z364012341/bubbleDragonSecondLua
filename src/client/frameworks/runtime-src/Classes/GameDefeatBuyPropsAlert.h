//*******************************************************************************
//������   : GameDefeatBuyPropsAlert
//����     : <��Ϸʧ�ܵ�������������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_DEFEAT_BUY_PROPS_ALERT_H_
#define _GAME_DEFEAT_BUY_PROPS_ALERT_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameDefeatBuyPropsAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameDefeatBuyPropsAlert);
        ~GameDefeatBuyPropsAlert();
    private:
        GameDefeatBuyPropsAlert();
        bool init();
        void loadCSB();
    };
}
#endif //_GAME_DEFEAT_BUY_PROPS_ALERT_H_