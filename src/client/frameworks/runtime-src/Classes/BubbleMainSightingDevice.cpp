#include "BubbleMainSightingDevice.h"
#include "BubbleReflectionPointComponent.h"
#include "EnterPropsViewManager.h"
#include "GamePlayController.h"   
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
        //this->sightingPointMove();
        int device_numble_max = EnterPropsViewManager::getInstance()->getPropsSwitchEnable(AIMING_LINE_COMMODITY_NAME) ?
            BUBBLE_SIGHTING_DEVICE_TOTAL : BUBBLE_SIGHTING_DEVICE_UNUSED_PROPS_TOTAL;
        BubbleSightingDevice* last_device = this;
        for (int i = MAIN_SIGHTING_DEVICE_TARGET_ID+1; i <= device_numble_max; i++)
        {
            BubbleSightingDevice* device = BubbleSightingDevice::create();
            this->getParent()->addChild(device);
            last_device->setNextSightingDevice(device);
            device->setTargetID(i);
            last_device = device;
            //remaind_device_.pushBack(device);
            //device->setVisible(false);
            //device->sightingPointMove();
        }
    }

    void BubbleMainSightingDevice::rotateDevice(const cocos2d::Vec2 & touch_point)
    {
        reflection_point_component_->calculateReflectionPoints(touch_point);
        //auto points = reflection_point_component_->getReflectionPoints();
        //auto angles = reflection_point_component_->getReflectionAngles();
        //int size = points.size();
        //float angle = -CC_RADIANS_TO_DEGREES(cocos2d::Vec2(0.0f, 1.0f).getAngle(touch_point - GamePlayController::getInstance()->getShootingInitialPosition()));
        
        this->setDeviceRotation(reflection_point_component_->getReflectionAngles());
        this->getNextSightingDevice()->setDevicePosition(reflection_point_component_->getReflectionPoints());
        //this->setRotation(angles.at(0));
        //for (auto var : remaind_device_)
        //{
        //    if (var->getTargetID() < size)
        //    {
        //        //angle *= -1;
        //        var->setPosition(points.at(var->getTargetID()-1));
        //        var->setRotation(angles.at(var->getTargetID()));
        //    }
        //}
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
    //void BubbleMainSightingDevice::changePointsColor(BubbleType color)
    //{
    //    BubbleSightingDevice::changePointsColor(color);
    //    for (auto var : remaind_device_)
    //    {
    //        var->changePointsColor(color);
    //    }

    //}
}