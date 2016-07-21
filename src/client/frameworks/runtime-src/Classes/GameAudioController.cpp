#include "GameAudioController.h"
#include "SimpleAudioEngine.h"
//const std::map<std::string, std::string> GAME_BACKGROUND_MUSIC_PATH = {
//};
const std::string COLOR_BOMB_BUBBLE_ELIMINATED_PATH = "triggers.ogg";
const std::map<std::string, std::string> GAME_EFFECT_PATH = {
    { "STAGE_BUTTON_EFFECT", "waterhit.ogg" }, //点击按钮时播放
    { "STAGE_UNLOCK_EFFECT", "stage_clear.ogg" },  //新关卡开启时播放
    { "GAME_START_EFFECT", "tilixiafei.ogg" },  //点击开始游戏按钮，心飞至开始按钮
    { "CONTACT_RAINBOWSEAL_BUBBLE_EFFECT", "coin_add.ogg" },  //击中小狼泡泡（小狼泡泡变色）
    { "RAINBOWSEAL_BUBBLE_ELIMINATED_EFFECT", "sound_smash_ice.ogg" },  //小狼泡泡裂开
    { "CONTACT_MUTIPLESEAL_BUTTLE_EFFECT", "ballblast.ogg" },  //动物泡泡爆炸
    { "CONTACT_SCORE_WIDGET_EFFECT", "sound_rebound.ogg" },  //撞击蜜蜂
    { "CONTACT_BARREL_HEAD_EFFECT", "sound_donut_bounce_1.ogg" },  //撞击木桶头部边缘
    { "CONTACT_BARREL_BOTTOM_EFFECT", "sound_special_liuxing_2.ogg" },  //撞击木桶头部边缘
    { "GAME_VICTORY_START_TURN_ON_EFFECT", "stage_star_goal.ogg" },  //游戏胜利面板上分数星星点亮
    { "GAME_COMPLETED_TASK_FLY_END_EFFECT", "changecolour.ogg" },  //任务目标飞至
    { "GAME_WOODENHAMMER_ATTACK_EFFECT", "chuzihit.ogg" },  //木锤砸
    { "PROP_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT", COLOR_BOMB_BUBBLE_ELIMINATED_PATH },  //彩球炸
    { "PROP_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "bomb1.ogg" },  //炸弹炸
    { "SKILL_DYING_BUBBLE_ELIMINATED_EFFECT", "sound_key.ogg" },  //染色
    { "SKILL_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT", COLOR_BOMB_BUBBLE_ELIMINATED_PATH },  //彩球
    { "SKILL_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "stage_bomb.ogg" },  //炸弹
    { "SKILL_STAVES_BUBBLE_ELIMINATED_EFFECT", "lightning.ogg" },  //闪电
    { "COLOR_BUBBLE_ELIMINATED_EFFECT", "bubble_pop1.ogg" },  //普通泡泡
    { "LIGHTNING_BUBBLE_ELIMINATED_EFFECT", "bubble_pop1.ogg" },  //闪电泡泡
    { "BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT", "stage_boss0skill.ogg" },  //炸弹泡泡
    { "DARK_CLOUD_BUBBLE_ELIMINATED_EFFECT", "stage_gem_destory.ogg" },  //阴云泡泡
};
namespace bubble_second {
    using CocosDenshion::SimpleAudioEngine;
    std::string transform(const std::string& str)
    {
        std::string tempStr = "";
        for (auto var : str)
        {
            if (var < 'a')
            {
                tempStr += var + 'a' - 'A';
            }
            else
            {
                tempStr += var;
            }
        }
        tempStr[0] -= 'a' - 'A';
        return  tempStr;
    }
    std::string specialSplit(const std::string& str, const char& separator)
    {
        std::string result = "";
        std::string tempStr = "";
        for (auto var : str)
        {
            if (var != separator)
            {
                tempStr += var;
            }
            else
            {
                result += transform(tempStr);
                tempStr = "";
            }
        }
        result += transform(tempStr);
        return result;
    }
    GameAudioController::GameAudioController()
    {
        //{//打印音效的声明和实现
        //    using std::string;
        //    string declaration = "";
        //    for (auto var : GAME_EFFECT_PATH)
        //    {
        //        declaration += "void play" + specialSplit(var.first, '_') + "();\n";
        //    }
        //    CCLOG("%s", declaration.c_str());

        //    string implement = "";
        //    for (auto var : GAME_EFFECT_PATH)
        //    {
        //        implement += "void GameAudioController::play" + specialSplit(var.first, '_') +
        //            "()\n{\n    this->playEffectWithKey(\"" + var.first + "\");\n}\n";
        //    }
        //    CCLOG("%s", implement.c_str());
        //}
    }

    void GameAudioController::playEffectWithKey(const std::string & key)
    {
        SimpleAudioEngine::getInstance()->playEffect(GAME_EFFECT_PATH.at(key).c_str());
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
    void GameAudioController::playBombBombBubbleEliminatedEffect()
    {
        this->playEffectWithKey("BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playColorBubbleEliminatedEffect()
    {
        this->playEffectWithKey("COLOR_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playContactBarrelBottomEffect()
    {
        this->playEffectWithKey("CONTACT_BARREL_BOTTOM_EFFECT");
    }
    void GameAudioController::playContactBarrelHeadEffect()
    {
        this->playEffectWithKey("CONTACT_BARREL_HEAD_EFFECT");
    }
    void GameAudioController::playContactMutiplesealButtleEffect()
    {
        this->playEffectWithKey("CONTACT_MUTIPLESEAL_BUTTLE_EFFECT");
    }
    void GameAudioController::playContactRainbowsealBubbleEffect()
    {
        this->playEffectWithKey("CONTACT_RAINBOWSEAL_BUBBLE_EFFECT");
    }
    void GameAudioController::playContactScoreWidgetEffect()
    {
        this->playEffectWithKey("CONTACT_SCORE_WIDGET_EFFECT");
    }
    void GameAudioController::playDarkCloudBubbleEliminatedEffect()
    {
        this->playEffectWithKey("DARK_CLOUD_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playGameCompletedTaskFlyEndEffect()
    {
        this->playEffectWithKey("GAME_COMPLETED_TASK_FLY_END_EFFECT");
    }
    void GameAudioController::playGameStartEffect()
    {
        this->playEffectWithKey("GAME_START_EFFECT");
    }
    void GameAudioController::playGameVictoryStartTurnOnEffect()
    {
        this->playEffectWithKey("GAME_VICTORY_START_TURN_ON_EFFECT");
    }
    void GameAudioController::playGameWoodenhammerAttackEffect()
    {
        this->playEffectWithKey("GAME_WOODENHAMMER_ATTACK_EFFECT");
    }
    void GameAudioController::playLightningBubbleEliminatedEffect()
    {
        this->playEffectWithKey("LIGHTNING_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playPropBigBombBombBubbleEliminatedEffect()
    {
        this->playEffectWithKey("PROP_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playPropColorBombBubbleEliminatedEffect()
    {
        this->playEffectWithKey("PROP_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playRainbowsealBubbleEliminatedEffect()
    {
        this->playEffectWithKey("RAINBOWSEAL_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playSkillBigBombBombBubbleEliminatedEffect()
    {
        this->playEffectWithKey("SKILL_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playSkillColorBombBubbleEliminatedEffect()
    {
        this->playEffectWithKey("SKILL_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playSkillDyingBubbleEliminatedEffect()
    {
        this->playEffectWithKey("SKILL_DYING_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playSkillStavesBubbleEliminatedEffect()
    {
        this->playEffectWithKey("SKILL_STAVES_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playStageButtonEffect()
    {
        this->playEffectWithKey("STAGE_BUTTON_EFFECT");
    }
    void GameAudioController::playStageUnlockEffect()
    {
        this->playEffectWithKey("STAGE_UNLOCK_EFFECT");
    }
}