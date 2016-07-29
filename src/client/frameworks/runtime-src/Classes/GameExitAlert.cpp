#include "GameExitAlert.h"
#include "cocostudio\CocoStudio.h"
#include "GameAlertMask.h"
#include "ui\UIButton.h"
#include "ButtonEffectController.h"
const std::string GAME_EXIT_ALERT_CSB_PATH = "GameExitAlert.csb";
namespace bubble_second {
    GameExitAlert::GameExitAlert()
    {
    }

    bool GameExitAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create(), -1);
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_EXIT_ALERT_CSB_PATH);
        this->addChild(csb_node);
        ButtonEffectController::setButtonsZoomScale(csb_node);
        dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("Button_5"))->addClickEventListener([=](cocos2d::Ref*) {
            this->removeFromParent();
        });
        dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("Button_4"))->addClickEventListener([=](cocos2d::Ref*) {
            cocos2d::Director::getInstance()->end();
        });
        return true;
    }


    GameExitAlert::~GameExitAlert()
    {
    }
}