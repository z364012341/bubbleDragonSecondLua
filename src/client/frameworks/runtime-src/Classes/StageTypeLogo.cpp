#include "StageTypeLogo.h"
#include "SpriteTextureController.h"
#include "GameScoreController.h"
const std::string STAGE_LOGO_FLASH_PATH = "wsparticle_star02.png";
const float BEZIER_FLYING_DURATION = 1.5f; //得分挂件的赛贝尔运动时间
namespace bubble_second {
    StageTypeLogo::StageTypeLogo()
    {
    }

    void StageTypeLogo::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_MUTIPLE_SEAL_BUBBLE_FLY, CC_CALLBACK_1(StageTypeLogo::completeTaskBubbleFly, this));
        if (stage_type_ == kTopEliminate)
        {
            cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_TOP_ELIMINATE_BUBBLE_FLY, CC_CALLBACK_1(StageTypeLogo::completeTaskBubbleFly, this));
        }
    }

    void StageTypeLogo::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_MUTIPLE_SEAL_BUBBLE_FLY);
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_TOP_ELIMINATE_BUBBLE_FLY);
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
        type_sprite_ = SpriteTextureController::getInstance()->createStageTypeSprite(type);
        this->addChild(type_sprite_);
        stage_type_ = type;
        return true;
    }

    void StageTypeLogo::completeTaskBubbleFly(cocos2d::EventCustom * event)
    {
        //MutipleSealBubble* bubble = static_cast<MutipleSealBubble*>(event->getUserData());
        //cocostudio::Armature* armature = bubble->getBubbleEliminateArmature();
        //this->addChild(armature, 1);
        //armature->setPosition(this->convertToNodeSpace(bubble->getParent()->convertToWorldSpace(bubble->getPosition())));

        //armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
        //    if (movementType == cocostudio::COMPLETE)
        //    {
        //        cocos2d::ccBezierConfig config;
        //        config.endPosition = this->getPosition();
        //        config.controlPoint_1 = this->getPosition();
        //        config.controlPoint_2 = cocos2d::Vec2(0.0f, 0.0f);
        //        cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, config);
        //        cocos2d::ScaleTo* scale = cocos2d::ScaleTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, 0.1f);
        //        cocos2d::Sequence* seq = cocos2d::Sequence::create(cocos2d::Spawn::createWithTwoActions(bezier, scale), cocos2d::DelayTime::create(0.1f), 
        //            cocos2d::CallFunc::create([=]() {
        //                this->playLogoFlash();
        //            }), cocos2d::DelayTime::create(0.83f), cocos2d::CallFunc::create([=]() {
        //            armature->removeFromParent();
        //            bubble->bubbleEliminateFlyCallfunc();
        //        }), nullptr);
        //        armature->runAction(seq);
        //    }
        //});
        cocos2d::Node* node = static_cast<cocos2d::Node*>(event->getUserData());
        node->setPosition(this->convertToNodeSpace(node->getPosition()));
        this->addChild(node,1);
        cocos2d::ccBezierConfig config;
        config.endPosition = this->getPosition();
        config.controlPoint_1 = this->convertToNodeSpace(cocos2d::Vec2(GAME_DESIGN_RESOLUTION_WIDTH/2, GAME_DESIGN_RESOLUTION_HEIGHT/2));
        config.controlPoint_2 = this->getPosition();
        cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(BEZIER_FLYING_DURATION, config);
        cocos2d::ScaleTo* scale = cocos2d::ScaleTo::create(BEZIER_FLYING_DURATION, 0.1f);
        cocos2d::Sequence* seq = cocos2d::Sequence::create(cocos2d::Spawn::createWithTwoActions(bezier, scale), cocos2d::DelayTime::create(0.1f),
            cocos2d::CallFunc::create([=]() {
            this->playLogoFlash();
        }), cocos2d::DelayTime::create(0.83f), cocos2d::CallFunc::create([=]() {
            node->removeFromParent();
            GameScoreController::getInstance()->addCompletedTaskNumble();
        }), nullptr);
        node->runAction(seq);
    }

    void StageTypeLogo::playLogoFlash()
    {
        cocos2d::Sprite* flash = SpriteTextureController::getInstance()->createGameSpriteWithPath(STAGE_LOGO_FLASH_PATH);
        //flash->setScale(0.5f);
        this->addChild(flash);
        flash->runAction(cocos2d::Sequence::create(cocos2d::ScaleTo::create(0.375f, 2.0f),
            cocos2d::Spawn::createWithTwoActions(cocos2d::ScaleTo::create(0.49f, 1.0f), cocos2d::FadeOut::create(0.49f)),
            cocos2d::CallFunc::create([=]() {
            flash->removeFromParent();
        }), nullptr));
        flash->runAction(cocos2d::RotateTo::create(0.83f, 110.0f));
        type_sprite_->runAction(cocos2d::Sequence::create(cocos2d::ScaleTo::create(0.17f, 0.7f, 1.4f), 
            cocos2d::ScaleTo::create(0.2f, 1.0f), 
            cocos2d::ScaleTo::create(0.17f, 1.3f, 1.0f), 
            cocos2d::ScaleTo::create(0.17f, 1.0f), 
            nullptr));
    }

}