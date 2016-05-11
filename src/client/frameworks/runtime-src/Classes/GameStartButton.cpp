#include "GameStartButton.h"
#include "cocostudio\CocoStudio.h"
#include "ButtonEffectController.h"
#include "SpriteTextureController.h"
#include "ui\UIScale9Sprite.h"
const std::string START_BUTTON_TOP_CSB = "GameStartMenuTop.csb";
const std::string START_BUTTON_BOTTOM_CSB = "GameStartMenuBottom.csb";
const std::string START_BUTTON_CLIPPINT_STENCIL_PATH = "startBubbleBG1.png";
const std::string ENTER_GAME_ALERT_START_BUTTON_NAME = "startButton";
namespace bubble_second {
    GameStartButton::GameStartButton()
    {
    }


    GameStartButton::~GameStartButton()
    {
    }

    void GameStartButton::addButtonClickEventListener(const cocos2d::ui::Widget::ccWidgetClickCallback & callback)
    {
        //button_->addTouchEventListener(callback);
        button_->addClickEventListener(callback);
    }

    cocos2d::ui::Button * GameStartButton::getStartButton()
    {
        return button_;
    }

    bool GameStartButton::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Node* button_top = cocos2d::CSLoader::createNode(START_BUTTON_TOP_CSB);
        auto action = cocos2d::CSLoader::createTimeline(START_BUTTON_TOP_CSB);
        button_top->runAction(action);
        action->gotoFrameAndPlay(0, true);

        cocos2d::ClippingNode* clipping = cocos2d::ClippingNode::create(SpriteTextureController::getInstance()->createGameSpriteWithPath(START_BUTTON_CLIPPINT_STENCIL_PATH));
        clipping->setAlphaThreshold(0);
        clipping->addChild(button_top);
        cocos2d::Node* start_node = cocos2d::CSLoader::createNode(START_BUTTON_BOTTOM_CSB);
        this->addChild(start_node);
        button_ = dynamic_cast<cocos2d::ui::Button*>(start_node->getChildByName(ENTER_GAME_ALERT_START_BUTTON_NAME));
        clipping->setPosition(button_->getContentSize().width / 2, button_->getContentSize().height / 2);
        button_->getRendererNormal()->addChild(clipping);
        ButtonEffectController::setButtonZoomScale(button_);
        return true;
    }
}