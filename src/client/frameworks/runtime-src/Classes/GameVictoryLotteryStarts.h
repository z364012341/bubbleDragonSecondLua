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
    class GameVictoryLotteryStarts : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameVictoryLotteryStarts);
        ~GameVictoryLotteryStarts();
    private:
        GameVictoryLotteryStarts();
        bool init();
        void initStarts();
        //�����Ϸ���������0��
        void addStartWithAngle(float angle);
    };
}
#endif