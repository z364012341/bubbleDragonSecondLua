//*******************************************************************************
//类名称   : EnterGameAlert
//功能     : <进入游戏场景前的面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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