#ifndef _GAME_BUY_STORE_MANNAGER_H_
#define _GAME_BUY_STORE_MANNAGER_H_
#include "BubbleSecondConstant.h"
const int PUZZLE_NEWBIE_GIFT_TARGET_ID = 113;
const std::string TARGET_ID_KEY = "targetID";
const std::string ITEM_PROPS_DATA_KEY = "item_props_data";
namespace bubble_second {
    class GameBuyStoreMannager
    {
    public:
        GETINSTANCE_FUNC(GameBuyStoreMannager);
        ~GameBuyStoreMannager(); 
        void buyProps(cocos2d::ValueMap data);
        bool isBuyPuzzleNewbiwGift();
        static cocos2d::ValueMap getRandomLotteryAwardWihtoutDecals();
        static cocos2d::ValueMap getRandomLotteryAwardIncludeCharactorDecals();
    private:
        GameBuyStoreMannager();
        int getCurrentPropsTarget();
        //ÉèÖÃ¹ºÂòµÄ
        void setBuyPropsKeyAndNumble(cocos2d::ValueMap data);
    private:
        //int props_target_ = 0;
        cocos2d::ValueMap buy_props_save_;
    };
}
#endif
