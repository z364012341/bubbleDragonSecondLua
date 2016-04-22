#include "StageTypeLogo.h"
#include "SpriteTextureController.h"
#include "MutipleSealBubble.h"
namespace bubble_second {
    StageTypeLogo::StageTypeLogo()
    {
    }

    void StageTypeLogo::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_MUTIPLE_SEAL_BUBBLE_FLY, CC_CALLBACK_1(StageTypeLogo::mutipleSealBubbleFly, this));
    }

    void StageTypeLogo::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_MUTIPLE_SEAL_BUBBLE_FLY);
    }

    StageTypeLogo * StageTypeLogo::create(const StageType & type)
    {
        StageTypeLogo *pRet = new(std::nothrow) StageTypeLogo();
        if (pRet && pRet->initWithType(type))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    StageTypeLogo::~StageTypeLogo()
    {
    }

    bool StageTypeLogo::initWithType(const StageType & type)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(SpriteTextureController::getInstance()->createMenuStageTypeSprite(type));
        return true;
    }

    void StageTypeLogo::mutipleSealBubbleFly(cocos2d::EventCustom * event)
    {
        MutipleSealBubble* bubble = static_cast<MutipleSealBubble*>(event->getUserData());
        cocostudio::Armature* armature = bubble->getBubbleEliminateArmature();
        this->addChild(armature);
        armature->setPosition(this->convertToNodeSpace(bubble->getParent()->convertToWorldSpace(bubble->getPosition())));

        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                cocos2d::ccBezierConfig config;
                config.endPosition = this->getPosition();
                config.controlPoint_1 = this->getPosition();
                config.controlPoint_2 = cocos2d::Vec2(0.0f, 0.0f);
                cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, config);
                cocos2d::ScaleTo* scale = cocos2d::ScaleTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, 0.1f);
                cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::Spawn::createWithTwoActions(bezier, scale), cocos2d::CallFunc::create([=]() {
                    armature->removeFromParent();
                    bubble->bubbleEliminateFlyCallfunc();
                }));
                armature->runAction(seq);
            }
        });
    }

}