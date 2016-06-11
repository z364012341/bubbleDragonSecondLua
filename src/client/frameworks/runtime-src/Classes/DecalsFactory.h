//*******************************************************************************
//������   : DecalsFactory
//����     : <��ֽ�Ĺ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _DECALS_FACTORY_H_
#define _DECALS_FACTORY_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class DecalsFactory
    {
    public:
        GETINSTANCE_FUNC(DecalsFactory);
        ~DecalsFactory();
        cocos2d::Sprite* createDecal(const std::string& path, int index_x, int index_y);
        cocos2d::Sprite* createDecalWithNumble(const std::string& path, int numble);
        cocos2d::Vec2 convertDecalNumbleToIndex(int numble, const std::string & path);
        void loadDecalsData();
        cocos2d::ValueVector getDecalsCharactorData();
        cocos2d::ValueVector getTreasureCharactorData();
        cocos2d::Vec2 getDecalsMaxIndexWithPath(const std::string& path);
    private:
        DecalsFactory();
    private:
        std::map<int, cocos2d::Vec2> numble_to_index_;
        cocos2d::ValueMap decals_data_;
    };
}
#endif //_DECALS_FACTORY_H_