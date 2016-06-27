//*******************************************************************************
//������   : GameVictoryLotteryGiftItem
//����     : <��Ϸʤ��������ǳ齱��Ʒitem>
//-------------------------------------------------------------------------------
//��ע     : <>
//           
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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