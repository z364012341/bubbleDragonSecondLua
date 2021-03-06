#include "PropsNumbleShow.h"
#include "SpriteTextureController.h"
#include "BubbleSecondConstant.h"
#include "XMLTool.h"
#include "UserDataManager.h"
//#include "cocostudio\CocoStudio.h"
#include "ExhibitionNumble.h"
#include "GameSinglePropBuyAlert.h"
#include "SmartScaleController.h"
#include "GameSinglePropBuyAlertFactory.h"
const std::string PLUS_SPRITE_PATH = "plus.png";
//const cocos2d::Vec2 PROPS_NUMBLE_SHOW_POSITION = cocos2d::Vec2(35.0f, -35.0f);
namespace bubble_second {
    PropsNumbleShow::PropsNumbleShow()
    {
    }

    PropsNumbleShow* bubble_second::PropsNumbleShow::create(const std::string& prop_key)
    {
        PropsNumbleShow *pRet = new(std::nothrow) PropsNumbleShow();
        if (pRet && pRet->init(prop_key))
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

    bool PropsNumbleShow::init(const std::string& prop_key)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        prop_key_ = prop_key;
        //this->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_NUMBLE_DISABLED_PATH));
        //props_numble_label_ = cocos2d::ui::TextAtlas::create(
        //    "", PROPS_NUMBLE_LABEL_PATH, PROPS_NUMBLE_LABEL_ITEM_WIDTH, PROPS_NUMBLE_LABEL_ITEM_HEIGHT, ".");
        //props_numble_label_->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
        //props_numble_label_->setPosition(cocos2d::Vec2(-3, 3));
        //this->addChild(props_numble_label_);
        //this->setPosition(PROPS_NUMBLE_SHOW_POSITION);
        props_numble_label_ = ExhibitionNumble::create();
        this->addChild(props_numble_label_);
        plus_sprite_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(PLUS_SPRITE_PATH);
        plus_sprite_->setPosition(cocos2d::Vec2(2.0f, -2.0f));
        this->addChild(plus_sprite_);
        this->updateLabel();
        return true;
    }

    void PropsNumbleShow::updateLabel()
    {
        props_numble_label_->setString(XMLTool::convertIntToString(UserDataManager::getInstance()->getPropsNumbleWithKey(prop_key_)));
        plus_sprite_->setVisible(this->isNoneProp());
    }

    bool PropsNumbleShow::isNoneProp()
    {
        return UserDataManager::getInstance()->getPropsNumbleWithKey(prop_key_) == 0;
    }
    PropsNumbleShow::~PropsNumbleShow()
    {
    }
    //void PropsNumbleShow::addPropNumble(int numble)
    //{
    //    UserDataManager::getInstance()->setPropsNumbleWithKey(prop_key_, UserDataManager::getInstance()->getPropsNumbleWithKey(prop_key_) + numble);
    //    this->updateLabel();
    //}
    bool PropsNumbleShow::cutPropNumble()
    {
        if (this->isNoneProp())
        {
            //this->addPropNumble(3);
            //std::string key = prop_key_;
            //cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_POP_GAME_STORE, &key);
            //GameSinglePropBuyAlert* alert = GameSinglePropBuyAlert::createWithPropKey(prop_key_);
            //alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
            //alert->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width / 2, cocos2d::Director::getInstance()->getVisibleSize().height / 2);
            //cocos2d::Scene* running_scene = cocos2d::Director::getInstance()->getRunningScene();
            //running_scene->addChild(alert);
            GameSinglePropBuyAlertFactory::getInstance()->popGameSinglePropBuyAlertWithKey(prop_key_);
            return false;
        }
        UserDataManager::getInstance()->cutPropsNumbleWithKey(prop_key_);
        this->updateLabel();
        return true;
    }
    void PropsNumbleShow::setPropNumble(int numble)
    {
        UserDataManager::getInstance()->setPropsNumbleWithKey(prop_key_, numble);
        this->updateLabel();
    }
    void PropsNumbleShow::onEnter()
    {
        cocos2d::Node::onEnter();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_UPDATE_PROPS_NUMBLE_LABEL, [=](cocos2d::EventCustom* event) {
            this->updateLabel();
        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener_, 2);
    }
    void PropsNumbleShow::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
    }
}