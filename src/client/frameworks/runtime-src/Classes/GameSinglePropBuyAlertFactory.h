//*******************************************************************************
//类名称   : GameSinglePropBuyAlertFactory
//功能     : <单个道具购买框工厂>
//-------------------------------------------------------------------------------
//备注     : <负责生成item>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SINGLE_PROP_BUY_ALERT_FACTORY_H_
#define _GAME_SINGLE_PROP_BUY_ALERT_FACTORY_H_
#include "BubbleSecondConstant.h"
#include "GameSinglePropBuyAlert.h"
namespace bubble_second {
    class GameSinglePropBuyAlertFactory
    {
    public:
        GETINSTANCE_FUNC(GameSinglePropBuyAlertFactory);
        ~GameSinglePropBuyAlertFactory();
        void popGameSinglePropBuyAlertWithKey(const std::string& prop_key);
        GameSinglePropBuyAlert * createGameSinglePropBuyAlert();
    private:
        GameSinglePropBuyAlertFactory();

    private:
        std::string prop_key_ = "";
    };
}
#endif