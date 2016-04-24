#include "BubbleReflectionPointComponent.h"
#include "BubbleSecondConstant.h"
#include "GamePlayController.h"
const float REFLECTION_POINT_MIN_X = BUBBLE_RADIUS;
const float REFLECTION_POINT_MAX_X = GAME_DESIGN_RESOLUTION_WIDTH - BUBBLE_RADIUS;
namespace bubble_second {
    BubbleReflectionPointComponent::BubbleReflectionPointComponent()
    {
        key_to_x_[true] = REFLECTION_POINT_MIN_X;
        key_to_x_[false] = REFLECTION_POINT_MAX_X;
    }

    bool BubbleReflectionPointComponent::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        return true;
    }

    BubbleReflectionPointComponent::~BubbleReflectionPointComponent()
    {
    }

    void BubbleReflectionPointComponent::calculateReflectionPoints(const cocos2d::Vec2& bubble_point, const cocos2d::Vec2 & touch_point)
    {
        reflection_points_.clear();
        cocos2d::Vec2 shooting_position = bubble_point;
        float max_y = GamePlayController::getInstance()->getPlayAreaMaxY();
        if (shooting_position.x == touch_point.x)
        {
            reflection_points_.push_back(cocos2d::Vec2(shooting_position.x, max_y));
            reflection_points_.push_back(cocos2d::Vec2(shooting_position.x, 0.0f));
            return;
        }
        float k = (touch_point.y - shooting_position.y) / (touch_point.x - shooting_position.x);
        float b = shooting_position.y - shooting_position.x *k;

        bool direction = touch_point.x < shooting_position.x;
        float x = key_to_x_[direction];
        float y = k*x + b;
        float delta_y = (y - shooting_position.y) * 2;

        {
            cocos2d::Vec2 point = cocos2d::Vec2(x, y);
            if (y < max_y)
            {
                reflection_points_.push_back(point);
            }
            else
            {
                reflection_points_.push_back(cocos2d::Vec2::getIntersectPoint(shooting_position, point, cocos2d::Vec2(REFLECTION_POINT_MIN_X, max_y), cocos2d::Vec2(REFLECTION_POINT_MAX_X, max_y)));
                reflection_points_.push_back(cocos2d::Vec2(point.x, max_y) - point + cocos2d::Vec2(point.x, max_y));
                delta_y *= -1;
            }
        }

        while (reflection_points_.back().y > 0.0f)
        {
            direction = !direction;
            cocos2d::Vec2 point = cocos2d::Vec2(key_to_x_[direction], reflection_points_.back().y + delta_y);
            if (point.y < max_y)
            {
                reflection_points_.push_back(point);
                //CCLOG("refle : x:%f, y:%f", point.x, point.y);
            }
            else
            {
                reflection_points_.push_back(cocos2d::Vec2::getIntersectPoint(reflection_points_.back(), point, cocos2d::Vec2(REFLECTION_POINT_MIN_X, max_y), cocos2d::Vec2(REFLECTION_POINT_MAX_X, max_y)));
                reflection_points_.push_back(cocos2d::Vec2(point.x, max_y) - point + cocos2d::Vec2(point.x, max_y));
                delta_y *= -1;
            }
        }
    }

    std::vector<cocos2d::Vec2> BubbleReflectionPointComponent::getReflectionPoints()
    {
        return reflection_points_;
    }
}