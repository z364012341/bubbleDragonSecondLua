//*******************************************************************************
//������   : UserStrengthInfoBoard
//����     : <��Ϸ�ؿ�����������������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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