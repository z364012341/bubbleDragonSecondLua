#include "SkillColorBombBubble.h"
#include "cocostudio\CocoStudio.h"
const std::string SKILL_COLOR_BOMB_ARMATURE_NAME = "juesejinengTX2";
const std::string SKILL_ELIMINATE_ARMATURE_NAME = "baoshi TX";
namespace bubble_second {
    bool SkillColorBombBubble::init()
    {
        if (!ColorBombBubble::init())
        {
            return false;
        }
        return true;
    }
    SkillColorBombBubble::SkillColorBombBubble()
    {
    }


    SkillColorBombBubble::~SkillColorBombBubble()
    {
    }
    void SkillColorBombBubble::setBubbleTexture(BubbleType)
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        cocostudio::Armature* armature = Armature::create(SKILL_COLOR_BOMB_ARMATURE_NAME);
        armature->getAnimation()->playWithIndex(0);
        this->addChild(armature);
    }
    std::string SkillColorBombBubble::getBubbleSightingDevicePointPath()
    {
        return "skill_color.png";
    }
    void SkillColorBombBubble::bubbleEliminate(int)
    {
        cocos2d::ParticleSystemQuad* particle = cocos2d::ParticleSystemQuad::create(SKILL_BOMB_BUBBLE_PARTICLE);
        this->getParent()->addChild(particle, SKILL_BUBBLE_PARTICLE_ZORDER);
        particle->setPosition(this->getPosition());
        particle->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.5f), cocos2d::CallFunc::create([=]() {
            particle->removeFromParent();
        })));
        ColorBombBubble::bubbleEliminate();
    }
    float SkillColorBombBubble::playTheSpecialEffects()
    {
        cocos2d::Node* parent_node = this->getParent();
        if (!parent_node)
        {
            return 0.0;
        }
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        this->setVisible(false);
        Armature *armature = Armature::create(SKILL_ELIMINATE_ARMATURE_NAME);
        armature->setPosition(this->getPosition());
        armature->getAnimation()->play(SKILL_ELIMINATE_ARMATURE_NAME);
        armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                armature->removeFromParent();
            }
        });
        parent_node->addChild(armature);
        return 0.0f;
    }
    void SkillColorBombBubble::dispatchEventAfterShooted()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_HAVE_USED_SKILL);
    }
}