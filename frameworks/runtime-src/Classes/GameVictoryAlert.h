//*******************************************************************************
//������   : GameVictoryAlert
//����     : <��Ϸʤ���󵯳������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_VICTORY_ALERT_H_
#define _GAME_VICTORY_ALERT_H_
#include "GameBaseAlert.h"
namespace bubble_second {
    class GameVictoryAlert : public GameBaseAlert
    {
    public:
        static GameVictoryAlert* create(int level, int score, int start_numble);
        ~GameVictoryAlert();
        void setReplayCallback(const cocos2d::ccMenuCallback& callback);
        void setNextCallback(const cocos2d::ccMenuCallback& callback);
    private:
        GameVictoryAlert();
        bool init(int level, int score, int start_numble);
        void addButtonItem();
        void addRewardsShow();
        void addTopLabel(int level);
        void addFlashLight();
        void addSamsung(int numble);
        void addScoreLabel(int score);
    private:
        cocos2d::MenuItem* replay_item_ = nullptr;
        cocos2d::MenuItem* store_item_ = nullptr;
        cocos2d::MenuItem* next_item_ = nullptr;
    };
}
#endif //_GAME_VICTORY_ALERT_H_