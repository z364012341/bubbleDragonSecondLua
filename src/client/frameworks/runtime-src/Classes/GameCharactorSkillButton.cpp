#include "GameCharactorSkillButton.h"
#include "GameCharactorNameManager.h"
#include "SpriteTextureController.h"
#include "GameScoreController.h"

const std::string SKILL_BUTTON_BACKGROUND_PATH_KEY = "skill_bg_key";
const std::string SKILL_BUTTON_PROGRESS_PATH_KEY = "skill_progress_key";
const std::string SKILL_BUTTON_LOGO_PATH_KEY = "skill_logo_key";
const std::string SKILL_PROGRESS_HEAD_PATH_KEY = "skill_progress_head";
const std::string SKILL_ENERGY_ADD_PARTICLE_PATH_KEY = "skill_energy_add_particle";
const std::string SKILL_ENERGY_ADD_PARTICLE_PATH = "particle/dutiao01.plist";
const std::string SKILL_ENERGY_FULL_ARMATURE_NAME = "jinengkuang";
const float PROGRESS_SPRITE_INITAIL_POS_Y = -145.0f;
const float PROGRESS_MOVE_SPEED = 500.0f;
const int SKILL_ENERGY_NUMBLE_MAX = 6;
const float PROGRESS_POS_Y_DELTA = PROGRESS_SPRITE_INITAIL_POS_Y / SKILL_ENERGY_NUMBLE_MAX;
const std::map<std::string, std::map<std::string, std::string>> CHARACTOR_TO_PATH = {
    { CHARCTOR_LAOHU_ARMATURE_KEY ,{
        {SKILL_BUTTON_BACKGROUND_PATH_KEY ,  std::string("skill_dyeing_button.png") },
        { SKILL_BUTTON_PROGRESS_PATH_KEY ,  std::string("skill_dyeing_bg.png") },
        { SKILL_BUTTON_LOGO_PATH_KEY ,  std::string("skill_logo_dyeing.png") },
        { SKILL_PROGRESS_HEAD_PATH_KEY ,  std::string("skill_dyeing_head.png") },
        { SKILL_ENERGY_ADD_PARTICLE_PATH_KEY ,  std::string("particle/skill_dyeing_particle.png") }
    }},
    { CHARCTOR_MIAO_ARMATURE_KEY ,{
        { SKILL_BUTTON_BACKGROUND_PATH_KEY ,  std::string("skill_color_bomb_button.png") },
        { SKILL_BUTTON_PROGRESS_PATH_KEY ,  std::string("skill_color_bomb_bg.png") },
        { SKILL_BUTTON_LOGO_PATH_KEY ,  std::string("skill_logo_color_bomb.png") },
        { SKILL_PROGRESS_HEAD_PATH_KEY ,  std::string("skill_color_bomb_head.png") } ,
        { SKILL_ENERGY_ADD_PARTICLE_PATH_KEY ,  std::string("particle/skill_color_bomb_particle.png") }
    } },
    { CHARCTOR_LAOSHU_ARMATURE_KEY ,{
        { SKILL_BUTTON_BACKGROUND_PATH_KEY ,  std::string("skill_staves_button.png") },
        { SKILL_BUTTON_PROGRESS_PATH_KEY ,  std::string("skill_staves_bg.png") },
        { SKILL_BUTTON_LOGO_PATH_KEY ,  std::string("skill_logo_staves.png") },
        { SKILL_PROGRESS_HEAD_PATH_KEY ,  std::string("skill_staves_head.png") } ,
        { SKILL_ENERGY_ADD_PARTICLE_PATH_KEY ,  std::string("particle/skill_staves_particle.png") }
    } },
    { CHARCTOR_TUZI_ARMATURE_KEY ,{
        { SKILL_BUTTON_BACKGROUND_PATH_KEY ,  std::string("skill_big_bomb_button.png") },
        { SKILL_BUTTON_PROGRESS_PATH_KEY ,  std::string("skill_big_bomb_bg.png") },
        { SKILL_BUTTON_LOGO_PATH_KEY ,  std::string("skill_big_bomb_logo.png") },
        { SKILL_PROGRESS_HEAD_PATH_KEY ,  std::string("skill_big_bomb_head.png") } ,
        { SKILL_ENERGY_ADD_PARTICLE_PATH_KEY ,  std::string("particle/skill_big_bomb_particle.png") }
    } },
};
namespace bubble_second {
    GameCharactorSkillButton::GameCharactorSkillButton()
    {
        //charactor_to_path_[CHARCTOR_LAOHU_ARMATURE_KEY][SKILL_BUTTON_BACKGROUND_PATH_KEY] = "skill_dyeing_button.png";
        //charactor_to_path_[CHARCTOR_LAOHU_ARMATURE_KEY][SKILL_BUTTON_PROGRESS_PATH_KEY] = "skill_dyeing_bg.png";
        //charactor_to_path_[CHARCTOR_LAOHU_ARMATURE_KEY][SKILL_BUTTON_LOGO_PATH_KEY] = "skill_logo_dyeing.png";
        //charactor_to_path_[CHARCTOR_LAOHU_ARMATURE_KEY][SKILL_PROGRESS_HEAD_PATH_KEY] = "skill_dyeing_head.png";

        //charactor_to_path_[CHARCTOR_MIAO_ARMATURE_KEY][SKILL_BUTTON_BACKGROUND_PATH_KEY] = "skill_color_bomb_button.png";
        //charactor_to_path_[CHARCTOR_MIAO_ARMATURE_KEY][SKILL_BUTTON_PROGRESS_PATH_KEY] = "skill_color_bomb_bg.png";
        //charactor_to_path_[CHARCTOR_MIAO_ARMATURE_KEY][SKILL_BUTTON_LOGO_PATH_KEY] = "skill_logo_color_bomb.png";
        //charactor_to_path_[CHARCTOR_MIAO_ARMATURE_KEY][SKILL_PROGRESS_HEAD_PATH_KEY] = "skill_color_bomb_head.png";

        //charactor_to_path_[CHARCTOR_LAOSHU_ARMATURE_KEY][SKILL_BUTTON_BACKGROUND_PATH_KEY] = "skill_staves_button.png";
        //charactor_to_path_[CHARCTOR_LAOSHU_ARMATURE_KEY][SKILL_BUTTON_PROGRESS_PATH_KEY] = "skill_staves_bg.png";
        //charactor_to_path_[CHARCTOR_LAOSHU_ARMATURE_KEY][SKILL_BUTTON_LOGO_PATH_KEY] = "skill_logo_staves.png";
        //charactor_to_path_[CHARCTOR_LAOSHU_ARMATURE_KEY][SKILL_PROGRESS_HEAD_PATH_KEY] = "skill_staves_head.png";

        //charactor_to_path_[CHARCTOR_TUZI_ARMATURE_KEY][SKILL_BUTTON_BACKGROUND_PATH_KEY] = "skill_big_bomb_button.png";
        //charactor_to_path_[CHARCTOR_TUZI_ARMATURE_KEY][SKILL_BUTTON_PROGRESS_PATH_KEY] = "skill_big_bomb_bg.png";
        //charactor_to_path_[CHARCTOR_TUZI_ARMATURE_KEY][SKILL_BUTTON_LOGO_PATH_KEY] = "skill_big_bomb_logo.png";
        //charactor_to_path_[CHARCTOR_TUZI_ARMATURE_KEY][SKILL_PROGRESS_HEAD_PATH_KEY] = "skill_big_bomb_head.png";
    }

    bool bubble_second::GameCharactorSkillButton::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        auto data = CHARACTOR_TO_PATH.at(GameCharactorNameManager::getInstance()->getCurrentArmatureName());
        cocos2d::ui::Button* button = cocos2d::ui::Button::create(data[SKILL_BUTTON_BACKGROUND_PATH_KEY], data[SKILL_BUTTON_BACKGROUND_PATH_KEY], data[SKILL_BUTTON_BACKGROUND_PATH_KEY]);
        button->addClickEventListener(CC_CALLBACK_1(GameCharactorSkillButton::skillButtonClickCallBack, this));
        this->addChild(button);
        skill_button_ = button;

        progress_sprite_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(data[SKILL_BUTTON_PROGRESS_PATH_KEY]);
        //progress_sprite_->setPositionY(PROGRESS_SPRITE_INITAIL_POS_Y);
        cocos2d::ClippingNode* clippingnode = cocos2d::ClippingNode::create(progress_sprite_);
        clippingnode->setAlphaThreshold(0);
        clippingnode->addChild(progress_sprite_);
        cocos2d::Sprite* logo = SpriteTextureController::getInstance()->createGameSpriteWithPath(data[SKILL_BUTTON_LOGO_PATH_KEY]);
        cocos2d::BlendFunc logo_bf = { GL_SRC_ALPHA , GL_ONE };
        logo->setBlendFunc(logo_bf);
        clippingnode->addChild(logo);

        //cocos2d::Sprite* top_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath("skill_button_top.png");
        cocos2d::ClippingNode* top_clippingnode = cocos2d::ClippingNode::create(SpriteTextureController::getInstance()->createGameSpriteWithPath("zhezhao.png"));
        top_clippingnode->setAlphaThreshold(0);
        top_clippingnode->addChild(clippingnode);
        this->addChild(top_clippingnode);
        this->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath("skill_button_edge.png"));
        this->addChild(SpriteTextureController::getInstance()->createGameSpriteWithPath("skill_button_top.png"));

        progress_head_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(data[SKILL_PROGRESS_HEAD_PATH_KEY]);
        cocos2d::BlendFunc bf = { GL_SRC_ALPHA , GL_ONE };
        progress_head_->setBlendFunc(bf);
        top_clippingnode->addChild(progress_head_);


        //this->setSkillEnergy(0);
        progress_sprite_->setPositionY(this->calculateProgressPositionY());
        progress_head_->setPositionY(progress_head_->getParent()->convertToNodeSpace(progress_sprite_->convertToWorldSpace(cocos2d::Vec2(progress_sprite_->getContentSize().width/2, progress_sprite_->getContentSize().height))).y);
        return true;
    }

    void GameCharactorSkillButton::setSkillEnergy(int numble)
    {
        if (numble > SKILL_ENERGY_NUMBLE_MAX || current_energy_nunble_ == numble)
        {
            return;
        }
        current_energy_nunble_ = numble;
        this->updateSkillEnergyFullArmature();
        this->updateProgressPosition();
    }

    void GameCharactorSkillButton::addOneSkillEnergy()
    {
        this->setSkillEnergy(this->getSkillEnergyNumble()+1);
    }

    int GameCharactorSkillButton::getSkillEnergyNumble()
    {
        return current_energy_nunble_;
    }

    void GameCharactorSkillButton::updateProgressPosition()
    {
        float pregress_y = this->calculateProgressPositionY();
        float move_dis = pregress_y - progress_sprite_->getPositionY();
        float move_duration = abs(move_dis) / PROGRESS_MOVE_SPEED;
        cocos2d::MoveBy* moveto = cocos2d::MoveBy::create(move_duration, cocos2d::Vec2(0.0f, move_dis));
        progress_sprite_->runAction(moveto);

        cocos2d::ParticleSystemQuad* particle = cocos2d::ParticleSystemQuad::create(SKILL_ENERGY_ADD_PARTICLE_PATH);
        particle->setScaleX(1.5f);
        particle->setPositionType(cocos2d::ParticleSystem::PositionType::RELATIVE);
        particle->setTexture(cocos2d::Director::getInstance()->getTextureCache()->addImage(CHARACTOR_TO_PATH.at(GameCharactorNameManager::getInstance()->getCurrentArmatureName()).at(SKILL_ENERGY_ADD_PARTICLE_PATH_KEY)));
        particle->setPosition(progress_head_->getContentSize().width/2, 100.0f);
        progress_head_->addChild(particle);
        progress_head_->runAction(cocos2d::Sequence::createWithTwoActions(moveto->clone(), cocos2d::CallFunc::create([=]() {
            particle->removeFromParent();
        })));
    }

    float GameCharactorSkillButton::calculateProgressPositionY()
    {
        return (SKILL_ENERGY_NUMBLE_MAX - this->getSkillEnergyNumble())*PROGRESS_POS_Y_DELTA;
    }

    void GameCharactorSkillButton::updateSkillEnergyFullArmature()
    {
        if (this->isSkillEnergyFull())
        {
            this->addSkillEnergyFullArmature();
        }
        else
        {
            this->removeSkillEnergyFullArmature();
        }
    }

    void GameCharactorSkillButton::addSkillEnergyFullArmature()
    {
        if (energy_full_armature_ == nullptr)
        {
            energy_full_armature_ = cocostudio::Armature::create(SKILL_ENERGY_FULL_ARMATURE_NAME);
            energy_full_armature_->getAnimation()->playWithIndex(0);
            this->addChild(energy_full_armature_, 1);
        }
    }

    void GameCharactorSkillButton::removeSkillEnergyFullArmature()
    {
        if (energy_full_armature_ != nullptr)
        {
            energy_full_armature_->removeFromParent();
            energy_full_armature_ = nullptr;
        }
    }

    bool GameCharactorSkillButton::isSkillEnergyFull()
    {
        return this->getSkillEnergyNumble() == SKILL_ENERGY_NUMBLE_MAX;
    }

    void GameCharactorSkillButton::skillButtonClickCallBack(cocos2d::Ref *)
    {
        if (!button_enabled_)
        {
            return;
        }
        if (this->isSkillEnergyFull() && !GameScoreController::getInstance()->noUseBubbleCount())
        {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_USE_CHARACTOR_SKILL);
        }
        //this->getEventDispatcher()->dispatchCustomEvent(EVENT_USE_CHARACTOR_SKILL);
    }

    void GameCharactorSkillButton::setSkillButtonEnabled(bool enabled)
    {
        button_enabled_ = enabled;
    }


    GameCharactorSkillButton::~GameCharactorSkillButton()
    {
    }
    void GameCharactorSkillButton::onEnter()
    {
        cocos2d::Node::onEnter();
        listerner_ = this->getEventDispatcher()->addCustomEventListener(EVENT_ADD_ELIMINATE_COMBO, [=](cocos2d::EventCustom* event) {this->addOneSkillEnergy(); });
        this->getEventDispatcher()->addCustomEventListener(EVENT_CLEAR_SKILL_ENERGY, [=](cocos2d::EventCustom* event) {this->setSkillEnergy(0); });
        this->getEventDispatcher()->addCustomEventListener(EVENT_CUT_ELIMINATE_COMBO, [=](cocos2d::EventCustom* event) {this->setSkillEnergy(0); });
    }
    void GameCharactorSkillButton::onExit()
    {
        cocos2d::Node::onExit();
        this->getEventDispatcher()->removeEventListener(listerner_);
        this->getEventDispatcher()->removeCustomEventListeners(EVENT_CLEAR_SKILL_ENERGY);
        this->getEventDispatcher()->removeCustomEventListeners(EVENT_CUT_ELIMINATE_COMBO);
    }
}