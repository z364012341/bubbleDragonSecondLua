//*******************************************************************************
//类名称   : SkillBigBombBubble
//功能     : <技能的2圈球炸弹>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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