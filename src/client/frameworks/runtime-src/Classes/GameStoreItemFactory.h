//*******************************************************************************
//������   : GameStoreItemFactory
//����     : <�̳�listview��item����>
//-------------------------------------------------------------------------------
//��ע     : <��������item>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_STORE_ITEM_FACTORY_H_
#define _GAME_STORE_ITEM_FACTORY_H_
#include "BubbleSecondConstant.h"
//const std::string COMMODITY_DECALS_LOTTERY_BEGIN_KEY = "decals_lottery_begin"; //��ֽ�齱��ʼ����
//const std::string COMMODITY_DECALS_LOTTERY_CONTINUE_KEY = "decals_lottery_continue"; //��ֽ�����齱����
namespace bubble_second {
    class GameStoreItemFactory
    {
    public:
        GETINSTANCE_FUNC(GameStoreItemFactory);
        ~GameStoreItemFactory();
        void loadItemsData();
        cocos2d::Vector<cocos2d::Node*> getGiftListViewItems();
        cocos2d::Vector<cocos2d::Node*> getDiamondListViewItems();
        cocos2d::Vector<cocos2d::Node*> getPropsListViewItems();
    private:
        GameStoreItemFactory();
    private:
        cocos2d::ValueMap store_items_data_;
        //cocos2d::ValueMap store_unit_price_data_;
    };
}
#endif //_GAME_STORE_ITEM_FACTORY_H_