#include "BombBombBubble.h"
#include "cocostudio/CocoStudio.h"
#include "GameScoreController.h"
#include "cocostudio\CocoStudio.h"
const std::string BOMB_BOMB_BUBBLE_CENTER_FIRE_NAME = "huoqiuTX";
namespace bubble_second {
    BombBombBubble::BombBombBubble()
    {
    }


    BombBombBubble::~BombBombBubble()
    {
    }

    bool BombBombBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleBombBomb);
        this->addCenterFire();
        return true;
    }

    void BombBombBubble::addCenterFire()
    {
        cocostudio::Armature* fire = cocostudio::Armature::create(BOMB_BOMB_BUBBLE_CENTER_FIRE_NAME);
        fire->getAnimation()->playWithIndex(0);
        fire->setPosition(this->getContentSize().width/2, this->getContentSize().height/2);
        this->addChild(fire);
    }

    void BombBombBubble::downFromAir()
    {
        this->bubbleEliminate();
    }

    void BombBombBubble::bubbleEliminate(int combo)
    {
        BaseBubble::bubbleEliminate();
    }

    float BombBombBubble::playTheSpecialEffects()
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        if (cocos2d::Node* parent = this->getParent())
        {
            Armature *armature = Armature::create(ONE_ROUND_BOMB_EFFECT_NAME);
            armature->setPosition(this->getPosition());
            armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    armature->removeFromParent();
                }
            });
            parent->addChild(armature);
            return ONE_ROUND_BOMB_EFFECT_DELAY_TIME;
        }
        return 0.0f;
    }
}