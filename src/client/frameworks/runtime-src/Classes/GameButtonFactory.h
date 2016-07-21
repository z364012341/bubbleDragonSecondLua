//*******************************************************************************
//������   : GameButtonFactory
//����     : <���ڴ���button>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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