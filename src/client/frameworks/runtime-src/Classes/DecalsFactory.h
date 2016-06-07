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
        cocos2d::Vec2 convertDecalNumbleToIndex(int numble);
    private:
        DecalsFactory();
    private:
        std::map<int, cocos2d::Vec2> numble_to_index_;
    };
}
#endif //_DECALS_FACTORY_H_