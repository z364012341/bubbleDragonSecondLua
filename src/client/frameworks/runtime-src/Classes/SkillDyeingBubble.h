//*******************************************************************************
//类名称   : SkillDyeingBubble
//功能     : <技能染色泡泡类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _SKILL_DYEING_BUBBLE_H_
#define _SKILL_DYEING_BUBBLE_H_
#include "ColorBubble.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class SkillDyeingBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(SkillDyeingBubble);
        ~SkillDyeingBubble();
        void bubbleEliminate(int = 0) override;
        void setDyeingColor(BubbleType type);
        BubbleType getDyeingColor();
        std::string getBubbleSightingDevicePointPath() override;
    private:
        SkillDyeingBubble();
        bool init();
        void setBubbleTexture(BubbleType) override;
        void dispatchEventAfterShooted() override;
    private:
        cocostudio::Armature* armature_ = nullptr;
        BubbleType dyeing_color_;
        std::map<BubbleType, int> type_to_skin_numble_1_;
        std::map<BubbleType, int> type_to_skin_numble_2_;
    };
}
#endif //_SKILL_DYEING_BUBBLE_H_
