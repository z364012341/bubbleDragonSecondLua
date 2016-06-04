#include "GameHelpAlert.h"
#include "GameAlertMask.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UIButton.h"
#include "ButtonEffectController.h"
const std::string GAME_HELP_ALERT_CSB_PATH = "GameHelpAlert.csb";
const std::string RETURN_BUTTON_NAME = "Button_1";
namespace bubble_second {
    GameHelpAlert::GameHelpAlert()
    {
    }

    bool GameHelpAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::createTransparentMask(), -1);
        this->loadCSB();
        return true;
    }

    void GameHelpAlert::loadCSB()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_HELP_ALERT_CSB_PATH);
        assert(csb_node);
        ButtonEffectController::setButtonsZoomScale(csb_node);
        this->addChild(csb_node);
        cocos2d::ui::Button* return_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName(RETURN_BUTTON_NAME));
        assert(return_button);
        return_button->addClickEventListener([=](cocos2d::Ref*) {
            this->removeFromParent();
        });
    }


    GameHelpAlert::~GameHelpAlert()
    {
    }
}