//*******************************************************************************
//������   : SkillStavesBubble
//����     : <���ܵķ�������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _SKILL_STAVES_BUBBLE_H_
#define _SKILL_STAVES_BUBBLE_H_
#include "ColorBubble.h"
namespace bubble_second {
    class SkillStavesBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(SkillStavesBubble);
        ~SkillStavesBubble();
        void bubbleEliminate(int = 0) override;
        std::string getBubbleSightingDevicePointPath() override;
    private:
        SkillStavesBubble();
        bool init();
        void setBubbleTexture(BubbleType) override;
        void dispatchEventAfterShooted() override;
    };
}
#endif