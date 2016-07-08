#include "GameStartButton.h"
#include "cocostudio\CocoStudio.h"
#include "ButtonEffectController.h"
#include "SpriteTextureController.h"
#include "ui\UIScale9Sprite.h"
const std::string START_BUTTON_TOP_CSB = "GameStartMenuTop.csb";
const std::string START_BUTTON_BOTTOM_CSB = "GameStartMenuBottom.csb";
const std::string START_BUTTON_CLIPPINT_STENCIL_PATH = "startBubbleBG1.png";
const std::string ENTER_GAME_ALERT_START_BUTTON_NAME = "startButton";
const std::string ENTER_GAME_ALERT_TRIANGLE_NAME = "startButtonTriangle_21";
const std::string ENTER_GAME_ALERT_PINK_TRIANGLE_NAME = "denglukaishisanjiao_1";
const std::string ENTER_GAME_ALERT_CONTINUE_NAME = "continueLabel";
namespace bubble_second {
    GameStartButton * GameStartButton::createButtonContinueForm()
    {
        GameStartButton *pRet = new(std::nothrow) GameStartButton();
        if (pRet && pRet->init(ENTER_GAME_ALERT_CONTINUE_NAME))
        { 
            pRet->autorelease(); 
            return pRet; 
        }
        else 
        { 
            delete pRet;
            pRet = nullptr; 
            return nullptr; 
        } 
        
    }
    GameStartButton * GameStartButton::createButtonStartForm()
    {
        GameStartButton *pRet = new(std::nothrow) GameStartButton();
        if (pRet && pRet->init(ENTER_GAME_ALERT_TRIANGLE_NAME))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
    GameStartButton * GameStartButton::createButtonPinkForm()
    {
        GameStartButton *pRet = new(std::nothrow) GameStartButton();
        if (pRet && pRet->initPinkForm())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
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

    bool GameStartButton::init(const std::string& logo_name)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Node* button_top = cocos2d::CSLoader::createNode(START_BUTTON_TOP_CSB);
        button_top->getChildByName(logo_name)->setVisible(true);
        particle_ = dynamic_cast<cocos2d::ParticleSystemQuad*>(button_top->getChildByName("Particle_1"));
        assert(particle_);
        auto action = cocos2d::CSLoader::createTimeline(START_BUTTON_TOP_CSB);
        button_top->runAction(action);
        action->gotoFrameAndPlay(0, true);

        cocos2d::ClippingNode* clipping = cocos2d::ClippingNode::create(SpriteTextureController::getInstance()->createGameSpriteWithPath(START_BUTTON_CLIPPINT_STENCIL_PATH));
        clipping->setAlphaThreshold(0);
        clipping->addChild(button_top);
        //cocos2d::Node* start_node = cocos2d::CSLoader::createNode(START_BUTTON_BOTTOM_CSB);
        //this->addChild(start_node);
        //button_ = dynamic_cast<cocos2d::ui::Button*>(start_node->getChildByName(ENTER_GAME_ALERT_START_BUTTON_NAME));
        button_ = cocos2d::ui::Button::create("startBubbleBG2.png");
        this->addChild(button_);
        clipping->setPosition(button_->getContentSize().width / 2, button_->getContentSize().height / 2);
        button_->getRendererNormal()->addChild(clipping);
        ButtonEffectController::setButtonZoomScale(button_);
        return true;
    }
    bool GameStartButton::initPinkForm()
    {
        if (!this->init(ENTER_GAME_ALERT_PINK_TRIANGLE_NAME))
        {
            return false;
        }
        particle_->setStartColor(cocos2d::Color4F(cocos2d::Color4B(158, 85, 255, 255)));
        particle_->setStartColorVar(cocos2d::Color4F(cocos2d::Color4B(151, 50, 255, 255)));
        particle_->setEndColor(cocos2d::Color4F(cocos2d::Color4B(158,54,255,255)));
        particle_->setEndColorVar(cocos2d::Color4F(cocos2d::Color4B(143, 43, 255, 255)));
        button_->loadTextureNormal("denglukaishi.png");
        return true;
    }
}