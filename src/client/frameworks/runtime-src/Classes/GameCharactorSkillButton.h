//*******************************************************************************
//类名称   : GameCharactorSkillButton
//功能     : <游戏角色技能按钮>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_CHARACTOR_SKILL_BUTTON_H_
#define _GAME_CHARACTOR_SKILL_BUTTON_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameCharactorSkillButton : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameCharactorSkillButton);
        ~GameCharactorSkillButton();
    private:
        GameCharactorSkillButton();
        bool init();
    private:
        std::map<std::string, std::map<std::string, std::string>> charactor_to_path_;
    };
}
#endif