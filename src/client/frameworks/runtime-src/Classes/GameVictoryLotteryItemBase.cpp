#include "GameVictoryLotteryItemBase.h"
#include "SpriteTextureController.h"

namespace bubble_second {
    GameVictoryLotteryItemBase::GameVictoryLotteryItemBase()
    {
    }


    GameVictoryLotteryItemBase::~GameVictoryLotteryItemBase()
    {
    }
    void GameVictoryLotteryItemBase::setGrayEnabled(bool enabled)
    {
        if (enabled)
        {
            SpriteTextureController::getInstance()->setGrayShader(item_sprite_);
        }
        else
        {
            SpriteTextureController::getInstance()->setNormalShader(item_sprite_);
        }
    }
    bool GameVictoryLotteryItemBase::initWithPath(const std::string & path)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        item_sprite_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(path);
        this->addChild(item_sprite_);
        return true;
    }
}