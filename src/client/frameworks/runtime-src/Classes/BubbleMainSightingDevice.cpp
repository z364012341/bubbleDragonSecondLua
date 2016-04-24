#include "BubbleMainSightingDevice.h"
#include "BubbleReflectionPointComponent.h"
#include "EnterPropsViewManager.h"
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
        this->initRemainDevice();
        return true;
    }

    void BubbleMainSightingDevice::initRemainDevice()
    {
        this->setTargetID(0);
        this->setVisible(false);
        this->sightingPointMove();
        int device_numble_max = EnterPropsViewManager::getInstance()->getPropsSwitchEnable(AIMING_LINE_COMMODITY_NAME) ?
            BUBBLE_SIGHTING_DEVICE_TOTAL : BUBBLE_SIGHTING_DEVICE_UNUSED_PROPS_TOTAL;
        for (int i = 1; i <= device_numble_max; i++)
        {
            BubbleSightingDevice* device = BubbleSightingDevice::create();
            device->setTargetID(i);
            remaind_device_.insert(i, device);
            device->setVisible(false);
            device->sightingPointMove();
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