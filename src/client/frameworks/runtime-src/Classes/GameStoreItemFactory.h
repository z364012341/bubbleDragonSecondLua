//*******************************************************************************
//类名称   : GameStoreItemFactory
//功能     : <商城listview的item工厂>
//-------------------------------------------------------------------------------
//备注     : <负责生成item>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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