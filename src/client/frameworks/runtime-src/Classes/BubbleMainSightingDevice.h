//*******************************************************************************
//类名称   : BubbleMainSightingDevice
//功能     : <游戏泡泡的主喵准器>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_MAIN_SIGHTING_DEVICE_H_
#define _BUBBLE_MAIN_SIGHTING_DEVICE_H_
#include "BubbleSightingDevice.h"
namespace bubble_second {
    class BubbleReflectionPointComponent;
    class BubbleMainSightingDevice : public BubbleSightingDevice
    {
    public:
        CREATE_FUNC(BubbleMainSightingDevice);
        ~BubbleMainSightingDevice();
    private:
        BubbleMainSightingDevice();
        bool init();
        //void turnOnDeviceOnce(int device_numble = 0) override;
        void initRemainDevice();
    private:
        BubbleReflectionPointComponent* reflection_point_component_ = nullptr;
        cocos2d::Map<int, BubbleSightingDevice*> remaind_device_;
    };
}
#endif //_BUBBLE_MAIN_SIGHTING_DEVICE_H_