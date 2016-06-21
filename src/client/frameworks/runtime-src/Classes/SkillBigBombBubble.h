//*******************************************************************************
//������   : SkillBigBombBubble
//����     : <���ܵ�2Ȧ��ը��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _SKILL_BIG_BOMB_BUBBLE_H_
#define _SKILL_BIG_BOMB_BUBBLE_H_
#include "BombPropertyBubble.h"
namespace bubble_second {
    class SkillBigBombBubble : public BombPropertyBubble
    {
    public:
        CREATE_FUNC(SkillBigBombBubble);
        ~SkillBigBombBubble();
        void setBubbleTexture(BubbleType) override;
        std::string getBubbleSightingDevicePointPath() override;
        float playTheSpecialEffects() override;
        void bubbleEliminate(int = 0) override;
    private:
        SkillBigBombBubble();
        bool init();
    };
}
#endif