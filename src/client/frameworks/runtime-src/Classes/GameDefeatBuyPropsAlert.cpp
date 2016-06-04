#include "GameDefeatBuyPropsAlert.h"
#include "cocostudio\CocoStudio.h"
#include "GameAlertMask.h"
#include "ui\UIButton.h"
#include "ButtonEffectController.h"
const std::string GAME_DEFEAT_BUY_PROPS_ALERT_CSB_PATH = "GameContinuePlayAlert.csb";
namespace bubble_second {
    GameDefeatBuyPropsAlert::GameDefeatBuyPropsAlert()
    {
    }


    GameDefeatBuyPropsAlert::~GameDefeatBuyPropsAlert()
    {
    }

    bool GameDefeatBuyPropsAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create(), -1);
        this->loadCSB();
        return true;
    }

    void GameDefeatBuyPropsAlert::loadCSB()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_DEFEAT_BUY_PROPS_ALERT_CSB_PATH);
        assert(csb_node);
        ButtonEffectController::setButtonsZoomScale(csb_node);
        this->addChild(csb_node);
        using cocos2d::ui::Button;
        Button* return_button = dynamic_cast<Button*>(csb_node->getChildByName("Button_1"));
        assert(return_button);
        return_button->addClickEventListener([=](cocos2d::Ref*) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_DEFEAT_BUY_ALERT_RETURN);
            this->removeFromParent();
        });

        Button* buy_continue_button = dynamic_cast<Button*>(csb_node->getChildByName("Button_4"));
        assert(buy_continue_button);
        buy_continue_button->addClickEventListener([=](cocos2d::Ref*) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_DEFEAT_BUY_CONTINUE_PLAY);
            this->removeFromParent();
        });
    }                                            
    
    
}