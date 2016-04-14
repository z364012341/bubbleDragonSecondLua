//*******************************************************************************
//������   : AirBubbleManager
//����     : <����С�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//           
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _AIR_BUBBLE_MANAGER_H_
#define _AIR_BUBBLE_MANAGER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "BaseBubble.h"
namespace bubble_second {
    class AirBubbleManager
    {
    public:
        GETINSTANCE_FUNC(AirBubbleManager);
        ~AirBubbleManager();
        void addAirBubble(BaseBubble* bubble);
        void cutAirBubble(BaseBubble* bubble);
        bool isNoneAirBubble();
    private:
        AirBubbleManager();
    private:
        std::set<BaseBubble*> air_bubbles_;
    };
}
#endif //_AIR_BUBBLE_MANAGER_H_