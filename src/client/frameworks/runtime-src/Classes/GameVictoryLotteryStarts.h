//*******************************************************************************
//������   : GameVictoryLotteryStarts
//����     : <��Ϸʤ��������ǳ齱>
//-------------------------------------------------------------------------------
//��ע     : <>
//           
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_VICTORY_LOTTERY_STARTS_H_
#define _GAME_VICTORY_LOTTERY_STARTS_H_
#include "cocos2d.h"
namespace bubble_second {
    class  GameVictoryLotteryItemBase;
    class GameVictoryLotteryStarts : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameVictoryLotteryStarts);
        ~GameVictoryLotteryStarts();
        //void flyStartsToLotteryBegin(std::deque<cocos2d::Vec2> points);
        void flyStartsToLotteryBegin(cocos2d::Vec2 point);
        void onEnter() override;
        void onExit() override;
    private:
        GameVictoryLotteryStarts();
        bool init();
        void initStarts();
        void initItemsColor();
        void initStartVisible();
        //void initGift();
        int getGrayBeginIndex();
        //void setGiftTextureWithIndex(int index);
        void addItemWithIndex(int index);
        GameVictoryLotteryItemBase* createStartWithIndex(int index);
        void contrarotateStarts();
        void setStartPosAndRotationAndScaleWithIndex(cocos2d::Node* start, int index);
        //void flyStartsToLottery();
        void lightenStart();
        cocos2d::Vec2 getStartPositionWithIndex(int index);
        void popGiftArmature(cocos2d::EventCustom* event);
    private:
        cocos2d::Map<int, GameVictoryLotteryItemBase*> starts_container_;
        //std::deque<cocos2d::Vec2> fly_points_;
        int total_start_numble_ = 0;
    };
}
#endif