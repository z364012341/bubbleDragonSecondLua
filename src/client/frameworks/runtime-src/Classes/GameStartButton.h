//*******************************************************************************
//������   : GameStartButton
//����     : <��ɫ�Ŀ�ʼ��ť>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_START_BUTTON_H_
#define _GAME_START_BUTTON_H_
//#include "GameBaseAlert.h"
#include "BubbleSecondConstant.h"
#include "ui\UIButton.h"
namespace bubble_second {
    class GameStartButton  : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameStartButton);
        GameStartButton();
        ~GameStartButton();
        void addButtonTouchEventListener(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback);
    private:
        bool init();
    private:
        cocos2d::ui::Button* button_ = nullptr;
    };
}
#endif //_GAME_START_BUTTON_H_