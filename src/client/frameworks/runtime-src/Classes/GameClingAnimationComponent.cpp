#include "GameClingAnimationComponent.h"
#include "BubbleSecondConstant.h"

namespace bubble_second {
    GameClingAnimationComponent::GameClingAnimationComponent()
    {
    }

    bool GameClingAnimationComponent::init(cocostudio::Armature * armature, const std::string& noop_name, std::function<void()> animation_end_func)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        armature_ = armature;
        animation_name_ = noop_name;
        animation_end_func_ = animation_end_func;
        return true;
    }


    GameClingAnimationComponent * GameClingAnimationComponent::create(cocostudio::Armature * armature, const std::string & noop_name, std::function<void()> animation_end_func)
    {
        GameClingAnimationComponent *pRet = new(std::nothrow) GameClingAnimationComponent();
        if (pRet && pRet->init(armature, noop_name, animation_end_func))
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

    GameClingAnimationComponent::~GameClingAnimationComponent()
    {
    }


    void GameClingAnimationComponent::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_BUBBLE_CLING, [=](cocos2d::EventCustom* event) {
            this->playClingAnimation();
        });
    }

    void GameClingAnimationComponent::playClingAnimation()
    {
        if (armature_->getAnimation()->getCurrentMovementID() != animation_name_)
        {
            armature_->getAnimation()->play(animation_name_);
            armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    //armature_->getAnimation()->setMovementEventCallFunc(nullptr);
                    if (animation_end_func_ != nullptr)
                    {
                        animation_end_func_();
                    }
                }
            });
        }
    }
}