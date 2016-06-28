#include "GameLotteryAwardItem.h"
#include "SpriteTextureController.h"
#include "UserDataManager.h"
#include "XMLTool.h"
namespace bubble_second {
    GameLotteryAwardItem::GameLotteryAwardItem()
    {
    }

    bool GameLotteryAwardItem::init(const std::string& key, int numble)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        award_sprite_ = SpriteTextureController::getInstance()->createPropSpriteWithKey(key);
        //award_sp->setPositionY(75.0f);
        this->addChild(award_sprite_);
        if (numble<1)
        {
            return true;
        }
        cocos2d::ui::TextBMFont* numble_label = SpriteTextureController::getInstance()->createWhitePurpleFnt(XMLTool::convertIntToString(numble));
        numble_label->setScale(0.6f);
        numble_label->setPositionY(-80.0f);
        this->addChild(numble_label);
        return true;
    }

    GameLotteryAwardItem * GameLotteryAwardItem::create(const std::string& key, int numble)
    {
        GameLotteryAwardItem *pRet = new(std::nothrow) GameLotteryAwardItem();
        if (pRet && pRet->init(key, numble))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    GameLotteryAwardItem::~GameLotteryAwardItem()
    {
    }
    cocos2d::Sprite * GameLotteryAwardItem::getAwardSprite()
    {
        return award_sprite_;
    }
}