#include "GameDefeatAnimationComponent.h"
#include "BubbleSecondConstant.h"

namespace bubble_second {
    GameDefeatAnimationComponent::GameDefeatAnimationComponent()
    {
    }

    bool GameDefeatAnimationComponent::init(cocostudio::Armature * armature, const std::string& noop_name)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        armature_ = armature;
        animation_name_ = noop_name;
        //animation_end_func_ = animation_end_func;
        return true;
    }


    GameDefeatAnimationComponent * GameDefeatAnimationComponent::create(cocostudio::Armature * armature, const std::string & noop_name)
    {
        GameDefeatAnimationComponent *pRet = new(std::nothrow) GameDefeatAnimationComponent();
        if (pRet && pRet->init(armature, noop_name))
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

    GameDefeatAnimationComponent::~GameDefeatAnimationComponent()
    {
    }


    void GameDefeatAnimationComponent::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_GAME_DEFEAT, [=](cocos2d::EventCustom* event) {
            this->playDefeatAnimation();
        });
    }

    void GameDefeatAnimationComponent::playDefeatAnimation()
    {
        if (armature_->getAnimation()->getCurrentMovementID() != animation_name_)
        {
            armature_->getAnimation()->play(animation_name_, SPECIAL_BUBBLE_EFFECT_DURATION, true);
            armature_->getAnimation()->setMovementEventCallFunc(nullptr);
        }
    }
}
