//*******************************************************************************
//类名称   : UserStrengthInfoBoard
//功能     : <游戏关卡场景上面的体力面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _USER_STRENGTH_INFO_BOARD_H_
#define _USER_STRENGTH_INFO_BOARD_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UITextBMFont.h"
namespace bubble_second {
    class StrengthCountDownLabel;
    class UserStrengthInfoBoard : public cocos2d::Node
    {
    public:
        CREATE_FUNC(UserStrengthInfoBoard);
        ~UserStrengthInfoBoard();
        void onEnter() override;
        void onExit() override;
    private:
        UserStrengthInfoBoard();
        bool init();
        void updateNumbleLabel();
        void playRandomTimeAnimation();
        void runFlyStrengthToButtonAction(cocos2d::EventCustom* event);
    private:
        cocos2d::ui::TextBMFont* numble_label_ = nullptr;
        StrengthCountDownLabel* countdown_label_ = nullptr;
        cocos2d::EventListenerCustom * listener_ = nullptr;
        cocostudio::Armature* armature_ = nullptr;
         
    };
}
#endif 