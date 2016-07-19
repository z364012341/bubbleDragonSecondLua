//*******************************************************************************
//������   : GameSinglePropBuyAlertFactory
//����     : <�������߹���򹤳�>
//-------------------------------------------------------------------------------
//��ע     : <��������item>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_SINGLE_PROP_BUY_ALERT_FACTORY_H_
#define _GAME_SINGLE_PROP_BUY_ALERT_FACTORY_H_
#include "BubbleSecondConstant.h"
#include "GameSinglePropBuyAlert.h"
namespace bubble_second {
    class GameSinglePropBuyAlertFactory
    {
    public:
        GETINSTANCE_FUNC(GameSinglePropBuyAlertFactory);
        ~GameSinglePropBuyAlertFactory();
        void popGameSinglePropBuyAlertWithKey(const std::string& prop_key);
        GameSinglePropBuyAlert * createGameSinglePropBuyAlert();
    private:
        GameSinglePropBuyAlertFactory();

    private:
        std::string prop_key_ = "";
    };
}
#endif