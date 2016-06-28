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
//#include "GameBaseAlert.h"
#include "BubbleSecondConstant.h"
#include "ui\UIButton.h"
#include "ui\UITextBMFont.h"
#include "ui\UIPageView.h"
namespace bubble_second {
    class EnterGameAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(EnterGameAlert);
        ~EnterGameAlert();
    private:
        EnterGameAlert();
        bool init();
        void loadView();
        void initStartButton(int cell_numble, int level);
        void initCharactorPageView();
        void initCloseButton();
        void initStageNumbleLabel(int level);
        void initStageTypeLabel(const StageType& type);
        void setDirectionalButtonsEnable(int pageview_index);
    private:
        cocos2d::ui::Button* getCloseButton();
        cocos2d::ui::TextBMFont* getStageTypeLabel();
    private:
        cocos2d::Node* alert_csb_node_ = nullptr;
		cocos2d::Node* start_node_ = nullptr;
        cocos2d::ui::PageView* charactor_pageview_ = nullptr;
        cocos2d::ui::Button* left_button_ = nullptr;
        cocos2d::ui::Button* right_button_ = nullptr;

    };
}
#endif //_ENTER_GAME_ALERT_H_