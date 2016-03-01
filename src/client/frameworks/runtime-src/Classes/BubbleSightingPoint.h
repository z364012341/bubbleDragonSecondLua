//*******************************************************************************
//������   : BubbleSightingPoint
//����     : <��Ϸ���ݵ���׼����������ĵ�
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BUBBLE_SIGHTING_POINT_H_
#define _BUBBLE_SIGHTING_POINT_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleSightingPoint : public cocos2d::Sprite
    {
    public:
        CREATE_FUNC(BubbleSightingPoint);
        ~BubbleSightingPoint();
        //void addImpulse();
        //void addPhysicsBody();
        void addPhysicsBodyCanntWorld();
        //������ʾ
        void setPointEnabled(bool flag);
        //��ײ����
        void addContactCount();
        void cutContactCount();
        void clearContactCount();
        //�Ƿ�������ײ
        bool isContacting();
        //�ı���ɫ
        void changeSelfColor(BubbleType color);
        //�����Ƿ����������߽�
        //void setContactTopBorder();
    private:
        BubbleSightingPoint();
        bool init();
        //cocos2d::Vec2 getPointInCsbSpace();
    private:
        //������ײ������
        int contact_count_ = 0;
    };
}
#endif //_BUBBLE_SIGHTING_POINT_H_