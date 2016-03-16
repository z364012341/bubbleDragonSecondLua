#include "GameAlertMask.h"
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
        cocos2d::Sprite* item_select = cocos2d::Sprite::create();
        item_select->setContentSize(cocos2d::Size(GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT));
        cocos2d::Sprite* item_normal = cocos2d::Sprite::create();
        item_normal->setContentSize(cocos2d::Size(GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT));
        cocos2d::MenuItemSprite* item = cocos2d::MenuItemSprite::create(item_normal, item_select);
        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(item);
        menu->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(menu, UI_ZORDER_MENU_MASK_NULL_BUTTON);
        cocos2d::LayerColor* layer = cocos2d::LayerColor::create(cocos2d::Color4B(0, 0, 0, 100), GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT);
        layer->setPosition(-GAME_ALERT_MASK_WIDTH / 2, -GAME_ALERT_MASK_HEIGHT / 2);
        this->addChild(layer, UI_ZORDER_MENU_MASK_COLOR_LAYER);
        return true;
    }
}