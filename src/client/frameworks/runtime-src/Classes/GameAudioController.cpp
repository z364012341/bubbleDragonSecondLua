#include "GameAudioController.h"
#include "SimpleAudioEngine.h"
//const std::map<std::string, std::string> GAME_BACKGROUND_MUSIC_PATH = {
//};
const std::string COLOR_BOMB_BUBBLE_ELIMINATED_PATH = "triggers.ogg";
const std::map<std::string, std::string> GAME_EFFECT_PATH = {
    { "STAGE_BUTTON_EFFECT", "waterhit.ogg" }, //�����ťʱ����
    { "STAGE_UNLOCK_EFFECT", "stage_clear.ogg" },  //�¹ؿ�����ʱ����
    { "GAME_START_EFFECT", "tilixiafei.ogg" },  //�����ʼ��Ϸ��ť���ķ�����ʼ��ť
    { "CONTACT_RAINBOWSEAL_BUBBLE_EFFECT", "coin_add.ogg" },  //����С�����ݣ�С�����ݱ�ɫ��
    { "RAINBOWSEAL_BUBBLE_ELIMINATED_EFFECT", "sound_smash_ice.ogg" },  //С�������ѿ�
    { "CONTACT_MUTIPLESEAL_BUTTLE_EFFECT", "ballblast.ogg" },  //�������ݱ�ը
    { "CONTACT_SCORE_WIDGET_EFFECT", "sound_rebound.ogg" },  //ײ���۷�
    { "CONTACT_BARREL_HEAD_EFFECT", "sound_donut_bounce_1.ogg" },  //ײ��ľͰͷ����Ե
    { "CONTACT_BARREL_BOTTOM_EFFECT", "sound_special_liuxing_2.ogg" },  //ײ��ľͰͷ����Ե
    { "GAME_VICTORY_START_TURN_ON_EFFECT", "stage_star_goal.ogg" },  //��Ϸʤ������Ϸ������ǵ���
    { "GAME_COMPLETED_TASK_FLY_END_EFFECT", "changecolour.ogg" },  //����Ŀ�����
    { "GAME_WOODENHAMMER_ATTACK_EFFECT", "chuzihit.ogg" },  //ľ����
    { "PROP_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT", COLOR_BOMB_BUBBLE_ELIMINATED_PATH },  //����ը
    { "PROP_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "bomb1.ogg" },  //ը��ը
    { "SKILL_DYING_BUBBLE_ELIMINATED_EFFECT", "sound_key.ogg" },  //Ⱦɫ
    { "SKILL_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT", COLOR_BOMB_BUBBLE_ELIMINATED_PATH },  //����
    { "SKILL_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "stage_bomb.ogg" },  //ը��
    { "SKILL_STAVES_BUBBLE_ELIMINATED_EFFECT", "lightning.ogg" },  //����
    { "COLOR_BUBBLE_ELIMINATED_EFFECT", "bubble_pop1.ogg" },  //��ͨ����
    { "LIGHTNING_BUBBLE_ELIMINATED_EFFECT", "bubble_pop1.ogg" },  //��������
    { "BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "stage_boss0skill.ogg" },  //ը������
    { "DARK_CLOUD_BUBBLE_ELIMINATED_EFFECT", "stage_gem_destory.ogg" },  //��������
};
namespace bubble_second {
    using CocosDenshion::SimpleAudioEngine;
    GameAudioController::GameAudioController()
    {
    }


    GameAudioController::~GameAudioController()
    {
    }
    void GameAudioController::loadAudioFile()
    {
        //SimpleAudioEngine::getInstance()->preloadBackgroundMusic();
        for (auto var : GAME_EFFECT_PATH)
        {
            SimpleAudioEngine::getInstance()->preloadEffect(var.second.c_str());
        }

    }
}