#include "GameCharactorSkillButton.h"
#include "GameCharactorNameManager.h"
#include "SpriteTextureController.h"
const std::string SKILL_BUTTON_BACKGROUND_PATH_KEY = "skill_bg_key";
const std::string SKILL_BUTTON_PROGRESS_PATH_KEY = "skill_progress_key";
const std::string SKILL_BUTTON_LOGO_PATH_KEY = "skill_logo_key";
namespace bubble_second {
    GameCharactorSkillButton::GameCharactorSkillButton()
    {
        charactor_to_path_[CHARCTOR_LAOHU_ARMATURE_KEY][SKILL_BUTTON_BACKGROUND_PATH_KEY] = "skill_dyeing_button.png";
        charactor_to_path_[CHARCTOR_LAOHU_ARMATURE_KEY][SKILL_BUTTON_PROGRESS_PATH_KEY] = "skill_dyeing_bg.png";
        charactor_to_path_[CHARCTOR_LAOHU_ARMATURE_KEY][SKILL_BUTTON_LOGO_PATH_KEY] = "skill_logo_dyeing.png";

        charactor_to_path_[CHARCTOR_MIAO_ARMATURE_KEY][SKILL_BUTTON_BACKGROUND_PATH_KEY] = "skill_color_bomb_button.png";
        charactor_to_path_[CHARCTOR_MIAO_ARMATURE_KEY][SKILL_BUTTON_PROGRESS_PATH_KEY] = "skill_color_bomb_bg.png";
        charactor_to_path_[CHARCTOR_MIAO_ARMATURE_KEY][SKILL_BUTTON_LOGO_PATH_KEY] = "skill_logo_color_bomb.png";

        charactor_to_path_[CHARCTOR_LAOSHU_ARMATURE_KEY][SKILL_BUTTON_BACKGROUND_PATH_KEY] = "skill_staves_button.png";
        charactor_to_path_[CHARCTOR_LAOSHU_ARMATURE_KEY][SKILL_BUTTON_PROGRESS_PATH_KEY] = "skill_staves_bg.png";
        charactor_to_path_[CHARCTOR_LAOSHU_ARMATURE_KEY][SKILL_BUTTON_LOGO_PATH_KEY] = "skill_logo_staves.png";

        charactor_to_path_[CHARCTOR_TUZI_ARMATURE_KEY][SKILL_BUTTON_BACKGROUND_PATH_KEY] = "skill_big_bomb_button.png";
        charactor_to_path_[CHARCTOR_TUZI_ARMATURE_KEY][SKILL_BUTTON_PROGRESS_PATH_KEY] = "skill_big_bomb_bg.png";
        charactor_to_path_[CHARCTOR_TUZI_ARMATURE_KEY][SKILL_BUTTON_LOGO_PATH_KEY] = "skill_big_bomb_logo.png";
    }

    bool bubble_second::GameCharactorSkillButton::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        auto data = charactor_to_path_[GameCharactorNameManager::getInstance()->getCurrentArmatureName()];
        this->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath(data[SKILL_BUTTON_BACKGROUND_PATH_KEY]));
        return true;
    }


    GameCharactorSkillButton::~GameCharactorSkillButton()
    {
    }
}