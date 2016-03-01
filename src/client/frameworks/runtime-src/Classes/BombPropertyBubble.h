//*******************************************************************************
//������   : BombPropertyBubble
//����     : <һըը��Ȧ��ը������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BOMB_PROPERTY_BUBBLE_H_
#define _BOMB_PROPERTY_BUBBLE_H_
#include "cocos2d.h"
#include "ColorBubble.h"
namespace bubble_second {
    class BombPropertyBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(BombPropertyBubble);
        virtual ~BombPropertyBubble();
    public:
        void dispatchEventAfterShooted() override;
        void bubbleEliminate(int = 0) override;
        float playTheSpecialEffects() override;
        void downFromAir() override;
    private:
        BombPropertyBubble();
        bool init();
    };
}
#endif //_BOMB_PROPERTY_BUBBLE_H_