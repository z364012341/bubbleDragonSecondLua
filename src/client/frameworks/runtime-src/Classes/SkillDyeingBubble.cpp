#include "SkillDyeingBubble.h"
const std::string DYEING_BUBBLE_ARMATURE_NAME = "ranseqiu";
const std::string ARMATURE_BONE_1_NAME = "Layer2";
const std::string ARMATURE_BONE_2_NAME = "Layer13";
namespace bubble_second {
    SkillDyeingBubble::SkillDyeingBubble()
    {
        type_to_skin_numble_1_[kBubblePurple] = 0;
        type_to_skin_numble_1_[kBubbleRed] = 1;
        type_to_skin_numble_1_[kBubbleBlue] = 2;
        type_to_skin_numble_1_[kBubbleOrange] = 3;
        type_to_skin_numble_1_[kBubbleGreen] = 4;
        type_to_skin_numble_1_[kBubbleYellow] = 5;

        type_to_skin_numble_2_[kBubblePurple] = 0;
        type_to_skin_numble_2_[kBubbleGreen] = 1;
        type_to_skin_numble_2_[kBubbleBlue] = 2;
        type_to_skin_numble_2_[kBubbleYellow] = 3;
        type_to_skin_numble_2_[kBubbleRed] = 4;
        type_to_skin_numble_2_[kBubbleOrange] = 5;
    }

    bool SkillDyeingBubble::init()
    {
        if (!ColorBubble::initWithTypeAndCloud(kBubbleSkillDyeingBubble))
        {
            return false;
        }
        this->setName(DYEING_BUBBLE_NAME);
        this->addBubblePrepareBody();
        return true;
    }


    SkillDyeingBubble::~SkillDyeingBubble()
    {
    }

    void SkillDyeingBubble::setBubbleTexture(BubbleType type)
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        Armature* armature = Armature::create(DYEING_BUBBLE_ARMATURE_NAME);
        armature->getAnimation()->playWithIndex(0);
        this->addChild(armature, 1);
        armature_ = armature;
    }
    void SkillDyeingBubble::dispatchEventAfterShooted()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_HAVE_USED_PROPS);
    }
    void SkillDyeingBubble::bubbleEliminate(int)
    {
        this->removeFromParent();
    }
    void SkillDyeingBubble::setDyeingColor(BubbleType type)
    {//×ÏºìÀ¶³ÈÂÌ»Æ
        armature_->getBone(ARMATURE_BONE_1_NAME)->changeDisplayWithIndex(type_to_skin_numble_1_[type], true);
        armature_->getBone(ARMATURE_BONE_2_NAME)->changeDisplayWithIndex(type_to_skin_numble_2_[type], true);
        dyeing_color_ = type;
    }
    BubbleType SkillDyeingBubble::getDyeingColor()
    {
        return dyeing_color_;
    }
}