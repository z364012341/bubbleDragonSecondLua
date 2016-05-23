#include "PropsNumbleShow.h"
#include "SpriteTextureController.h"
#include "BubbleSecondConstant.h"
//const std::string BACKGROUND_PATH = "anniushuliang.PNG";
const cocos2d::Vec2 PROPS_NUMBLE_SHOW_POSITION = cocos2d::Vec2(35.0f, -35.0f);
namespace bubble_second {
    PropsNumbleShow::PropsNumbleShow()
    {
    }

    bool PropsNumbleShow::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath(PROPS_NUMBLE_DISABLED_PATH));
        props_numble_label_ = cocos2d::ui::TextAtlas::create(
            "10", PROPS_NUMBLE_LABEL_PATH, PROPS_NUMBLE_LABEL_ITEM_WIDTH, PROPS_NUMBLE_LABEL_ITEM_HEIGHT, ".");
        props_numble_label_->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
        props_numble_label_->setPosition(cocos2d::Vec2(-3, 3));
        this->addChild(props_numble_label_);
        this->setPosition(PROPS_NUMBLE_SHOW_POSITION);
        //props_numble_label_->setPosition(cocos2d::Vec2(bgSprite->getContentSize().width / 2, bgSprite->getContentSize().height / 2));
        //bgSprite->addChild(props_numble_label_, UI_ZORDER_MENU_INFO);
        return true;
    }


    PropsNumbleShow::~PropsNumbleShow()
    {
    }
}