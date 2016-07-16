#include "GameBuyStoreMannager.h"
#include "GameJNIHelper.h"
#include "UserDataManager.h"
const float LOTTERY_CHARACTOR_DECALS_PROBABILITY = 0.2f;
const std::vector<std::map<std::string, int>> GAME_LOTTERY_AWARD = {
    { { PUZZLE_SEARCH_PROP_KEY , 1 } },
    { { PUZZLE_BIG_EYES_PROP_KEY , 1 } },
    { { PUZZLE_ADD_TIME_PROP_KEY , 1 } },
    { { BUBBLE_WOODEN_HAMMER_PROP_KEY , 1 } },
    { { BUBBLE_COLOR_BOMB_PROP_KEY , 1 } },
    { { BUBBLE_BIG_BOMB_BOMB_PROP_KEY , 1 } },
    { { BUBBLE_STAVES_PROP_KEY , 1 } },
    { { PUZZLE_SEARCH_PROP_KEY , 1 } },
    { { BUBBLE_STAVES_PROP_KEY , 1 } },
    { { PUZZLE_SEARCH_PROP_KEY , 1 } },
    { { BUBBLE_WOODEN_HAMMER_PROP_KEY , 1 } },
    { { GAME_COIN_KEY , 1000 } },
    { { GAME_COIN_KEY , 1500 } },
    { { GAME_COIN_KEY , 500 } },
    { { GAME_STRENGTH_KEY , 1 } }
};
namespace bubble_second {
    GameBuyStoreMannager::GameBuyStoreMannager()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_BUY_PROPS_PAY_SUCCESS, [=](cocos2d::EventCustom* event) {
            if (GameBuyStoreMannager::getInstance()->isBuyPuzzleNewbiwGift())
            {
                UserDataManager::getInstance()->buyNewbieGift();
            }
            for (auto var : buy_props_save_.at(ITEM_PROPS_DATA_KEY).asValueMap())
            {
                UserDataManager::getInstance()->addPropsNumbleWithKey(var.first, var.second.asInt());
            }

        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_BUY_PROPS_PAY_FAIL, [=](cocos2d::EventCustom* event) {
            buy_props_save_.clear();
        });
    }


    GameBuyStoreMannager::~GameBuyStoreMannager()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_BUY_PROPS_PAY_SUCCESS);
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_BUY_PROPS_PAY_FAIL);
    }

    int bubble_second::GameBuyStoreMannager::getCurrentPropsTarget()
    {
        return buy_props_save_.at(TARGET_ID_KEY).asInt();
    }
    void GameBuyStoreMannager::setBuyPropsKeyAndNumble(cocos2d::ValueMap data)
    {
        buy_props_save_ = data;
    }
    void GameBuyStoreMannager::buyProps(cocos2d::ValueMap data)
    {
        this->setBuyPropsKeyAndNumble(data);
        int target = data.at(TARGET_ID_KEY).asInt();
        GameJNIHelper::getInstance()->payWithTargetID(target);
        //this->setCurrentPropsTarget(target);
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_BUY_PROPS_PAY_SUCCESS);
    }
    void GameBuyStoreMannager::buyPropsWithTokens(cocos2d::ValueMap data)
    {
        if (data.at(STORE_COST_KEY).asInt() <= UserDataManager::getInstance()->getPropsNumbleWithKey(data.at(STORE_COST_TYPE_KEY).asString()))
        {
            for (auto var : data.at(ITEM_PROPS_DATA_KEY).asValueMap())
            {
                UserDataManager::getInstance()->addPropsNumbleWithKey(var.first, var.second.asInt());
            }
            UserDataManager::getInstance()->cutPropsNumbleWithKey(data.at(STORE_COST_TYPE_KEY).asString(), data.at(STORE_COST_KEY).asInt());
        }
    }
    bool GameBuyStoreMannager::isBuyPuzzleNewbiwGift()
    {
        return this->getCurrentPropsTarget() == PUZZLE_NEWBIE_GIFT_TARGET_ID;
    }
    cocos2d::ValueMap GameBuyStoreMannager::getRandomLotteryAwardWihtoutDecals()
    {
        int numble = cocos2d::random(0, (int)GAME_LOTTERY_AWARD.size() - 1);
        auto data = GAME_LOTTERY_AWARD.at(numble);
        cocos2d::ValueMap map;
        map[data.begin()->first] = data.begin()->second;
        return map;
    }
    cocos2d::ValueMap GameBuyStoreMannager::getRandomLotteryAwardIncludeCharactorDecals()
    {
        if (cocos2d::rand_0_1() <= LOTTERY_CHARACTOR_DECALS_PROBABILITY)
        {
            cocos2d::ValueMap map;
            map[DECALS_CHARACTOR_KEY] = -1;
            return map;
        };
        return GameBuyStoreMannager::getRandomLotteryAwardWihtoutDecals();
    }
}