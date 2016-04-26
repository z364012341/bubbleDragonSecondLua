#include "BubbleSightingDevice.h"
#include "BubbleSightingPoint.h"
#include "EnterPropsViewManager.h"
#include "GamePlayController.h"
const float SIGHTING_POINT_BUBBLE_RADIUS = BUBBLE_RADIUS;
const float SIGHTING_POINT_REFLECTION_WIDTH = /*700.0f;*/GAME_DESIGN_RESOLUTION_WIDTH - SIGHTING_POINT_BUBBLE_RADIUS * 2;
const float SIGHTING_POINT_WORLD_MAX_X = GAME_DESIGN_RESOLUTION_WIDTH - SIGHTING_POINT_BUBBLE_RADIUS;
const float SIGHTING_POINT_MOVE_SPEED = 75.0f; //瞄准点移动速度
const float BUBBLE_SIGHTING_POINT_TOP_MOVEBY_Y = BUBBLE_RADIUS *4;  //瞄准线碰到顶部只反弹2颗
const std::string SIGHTING_POINTS_VISIBLE_SCHEDULE_KEY = "sighting_points_visible_schedule_key";
namespace bubble_second {
    //float BubbleSightingDevice::first_device_angle_ = 0.0f;
    //float BubbleSightingDevice::max_top_y_ = 0.0f;
    BubbleSightingDevice::BubbleSightingDevice()
    {
    }

    BubbleSightingDevice::~BubbleSightingDevice()
    {
    }

    bool BubbleSightingDevice::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }

        this->setName(NAME_BUBBLE_SIGHTING_DEVICE);
        for (int i = 0; i < BUBBLE_SIGHTING_POINT_NUMBLE; i++)
        {
            sighting_points_.pushBack(BubbleSightingPoint::create());
        }
        this->sightingPointMove();
        //this->addPhysicsBody();
        return true;
    }

    void BubbleSightingDevice::onEnter()
    {
        cocos2d::Node::onEnter();
        this->schedule([=](float) {
            this->setSightingPointsVisibled();
        }, SIGHTING_POINTS_VISIBLE_SCHEDULE_KEY);
    }
    void BubbleSightingDevice::onExit()
    {
        cocos2d::Node::onExit();
        this->unschedule(SIGHTING_POINTS_VISIBLE_SCHEDULE_KEY);
    }

    //void BubbleSightingDevice::rotateSightingDevice(const float angle, const float& max_pos_y)
    //{
    //    this->setRotation(angle);
    //    if (-1.0f <= angle && angle <= 1.0f)
    //    {
    //        return;
    //    }
    //    this->setFirstDeviceAngle(angle);
    //    if (sight_device_)
    //    {
    //        //this->setMaxTopY(max_pos_y);
    //        sight_device_->rotateRemainDevice(angle*2, this->getReflectionPoint(), max_pos_y);
    //    }
    //}

    //void BubbleSightingDevice::rotateRemainDevice(const float angle, const cocos2d::Vec2& point, const float& max_pos_y)
    //{
    //    this->setDeviceRotationAndPosition(angle, point);
    //    bool contact_top = this->isContactTopBorder(max_pos_y);
    //    bool used_props = !EnterPropsViewManager::getInstance()->getPropsSwitchEnable(AIMING_LINE_COMMODITY_NAME) || contact_top;
    //    this->setHidePointEnable(used_props);
    //    if (contact_top)
    //    {
    //        this->setTopReflectRotationAndPosition(angle, point, max_pos_y);
    //    }
    //    if (sight_device_)
    //    {
    //        if (!contact_top)
    //        {
    //            sight_device_->rotateRemainDevice(this->getRotation(), this->getReflectionPoint(), max_pos_y);

    //        }
    //        else
    //        {
    //            sight_device_->deviceGoAway();
    //        }
    //    }
    //}

    //void BubbleSightingDevice::setDeviceRotationAndPosition(float angle, const cocos2d::Vec2 & point)
    //{
    //    float device_angle = angle*-1;
    //    this->setRotation(device_angle);
    //    int hypotenuse = (int)(point.y) % (int)MAP_BUBBLE_DIAMETER;
    //    this->setHypotenuseOffset(hypotenuse);
    //    float pos_x_offs = hypotenuse * sin(CC_DEGREES_TO_RADIANS(device_angle));
    //    float pos_y_offs = hypotenuse * cos(CC_DEGREES_TO_RADIANS(device_angle));
    //    cocos2d::Vec2 result_point(0.0f - pos_x_offs, point.y - pos_y_offs);
    //    this->setPosition(result_point);
    //}

    void BubbleSightingDevice::setDeviceRotation(const std::vector<float>& angles)
    {
        if (this->getTargetID() < (int)angles.size())
        {
            this->setRotation(angles.at(this->getTargetID()));
            if (sight_device_)
            {
                sight_device_->setDeviceRotation(angles);
            }
        }
        else 
        {
            this->deviceGoAway();
            return;
        }
    }

    void BubbleSightingDevice::setDevicePosition(const std::vector<cocos2d::Vec2>& points)
    {
        if (this->getTargetID()-1 < (int)points.size())
        {
            this->setPosition(points.at(this->getTargetID()-1));
            if (sight_device_)
            {
                sight_device_->setDevicePosition(points);
            }
        }
        else
        {
            this->deviceGoAway();
            return;
        }
    }

    void BubbleSightingDevice::turnOnSightingDevice()
    {
        switch_flag_ = true;
        if (nullptr != sight_device_)
        {
            sight_device_->turnOnSightingDevice();
        }
    }

    void BubbleSightingDevice::turnOffSightingDevice()
    {
        switch_flag_ = false;
        if (nullptr != sight_device_)
        {
            sight_device_->turnOffSightingDevice();
        }
    }

    bool BubbleSightingDevice::isDeviceOnStage()
    {
        return switch_flag_;
    }

    void BubbleSightingDevice::setReflectionPointOffset(float offset)
    {
        relection_offset_ = offset;
        points_node_->setPositionY(offset);
        if (sight_device_ != nullptr)
        {
            sight_device_->setReflectionPointOffset(offset);
        }
    }

    void BubbleSightingDevice::setDevicePointHidden(const std::vector<bool>& flags)
    {
        if (this->getTargetID()-1 < (int)flags.size())
        {
            this->setHidePointEnable(flags.at(this->getTargetID()-1));
            if (sight_device_)
            {
                sight_device_->setDevicePointHidden(flags);
            }
            else
            {
                this->setHidePointEnable(true);
            }
        }
        else
        {
            this->deviceGoAway();
            return;
        }
    }

    void BubbleSightingDevice::setVisible(bool visible)
    {
        cocos2d::Node::setVisible(visible && this->isDeviceOnStage());
        if (sight_device_ != nullptr)
        {
            sight_device_->setVisible(visible);
        }
    }

    //cocos2d::Vec2 bubble_second::BubbleSightingDevice::calculateReflectTopPosition(const cocos2d::Vec2& point, const float& max_pos_y)
    //{
    //    float local_y = (this->convertLocalToCsbSpace(cocos2d::Vec2::ZERO).y - max_pos_y) / cos(CC_DEGREES_TO_RADIANS(this->getFirstDeviceAngle()));
    //    float pos_y = point.y - local_y - this->getHypotenuseOffset();
    //    int hypotenuse = (int)(pos_y) % (int)MAP_BUBBLE_DIAMETER;
    //    this->setHypotenuseOffset(hypotenuse);
    //    float pos_x_offs = hypotenuse * sin(CC_DEGREES_TO_RADIANS(this->getRotation()));
    //    float pos_y_offs = hypotenuse * cos(CC_DEGREES_TO_RADIANS(this->getRotation()));
    //    return cocos2d::Vec2(0.0f + pos_x_offs, pos_y + pos_y_offs);
    //}

    //void BubbleSightingDevice::setTopReflectRotationAndPosition(float angle, const cocos2d::Vec2 & point, const float & max_pos_y)
    //{
    //    this->setPosition(calculateReflectTopPosition(point, max_pos_y));
    //    this->setRotation(this->getRotation() + 180.0f);
    //}

    void BubbleSightingDevice::deviceGoAway()
    {
        this->setRotation(0.0f);
        this->setPositionX(BUBBLE_SIGHTING_DEVICE_GO_AWAY_Y);
        if (sight_device_)
        {
            sight_device_->deviceGoAway();
        }
    }

    void BubbleSightingDevice::stopDevicePoint()
    {
        for (auto var : sighting_points_)
        {
            var->pointStop();
        }
    }

    void BubbleSightingDevice::performSightingDevice()
    {
        this->turnOnDeviceOnce();
        this->stopDevicePoint();
        this->schedule([=](float) {
            float angle = this->getRotation();
            //SHOOT_BUBBLE_ENABLED_DEGREE;
            //this->rotateSightingDevice(angle + 1, 2000.0f);
        }, "unused_key");
    }

    cocos2d::Vec2 BubbleSightingDevice::convertLocalToCsbSpace(const cocos2d::Vec2& local_point)
    {
        cocos2d::Vec2 point = local_point;
        cocos2d::Node* parent = points_node_;
        do
        {
            parent = parent->getParent();
        } while (parent->getName() != UI_NAME_GAME_PLAY_AREA_NODE);
        auto p1 = points_node_->convertToWorldSpaceAR(local_point);
        auto p2 = parent->convertToNodeSpaceAR(p1);
        return p2;
    }

    void BubbleSightingDevice::setHidePointEnable(bool flag)
    {
        is_hide_point_ = flag;
        if (is_hide_point_ && sight_device_)
        {
            sight_device_->deviceGoAway();
        }
    }

    bool BubbleSightingDevice::isHidePoint()
    {
        return is_hide_point_;
    }

    void BubbleSightingDevice::turnOnDeviceOnce(int device_numble)
    {
        this->setTargetID(device_numble);
        this->setVisible(false);
        this->sightingPointMove();
        //auto b = EnterPropsViewManager::getInstance()->getPropsSwitchEnable(AIMING_LINE_COMMODITY_NAME);
        int device_numble_max = EnterPropsViewManager::getInstance()->getPropsSwitchEnable(AIMING_LINE_COMMODITY_NAME) ?
            BUBBLE_SIGHTING_DEVICE_TOTAL : BUBBLE_SIGHTING_DEVICE_UNUSED_PROPS_TOTAL;
        if (this->getTargetID() < device_numble_max)
        {
            sight_device_ = BubbleSightingDevice::create();
            this->addChild(sight_device_);
            sight_device_->turnOnDeviceOnce(this->getTargetID()+1);
        }
    }

    void BubbleSightingDevice::sightingPointMove()
    {
        //cocos2d::MoveTo* move_go = cocos2d::MoveTo::create(5.0f, cocos2d::Vec2(0.0f, MAP_BUBBLE_DIAMETER*sighting_points_.size()));
        //cocos2d::MoveBy* move_back = cocos2d::MoveBy::create(0.0f, cocos2d::Vec2(0.0f, -MAP_BUBBLE_DIAMETER*sighting_points_.size()));
        //cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(move_go, move_back);
        float distance = MAP_BUBBLE_DIAMETER*sighting_points_.size();
        float sighting_point_y = 0.0f;
        float y_offs = MAP_BUBBLE_DIAMETER;
        points_node_ = cocos2d::Node::create();
        this->addChild(points_node_);
        for (auto var : sighting_points_)
        {
            var->stopAllActions();
            var->setPosition(0.0f, sighting_point_y);
            if (!var->getParent())
            {
                points_node_->addChild(var);
            }
            var->clearContactCount();
            var->addPhysicsBodyCanntWorld();
            cocos2d::MoveBy* move_go = cocos2d::MoveBy::create((distance - sighting_point_y)/ SIGHTING_POINT_MOVE_SPEED, cocos2d::Vec2(0.0f, distance - sighting_point_y));

            cocos2d::CallFunc* callfunc = cocos2d::CallFunc::create([=]() {
                cocos2d::MoveBy* move_back = cocos2d::MoveBy::create(0.0f, cocos2d::Vec2(0.0f, -distance));
                cocos2d::MoveBy* move_go2 = cocos2d::MoveBy::create(distance / SIGHTING_POINT_MOVE_SPEED, cocos2d::Vec2(0.0f, distance));
                var->runAction(cocos2d::RepeatForever::create(cocos2d::Sequence::create(move_back, move_go2, nullptr)));
            });
            cocos2d::Sequence* seq = cocos2d::Sequence::create(move_go, callfunc, nullptr);
            var->runAction(seq);
            sighting_point_y += y_offs;
        }   
    }

    void BubbleSightingDevice::setHypotenuseOffset(float offset)
    {
        hypotenuse_offset_ = offset;
    }

    float BubbleSightingDevice::getHypotenuseOffset()
    {
        return hypotenuse_offset_;
    }

    //void BubbleSightingDevice::setMaxTopY(float numble)
    //{
    //    max_top_y_ = numble;
    //}

    float BubbleSightingDevice::getMaxTopY()
    {
        return GamePlayController::getInstance()->getPlayAreaMaxY();
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    //void BubbleSightingDevice::addPhysicsBody()
    //{
    //   cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createBox(cocos2d::Size(BUBBLE_BODY_DIAMETER, MAP_BUBBLE_DIAMETER*sighting_points_.size()*2),
    //        cocos2d::PhysicsMaterial(PHYSICS_SIGHTING_POINT_BODY_DENSITY, PHYSICS_SIGHTING_POINT_BODY_RESTITUTION, PHYSICS_SIGHTING_POINT_BODY_FRICTION));
    //    body->setDynamic(true);
    //    body->setCategoryBitmask(0);
    //    body->setCollisionBitmask(0);
    //    body->setContactTestBitmask(0);
    //    body->setGravityEnable(false);
    //    body->setGroup(BUBBLE_BODY_GROUP);
    //    this->setPhysicsBody(body);
    //}

    cocos2d::Vec2 BubbleSightingDevice::getReflectionPoint()
    {//计算反射点
        cocos2d::Vec2 point(cocos2d::Vec2::ZERO);
        float original_y = 0.0f;
        float bottom_edges = SIGHTING_POINT_REFLECTION_WIDTH;
        if (!isFirstDevice())
        {
            original_y = bottom_edges / sin(CC_DEGREES_TO_RADIANS(this->getRotation() / 2));
        }
        else
        {
            original_y = bottom_edges / 2 / sin(CC_DEGREES_TO_RADIANS(this->getRotation()));
        }
        //auto p = this->convertLocalToCsbSpace(point);
        point = cocos2d::Vec2(0.0f, abs(original_y) + this->getHypotenuseOffset());
        return point;
    }

    bool BubbleSightingDevice::isFirstDevice()
    {
        return this->getTargetID() == 0;
    }

    //void BubbleSightingDevice::setFirstDeviceAngle(const float& angle)
    //{
    //    first_device_angle_ = angle;
    //}

    //float BubbleSightingDevice::getFirstDeviceAngle() const
    //{
    //    return first_device_angle_;
    //}

    float BubbleSightingDevice::getSightingPointsMinPositionY()
    {
        float top_min_y = BUBBLE_SIGHTING_POINT_TOP_MOVEBY_Y + this->getHypotenuseOffset();
        float min_y = this->isHidePoint() ? top_min_y : BUBBLE_SIGHTING_POINT_MOVEBY_Y;
        for (auto var : sighting_points_)
        {
            if (var->isContacting() && var->getPositionY() < min_y)
            {
                min_y = var->getPositionY();
            }
        }
        return min_y;
    }

    bool BubbleSightingDevice::isSightingPointsNeedHidden(const cocos2d::Vec2& point/*, float min_y, float max_y*/)
    {
        cocos2d::Vec2 var_point = this->convertLocalToCsbSpace(point);
        return point.y >= this->getSightingPointsMinPositionY() || var_point.x <= SIGHTING_POINT_BUBBLE_RADIUS || var_point.x >= SIGHTING_POINT_WORLD_MAX_X || var_point.y >= this->getMaxTopY();
    }

    void BubbleSightingDevice::setSightingPointsVisibled()
    {
        //float min_y = this->getSightingPointsMinPositionY();
        //float max_y = GAME_DESIGN_RESOLUTION_WIDTH - MAP_BUBBLE_RADIUS;
        for (auto var : sighting_points_)
        {
            bool need_hidden = this->isSightingPointsNeedHidden(var->getPosition()) && this->isDeviceOnStage();
            var->setPointEnabled(!need_hidden);
        }

        bool contact_bubble = this->isContactBubble();
        if (sight_device_ && contact_bubble)
        {
            sight_device_->setVisible(!contact_bubble);
        }

    }

    bool BubbleSightingDevice::isContactBubble()
    {
        bool contact_bubble = false;
        for (auto var : sighting_points_)
        {
            if (var->isContacting())
            {
                contact_bubble = !contact_bubble;
                break;
            }
        }
        return contact_bubble;
    }

    void BubbleSightingDevice::contactWorldBorder()
    {
        if (sight_device_)
        {
            //sight_device_->setVisible(!this->isContactBubble());
        }
    }

    void BubbleSightingDevice::contactBubble()
    {
        if (sight_device_)
        {
            sight_device_->setVisible(false);
            //sight_device_->turnOffSightingDevice();
        }
    }

    void BubbleSightingDevice::setTargetID(int numble)
    {
        target_id_ = numble;
    }

    int BubbleSightingDevice::getTargetID() const
    {
        return target_id_;
    }

    void BubbleSightingDevice::setNextSightingDevice(BubbleSightingDevice * device)
    {
        sight_device_ = device;
    }

    BubbleSightingDevice * BubbleSightingDevice::getNextSightingDevice()
    {
        return sight_device_;
    }

    void BubbleSightingDevice::changePointsColor(BubbleType color)
    {
        sighting_points_;
        for (auto var : sighting_points_)
        {
            var->changeSelfColor(color);
        }
        if (sight_device_)
        {
            sight_device_->changePointsColor(color);
        }
    }

    //bool BubbleSightingDevice::isContactTopBorder(const float& max_pos_y)
    //{
    //    return this->convertLocalToCsbSpace(cocos2d::Vec2::ZERO).y >= max_pos_y;
    //}
}