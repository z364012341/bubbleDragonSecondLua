#include "GameBuyStoreMannager.h"
#include "GameJNIHelper.h"
const std::vector<std::map<std::string, int>> GAME_LOTTERY_AWARD = {
    {{ "search" , 1 }},
    {{ "bigEyes" , 1 }},
    {{ "addTime" , 1 }},
    {{ "woodenHammer" , 1 }},
    {{ "colorBomb" , 1 }},
    {{ "bigBombBomb" , 1 }},
    {{ "staves" , 1 }},
    {{ "search" , 1 }},
    {{ "staves" , 1 }},
    {{ "search" , 1 }},
    {{ "woodenHammer" , 1 }},
    {{ "coin" , 1000 }},
    {{ "coin" , 1500 }},
    {{ "coin" , 500 }}
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
    cocos2d::ValueMap GameBuyStoreMannager::getRandomLotteryAward()
    {
        int numble = cocos2d::random(0, (int)GAME_LOTTERY_AWARD.size());
        auto data = GAME_LOTTERY_AWARD.at(numble);
        cocos2d::ValueMap map;
        map[data.begin()->first] = data.begin()->second;
        return map;
    }
}