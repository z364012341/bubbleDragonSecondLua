#include "BubbleMainSightingDevice.h"
#include "BubbleReflectionPointComponent.h"
namespace bubble_second {
    BubbleMainSightingDevice::BubbleMainSightingDevice()
    {
    }

    bool BubbleMainSightingDevice::init()
    {  
        if (!BubbleSightingDevice::init())
        {
            return false;
        }
        return true;
    }

    void BubbleMainSightingDevice::initRemainDevice()
    {
        for (int i = 1; i < length; i++)
        {

        }
    }

    //void BubbleMainSightingDevice::turnOnDeviceOnce(int device_numble)
    //{
    //    BubbleSightingDevice::turnOnDeviceOnce(device_numble);
    //    reflection_point_component_ = BubbleReflectionPointComponent::create();
    //    this->addChild(reflection_point_component_);
    //}

    BubbleMainSightingDevice::~BubbleMainSightingDevice()
    {

    }
}