#include "GameAlertMask.h"
#include "SpriteTextureController.h"
#include "SmartScaleController.h"
namespace bubble_second {
    GameAlertMask::GameAlertMask()
    {
    }


    GameAlertMask::~GameAlertMask()
    {
    }

    bool bubble_second::GameAlertMask::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->setScale(1 / SmartScaleController::getInstance()->getFixedHeightZoom());

        this->addChild(SpriteTextureController::getInstance()->createGameBlurBackground());

        cocos2d::Sprite* item_select = cocos2d::Sprite::create();
        item_select->setContentSize(cocos2d::Size(GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT));
        cocos2d::Sprite* item_normal = cocos2d::Sprite::create();
        item_normal->setContentSize(cocos2d::Size(GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT));
        cocos2d::MenuItemSprite* item = cocos2d::MenuItemSprite::create(item_normal, item_select);
        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(item);
        menu->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(menu);

        cocos2d::LayerColor* layer = cocos2d::LayerColor::create(cocos2d::Color4B(100, 100, 100, 100), GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT);
        layer->setPosition(-GAME_ALERT_MASK_WIDTH / 2, -GAME_ALERT_MASK_HEIGHT / 2);
        this->addChild(layer);

        return true;
    }
}