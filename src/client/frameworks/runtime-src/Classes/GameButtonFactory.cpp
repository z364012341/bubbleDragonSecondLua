#include "GameButtonFactory.h"
#include "ButtonEffectController.h"
const std::string& GAME_UNLOCK_BUTTON_PATH = "daojusuo.png";

namespace bubble_second {
    GameButtonFactory::GameButtonFactory()
    {
    }


    GameButtonFactory::~GameButtonFactory()
    {
    }
    cocos2d::ui::Button * GameButtonFactory::createGameButton(const std::string & normalImage, const std::string & selectedImage, const std::string & disableImage)
    {
        using cocos2d::ui::Button;
        Button* button = Button::create(normalImage, selectedImage, disableImage);
        ButtonEffectController::setButtonZoomScale(button);
        return button;
    }
    cocos2d::ui::Button * GameButtonFactory::createUnlockButton()
    {
        return this->createGameButton(GAME_UNLOCK_BUTTON_PATH, GAME_UNLOCK_BUTTON_PATH);
    }
}