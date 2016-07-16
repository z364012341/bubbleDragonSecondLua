//*******************************************************************************
//������   : GameSinglePropBuyAlert
//����     : <��Ϸ��������ĵ��߹������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_SINGLE_PROP_BUY_ALERT_H_
#define _GAME_SINGLE_PROP_BUY_ALERT_H_
#include "cocos2d.h"
#include "ui\UITextBMFont.h"
namespace bubble_second {
    class GameSinglePropBuyAlert : public cocos2d::Node
    {
    public:
        static GameSinglePropBuyAlert* createWithPropKey(const std::string& prop_key);
        ~GameSinglePropBuyAlert();
    private:
        GameSinglePropBuyAlert();
        bool initWithPropKey(const std::string& prop_key);
        void loadView();
        void updataNumbleLabel();
    private:
        std::string prop_key_ = "";
        int buy_numble_ = 0;
        cocos2d::ui::TextBMFont* numble_label_ = nullptr;
    };
}
#endif