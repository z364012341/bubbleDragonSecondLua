//*******************************************************************************
//������   : BlackObstacleBubble
//����     : <��ɫ�ϰ���С��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BLACK_OBSTACLE_BUBBLE_H_
#define _BLACK_OBSTACLE_BUBBLE_H_
#include "ColorBubble.h"
namespace bubble_second {
    class BlackObstacleBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(BlackObstacleBubble);
        BlackObstacleBubble();
        ~BlackObstacleBubble();
    private:
        bool init();
    };
}
#endif