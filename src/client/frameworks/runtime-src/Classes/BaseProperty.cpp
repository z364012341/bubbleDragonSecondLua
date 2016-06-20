#include "BaseProperty.h"
#include "GamePlayController.h"
#include "XMLTool.h"
#include "ButtonEffectController.h"
#include "ui\UIScale9Sprite.h"
#include "PropsNumbleShow.h"
const float PROPS_BUTTON_POS_X = 100.0f;
const float PROPS_BUTTON_POS_Y = 35.0f;

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
    }

    void BaseProperty::useItem()
    {
        use_state_ = kUsing;
    }

    void BaseProperty::cancelUseItem()
    {
        use_state_ = kNotUsed;
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
        touch_enable_ = flag && !props_numble_label_->isNoneProp();
        //button_->setEnabled(flag);
    }

    bool BaseProperty::isPropertyEnabled()
    {
        return touch_enable_;
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
        this->addChild(props_numble_label_, UI_ZORDER_MENU_INFO+1);
        //this->updateNumbleLabel();
    }

    void BaseProperty::initHandle()
    {
        state_to_handle_[kUsing] = [=]() {this->cancelUseItem(); };
        state_to_handle_[kNotUsed] = [=]() {this->useItem(); };
    }

    void BaseProperty::addTouchEventListener()
    {
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        GamePlayController* game_controller = GamePlayController::getInstance();
        listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::touchPropertyBegan, game_controller);
        listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::touchPropertyMoved, game_controller);
        listener->onTouchEnded = CC_CALLBACK_2(GamePlayController::touchPropertyEnded, game_controller);
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    }

    void BaseProperty::initIcon()
    {
        cocos2d::Sprite* iter_sprite = SpriteTextureController::getInstance()->createPropSpriteWithKey(property_key_);
        cocos2d::Size size = this->getContentSize();
        iter_sprite->setPosition(cocos2d::Vec2(size.width / 2, size.height / 2));
        this->addChild(iter_sprite);
    }

    void BaseProperty::haveUsedProperty(cocos2d::EventCustom*)
    {
        this->setPropsState(kNotUsed);
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