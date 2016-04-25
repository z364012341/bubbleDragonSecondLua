//*******************************************************************************
//������   : BubbleReflectionPointComponent
//����     : <С����·���������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BUBBLE_REFLECTION_POINT_COMPONENT_H_
#define _BUBBLE_REFLECTION_POINT_COMPONENT_H_
#include "cocos2d.h"
namespace bubble_second {
    class BubbleReflectionPointComponent  : public cocos2d::Node
    {
    public:
        CREATE_FUNC(BubbleReflectionPointComponent);
        ~BubbleReflectionPointComponent();
        //void setBubblePositionOfShooting(const cocos2d::Vec2& point);
        void calculateReflectionPoints(const cocos2d::Vec2& touch_point);
        std::vector<cocos2d::Vec2> getReflectionPoints();
        std::vector<float> getReflectionAngles();
    private:
        BubbleReflectionPointComponent();
        bool init();
        void pushBackRelectionPoint(const cocos2d::Vec2& pre_point, const cocos2d::Vec2& current_point);
        void pushBackAngle(const cocos2d::Vec2& pre_point, const cocos2d::Vec2& current_point);
    private:
        //cocos2d::Vec2 shooting_position_;
        std::vector<cocos2d::Vec2> reflection_points_;
        std::vector<float> reflection_angles_;
        std::map<bool, float> key_to_x_;
        float delta_y_ = 0.0f;
    };
}
#endif //_BUBBLE_REFLECTION_POINT_COMPONENT_H_