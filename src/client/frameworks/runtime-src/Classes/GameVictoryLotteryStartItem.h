//*******************************************************************************
//������   : GameVictoryLotteryStartItem
//����     : <��Ϸʤ��������ǳ齱����item>
//-------------------------------------------------------------------------------
//��ע     : <>
//           
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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