#include "GameDefeatBuyPropsAlert.h"
#include "cocostudio\CocoStudio.h"
#include "GameAlertMask.h"
#include "ui\UIButton.h"
#include "ui\UIScale9Sprite.h"
#include "ButtonEffectController.h"
#include "GamePropsCostTag.h"
#include "GameUnitPriceManager.h"
#include "GameCharactorNameManager.h"
#include "BubbleFactory.h"
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
        GamePropsCostTag* cost_tag = GamePropsCostTag::createWithKey(GAME_DEFEAT_BUY_CONTINUE_KEY);
        cost_tag->setPosition(buy_continue_button->getContentSize().width/2, buy_continue_button->getContentSize().height / 2);
        buy_continue_button->getRendererNormal()->addChild(cost_tag);
        buy_continue_button->addClickEventListener([=](cocos2d::Ref*) {
            if (cost_tag->canPay())
            {
                cost_tag->pay();
                this->getEventDispatcher()->dispatchCustomEvent(EVENT_DEFEAT_BUY_CONTINUE_PLAY);
                this->removeFromParent();
            }
        });

        csb_node->getChildByName("Node_1")->addChild(BubbleFactory::getInstance()->createBubbleWithType(GameCharactorNameManager::getInstance()->getCurrentSkillType()));
    }                                            
    
    
}