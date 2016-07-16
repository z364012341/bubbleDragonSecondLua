//*******************************************************************************
//类名称   : GameSinglePropBuyAlert
//功能     : <游戏单个种类的道具购买面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SINGLE_PROP_BUY_ALERT_H_
#define _GAME_SINGLE_PROP_BUY_ALERT_H_
#include "cocos2d.h"
#include "ui\UITextBMFont.h"
namespace bubble_second {
    class GameSinglePropBuyAlert : public cocos2d::Node
    {
    public:
        static GameSinglePropBuyAlert* createWithPropKey(const std::string& prop_key);
        ~GameSinglePropBuyAlert();
    private:
        GameSinglePropBuyAlert();
        bool initWithPropKey(const std::string& prop_key);
        void loadView();
        void updataNumbleLabel();
    private:
        std::string prop_key_ = "";
        int buy_numble_ = 0;
        cocos2d::ui::TextBMFont* numble_label_ = nullptr;
    };
}
#endif