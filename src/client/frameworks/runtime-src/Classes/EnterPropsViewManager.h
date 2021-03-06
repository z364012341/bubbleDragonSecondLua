//*******************************************************************************
//类名称   : EnterPropsViewManager
//功能     : <进入道具的管理类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _ENTER_PROPS_VIEW_MANAGER_H_
#define _ENTER_PROPS_VIEW_MANAGER_H_
#include "BubbleSecondConstant.h"
//const std::string AIMING_LINE_COMMODITY_NAME = "AimingLineCommodity";
//const std::string ADD_SPECIAL_COMMODITY_NAME = "AddSpecialCommodity";
//const std::string ADD_BUBBLE_NUMBLE_COMMODITY_NAME = "AddBubbleNumbleCommodity";
namespace bubble_second {
    class EnterPropsViewManager
    {
    public:
        GETINSTANCE_FUNC(EnterPropsViewManager);
        ~EnterPropsViewManager();
        cocos2d::Node* createEnterPropsAlert();
        void setPropsSwitch(const std::string& props, bool pros_switch = false);
        bool getPropsSwitchEnable(const std::string& props);
        int getAddBubbleNumblePropsNumble();
        void addPrePropsCost(int numble);
        void cutPrePropsCost(int numble);
        int getPrePropsCost();
    private:
        EnterPropsViewManager();
        std::map<std::string, bool> props_switch_;
        int pre_props_cost_ = 0; //以选择的进场道具的预扣费
    };
}
#endif //_ENTER_PROPS_VIEW_MANAGER_H_