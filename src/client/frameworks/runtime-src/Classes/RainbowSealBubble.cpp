#include "RainbowSealBubble.h"
#include "BubbleComponent.h"
#include "GamePlayController.h"
#include "RainbowSealManager.h"
#include "BubbleFactory.h"
#include "RainbowCharactor.h"
#include "SpriteTextureController.h"
namespace bubble_second {
    RainbowSealBubble::RainbowSealBubble()
    {
        first_flag_ = true;
        sealed_charactor_ = nullptr;
    }

    RainbowSealBubble::~RainbowSealBubble()
    {
    }

    bool RainbowSealBubble::init()
    {
        if (!BaseComponentBubble::init())
        {
            return false;
        }
        this->addStandbyAnimation();
        this->setBubbleType(kBubbleRainbowSeal);
        this->setRainbowColor(kBubbleTransparent);
        this->setSupensionPoint(true);
        this->setBubbleComponentNumble(BUBBLE_REABOW_SEAL_COMPONENT_NUMBLE);
        this->addGameTaskNumble();
        this->runAction(cocos2d::CallFunc::create([=]() {       
            RainbowSealManager::getInstance()->addRainbowSealBubble(this);
        }));
        return true;
    }

    void RainbowSealBubble::setBubbleTexture(BubbleType type)
    {
        if (type >= 0)
        {
            //this->setSpriteFrame(BubbleFactory::getInstance()->getPathWithType(type));
            this->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath(BubbleFactory::getInstance()->getPathWithType(type)), 1);
        }
    }

    bool RainbowSealBubble::isEqualRainbowColor(BubbleType color)
    {
        return color == this->getRainbowColor();
    }

    bool RainbowSealBubble::isSealing()
    {
        return sealed_charactor_!=nullptr;
    }

    BubbleVector RainbowSealBubble::disposeRainbowSeal(BubbleType color)
    {
        //BubbleVector vector(0);
        if (this->isEqualRainbowColor(color))
        {   
            return this->getTotalBubbles();
        }
        else
        {
            this->changeRainbowColor();
        }
        return BubbleVector(0);
    }

    BubbleType RainbowSealBubble::getRainbowColor()
    {
        return rainbow_color_;
    }

    void RainbowSealBubble::changeRainbowColor()
    {
        if (this->isSealing())
        {
            BubbleType color = this->getRainbowColor();
            do
            {
                color = GamePlayController::getInstance()->getBubbleColorFromPicker();
            } while (color == this->getRainbowColor());
            this->setRainbowColor(color);
        }
    }

    void RainbowSealBubble::setRainbowColor(BubbleType color)
    {
        GamePlayController::getInstance()->addPrepareColor(color);
        GamePlayController::getInstance()->subtractPrepareColor(getRainbowColor());
        rainbow_color_ = color;
        if (this->isSealing())
        {
            sealed_charactor_->setRainbowColor(rainbow_color_);
        }
    }

    //void RainbowSealBubble::setSealedCharactor(RainbowCharactor* charactor)
    //{
    //    sealed_charactor_ = charactor;
    //}

    //RainbowCharactor * RainbowSealBubble::getSealedCharactor()
    //{
    //    return sealed_charactor_;
    //}

    void RainbowSealBubble::bubbleEliminate(int combo)
    {
        this->addCompletedTaskNumble();

        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature *armature = Armature::create(RAINBOW_BUBBLE_ARMATURE_NAME);
        armature->setScale(0.87f);
        armature->setPosition(-13.0f, -2.0f);
        armature->getAnimation()->play(RAINBOW_BUBBLE_ARMATURE_BOMB_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                RainbowSealManager::getInstance()->moveSealedCharactor(this);
                this->removeFromParent();
            }
        });
        this->addChild(armature, 1);
    }

    void RainbowSealBubble::downFromAir()
    {
        //this->bubbleEliminate();
    }

    void RainbowSealBubble::addStandbyAnimation()
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature *armature = Armature::create(RAINBOW_BUBBLE_ARMATURE_NAME);
        armature->setScale(0.87f);
        armature->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
        armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::START)
            {
                armature->setVisible(true);
            }
            if (movementType == cocostudio::COMPLETE)
            {
                armature->setVisible(false);
            }
        });
        this->addChild(armature, 1);
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(10.0f), cocos2d::CallFunc::create([=]() {
            if (this->isSealing())
            {
                armature->getAnimation()->play(RAINBOW_BUBBLE_ARMATURE_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            }

        }));
        armature->runAction(cocos2d::RepeatForever::create(seq));

        if (sealed_charactor_)
        {
            sealed_charactor_->playDefeatAnimation();
        }
    }

    void RainbowSealBubble::addRainbowCharactor()
    {
        sealed_charactor_ = RainbowCharactor::createWithFile(RAINBOW_CHARACTOR_ARMATURE_NAME);
        sealed_charactor_->setPosition(this->getContentSize().width/2, this->getContentSize().height / 2);
        this->addChild(sealed_charactor_);
    }

    void RainbowSealBubble::runBubbleEffect(const std::string& name, const cocos2d::Vec2& point)
    {
        BaseComponentBubble::runBubbleEffect(name, point);
        if (sealed_charactor_)
        {
            sealed_charactor_->playContactAnimation();
        }
    }

    void RainbowSealBubble::beginSealingCharactor()
    {
        this->addRainbowCharactor();
        sealed_charactor_->beginSealingCharactor();
        this->changeRainbowColor();
    }
}