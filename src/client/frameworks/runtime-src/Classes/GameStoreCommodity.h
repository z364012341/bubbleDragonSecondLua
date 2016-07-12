//*******************************************************************************
//类名称   : GameStoreCommodity
//功能     : <商城的商品展示, 商品图标加上 "x数量">
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_STORE_COMMODITY_H_
#define _GAME_STORE_COMMODITY_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameStoreCommodity : public cocos2d::Node
    {
    public:
        static GameStoreCommodity* createWithPropKeyAndNumble(const std::string& prop_key, const std::string& numble);
        ~GameStoreCommodity();
    private:
        GameStoreCommodity();
        bool initWithPropKeyAndNumble(const std::string& prop_key, const std::string& numble);
    };
}
#endif