#include "BarrelHead.h"
#include "BubbleSecondConstant.h"
#include "GameAudioController.h"
const int BARRELHEADEDGE_BODY_RADIUS = 20;  //Í°±ß¸ÕÌå°ë¾¶
namespace bubble_second {
    BarrelHead::BarrelHead()
    {
    }

    bool BarrelHead::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->setName(BARREL_HEAD_NAME);
        cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(BARRELHEADEDGE_BODY_RADIUS,
            cocos2d::PhysicsMaterial(PHYSICS_BARRELHEADEDGE_BODY_DENSITY,
                PHYSICS_BARRELHEADEDGE_BODY_RESTITUTION, PHYSICS_BARRELHEADEDGE_BODY_FRICTION));//ÃÜ¶È, »Ö¸´,Ä¦²ÁÁ¦
        body->setDynamic(false);
        body->setGravityEnable(false);
        body->setCategoryBitmask(BITMASK_BARRELHEADEDGE_CATEGORY);
        body->setCollisionBitmask(BITMASK_BARRELHEADEDGE_COLLISION);
        body->setContactTestBitmask(BITMASK_BARRELHEADEDGE_CONTACTTEST);
        this->setPhysicsBody(body);
        return true;
    }


    BarrelHead::~BarrelHead()
    {
    }
    void BarrelHead::contactOnce()
    {
        GameAudioController::getInstance()->playContactBarrelHeadEffect();
    }
}