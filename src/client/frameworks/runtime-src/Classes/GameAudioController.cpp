#include "GameAudioController.h"
#include "SimpleAudioEngine.h"
#include "UserDataManager.h"
const std::map<std::string, std::string> GAME_BACKGROUND_MUSIC_PATH = {
    { "GAME_LAUNCH_MUSIC", "Accomplish.mp3" },
    { "GAME_STAGE_CELL_FIRST_MUSIC", "Accomplish.mp3" },
    { "GAME_STAGE_CELL_SECOND_MUSIC", "bgm_game_puzzle.mp3" },
    { "GAME_STAGE_CELL_THIRD_MUSIC", "bg_menu.mp3" },
    { "GAME_STAGE_CELL_FOURTH_MUSIC", "game_music_1.mp3" },
    { "GAME_TOP_ELIMINATE_MUSIC", "game_xg.mp3" },
    { "GAME_RESCUE_ANIMAL_MUSIC", "music_battle2.mp3" },
    { "GAME_DESTROY_RAINBOWSEAL_MUSIC", "music_comgame.mp3" },
    { "GAME_WINDMILL_MUSIC", "music_boss.mp3" },
};
const std::string COLOR_BOMB_BUBBLE_ELIMINATED_PATH = "triggers.ogg";
const std::map<std::string, std::string> GAME_EFFECT_PATH = {
    { "STAGE_BUTTON_EFFECT", "waterhit.ogg" }, //�����ťʱ����
    { "STAGE_UNLOCK_EFFECT", "stage_clear.ogg" },  //�¹ؿ�����ʱ����
    { "GAME_START_EFFECT", "tilixiafei.ogg" },  //�����ʼ��Ϸ��ť���ķ�����ʼ��ť
    { "CONTACT_RAINBOWSEAL_BUBBLE_EFFECT", "coin_add.ogg" },  //����С�����ݣ�С�����ݱ�ɫ��
    { "RAINBOWSEAL_BUBBLE_ELIMINATED_EFFECT", "sound_smash_ice.ogg" },  //С�������ѿ�
    { "MUTIPLESEAL_BUBBLE_ELIMINATED_EFFECT", "ballblast.ogg" },  //�������ݱ�ը
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
        {//��ӡ��Ч��������ʵ��
            using std::string;
            string declaration = "";
            for (auto var : GAME_EFFECT_PATH)
            {
                declaration += "void play" + specialSplit(var.first, '_') + "();\n";
            }
            CCLOG("%s", declaration.c_str());

            string implement = "";
            for (auto var : GAME_EFFECT_PATH)
            {
                implement += "void GameAudioController::play" + specialSplit(var.first, '_') +
                    "()\n{\n    this->playEffectWithKey(\"" + var.first + "\");\n}\n";
            }
            CCLOG("%s", implement.c_str());
        }
        {//��ӡ�������ֵ�������ʵ��
            CCLOG("-------------------------MUSIC--------------------------");
            using std::string;
            string declaration = "";
            for (auto var : GAME_BACKGROUND_MUSIC_PATH)
            {
                declaration += "void play" + specialSplit(var.first, '_') + "();\n";
            }
            CCLOG("%s", declaration.c_str());

            string implement = "";
            for (auto var : GAME_BACKGROUND_MUSIC_PATH)
            {
                implement += "void GameAudioController::play" + specialSplit(var.first, '_') +
                    "()\n{\n    this->playBackgroundMusicWithKey(\"" + var.first + "\");\n}\n";
            }
            CCLOG("%s", implement.c_str());
        }
    }

    void GameAudioController::playEffectWithKey(const std::string & key)
    {
        if (UserDataManager::getInstance()->isSoundEffectEnable())
        {
            SimpleAudioEngine::getInstance()->playEffect(GAME_EFFECT_PATH.at(key).c_str());
        }
    }

    void GameAudioController::playBackgroundMusicWithKey(const std::string & key)
    {
        if (UserDataManager::getInstance()->isGameMusicEnable() && (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() || current_music_key_ != key))
        {
            SimpleAudioEngine::getInstance()->playBackgroundMusic(GAME_BACKGROUND_MUSIC_PATH.at(key).c_str(), true);
        }
        current_music_key_ = key;
    }


    GameAudioController::~GameAudioController()
    {
    }
    void GameAudioController::loadAudioFile()
    {
        for (auto var : GAME_EFFECT_PATH)
        {
            SimpleAudioEngine::getInstance()->preloadEffect(var.second.c_str());
        }
        for (auto var : GAME_BACKGROUND_MUSIC_PATH)
        {
            SimpleAudioEngine::getInstance()->preloadBackgroundMusic(var.second.c_str());
        }
    }
    void GameAudioController::setBackgroundMusicEnabled(bool enabled)
    {
        UserDataManager::getInstance()->setGameMusicEnable(enabled);
        if (enabled)
        {
            this->playBackgroundMusicWithKey(current_music_key_);
        }
        else
        {
            SimpleAudioEngine::getInstance()->stopBackgroundMusic();
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
    void GameAudioController::playContactMutiplesealBubbleEliminatedEffect()
    {
        this->playEffectWithKey("MUTIPLESEAL_BUTTLE_ELIMINATED_EFFECT");
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



    void GameAudioController::playGameDestroyRainbowsealMusic()
    {
        this->playBackgroundMusicWithKey("GAME_DESTROY_RAINBOWSEAL_MUSIC");
    }
    void GameAudioController::playGameLaunchMusic()
    {
        this->playBackgroundMusicWithKey("GAME_LAUNCH_MUSIC");
    }
    void GameAudioController::playGameRescueAnimalMusic()
    {
        this->playBackgroundMusicWithKey("GAME_RESCUE_ANIMAL_MUSIC");
    }
    void GameAudioController::playGameStageCellFirstMusic()
    {
        this->playBackgroundMusicWithKey("GAME_STAGE_CELL_FIRST_MUSIC");
    }
    void GameAudioController::playGameStageCellFourthMusic()
    {
        this->playBackgroundMusicWithKey("GAME_STAGE_CELL_FOURTH_MUSIC");
    }
    void GameAudioController::playGameStageCellSecondMusic()
    {
        this->playBackgroundMusicWithKey("GAME_STAGE_CELL_SECOND_MUSIC");
    }
    void GameAudioController::playGameStageCellThirdMusic()
    {
        this->playBackgroundMusicWithKey("GAME_STAGE_CELL_THIRD_MUSIC");
    }
    void GameAudioController::playGameTopEliminateMusic()
    {
        this->playBackgroundMusicWithKey("GAME_TOP_ELIMINATE_MUSIC");
    }
    void GameAudioController::playGameWindmillMusic()
    {
        this->playBackgroundMusicWithKey("GAME_WINDMILL_MUSIC");
    }
    void GameAudioController::playStageCellBackgroundMusic(int cell_numble)
    {
        switch (cell_numble)
        {
        case 0:
            this->playGameStageCellFirstMusic();
            break;
        case 1:
            this->playGameStageCellSecondMusic();
            break;
        case 2:
            this->playGameStageCellThirdMusic();
            break;
        case 3:
            this->playGameStageCellFourthMusic();
            break;
        default:
            break;
        }
    }
    void GameAudioController::playStageTypeBackgroundMusic(StageType type)
    {
        switch (type)
        {
        case kTopEliminate:
            this->playGameTopEliminateMusic();
            break;
        case kRescueAnimal:
            this->playGameRescueAnimalMusic();
            break;
        case kDestroyRainbowSeal:
            this->playGameDestroyRainbowsealMusic();
            break;
        case kWindmill:
            this->playGameWindmillMusic();
            break;
        default:
            break;
        }
    }
}