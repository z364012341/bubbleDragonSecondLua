//*******************************************************************************
//������   : BubbleSightingDevice
//����     : <��Ϸ���ݵ���׼��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б���
//*******************************************************************************
#ifndef _BUBBLE_SIGHTING_DEVICE_H_
#define _BUBBLE_SIGHTING_DEVICE_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleSightingPoint;
    typedef cocos2d::Vector<BubbleSightingPoint*> SightPointVector;
    class BubbleSightingDevice : public cocos2d::Node
    {
    public:
        CREATE_FUNC(BubbleSightingDevice);
        ~BubbleSightingDevice();
        void rotateSightingDevice(const float angle, const float& max_pos_y);
        void contactWorldBorder();
        void contactBubble();
        //���豸
        void turnOnDeviceOnce(int device_numble = 0);
        //�ı���ɫ
        void changePointsColor(BubbleType color);
        //�Ƿ����������߽�
        bool isContactTopBorder(const float& max_pos_y);
        //�Ƿ��ǵ�һ̨�豸
        bool isFirstDevice();
        //�����һ̨�豸�ĽǶ��������㶥��������λ��
        void setFirstDeviceAngle(const float& angle);
        float getFirstDeviceAngle() const;
        //����������������ʣ�µ���Զ��
        void deviceGoAway();
    private:
        BubbleSightingDevice();
        bool init();
        //��ȡ��һ����׼�ߵ�λ��
        cocos2d::Vec2 getReflectionPoint();
        //����point����ʾ
        void setSightingPointsVisibled();
        //������׼�����Сλ��y
        float getSightingPointsMinPositionY();
        //�ж��Ƿ��鵽
        bool isContactBubble();
        //�ж���׼���Ƿ���Ҫ����
        bool isSightingPointsNeedHidden(const cocos2d::Vec2& point, float min_y, float max_y);
        //targetID  {set get}
        void setTargetID(int numble);
        int getTargetID() const;
        //��תʣ����豸
        void rotateRemainDevice(const float angle, const cocos2d::Vec2& point, const float& max_pos_y);
        void setDeviceRotationAndPosition(float angle, const cocos2d::Vec2& point);
        //���㶥��������λ��
        //�Ȱ���ͨ���㷨���λ��, ���λ�ó�������, �����¼���λ��
        //��һ������: ��ûƫ�ƹ��ĵ��λ��
        //�ڶ�������: ����λ��
        cocos2d::Vec2 calculateReflectTopPosition(const cocos2d::Vec2& point, const float& max_pos_y);
        void setTopReflectRotationAndPosition(float angle, const cocos2d::Vec2& point, const float& max_pos_y);
        cocos2d::Vec2 convertLocalToCsbSpace(const cocos2d::Vec2& local_point);
        //�����Ƿ�Ҫ���ص��
        void setHidePointEnable(bool flag);
        bool isHidePoint();
        //������ȥ
        void sightingPointMove();
        //hypotenuse_offset_ set get
        void setHypotenuseOffset(float offset);
        float getHypotenuseOffset();
        //max_top_y_ set get
        void setMaxTopY(float numble);
        float getMaxTopY();
    private:
        static float max_top_y_; //�������������y   �����csb������
        size_t points_index_ = 0;
        BubbleSightingDevice* sight_device_ = nullptr;
        SightPointVector sighting_points_;
        int target_id_ = 0;
        static float first_device_angle_;
        bool is_hide_point_ = false;
        float hypotenuse_offset_ = 0.0f; //б��ƫ��, ����׼�ߵĵ��з���Ч��
    };
}
#endif //_BUBBLE_SIGHTING_DEVICE_H_