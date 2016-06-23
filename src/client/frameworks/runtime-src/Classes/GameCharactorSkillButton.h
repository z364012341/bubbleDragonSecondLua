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
#include "cocostudio\CocoStudio.h"
#include "ui\UIButton.h"
namespace bubble_second {
    class GameCharactorSkillButton : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameCharactorSkillButton);
        ~GameCharactorSkillButton();
        void onEnter() override;
        void onExit() override;
        void setSkillButtonEnabled(bool enabled);
    private:
        GameCharactorSkillButton();
        bool init();
        void setSkillEnergy(int numble);
        void addOneSkillEnergy();
        int getSkillEnergyNumble();
        void updateProgressPosition();
        float calculateProgressPositionY();
        void updateSkillEnergyFullArmature();
        void addSkillEnergyFullArmature();
        void removeSkillEnergyFullArmature();
        bool isSkillEnergyFull();
        void skillButtonClickCallBack(cocos2d::Ref*);
    private:
        //std::map<std::string, std::map<std::string, std::string>> charactor_to_path_;
        cocos2d::Sprite* progress_sprite_ = nullptr;
        cocos2d::Sprite* progress_head_ = nullptr;
        int current_energy_nunble_ = 0;
        cocostudio::Armature* energy_full_armature_ = nullptr;
        cocos2d::EventListenerCustom* listerner_ = nullptr;
        cocos2d::ui::Button* skill_button_ = nullptr;
    };
}
#endif