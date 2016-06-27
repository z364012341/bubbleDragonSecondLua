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
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class GameVictoryLotteryStarts;
    class GameVictoryAlert : public cocos2d::Node
    {
    public:
        static GameVictoryAlert* create(int level, int score, int start_numble);
        ~GameVictoryAlert();
        void setReplayCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback);
        void setNextCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback);
    private:
        GameVictoryAlert();
        void loadView();
        bool init(int level, int score, int start_numble);
        void initTopLabel(int level);
        void initScoreLabel(int score);  
        void initStart(int start_numble);
        void addLotteryStarts();
        void flyStartToLottery(int level, int start_numble);
        void playStartPopAction(cocos2d::Node* start, float delay);
        void playStart1PopAction();
        void playStart2PopAction();
        void playStart3PopAction();
    private:
        cocos2d::Node* csb_node_ = nullptr;
        cocos2d::Node* start_1_ = nullptr;
        cocos2d::Node* start_2_ = nullptr;
        cocos2d::Node* start_3_ = nullptr;
        cocos2d::Vector<cocos2d::Node*> starts_;
        GameVictoryLotteryStarts* lottery_starts_ = nullptr;
        float pop_start_total_time_ = 0.0f;
    };
}
#endif //_GAME_VICTORY_ALERT_H_