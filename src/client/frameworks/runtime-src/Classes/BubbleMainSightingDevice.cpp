#include "BubbleMainSightingDevice.h"
#include "BubbleReflectionPointComponent.h"
#include "EnterPropsViewManager.h"
#include "GamePlayController.h" 
#include "BubbleSecondConstant.h"
const int MAIN_SIGHTING_DEVICE_TARGET_ID = 0;
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
        this->addChild(reflection_point_component_ = BubbleReflectionPointComponent::create());
        return true;
    }

    void BubbleMainSightingDevice::initRemainDevice()
    {
        this->setTargetID(MAIN_SIGHTING_DEVICE_TARGET_ID);
        this->setVisible(false);
        int device_numble_max = EnterPropsViewManager::getInstance()->getPropsSwitchEnable(AIMING_LINE_COMMODITY_NAME) ?
            BUBBLE_SIGHTING_DEVICE_TOTAL : BUBBLE_SIGHTING_DEVICE_UNUSED_PROPS_TOTAL;
        BubbleSightingDevice* last_device = this;
        for (int i = MAIN_SIGHTING_DEVICE_TARGET_ID+1; i <= device_numble_max; i++)
        {
            BubbleSightingDevice* device = BubbleSightingDevice::create();
            device->setPositionX(BUBBLE_SIGHTING_DEVICE_GO_AWAY_Y);
            this->getParent()->addChild(device);
            last_device->setNextSightingDevice(device);
            device->setTargetID(i);
            last_device = device;
        }
    }

    void BubbleMainSightingDevice::rotateDevice(const cocos2d::Vec2 & touch_point)
    {
        reflection_point_component_->calculateReflectionPoints(touch_point);
        auto points = reflection_point_component_->getReflectionPoints();
        int relection_offset = (int)(points.front().getDistance(GamePlayController::getInstance()->getShootingInitialPosition())) % (int)MAP_BUBBLE_DIAMETER;
        this->getNextSightingDevice()->setReflectionPointOffset(reflection_point_component_->getReflectionoffset());
        this->setDeviceRotation(reflection_point_component_->getReflectionAngles());
        this->getNextSightingDevice()->setDevicePosition(reflection_point_component_->getReflectionPoints());
        this->getNextSightingDevice()->setDevicePointHidden(reflection_point_component_->getHiddenFlags());
    }
    BubbleMainSightingDevice::~BubbleMainSightingDevice()
    {

    }
    void BubbleMainSightingDevice::setParent(cocos2d::Node * parent)
    {
        BubbleSightingDevice::setParent(parent);
        this->initRemainDevice();
    }
    void BubbleMainSightingDevice::onEnter()
    {
        BubbleSightingDevice::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_MAIN_ROTATE_SIGHTING_DEVICE, [=](cocos2d::EventCustom* event) {
            cocos2d::Vec2 touch_point = *static_cast<cocos2d::Vec2*>(event->getUserData());
            this->rotateDevice(touch_point);
        });
    }
    void BubbleMainSightingDevice::onExit()
    {
        BubbleSightingDevice::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_MAIN_ROTATE_SIGHTING_DEVICE);
    }
    void BubbleMainSightingDevice::turnOnSightingDevice()
    {
        BubbleSightingDevice::turnOnSightingDevice();
        this->setVisible(true);
 
    }
    void BubbleMainSightingDevice::turnOffSightingDevice()
    {
        BubbleSightingDevice::turnOffSightingDevice();
        this->setVisible(false);
    }
}