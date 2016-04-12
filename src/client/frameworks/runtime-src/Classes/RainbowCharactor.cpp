#include "RainbowCharactor.h"
#include "SpriteTextureController.h"
#include "BubbleFactory.h"
#include "RainbowSealBubble.h"
#include "RainbowSealManager.h"
#include "GameScene.h"
#include "GameNoopAnimationComponent.h"
#include "GameClingAnimationComponent.h"
#include "GameDefeatAnimationComponent.h"
const int UI_ZORDER_RAINBOW_SEALED_CHARACTOR = -1; //彩虹封印里面的人物
const float CHARACTOR_ARMATURE_SCALE = 0.8f;
namespace bubble_second {
    RainbowCharactor::RainbowCharactor()
    {
        //sealed_bubble_ = nullptr;
        rainbow_swirl_ = nullptr;
        rainbow_background_ = nullptr;
    }

    RainbowCharactor::~RainbowCharactor()
    {
    }

    RainbowCharactor* bubble_second::RainbowCharactor::createWithFile(const std::string& path)
    {
        RainbowCharactor *pRet = new(std::nothrow) RainbowCharactor();
        if (pRet && pRet->initWithFile(path))
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

    bool RainbowCharactor::initWithFile(const std::string& path)
    {
        if (!cocos2d::Node::init())
        {
            return false;

        }         
        this->setArmaturePath(path);
        this->initTexture();
        //this->setVisible(false);
        return true;
    }

    void RainbowCharactor::initTexture()
    {

        this->addCharactorArmature();
        {
            auto bubble = BubbleFactory::getInstance()->createBubbleWithType(kBubbleTransparent);
            bubble->setScale(BUBBLE_IN_RAINBOW_BUBBLE_SCALE);
            bubble->setPosition(BUBBLE_IN_RAINBOW_BUBBLE_POS);
            this->addChild(bubble, 1);
            //this->setSealedBubble(bubble);
        }
        {
            rainbow_swirl_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(RAINBOW_CHARACTOR_SWIRL_PATH);
            this->addChild(rainbow_swirl_, -1);
            rainbow_swirl_->setOpacity(200);
            cocos2d::BlendFunc blend = { GL_SRC_ALPHA, GL_ONE };
            rainbow_swirl_->setBlendFunc(blend);
            cocos2d::RotateBy* rotate = cocos2d::RotateBy::create(8.0f, 360);
            rainbow_swirl_->runAction(cocos2d::RepeatForever::create(rotate));
        }
        {
            rainbow_background_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(RAINBOW_CHARACTOR_BG_PATH);
            //rainbow_background_->setScale(0.9f);
            this->addChild(rainbow_background_, -2);
        }
    }

    void bubble_second::RainbowCharactor::addCharactorArmature()
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        armature_ = Armature::create(this->getArmaturePath());
        //armature_->setPositionX(RAINBOW_CHARACTOR_ARMATURE_POS_X);
        //armature_->getAnimation()->play(RAINBOW_CHARACTOR_ANIMATIOIN_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
        //armature_->setScale(0.8f);
        armature_->setOpacity(0);
        this->addChild(armature_);
        this->playStandbyAnimation();

        this->addChild(GameNoopAnimationComponent::create(armature_, BUBBLE_ANIMATION_NOOP_NAME, CC_CALLBACK_0(RainbowCharactor::playStandbyAnimation, this)));
        this->addChild(GameClingAnimationComponent::create(armature_, BUBBLE_ANIMATION_DEFEAT_NAME, CC_CALLBACK_0(RainbowCharactor::playStandbyAnimation, this)));
        this->addChild(GameDefeatAnimationComponent::create(armature_, BUBBLE_ANIMATION_DEFEAT_NAME));

    }

    void RainbowCharactor::playStandbyAnimation()
    {
        std::vector<std::string> names;
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_2);
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_2);
        armature_->getAnimation()->playWithNames(names);
        armature_->getAnimation()->setMovementEventCallFunc(nullptr);
    }

    void RainbowCharactor::playDefeatAnimation()
    {
        armature_->getAnimation()->play(BUBBLE_ANIMATION_VICTORY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->removeFromParent();
            }
        });
    }

    void RainbowCharactor::beginSealingCharactor()
    {
        //bubble->setSealedCharactor(this);
        //bubble->getParent()->addChild(this, UI_ZORDER_RAINBOW_SEALED_CHARACTOR);
        //this->setVisible(false);
        //cocos2d::Vec2 bubble_pos = bubble->getPosition();
        //this->setPosition(bubble_pos);
        //cocos2d::Node* node = bubble->getParent()->getParent();
        //GameScene* game_scene = dynamic_cast<GameScene*>(node->getParent());
        //using cocostudio::ArmatureDataManager;
        //using cocostudio::Armature;
        //Armature* armature = Armature::create(this->getArmaturePath());
        //armature->setPosition(RAINBOW_CHARACTOR_ARMATURE_ENTER_FROM_LEFT_POS);
        //if (bubble_pos < armature->getPosition())
        //{
        //    armature->setScaleX(-1);
        //}
        //armature->getAnimation()->play(RAINBOW_CHARACTOR_ANIMATIOIN_FLYING_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
        //node->addChild(armature);
        //cocos2d::ccBezierConfig config;
        //config.endPosition = game_scene->convertMapToCsbSpace(bubble_pos);
        //config.controlPoint_1 = armature->getPosition();
        //config.controlPoint_2 = config.endPosition + RAINBOW_CHARACTOR_ARMATURE_BEZIERTO_CONTROLLPOINT_2_OFFS;
        //cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(RAINBOW_CHARACTOR_ARMATURE_BEZIERTO_DURATION, config);
        //cocos2d::Sequence* seq = cocos2d::Sequence::create(bezier, cocos2d::CallFunc::create([=]() {
        //    armature->removeFromParent();
        //    this->setVisible(true);
        //    bubble->changeRainbowColor();
        //}), nullptr);
        //armature->runAction(seq);
        armature_->setScale(0.5f);
        cocos2d::FadeIn* fade = cocos2d::FadeIn::create(0.5f);
        cocos2d::ScaleTo* scale_1 = cocos2d::ScaleTo::create(0.4f, CHARACTOR_ARMATURE_SCALE+0.2f);
        cocos2d::ScaleTo* scale_2 = cocos2d::ScaleTo::create(0.2f, CHARACTOR_ARMATURE_SCALE - 0.2f);
        cocos2d::ScaleTo* scale_3 = cocos2d::ScaleTo::create(0.1f, CHARACTOR_ARMATURE_SCALE);
        cocos2d::Sequence* seq = cocos2d::Sequence::create(fade, scale_1, scale_2, scale_3, nullptr);
        armature_->runAction(seq);
    }
    void RainbowCharactor::moveSealintCharactor(RainbowSealBubble* bubble, const cocos2d::Vec2& from_point)
    {
        if (!bubble)
        {
            this->removeFromParent();
            return;
        }
        this->setVisible(false);
        cocos2d::Vec2 bubble_pos = bubble->getPosition();
        this->setPosition(bubble_pos);
        //bubble->setSealedCharactor(this);
        cocos2d::Node* node = bubble->getParent();
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature* armature = Armature::create(this->getArmaturePath());
        armature->setPosition(from_point);
        if (bubble_pos < armature->getPosition())
        {
            armature->setScaleX(-1);
        }
        armature->getAnimation()->play(RAINBOW_CHARACTOR_ANIMATIOIN_FLYING_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
        node->addChild(armature);
        cocos2d::ccBezierConfig config;
        config.endPosition = bubble_pos;
        config.controlPoint_1 = armature->getPosition();
        config.controlPoint_2 = config.endPosition + RAINBOW_CHARACTOR_ARMATURE_BEZIERTO_CONTROLLPOINT_2_OFFS;
        cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(RAINBOW_CHARACTOR_ARMATURE_MOVE_DURATION, config);
        cocos2d::Sequence* seq = cocos2d::Sequence::create(bezier, cocos2d::CallFunc::create([=]() {
            armature->removeFromParent();
            this->setVisible(true);
            bubble->changeRainbowColor();
        }), nullptr);
        armature->runAction(seq);
    }

    void RainbowCharactor::setRainbowColor(BubbleType color)
    {
        //this->getSealedBubble()->setBubbleType(color);
        rainbow_background_->setColor(RainbowSealManager::getInstance()->getColor3BWithBubbleColor(color));
    }

    void RainbowCharactor::setArmaturePath(const std::string& path)
    {
        armature_path_ = path;
    }

    std::string RainbowCharactor::getArmaturePath()
    {
        return armature_path_;
    }

    void RainbowCharactor::playContactAnimation()
    {
        armature_->getAnimation()->play(BUBBLE_ANIMATION_CONTACT_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->playStandbyAnimation();
            }
        });
    }

    //void RainbowCharactor::setSealedBubble(BaseBubble* bubble)
    //{
    //    sealed_bubble_ = bubble;
    //}

    //BaseBubble* RainbowCharactor::getSealedBubble()
    //{
    //    return sealed_bubble_;
    //}
}