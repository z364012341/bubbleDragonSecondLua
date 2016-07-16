#ifndef _GAME_BUY_STORE_MANNAGER_H_
#define _GAME_BUY_STORE_MANNAGER_H_
#include "BubbleSecondConstant.h"
const int PUZZLE_NEWBIE_GIFT_TARGET_ID = 113;
const std::string TARGET_ID_KEY = "targetID";
const std::string ITEM_PROPS_DATA_KEY = "item_props_data";
const std::string STORE_COST_TYPE_KEY = "cost_type"; //货币的种类
const std::string STORE_COST_KEY = "cost"; //花费多少
namespace bubble_second {
    class GameBuyStoreMannager
    {
    public:
        GETINSTANCE_FUNC(GameBuyStoreMannager);
        ~GameBuyStoreMannager(); 
        void buyProps(cocos2d::ValueMap data);
        void buyPropsWithTokens(cocos2d::ValueMap data);
        bool isBuyPuzzleNewbiwGift();
        static cocos2d::ValueMap getRandomLotteryAwardWihtoutDecals();
        static cocos2d::ValueMap getRandomLotteryAwardIncludeCharactorDecals();

    private:
        GameBuyStoreMannager();
        int getCurrentPropsTarget();
        //设置购买的
        void setBuyPropsKeyAndNumble(cocos2d::ValueMap data);
    private:
        //int props_target_ = 0;
        cocos2d::ValueMap buy_props_save_;
    };
}
#endif
