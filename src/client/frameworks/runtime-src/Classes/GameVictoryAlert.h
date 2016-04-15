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
    class GameVictoryAlert : public cocos2d::Node
    {
    public:
        static GameVictoryAlert* create(int level, int score, int start_numble);
        ~GameVictoryAlert();
        void setReplayCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback);
        void setNextCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback);
    private:
        GameVictoryAlert();
        bool init(int level, int score, int start_numble);
        //void addButtonItem();
        //void addRewardsShow();
        //void addTopLabel(int level);
        //void addFlashLight();
        //void addSamsung(int numble);
        //void addScoreLabel(int score);
        
        void loadView();
        //void initNextButton(int level);
    //private:
    //    cocos2d::MenuItem* replay_item_ = nullptr;
    //    cocos2d::MenuItem* store_item_ = nullptr;
    //    cocos2d::MenuItem* next_item_ = nullptr;
    private:
        cocos2d::Node* csb_node_ = nullptr;
    };
}
#endif //_GAME_VICTORY_ALERT_H_