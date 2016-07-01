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
    }


    GameBuyStoreMannager::~GameBuyStoreMannager()
    {
    }

    void bubble_second::GameBuyStoreMannager::setCurrentPropsTarget(int target)
    {
        props_target_ = target;
    }
    void GameBuyStoreMannager::buyProps(int target)
    {
        GameJNIHelper::getInstance()->payWithTargetID(target);
        this->setCurrentPropsTarget(target);
    }
    bool GameBuyStoreMannager::isBuyPuzzleNewbiwGift()
    {
        return props_target_ == PUZZLE_NEWBIE_GIFT_TARGET_ID;
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