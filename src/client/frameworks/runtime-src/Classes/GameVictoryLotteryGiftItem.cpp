#include "GameVictoryLotteryGiftItem.h"
#include "BubbleSecondConstant.h"

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
        this->setGrayEnabled(false);
        //this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_VICTORY_LETTERY_ITEM_LIGHTEN);
        this->getEventDispatcher()->dispatchCustomEvent(EVENT_POP_VICTORY_GIFT_ARMATURE);
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