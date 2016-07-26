#include "WoodenHammerProperty.h"
#include "WoodenHammerWeapon.h"
namespace bubble_second {
    WoodenHammerProperty::WoodenHammerProperty()
    {
    }


    WoodenHammerProperty::~WoodenHammerProperty()
    {
    }

    bool WoodenHammerProperty::init()
    {
        if (!BaseProperty::initWithPropKey(BUBBLE_WOODEN_HAMMER_PROP_KEY))
        {
            return false;
        }
        this->setName(PROPS_WOODEN_HAMMER_NAME);
        //this->initIconWithPath(PROPS_WOODEN_HAMMER_PATH);
        return true;
    }

    void WoodenHammerProperty::useItem()
    {
        BaseProperty::useItem();
        WoodenHammerWeapon* hammer = WoodenHammerWeapon::create();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_USE_SELECTION_PROPS, hammer);
    }

    void WoodenHammerProperty::cancelUseItem()
    {
            BaseProperty::cancelUseItem();
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_PROPS_SELECT_ALERT_CANCEL, this);
    }
}