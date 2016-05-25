//*******************************************************************************
//������   : PuzzleStoreItemFactory
//����     : <ƴͼ�������listview��item����>
//-------------------------------------------------------------------------------
//��ע     : <��������item>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _PUZZLE_STORE_ITEM_FACTORY_H_
#define _PUZZLE_STORE_ITEM_FACTORY_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class PuzzleStoreItemFactory
    {
    public:
        GETINSTANCE_FUNC(PuzzleStoreItemFactory);
        cocos2d::Node* createItemWithIndex(int index);
        ~PuzzleStoreItemFactory();
        void loadItemData();
    private:
        PuzzleStoreItemFactory();
    private:
        cocos2d::ValueMap item_data_;
    };
}
#endif //PuzzleStoreItemFactory