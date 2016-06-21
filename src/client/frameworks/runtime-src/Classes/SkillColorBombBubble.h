//*******************************************************************************
//类名称   : SkillColorBombBubble
//功能     : <技能的彩球炸弹>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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