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
        //{//��ӡ��Ч��������ʵ��
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