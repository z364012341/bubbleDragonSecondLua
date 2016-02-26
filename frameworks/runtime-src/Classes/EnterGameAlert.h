//*******************************************************************************
//������   : EnterGameAlert
//����     : <������Ϸ����ǰ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _ENTER_GAME_ALERT_H_
#define _ENTER_GAME_ALERT_H_
#include "GameBaseAlert.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class EnterGameAlert : public GameBaseAlert
    {
    public:
        static EnterGameAlert* create(int cell_numble, int level, const StageType& type);
        ~EnterGameAlert();
        void onExit() override;
        void setBeginCallback(const cocos2d::ccMenuCallback& callback);
    private:
        EnterGameAlert();
        bool init(int cell_numble, int level, const StageType& type);
        //void addBackground();
        void addTopLabel(int level);
        void addStageTypeLabel(const StageType& type);
        void addCharactor();
        void addPropsShow();
        void addButtonItem();
    private:
        cocos2d::MenuItem* cancel_item_ = nullptr;
        cocos2d::MenuItem* begin_item_ = nullptr;
    };
}
#endif //_ENTER_GAME_ALERT_H_