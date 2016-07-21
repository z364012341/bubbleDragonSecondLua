//*******************************************************************************
//类名称   : GameButtonFactory
//功能     : <用于创建button>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_BUTTON_FACTORY_H_
#define _GAME_BUTTON_FACTORY_H_
#include "BubbleSecondConstant.h"
#include "ui\UIButton.h"
namespace bubble_second {
    class GameButtonFactory
    {
    public:
        GETINSTANCE_FUNC(GameButtonFactory);
        ~GameButtonFactory();
        cocos2d::ui::Button* createGameButton(const std::string& normalImage,
            const std::string& selectedImage = "",
            const std::string& disableImage = "");
        cocos2d::ui::Button* createUnlockButton();
    private:
        GameButtonFactory();
    };
}
#endif