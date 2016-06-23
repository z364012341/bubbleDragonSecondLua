#include "SkillBigBombBubble.h"
const std::string SKILL_BIG_BOMB_ARMATURE_NAME = "juesejinengTX4";
namespace bubble_second {
    SkillBigBombBubble::SkillBigBombBubble()
    {
    }

    bool SkillBigBombBubble::init()
    {
        if (!BombPropertyBubble::init())
        {
            return false;
        }
        return true;
    }


    SkillBigBombBubble::~SkillBigBombBubble()
    {
    }
    void SkillBigBombBubble::setBubbleTexture(BubbleType)
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        cocostudio::Armature* armature = Armature::create(SKILL_BIG_BOMB_ARMATURE_NAME);
        armature->getAnimation()->playWithIndex(0);
        this->addChild(armature);
    }
    std::string SkillBigBombBubble::getBubbleSightingDevicePointPath()
    {
        return BUBBLE_SIGHTING_POINT_PATH;
    }
    float SkillBigBombBubble::playTheSpecialEffects()
    {
        cocos2d::Node* parent_node = this->getParent();
        if (!parent_node)
        {
            return 0.0;
        }
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        this->setVisible(false);
        Armature *armature = Armature::create(TWO_ROUND_BOMB_EFFECT_NAME);
        armature->setPosition(this->getPosition());
        armature->getAnimation()->play(BOMB_BUBBLE_BOMB_BOMB_NAME);
        armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                armature->removeFromParent();
            }
        });
        parent_node->addChild(armature);
        return 0.0f;
    }
    void SkillBigBombBubble::bubbleEliminate(int)
    {
        cocos2d::ParticleSystemQuad* particle = cocos2d::ParticleSystemQuad::create(SKILL_BOMB_BUBBLE_PARTICLE);
        this->getParent()->addChild(particle, SKILL_BUBBLE_PARTICLE_ZORDER);
        particle->setPosition(this->getPosition());
        particle->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.5f), cocos2d::CallFunc::create([=]() {
            particle->removeFromParent();
        })));
        BombPropertyBubble::bubbleEliminate();
    }
    void SkillBigBombBubble::dispatchEventAfterShooted()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_HAVE_USED_SKILL);
    }
}