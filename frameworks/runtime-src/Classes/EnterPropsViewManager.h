//*******************************************************************************
//������   : EnterPropsViewManager
//����     : <������ߵĹ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _ENTER_PROPS_VIEW_MANAGER_H_
#define _ENTER_PROPS_VIEW_MANAGER_H_
#include "BubbleSecondConstant.h"
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
    private:
        EnterPropsViewManager();
        std::map<std::string, bool> props_switch_;
    };
}
#endif //_ENTER_PROPS_VIEW_MANAGER_H_