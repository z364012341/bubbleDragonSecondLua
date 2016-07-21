#include "GameAudioController.h"
#include "SimpleAudioEngine.h"
//const std::map<std::string, std::string> GAME_BACKGROUND_MUSIC_PATH = {
//};
const std::string COLOR_BOMB_BUBBLE_ELIMINATED_PATH = "triggers.ogg";
const std::map<std::string, std::string> GAME_EFFECT_PATH = {
    { "STAGE_BUTTON_EFFECT", "waterhit.ogg" }, //µã»÷°´Å¥Ê±²¥·Å
    { "STAGE_UNLOCK_EFFECT", "stage_clear.ogg" },  //ÐÂ¹Ø¿¨¿ªÆôÊ±²¥·Å
    { "GAME_START_EFFECT", "tilixiafei.ogg" },  //µã»÷¿ªÊ¼ÓÎÏ·°´Å¥£¬ÐÄ·ÉÖÁ¿ªÊ¼°´Å¥
    { "CONTACT_RAINBOWSEAL_BUBBLE_EFFECT", "coin_add.ogg" },  //»÷ÖÐÐ¡ÀÇÅÝÅÝ£¨Ð¡ÀÇÅÝÅÝ±äÉ«£©
    { "RAINBOWSEAL_BUBBLE_ELIMINATED_EFFECT", "sound_smash_ice.ogg" },  //Ð¡ÀÇÅÝÅÝÁÑ¿ª
    { "CONTACT_MUTIPLESEAL_BUTTLE_EFFECT", "ballblast.ogg" },  //¶¯ÎïÅÝÅÝ±¬Õ¨
    { "CONTACT_SCORE_WIDGET_EFFECT", "sound_rebound.ogg" },  //×²»÷ÃÛ·ä
    { "CONTACT_BARREL_HEAD_EFFECT", "sound_donut_bounce_1.ogg" },  //×²»÷Ä¾Í°Í·²¿±ßÔµ
    { "CONTACT_BARREL_BOTTOM_EFFECT", "sound_special_liuxing_2.ogg" },  //×²»÷Ä¾Í°Í·²¿±ßÔµ
    { "GAME_VICTORY_START_TURN_ON_EFFECT", "stage_star_goal.ogg" },  //ÓÎÏ·Ê¤ÀûÃæ°åÉÏ·ÖÊýÐÇÐÇµãÁÁ
    { "GAME_COMPLETED_TASK_FLY_END_EFFECT", "changecolour.ogg" },  //ÈÎÎñÄ¿±ê·ÉÖÁ
    { "GAME_WOODENHAMMER_ATTACK_EFFECT", "chuzihit.ogg" },  //Ä¾´¸ÔÒ
    { "PROP_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT", COLOR_BOMB_BUBBLE_ELIMINATED_PATH },  //²ÊÇòÕ¨
    { "PROP_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "bomb1.ogg" },  //Õ¨µ¯Õ¨
    { "SKILL_DYING_BUBBLE_ELIMINATED_EFFECT", "sound_key.ogg" },  //È¾É«
    { "SKILL_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT", COLOR_BOMB_BUBBLE_ELIMINATED_PATH },  //²ÊÇò
    { "SKILL_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "stage_bomb.ogg" },  //Õ¨µ¯
    { "SKILL_STAVES_BUBBLE_ELIMINATED_EFFECT", "lightning.ogg" },  //ÉÁµç
    { "COLOR_BUBBLE_ELIMINATED_EFFECT", "bubble_pop1.ogg" },  //ÆÕÍ¨ÅÝÅÝ
    { "LIGHTNING_BUBBLE_ELIMINATED_EFFECT", "bubble_pop1.ogg" },  //ÉÁµçÅÝÅÝ
    { "BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "stage_boss0skill.ogg" },  //Õ¨µ¯ÅÝÅÝ
    { "DARK_CLOUD_BUBBLE_ELIMINATED_EFFECT", "stage_gem_destory.ogg" },  //ÒõÔÆÅÝÅÝ
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