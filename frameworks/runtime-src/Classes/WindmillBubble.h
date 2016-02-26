//*******************************************************************************
//������   : WindmillBubble
//����     : <�糵������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _WINDMILL_BUBBLE_H_
#define _WINDMILL_BUBBLE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
namespace bubble_second {
    class WindmillBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(WindmillBubble);
        ~WindmillBubble();
        void setParent(cocos2d::Node* parent) override;
        void bubbleEliminate(int combo = 0) override;
    private:
        WindmillBubble();
        bool init();
        void setBubbleTexture(BubbleType type) override;
        cocos2d::Node* getFlyingTexture();
        cocos2d::Action* getFlyingAction();
        cocos2d::CardinalSplineBy* getArchimedeanSpiralAction();
    private:
        cocos2d::Sprite* sp_ = nullptr;
    };
}
#endif //_WINDMILL_BUBBLE_H_