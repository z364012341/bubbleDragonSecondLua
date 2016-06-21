//*******************************************************************************
//������   : SkillColorBombBubble
//����     : <���ܵĲ���ը��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _SKILL_COLOR_BOMB_BUBBLE_H_
#define _SKILL_COLOR_BOMB_BUBBLE_H_
#include "ColorBombBubble.h"
namespace bubble_second {
    class SkillColorBombBubble  : public ColorBombBubble
    {
    public:
        CREATE_FUNC(SkillColorBombBubble);
        ~SkillColorBombBubble();
        void setBubbleTexture(BubbleType) override;
        std::string getBubbleSightingDevicePointPath() override;
        void bubbleEliminate(int = 0) override;
    private:
        bool init();
        SkillColorBombBubble();
    };
}
#endif //_SKILL_COLOR_BOMB_BUBBLE_H_