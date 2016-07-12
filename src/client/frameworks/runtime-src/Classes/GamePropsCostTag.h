//*******************************************************************************
//类名称   : GamePropsCostTag
//功能     : <道具的价格标签>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_PROPS_COST_TAG_H_
#define _GAME_PROPS_COST_TAG_H_
#include "cocos2d.h"
namespace bubble_second {
    class GamePropsCostTag : public cocos2d::Node
    {
    public:
        static GamePropsCostTag* createWithKey(const std::string& prop_key);
        //参数cost_type是货币类型, 钻石或者金币, numble是数量
        static GamePropsCostTag* createWithCostTypeAndNumble(const std::string& cost_type, cocos2d::Value numble);
        static GamePropsCostTag* createDecalsLotteryBeginTag();
        static GamePropsCostTag* createDecalsLotteryContinueTag();
        GamePropsCostTag();
        ~GamePropsCostTag();
        void onEnter() override;
        void onExit() override;
        void changeSelectedState();
        bool getSelectedState();
        //是否有足够的钱支付
        bool canPay();
        //扣费
        void pay();

        int getCostNumble();
    private:
        bool initWithKey(const std::string& prop_key);
        bool initWithCostTypeAndNumble(const std::string& cost_type, cocos2d::Value numble);
    private:
        cocos2d::Sprite* selected_sprite_ = nullptr;
        std::string cost_key_ = "";
        int cost_numble_ = 0;
        cocos2d::EventListenerCustom * listener_ = nullptr;
    };
}
#endif