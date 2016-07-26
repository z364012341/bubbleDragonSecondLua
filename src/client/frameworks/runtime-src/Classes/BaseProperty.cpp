#include "BaseProperty.h"
#include "GamePlayController.h"
#include "XMLTool.h"
#include "ButtonEffectController.h"
#include "ui\UIScale9Sprite.h"
#include "PropsNumbleShow.h"
#include "GameSinglePropBuyAlertFactory.h"
#include "GameButtonFactory.h"
//#include "GameSinglePropBuyAlert.h"
const float PROPS_BUTTON_POS_X = 100.0f;
const float PROPS_BUTTON_POS_Y = 35.0f;
const std::map<std::string, int> GAME_PROPS_UNLOCK_STAGE_INDEX = {
    { BUBBLE_WOODEN_HAMMER_PROP_KEY , 8 },
    { BUBBLE_COLOR_BOMB_PROP_KEY , 6 },
    { BUBBLE_BIG_BOMB_BOMB_PROP_KEY , 13 },
    { BUBBLE_STAVES_PROP_KEY , 16},
};
namespace bubble_second {
    BaseProperty::BaseProperty()
    {
    }

    BaseProperty::~BaseProperty()
    {
    }

    //bool BaseProperty::initWithName(const std::string& name)
    //{
    //    if (!Sprite::init())
    //    {
    //        return false;
    //    }
    //    //this->setName(name);
    //    //SpriteTextureController::getInstance()->setSpriteTexture("", this);
    //    return true;
    //}
    void BaseProperty::onExit()
    {
        Sprite::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_HAVE_USED_PROPS);
        this->getEventDispatcher()->removeCustomEventListeners(EVENT_PROPS_SELECT_ALERT_CONFIRM);
    }

    void BaseProperty::useItem()
    {
        use_state_ = kUsing;
        this->playUsingAction();
    }

    void BaseProperty::cancelUseItem()
    {
        use_state_ = kNotUsed;
        this->stopUsingAction();
    }

    void BaseProperty::setPropsState(PropsState state)
    {
        use_state_ = state;
    }

    PropsState BaseProperty::getPropsState()
    {
        return use_state_;
    }

    void BaseProperty::touchItem()
    {
        if (!this->itemIsUsing() && !this->isPropertyEnabled())
        {
            //GameSinglePropBuyAlert* alert = GameSinglePropBuyAlert::createWithPropKey(property_key_);
            //cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
            //alert->setPosition(visibleSize.width / 2, visibleSize.height / 2);
            //cocos2d::Director::getInstance()->getRunningScene()->addChild(alert);
            //std::string str = property_key_;
            //this->getEventDispatcher()->dispatchCustomEvent(EVENT_POP_GAME_STORE, &str);
            if (props_numble_label_->isNoneProp())
            {
                GameSinglePropBuyAlertFactory::getInstance()->popGameSinglePropBuyAlertWithKey(property_key_);
            }
            return;
        }
        auto handle = state_to_handle_[this->getPropsState()];
        if (handle && touch_flag_)
        {
            handle();
        }
    }

    bool BaseProperty::initWithPropKey(const std::string& key)
    {
        if (!Sprite::init())
        {
            return false;
        }
        use_state_ = kNotUsed;
        touch_flag_ = true;
        property_key_ = key;
        SpriteTextureController::getInstance()->setSpriteTexture(PROPS_ITEM_BACKGROUND_PATH, this);
        this->initIcon();
        this->addNumbleLabel();
        this->initHandle();
        this->addTouchEventListener();
        //this->setPropertyEnabled(true);
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_HAVE_USED_PROPS, 
            CC_CALLBACK_1(BaseProperty::haveUsedProperty, this));
        return true;
    }

    //void BaseProperty::actionBegan()
    //{
    //    touch_flag_ = false;
    //}

    //void BaseProperty::actionEnded()
    //{
    //    touch_flag_ = true;
    //}

    isUsing BaseProperty::itemIsUsing()
    {
        return use_state_ == kUsing;
    }

    void BaseProperty::setPropertyEnabled(bool flag)
    {
        //if (flag)
        //{
        //    this->addTouchEventListener();
        //}
        //else
        //{
        //    this->removeTouchEventListener();
        //}
        touch_enable_ = flag;
        //button_->setEnabled(flag);
    }

    bool BaseProperty::isPropertyEnabled()
    {
        return touch_enable_ && !props_numble_label_->isNoneProp();
    }

    void BaseProperty::removeTouchEventListener()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    }

    //void BaseProperty::addNumbleButton()
    //{
    //    //button_ = cocos2d::ui::Button::create(PROPS_NUMBLE_ENABLED_PATH, "", PROPS_NUMBLE_DISABLED_PATH);
    //    //ButtonEffectController::setButtonZoomScale(button_);
    //    //button_->setScale(PROPS_BUTTON_SPRITE_SCALE);
    //    //button_->setPosition(cocos2d::Vec2(PROPS_BUTTON_POS_X, PROPS_BUTTON_POS_Y));
    //    //this->addChild(button_, 1);
    //    this->addNumbleLabel();



    //}

    void bubble_second::BaseProperty::addNumbleLabel()
    {
        //props_numble_label_ = cocos2d::ui::TextAtlas::create(
        //    "9", PROPS_NUMBLE_LABEL_PATH, PROPS_NUMBLE_LABEL_ITEM_WIDTH, PROPS_NUMBLE_LABEL_ITEM_HEIGHT, ".");
        props_numble_label_ = PropsNumbleShow::create(property_key_);
        //props_numble_label_->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
        props_numble_label_->setPosition(cocos2d::Vec2(PROPS_BUTTON_POS_X, PROPS_BUTTON_POS_Y));
        this->addChild(props_numble_label_, UI_ZORDER_ALERT);
        //this->updateNumbleLabel();
    }

    void BaseProperty::initHandle()
    {
        state_to_handle_[kUsing] = [=]() {this->cancelUseItem(); };
        state_to_handle_[kNotUsed] = [=]() {this->useItem(); };
    }

    void BaseProperty::addTouchEventListener()
    {
        if (UserDataManager::getInstance()->getStagePassCount() < GAME_PROPS_UNLOCK_STAGE_INDEX.at(property_key_))
        {//µÀ¾ß¼ÓËø
            cocos2d::ui::Button* unlock_button = GameButtonFactory::getInstance()->createUnlockButton();
            this->addChild(unlock_button, UI_ZORDER_NOVICE_GUIDE_ALERT);
            cocos2d::Size size = this->getContentSize();
            unlock_button->setPosition(cocos2d::Vec2(size.width / 2, size.height / 2));
            return;
        }
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        GamePlayController* game_controller = GamePlayController::getInstance();
        listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::touchPropertyBegan, game_controller);
        listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::touchPropertyMoved, game_controller);
        listener->onTouchEnded = CC_CALLBACK_2(GamePlayController::touchPropertyEnded, game_controller);
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

        dispatcher->addCustomEventListener(EVENT_PROPS_SELECT_ALERT_CONFIRM, [=](cocos2d::EventCustom*) {this->stopUsingAction(); });
    }

    void BaseProperty::initIcon()
    {
        icon_sprite_ = SpriteTextureController::getInstance()->createPropSpriteWithKey(property_key_);
        cocos2d::Size size = this->getContentSize();
        icon_sprite_->setPosition(cocos2d::Vec2(size.width / 2, size.height / 2));
        this->addChild(icon_sprite_);
    }

    void BaseProperty::playUsingAction()
    {
        icon_sprite_->runAction(cocos2d::RepeatForever::create(cocos2d::Sequence::createWithTwoActions(cocos2d::ScaleTo::create(0.2f, 1.2f), cocos2d::ScaleTo::create(0.2f, 1.0f))));
    }

    void BaseProperty::stopUsingAction()
    {
        icon_sprite_->stopAllActions();
        icon_sprite_->setScale(1.0);
    }

    void BaseProperty::haveUsedProperty(cocos2d::EventCustom*)
    {
        this->setPropsState(kNotUsed);
        this->stopUsingAction();
        //UserDataManager::getInstance()->cutPropsNumbleWithKey(property_key_);
    }

    //void BaseProperty::setNumbleLabelStringWithNumble(int numble)
    //{
    //    props_numble_label_->set(XMLTool::convertIntToString(numble));
    //}
    //void BaseProperty::updateNumbleLabel()
    //{
    //    assert(property_key_ != "");
    //    int numble = UserDataManager::getInstance()->getPropsNumbleWithKey(property_key_);
    //    button_->setEnabled(numble == 0);
    //    this->setNumbleLabelStringWithNumble(numble);
    //}
}