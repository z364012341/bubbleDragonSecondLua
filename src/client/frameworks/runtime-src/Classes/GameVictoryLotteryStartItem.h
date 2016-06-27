//*******************************************************************************
//类名称   : GameVictoryLotteryStartItem
//功能     : <游戏胜利后的星星抽奖星星item>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_VICTORY_LOTTERY_START_ITEM_H_
#define _GAME_VICTORY_LOTTERY_START_ITEM_H_
#include "GameVictoryLotteryItemBase.h"
namespace bubble_second {
    class GameVictoryLotteryStartItem : public  GameVictoryLotteryItemBase
    {
    public:
        CREATE_FUNC(GameVictoryLotteryStartItem);
        ~GameVictoryLotteryStartItem();
        void lightenItem() override;
    private:
        GameVictoryLotteryStartItem();
        bool init();
    };
}
#endif