//*******************************************************************************
//类名称   : StrengthCountDownLabel
//功能     : <游戏体力面板的倒计时显示>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STRENGTH_COUNTDOWN_LABEL_H_
#define _STRENGTH_COUNTDOWN_LABEL_H_
#include "cocos2d.h"
#include "ui\UITextBMFont.h"
namespace bubble_second {
    class StrengthCountDownLabel  : public cocos2d::Node
    {
    public:
        CREATE_FUNC(StrengthCountDownLabel);
        ~StrengthCountDownLabel();
        void onEnter() override;
        void onExit() override;
        void updateLabel();
    private:
        bool init();
        StrengthCountDownLabel();
        void countDownBegin();
        void countDownEnd();
        void countDownWithTime(time_t tiem);
        void setCountDownLabel(time_t tiem);
    private:
        cocos2d::ui::TextBMFont* label_ = nullptr;
        cocos2d::EventListenerCustom * listener_ = nullptr;
        int strength_numble_ = -1;
        time_t count_down_time_ = 0;
        bool is_begin_flag_ = false;
    };
}
#endif 