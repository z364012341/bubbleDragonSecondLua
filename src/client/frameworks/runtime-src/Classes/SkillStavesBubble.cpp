#include "SkillStavesBubble.h"
#include "cocostudio\CocoStudio.h"
#include "GameAudioController.h"
const std::string SKILL_STAVES_BUBBLE_ARMATURE_1_NAME = "juesejinengTX1";
const std::string SKILL_STAVES_BUBBLE_PARTICLE_PATH = "particle/lanseTX.plist";
namespace bubble_second {
    SkillStavesBubble::SkillStavesBubble()
    {
    }

    bool SkillStavesBubble::init()
    {
        if (!ColorBubble::initWithTypeAndCloud(kBubbleSkillStavesBubble))
        {
            return false;
        }
        this->setName(STAVES_BUBBLE_NAME);
        this->addBubblePrepareBody();
        return true;
    }

    void SkillStavesBubble::setBubbleTexture(BubbleType)
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature* armature = Armature::create(SKILL_STAVES_BUBBLE_ARMATURE_1_NAME);
        armature->getAnimation()->playWithIndex(0);
        this->addChild(armature, 1);
    }

    void SkillStavesBubble::dispatchEventAfterShooted()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_HAVE_USED_SKILL);
    }


    SkillStavesBubble::~SkillStavesBubble()
    {
    }
    void SkillStavesBubble::bubbleEliminate(int)
    {
        cocos2d::ParticleSystemQuad* particle = cocos2d::ParticleSystemQuad::create(SKILL_STAVES_BUBBLE_PARTICLE_PATH);
        this->getParent()->addChild(particle, SKILL_BUBBLE_PARTICLE_ZORDER);
        particle->setPosition(this->getPosition());
        particle->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.5f), cocos2d::CallFunc::create([=]() {
            particle->removeFromParent();
        })));
        this->removeFromParent();
        GameAudioController::getInstance()->playSkillStavesBubbleEliminatedEffect();
    }
    std::string SkillStavesBubble::getBubbleSightingDevicePointPath()
    {
        return "skill_staves.png";
    }
}