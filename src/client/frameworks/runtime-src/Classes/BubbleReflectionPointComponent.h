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
        void calculateReflectionPoints(const cocos2d::Vec2& bubble_point, const cocos2d::Vec2& touch_point);
        std::vector<cocos2d::Vec2> getReflectionPoints();
    private:
        BubbleReflectionPointComponent();
        bool init();
    private:
        //cocos2d::Vec2 shooting_position_;
        std::vector<cocos2d::Vec2> reflection_points_;
        std::map<bool, float> key_to_x_;
    };
}
#endif //_BUBBLE_REFLECTION_POINT_COMPONENT_H_