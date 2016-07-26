//*******************************************************************************
//������   : GameUnitPriceManager
//����     : <��Ϸ������Ŀ�ĵ���>
//-------------------------------------------------------------------------------
//��ע     : <��������item>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_UNIT_PRICE_MANAGER_H_
#define _GAME_UNIT_PRICE_MANAGER_H_
#include "BubbleSecondConstant.h"
const std::string COMMODITY_DECALS_LOTTERY_BEGIN_KEY = "decals_lottery_begin"; //��ֽ�齱��ʼ����
const std::string COMMODITY_DECALS_LOTTERY_CONTINUE_KEY = "decals_lottery_continue"; //��ֽ�����齱����
const std::string GAME_DEFEAT_BUY_CONTINUE_KEY = "game_defeat_buy_continue_key"; //ʧ�ܺ������Ϸ����
namespace bubble_second {
    class GameUnitPriceManager
    {
    public:
        GETINSTANCE_FUNC(GameUnitPriceManager);
        ~GameUnitPriceManager();
        void addUnitPriceData(cocos2d::ValueMap price_data, const std::string& key);
        cocos2d::ValueMap getPropUnitPriceData(const std::string& prop_key);
    private:
        GameUnitPriceManager();
    private:
        cocos2d::ValueMap store_unit_price_data_;
    };
}
#endif 