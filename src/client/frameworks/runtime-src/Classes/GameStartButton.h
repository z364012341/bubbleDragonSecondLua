//*******************************************************************************
//类名称   : GameStartButton
//功能     : <绿色的开始按钮>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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