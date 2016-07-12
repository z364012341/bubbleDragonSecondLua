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
namespace bubble_second {
    class GameStoreItemFactory
    {
    public:
        GETINSTANCE_FUNC(GameStoreItemFactory);
        ~GameStoreItemFactory();
        cocos2d::Vector<cocos2d::Node*> getGiftListViewItems();
    private:
        GameStoreItemFactory();
    private:
        cocos2d::ValueMap store_items_data_;
    };
}
#endif //_GAME_STORE_ITEM_FACTORY_H_