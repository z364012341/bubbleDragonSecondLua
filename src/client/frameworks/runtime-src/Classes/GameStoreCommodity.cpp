#include "GameStoreCommodity.h"
#include "SpriteTextureController.h"
#include "ui\UITextBMFont.h"

namespace bubble_second {
    GameStoreCommodity * GameStoreCommodity::createWithPropKeyAndNumble(const std::string & prop_key, const std::string& numble)
    {
        GameStoreCommodity* pRet = new (std::nothrow) GameStoreCommodity;
        if (pRet && pRet->initWithPropKeyAndNumble(prop_key, numble))
        {
            pRet->autorelease();
            return pRet;
        }
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
    GameStoreCommodity::GameStoreCommodity()
    {
    }

    bool GameStoreCommodity::initWithPropKeyAndNumble(const std::string & prop_key, const std::string& numble)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createPropSpriteWithKey(prop_key);
        this->addChild(sp);
        cocos2d::ui::TextBMFont* label = SpriteTextureController::getInstance()->createWhitePurpleFnt("*"+ numble);
        label->setPositionY(-20.0f);
        this->addChild(label);
        return true;
    }


    GameStoreCommodity::~GameStoreCommodity()
    {
    }
}