#include "AddBubbleNumbleCommodity.h"
#include "GameScoreController.h"
#include "GameAlertMask.h"
#include "cocostudio\CocoStudio.h"
//const std::string ENTER_GAME_PROPS_VIEW_ADD_BUBBLE_PROPS_PATH = GAME_COMMODITY_TEN_BUBBLE_PATH;
//const std::string ADD_BUBBLE_NUMBLE_COMMODITY_CSB_PATH = "AddBubbleNumbleCommodity.csb";


namespace bubble_second {
    //cocos2d::Node * AddBubbleNumbleCommodity::createCommodityArmature()
    //{
    //    cocos2d::Node* node = cocos2d::Node::create();
    //    GameAlertMask* mask = GameAlertMask::create();
    //    node->addChild(mask);
    //    cocostudio::Armature* armature = cocostudio::Armature::create(ADD_BUBBLE_NUMBLE_ANIMATION_NAME);
    //    armature->getAnimation()->playWithIndex(0);
    //    armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
    //        if (movementType == cocostudio::COMPLETE)
    //        {
    //            mask->backgroundFadeOut(BACKGROUND_FADEOUT_DURATION, cocos2d::CallFunc::create([=]() {
    //                node->removeFromParent();
    //                GameScoreController::getInstance()->addBubbleUseCount(EnterPropsViewManager::getInstance()->getAddBubbleNumblePropsNumble());
    //                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_END_ADD_BUBBLT_ANIMATION);
    //            }));
    //        }
    //    });
    //    node->addChild(armature);
    //    return node;
    //}

    AddBubbleNumbleCommodity::AddBubbleNumbleCommodity()
    {
    }


    AddBubbleNumbleCommodity::~AddBubbleNumbleCommodity()
    {
    }

    bool AddBubbleNumbleCommodity::init()
    {
        if (!EnterGamePropsView::init(BUBBLE_ADD_BUBBLE_NUMBLE_PROP_KEY))
        {
            return false;
        }
        //this->setCostLabelStringWithKey(BUBBLE_ADD_BUBBLE_NUMBLE_PROP_KEY);
        //this->setName(ADD_BUBBLE_NUMBLE_COMMODITY_NAME);
        return true;
    }
}