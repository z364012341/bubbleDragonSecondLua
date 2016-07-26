#include "EnterGamePropsView.h"
#include "GameAlertMask.h"
#include "EnterPropsViewManager.h"
#include "cocostudio\CocoStudio.h"
#include "GameTextInfo.h"
#include "GamePropsCostTag.h"
#include "GameButtonFactory.h"
#include "StageDataManager.h"
#include "GameUnitPriceManager.h"
#include "GameAudioController.h"
const std::map<std::string, std::string> COMMODITY_TO_CSB_PATH = {
    { BUBBLE_ADD_BUBBLE_NUMBLE_PROP_KEY , "AddBubbleNumbleCommodity.csb" },
    { BUBBLE_AIMING_LINE_PROP_KEY , "AimingLineCommodity.csb" },
    { BUBBLE_ADD_SPECIAL_BUBBLE_PROP_KEY , "AddSpecialCommodity.csb" }
};
const std::map<std::string, int> COMMODITY_TO_UNLOCK_STAGE_INDEX = {
    { BUBBLE_ADD_BUBBLE_NUMBLE_PROP_KEY , 20 },
    { BUBBLE_AIMING_LINE_PROP_KEY , 10 },
    { BUBBLE_ADD_SPECIAL_BUBBLE_PROP_KEY , 15 }
};
const std::map<std::string, float> COMMODITY_TO_ANIMATION_END_TIME = {
    { ADD_BUBBLE_NUMBLE_ANIMATION_NAME , 0.92f },
    { AIMING_LINE_COMMODITY_ANIMATION_NAME , 1.625f },
    { ADD_SPECIAL_ANIMATION_NAME , 1.58f }
};
namespace bubble_second {

    EnterGamePropsView::EnterGamePropsView()
    {
    }

    cocos2d::Node * EnterGamePropsView::createCommodityArmature(const std::string& animation_name, const std::string& end_event_name)
    {
        cocos2d::Node* node = cocos2d::Node::create();
        GameAlertMask* mask = GameAlertMask::create();
        node->addChild(mask);
        cocostudio::Armature* armature = cocostudio::Armature::create(animation_name);
        armature->getAnimation()->playWithIndex(0);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                mask->backgroundFadeOut(BACKGROUND_FADEOUT_DURATION, cocos2d::CallFunc::create([=]() {
                    node->removeFromParent();
                    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(end_event_name);
                }));
            }
        });
        node->addChild(armature);
        node->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(COMMODITY_TO_ANIMATION_END_TIME.at(animation_name)), 
            cocos2d::CallFunc::create([=]() {
                GameAudioController::getInstance()->playEnterPropsAnimationEndEffect();
            })
        ));
        return node;
    }

    EnterGamePropsView::~EnterGamePropsView()
    {
    }

    bool EnterGamePropsView::init(const std::string & prop_key)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        prop_key_ = prop_key;
        this->loadView();
        this->disposedEnterPropsUnlock();
        return true;
    }

    void EnterGamePropsView::buttonClickCallfunc(cocos2d::Ref *)
    {
        if (cost_tag_->getSelectedState())
        {
            cost_tag_->changeSelectedState();
            EnterPropsViewManager::getInstance()->setPropsSwitch(this->getName(), cost_tag_->getSelectedState());
            EnterPropsViewManager::getInstance()->cutPrePropsCost(cost_tag_->getCostNumble());
        }
        else if (UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_COIN_KEY) - EnterPropsViewManager::getInstance()->getPrePropsCost() >= cost_tag_->getCostNumble())
        {
            auto a = EnterPropsViewManager::getInstance()->getPrePropsCost();
            auto b = UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_COIN_KEY);
            cost_tag_->changeSelectedState();
            EnterPropsViewManager::getInstance()->setPropsSwitch(this->getName(), cost_tag_->getSelectedState());
            EnterPropsViewManager::getInstance()->addPrePropsCost(cost_tag_->getCostNumble());
        }
    }

    void EnterGamePropsView::disposedEnterPropsUnlock()
    {
        if (!UserDataManager::getInstance()->isSkillAndPropsUnlocked(prop_key_) && StageDataManager::getInstance()->getCurrentLevel() == COMMODITY_TO_UNLOCK_STAGE_INDEX.at(prop_key_))
        {
            UserDataManager::getInstance()->changeSkillAndPropsFirstUnlockFlag(prop_key_);
            auto data = GameUnitPriceManager::getInstance()->getPropUnitPriceData(prop_key_);
            UserDataManager::getInstance()->addPropsNumbleWithKey(data.begin()->first, data.begin()->second.asInt());
            this->buttonClickCallfunc(nullptr);
        }
    }

    void EnterGamePropsView::loadView()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(COMMODITY_TO_CSB_PATH.at(prop_key_));
        this->addChild(csb_node);

        GamePropsCostTag* cost_tag = GamePropsCostTag::createWithKey(prop_key_);
        cost_tag->setScale(0.6f);
        cost_tag->setPosition(cocos2d::Vec2(0.0, -37.93f));
        csb_node->addChild(cost_tag);
        cost_tag_ = cost_tag;

        button_ = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("background_node")->getChildByName("Button"));
        assert(button_);
        if (StageDataManager::getInstance()->getCurrentLevel() >= COMMODITY_TO_UNLOCK_STAGE_INDEX.at(prop_key_))
        {
            button_->addClickEventListener(CC_CALLBACK_1(EnterGamePropsView::buttonClickCallfunc, this));
        }
        else
        {
            this->addChild(GameButtonFactory::getInstance()->createUnlockButton());
        }
    }
}