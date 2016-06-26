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
        void flyStartsToLotteryBegin(std::deque<cocos2d::Vec2> points);
    private:
        GameVictoryLotteryStarts();
        bool init();
        void initStarts();
        void initStartsColor();
        void initStartVisible();
        void initGift();
        int getGrayBeginIndex();
        void setGiftTextureWithIndex(int index);
        void addStartWithIndex(int index);
        void contrarotateStarts();
        void setStartPosAndRotationAndScaleWithIndex(cocos2d::Sprite* start, int index);
        void flyStartsToLottery();
        cocos2d::Vec2 getStartPositionWithIndex(int index);
    private:
        cocos2d::Map<int, cocos2d::Sprite*> starts_container_;
        std::deque<cocos2d::Vec2> fly_points_;
        int total_start_numble_ = 0;
    };
}
#endif