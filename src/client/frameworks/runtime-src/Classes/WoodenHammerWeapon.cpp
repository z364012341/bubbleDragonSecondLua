#include "WoodenHammerWeapon.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"
#include "UserDataManager.h"
const std::string WOODEN_HAMMER_ANIMATION_NAME = "chuizi";
const std::string WOODEN_HAMMER_ATTACK_ANIMATION_NAME = "shiyong";
namespace bubble_second {
    WoodenHammerWeapon::WoodenHammerWeapon()
    {
    }

    WoodenHammerWeapon::~WoodenHammerWeapon()
    {
    }

    void WoodenHammerWeapon::attackBubble(const cocos2d::Vec2& point)
    {
        GamePlayController::getInstance()->setBubbleShootEnabled(false);
        cocostudio::Armature* armature = cocostudio::Armature::create(WOODEN_HAMMER_ANIMATION_NAME);
        this->addChild(armature);
        armature->setPosition(point);
        armature->getAnimation()->play(WOODEN_HAMMER_ATTACK_ANIMATION_NAME);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                BaseWeapon::attackBubble(point);
                GamePlayController::getInstance()->setBubbleShootEnabled(true);
            }
        });
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.625f), cocos2d::CallFunc::create([=]() {
            GamePlayController::getInstance()->disposeUseWoodenHammer();
        })));
        UserDataManager::getInstance()->cutPropsNumbleWithKey(BUBBLE_WOODEN_HAMMER_PROP_KEY);
    }

    bool WoodenHammerWeapon::init()
    {
        if (!BaseWeapon::init())
        //if (!BaseWeapon::init(WOODEN_HAMMER_ANIMATION_NAME))
        {
            return false;
        }
        //SpriteTextureController::getInstance()->setSpriteTexture(PROPS_WOODEN_HAMMER_PATH, this);
        this->setName(WEAPON_WOODEN_HAMMER_NAME);
        return true;
    }
}