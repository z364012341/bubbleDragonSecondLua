#include "GameVictoryLotteryGiftItem.h"
#include "BubbleSecondConstant.h"
#include "SpriteTextureController.h"
#include "GameAudioController.h"
const std::string LOTTERY_GIFT_PATH = "faguang6xinglibao.PNG";
namespace bubble_second {
    GameVictoryLotteryGiftItem::GameVictoryLotteryGiftItem()
    {
    }

    bool GameVictoryLotteryGiftItem::init()
    {
        if (!GameVictoryLotteryItemBase::initWithPath(LOTTERY_GIFT_PATH))
        {
            return false;
        }
        return true;
    }

    GameVictoryLotteryGiftItem::~GameVictoryLotteryGiftItem()
    {
    }
    void GameVictoryLotteryGiftItem::lightenItem()
    {
        //this->setGrayEnabled(false);
        //this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_VICTORY_LETTERY_ITEM_LIGHTEN);

        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(LOTTERY_GIFT_PATH);
        this->addChild(sp);
        sp->setScale(0.1f);
        sp->runAction(cocos2d::Sequence::create(cocos2d::ScaleTo::create(0.2f, 1.2f),
            cocos2d::DelayTime::create(0.02f),
            cocos2d::ScaleTo::create(0.05f, 1.0f),
            cocos2d::CallFunc::create([=]() {
            sp->removeFromParent();
            this->setGrayEnabled(false);
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_POP_VICTORY_GIFT_ARMATURE);
        }),nullptr));
        GameAudioController::getInstance()->playGameVictoryLotteryGiftPopEffect();
    }
    void GameVictoryLotteryGiftItem::onEnter()
    {
        cocos2d::Node::onEnter();
        this->getEventDispatcher()->addCustomEventListener(EVENT_VICTORY_GIFT_ARMATURE_END, [=](cocos2d::EventCustom* event) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_VICTORY_LETTERY_ITEM_LIGHTEN);
        });
    }
    void GameVictoryLotteryGiftItem::onExit()
    {
        cocos2d::Node::onExit();
        this->getEventDispatcher()->removeCustomEventListeners(EVENT_VICTORY_GIFT_ARMATURE_END);
    }
}