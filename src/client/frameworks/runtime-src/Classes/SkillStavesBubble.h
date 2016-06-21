//*******************************************************************************
//类名称   : SkillStavesBubble
//功能     : <技能的法杖泡泡>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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