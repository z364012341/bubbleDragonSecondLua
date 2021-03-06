//*******************************************************************************
//类名称   : DecalsFactory
//功能     : <贴纸的工厂类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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
        //cocos2d::ValueVector getDecalsCharactorData();
        //cocos2d::ValueVector getDecalsTreasureData();
        cocos2d::ValueVector getDecalsDataWithType(const std::string& decals_type);
        cocos2d::Vec2 getDecalsMaxIndexWithPath(const std::string& path);

        //cocos2d::Sprite* createCharactorNextDecal();
        //cocos2d::Sprite* createTreasureNextDecal();
        cocos2d::Sprite* createNextDecalWithType(const std::string& decals_type);

        void saveNextDecal(const std::string& decals_type);
        //void saveCharactorNextDecal();
        //void saveTreasureNextDecal();
    private:
        DecalsFactory();
        cocos2d::Sprite* createDecalBackground(cocos2d::Sprite* decal, const std::string& path, int numble);
    private:
        //std::map<int, cocos2d::Vec2> numble_to_index_;
        cocos2d::ValueMap decals_data_;
    };
}
#endif //_DECALS_FACTORY_H_