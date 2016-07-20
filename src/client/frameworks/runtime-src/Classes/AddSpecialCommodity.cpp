#include "AddSpecialCommodity.h"
#include "GameAlertMask.h"
#include "GameTextInfo.h"
#include "cocostudio\CocoStudio.h"
//const std::string ADD_SPECIAL_COMMODITY_CSB_PATH = "AddSpecialCommodity.csb";
namespace bubble_second {
    //cocos2d::Node * AddSpecialCommodity::createCommodityArmature()
    //{
    //    cocos2d::Node* node = cocos2d::Node::create();
    //    GameAlertMask* mask = GameAlertMask::create();
    //    node->addChild(mask);
    //    cocostudio::Armature* armature = cocostudio::Armature::create(ADD_SPECIAL_ANIMATION_NAME);
    //    armature->getAnimation()->playWithIndex(0);
    //    armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
    //        if (movementType == cocostudio::COMPLETE)
    //        {
    //            mask->backgroundFadeOut(BACKGROUND_FADEOUT_DURATION, cocos2d::CallFunc::create([=]() {
    //                node->removeFromParent();
    //                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_END_ADD_BUBBLT_ANIMATION);
    //            }));
    //        }
    //    });
    //    node->addChild(armature);
    //    return node;
    //}
    AddSpecialCommodity::AddSpecialCommodity()
    {
    }


    AddSpecialCommodity::~AddSpecialCommodity()
    {
    }

    bool AddSpecialCommodity::init()
    {
        if (!EnterGamePropsView::init(BUBBLE_ADD_SPECIAL_BUBBLE_PROP_KEY))
        {
            return false;
        }
        //this->setCostLabelStringWithKey(BUBBLE_ADD_SPECIAL_BUBBLE_PROP_KEY);
        this->setName(ADD_SPECIAL_COMMODITY_NAME);
        return true;
    }
}