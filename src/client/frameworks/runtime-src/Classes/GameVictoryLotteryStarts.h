//*******************************************************************************
//类名称   : GameVictoryLotteryStarts
//功能     : <游戏胜利后的星星抽奖>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_VICTORY_LOTTERY_STARTS_H_
#define _GAME_VICTORY_LOTTERY_STARTS_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameVictoryLotteryStarts : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameVictoryLotteryStarts);
        ~GameVictoryLotteryStarts();
    private:
        GameVictoryLotteryStarts();
        bool init();
        void initStarts();
        //正中上方的星星是0度
        void addStartWithAngle(float angle);
    };
}
#endif