#include "EnterGamePropsView.h"
#include "GameAlertMask.h"
#include "EnterPropsViewManager.h"
#include "cocostudio\CocoStudio.h"
#include "GameTextInfo.h"
#include "GamePropsCostTag.h"
const std::map<std::string, std::string> COMMODITY_TO_CSB_PATH = {
    { COMMODITY_ADD_10_BUBBLE_KEY , "AddBubbleNumbleCommodity.csb"},
    { COMMODITY_AIMING_LINE_KEY , "AimingLineCommodity.csb" },
    { COMMODITY_ADD_SPECIAL_KEY , "AddSpecialCommodity.csb"}
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
        this->loadView(prop_key);
        return true;
    }

    //void EnterGamePropsView::setCostLabelStringWithKey(const std::string& key)
    //{
    //    cost_label_->setString(GameTextInfo::getInstance()->getCommodityCoinValueWithKey(key).asString());
    //}

    void EnterGamePropsView::loadView(const std::string & prop_key)
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(COMMODITY_TO_CSB_PATH.at(prop_key));
        this->addChild(csb_node);

        GamePropsCostTag* cost_tag = GamePropsCostTag::createWithKey(prop_key);
        cost_tag->setPosition(cocos2d::Vec2(0.0, -37.93f));
        csb_node->addChild(cost_tag);
        //cost_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName("cost_node")->getChildByName("cost_label"));
        //assert(cost_label_);
        //selected_sprite_ = dynamic_cast<cocos2d::Sprite*>(csb_node->getChildByName("cost_node")->getChildByName("selected_sprite"));
        //assert(selected_sprite_);
        button_ = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("background_node")->getChildByName("Button"));
        assert(button_);
        button_->addTouchEventListener([=](cocos2d::Ref* target, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                cost_tag->changeSelectedState();
                EnterPropsViewManager::getInstance()->setPropsSwitch(this->getName(), cost_tag->getSelectedState());
            }
        });


    }
}