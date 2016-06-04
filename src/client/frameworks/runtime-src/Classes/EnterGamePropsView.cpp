#include "EnterGamePropsView.h"
#include "GameAlertMask.h"
#include "EnterPropsViewManager.h"
#include "cocostudio\CocoStudio.h"
#include "GameTextInfo.h"
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

    bool EnterGamePropsView::init(const std::string & csb_path)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->loadView(csb_path);
        return true;
    }

    void EnterGamePropsView::setCostLabelStringWithKey(const std::string& key)
    {
        cost_label_->setString(GameTextInfo::getInstance()->getCommodityCoinValueWithKey(key).asString());
    }

    void EnterGamePropsView::loadView(const std::string & csb_path)
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(csb_path);
        this->addChild(csb_node);
        cost_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName("cost_node")->getChildByName("cost_label"));
        assert(cost_label_);
        selected_sprite_ = dynamic_cast<cocos2d::Sprite*>(csb_node->getChildByName("cost_node")->getChildByName("selected_sprite"));
        assert(selected_sprite_);
        button_ = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("background_node")->getChildByName("Button"));
        assert(button_);
        button_->addTouchEventListener([=](cocos2d::Ref* target, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                selected_sprite_->setVisible(!selected_sprite_->isVisible());
                EnterPropsViewManager::getInstance()->setPropsSwitch(this->getName(), selected_sprite_->isVisible());
            }
        });
    }
}