//*******************************************************************************
//������   : GameLotteryAwardItem
//����     : <��Ϸ�齱����չʾ>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_LOTTERY_AWARD_ITEM_H_
#define _GAME_LOTTERY_AWARD_ITEM_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameLotteryAwardItem : public cocos2d::Node
    {
    public:
        static GameLotteryAwardItem* create(const std::string& key, int numble);
        ~GameLotteryAwardItem();
        cocos2d::Sprite* getAwardSprite();
    private:
        GameLotteryAwardItem();
        bool init(const std::string& key, int numble);
    private:
        cocos2d::Sprite* award_sprite_ = nullptr;
    };
}
#endif 