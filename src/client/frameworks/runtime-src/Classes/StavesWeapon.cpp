#include "StavesWeapon.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"
const std::string WOODEN_HAMMER_ANIMATION_NAME = "fazhang";
namespace bubble_second {
    StavesWeapon::StavesWeapon()
    {
    }

    bool bubble_second::StavesWeapon::init()
    {
        if (!BaseWeapon::init(WOODEN_HAMMER_ANIMATION_NAME))
        {
            return false;
        }
        //SpriteTextureController::getInstance()->setSpriteTexture(PROPS_STAVES_PATH, this);
        this->setName(WEAPON_STAVES_NAME);
        return true;
    }


    StavesWeapon::~StavesWeapon()
    {
    }

    void bubble_second::StavesWeapon::attackBubble()
    {
        BaseWeapon::attackBubble();
        GamePlayController::getInstance()->disposeUseStaves();
    }

    bool StavesWeapon::inAttackRange(BubbleType color)
    {
        return color>=kNormalColorFirst && color <=kNormalColorLast;
    }

    void StavesWeapon::selectBubble(const cocos2d::Vec2 & point)
    {
        BaseWeapon::selectBubble(point);
    }
}