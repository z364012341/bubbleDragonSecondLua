//*******************************************************************************
//类名称   : GameVictoryLotteryGiftItem
//功能     : <游戏胜利后的星星抽奖礼品item>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_VICTORY_LOTTERY_GIFT_ITEM_H_
#define _GAME_VICTORY_LOTTERY_GIFT_ITEM_H_
#include "GameVictoryLotteryItemBase.h"
namespace bubble_second {
    class GameVictoryLotteryGiftItem : public  GameVictoryLotteryItemBase
    {
    public:
        CREATE_FUNC(GameVictoryLotteryGiftItem);
        ~GameVictoryLotteryGiftItem();
        void lightenItem() override;
        void onEnter() override;
        void onExit() override;
    private:
        GameVictoryLotteryGiftItem();
        bool init();
    };
}
#endif