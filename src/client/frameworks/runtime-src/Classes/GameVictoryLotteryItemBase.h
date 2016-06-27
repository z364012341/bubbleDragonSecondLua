//*******************************************************************************
//������   : GameVictoryLotteryItemBase
//����     : <��Ϸʤ��������ǳ齱item�Ļ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//           
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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