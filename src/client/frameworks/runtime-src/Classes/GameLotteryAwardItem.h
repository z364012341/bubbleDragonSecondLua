//*******************************************************************************
//类名称   : GameLotteryAwardItem
//功能     : <游戏抽奖道具展示>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_LOTTERY_AWARD_ITEM_H_
#define _GAME_LOTTERY_AWARD_ITEM_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameLotteryAwardItem : public cocos2d::Node
    {
    public:
        static GameLotteryAwardItem* create(const std::string& key, int numble);
        ~GameLotteryAwardItem();
        cocos2d::Sprite* getAwardSprite();
    private:
        GameLotteryAwardItem();
        bool init(const std::string& key, int numble);
    private:
        cocos2d::Sprite* award_sprite_ = nullptr;
    };
}
#endif 