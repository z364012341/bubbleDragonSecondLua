//*******************************************************************************
//������   : BubbleMainSightingDevice
//����     : <��Ϸ���ݵ�����׼��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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