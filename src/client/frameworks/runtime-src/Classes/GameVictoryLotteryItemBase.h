//*******************************************************************************
//类名称   : GameVictoryLotteryItemBase
//功能     : <游戏胜利后的星星抽奖item的基类>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_VICTORY_LOTTERY_ITEM_BASE_H_
#define _GAME_VICTORY_LOTTERY_ITEM_BASE_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameVictoryLotteryItemBase : public cocos2d::Node
    {
    public:
        GameVictoryLotteryItemBase();
        ~GameVictoryLotteryItemBase();
        void setGrayEnabled(bool enabled);
        virtual void lightenItem() = 0;
    protected:
        bool initWithPath(const std::string& path);
    private:
        cocos2d::Sprite* item_sprite_ = nullptr;
    };
}
#endif