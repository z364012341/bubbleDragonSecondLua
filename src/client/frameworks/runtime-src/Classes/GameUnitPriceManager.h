//*******************************************************************************
//类名称   : GameUnitPriceManager
//功能     : <游戏付费项目的单价>
//-------------------------------------------------------------------------------
//备注     : <负责生成item>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_UNIT_PRICE_MANAGER_H_
#define _GAME_UNIT_PRICE_MANAGER_H_
#include "BubbleSecondConstant.h"
const std::string COMMODITY_DECALS_LOTTERY_BEGIN_KEY = "decals_lottery_begin"; //贴纸抽奖开始花费
const std::string COMMODITY_DECALS_LOTTERY_CONTINUE_KEY = "decals_lottery_continue"; //贴纸继续抽奖花费
const std::string GAME_DEFEAT_BUY_CONTINUE_KEY = "game_defeat_buy_continue_key"; //失败后继续游戏花费
namespace bubble_second {
    class GameUnitPriceManager
    {
    public:
        GETINSTANCE_FUNC(GameUnitPriceManager);
        ~GameUnitPriceManager();
        void addUnitPriceData(cocos2d::ValueMap price_data, const std::string& key);
        cocos2d::ValueMap getPropUnitPriceData(const std::string& prop_key);
    private:
        GameUnitPriceManager();
    private:
        cocos2d::ValueMap store_unit_price_data_;
    };
}
#endif 