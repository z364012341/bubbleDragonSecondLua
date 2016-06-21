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
        progress_sprite_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(data[SKILL_BUTTON_PROGRESS_PATH_KEY]);
        progress_sprite_->setPositionY(-50.0f);
        cocos2d::ClippingNode* clippingnode = cocos2d::ClippingNode::create(progress_sprite_);
        clippingnode->setAlphaThreshold(0);
        clippingnode->addChild(progress_sprite_);
        clippingnode->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath(data[SKILL_BUTTON_LOGO_PATH_KEY]));

        //cocos2d::Sprite* top_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath("skill_button_top.png");
        cocos2d::ClippingNode* top_clippingnode = cocos2d::ClippingNode::create(SpriteTextureController::getInstance()->createGameSpriteWithPath(data[SKILL_BUTTON_PROGRESS_PATH_KEY]));
        top_clippingnode->setAlphaThreshold(0);
        top_clippingnode->addChild(clippingnode);
        this->addChild(top_clippingnode);
        this->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath("skill_button_edge.png"));
        this->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath("skill_button_top.png"));
        return true;
    }


    GameCharactorSkillButton::~GameCharactorSkillButton()
    {
    }
}