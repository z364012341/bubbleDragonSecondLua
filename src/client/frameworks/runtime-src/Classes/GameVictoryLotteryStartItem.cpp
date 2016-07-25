#include "GameVictoryLotteryStartItem.h"
#include "SpriteTextureController.h"
#include "GameAudioController.h"
const std::string LOTTERY_START_PATH = "faguangxingxing.PNG";

namespace bubble_second {
    GameVictoryLotteryStartItem::GameVictoryLotteryStartItem()
    {
    }

    bool GameVictoryLotteryStartItem::init()
    {
        if (!GameVictoryLotteryItemBase::initWithPath(LOTTERY_START_PATH))
        {
            return false;
        }
        return true;
    }

    GameVictoryLotteryStartItem::~GameVictoryLotteryStartItem()
    {
    }
    void GameVictoryLotteryStartItem::lightenItem()
    {
        GameAudioController::getInstance()->playGameVictoryLotteryStartPopEffect();
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(LOTTERY_START_PATH);
        this->addChild(sp);
        sp->setScale(0.1f);
        sp->runAction(cocos2d::Sequence::create(cocos2d::ScaleTo::create(0.2f, 1.2f),
            cocos2d::DelayTime::create(0.02f),
            cocos2d::ScaleTo::create(0.05f, 1.0f),
            cocos2d::CallFunc::create([=]() {
                sp->removeFromParent();
                this->setGrayEnabled(false);
                this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_VICTORY_LETTERY_ITEM_LIGHTEN);
            }),
            nullptr));
    }
}