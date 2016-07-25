#include "GameAudioController.h"
#include "SimpleAudioEngine.h"
#include "UserDataManager.h"
const std::map<std::string, std::string> GAME_BACKGROUND_MUSIC_PATH = {
    { "GAME_LAUNCH_MUSIC", "Accomplish.mp3" },
    { "GAME_STAGE_CELL_FIRST_MUSIC", "music_bground.mp3" },
    { "GAME_STAGE_CELL_SECOND_MUSIC", "bgm_game_puzzle.mp3" },
    { "GAME_STAGE_CELL_THIRD_MUSIC", "bg_menu.mp3" },
    { "GAME_STAGE_CELL_FOURTH_MUSIC", "game_music_1.mp3" },
    { "GAME_TOP_ELIMINATE_MUSIC", "game_xg.mp3" },
    { "GAME_RESCUE_ANIMAL_MUSIC", "music_battle2.mp3" },
    { "GAME_DESTROY_RAINBOWSEAL_MUSIC", "music_comgame.mp3" },
    { "GAME_WINDMILL_MUSIC", "music_boss.mp3" },
    { "GAME_PUZZLE_SELECTED_SCENE_MUSIC", "soundpintu.mp3" },  //拼图选择界面播放
    { "GAME_PUZZLE_PLAY_SCENE_MUSIC", "bgmusic_5.mp3" },  // 拼图游戏界面播放
};
const std::string COLOR_BOMB_BUBBLE_ELIMINATED_PATH = "triggers.ogg";
const std::map<std::string, std::string> GAME_EFFECT_PATH = {
    //0701
    { "STAGE_BUTTON_EFFECT", "waterhit.ogg" }, //点击按钮时播放
    { "STAGE_UNLOCK_EFFECT", "stage_clear.ogg" },  //新关卡开启时播放
    { "GAME_START_EFFECT", "tilixiafei.ogg" },  //点击开始游戏按钮，心飞至开始按钮
    { "CONTACT_RAINBOWSEAL_BUBBLE_EFFECT", "coin_add.ogg" },  //击中小狼泡泡（小狼泡泡变色）
    { "RAINBOWSEAL_BUBBLE_ELIMINATED_EFFECT", "sound_smash_ice.ogg" },  //小狼泡泡裂开
    { "MUTIPLESEAL_BUBBLE_ELIMINATED_EFFECT", "ballblast.ogg" },  //动物泡泡爆炸
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
    //0722
    { "AIMING_LINE_PROP_USED_EFFECT", "yinxiaofzx.mp3" },  //辅助线使用
    { "ADD_SPECIAL_PROP_USED_EFFECT", "yinxiaomofaping.mp3" },  //魔法瓶使用
    { "ADD_TEN_BUBBLE_PROP_USED_EFFECT", "sfx_potion_appear.ogg" },  //+10球
    { "ENTER_PROPS_ANIMATION_END_EFFECT", "stage_star_goal.ogg" },  //游戏中进场道具动画最后烟雾炸开
    { "GAME_VICTORY_LOTTERY_START_FLY_EFFECT", "stage_star_goal.ogg" },  //胜利抽奖星星上飞
    { "GAME_VICTORY_LOTTERY_GIFT_POP_EFFECT", "potion.ogg" },  //礼包弹出
    { "GAME_VICTORY_LOTTERY_START_POP_EFFECT", "stage_colorgem.mp3" },  //胜利抽奖星星弹出
    { "GAME_VICTORY_LOTTERY_EFFECT", "stage_star_goal.ogg" },  //抽奖
    { "CONTACT_BLACK_HOLE_BUBBLE_EFFECT", "bubble_put.mp3" },  //击中黑洞泡泡
    { "CONTACT_ADD_BUBBLE_NUMBLE_BUBBLE_EFFECT", "sfx_star_gui_counter_pling.ogg" },  //击中+3球泡泡
    { "PUZZLE_VICTORY_GIFT_POP_EFFECT", "stage_star_goal.ogg" },  //拼图奖励弹出
    { "PUZZLE_USED_SEARCH_PROP_EFFECT", "sound_items_rollend.mp3" },  //使用快速提示
    { "PUZZLE_USED_BIG_EYES_PROP_EFFECT", "sound_material_compound.mp3" },  //使用天空之眼
    { "PUZZLE_USED_ADD_TIME_PROP_EFFECT", "sound_item_use.mp3" },  //使用时间倒流
    { "PUZZLE_VICTORY_EFFECT", "bubble_reward.mp3" },  //拼图完成
    { "PUZZLE_FIND_ANSWER_EFFECT", "sound_pvpitem_boom_03.mp3" },  //拼图块嵌入
    { "DECALS_SHUFFLE_CONTACT_BORDER_EFFECT", "sound_donut_bounce_3.mp3" },  //洗牌（碰撞边框）
    { "DECALS_CHANGE_CARD_STATE_EFFECT", "sound_pvpitem_boom_03.mp3" },  //翻牌
    { "DECALS_SELECTED_CARD_END_EFFECT", "stage_star_goal.ogg" },  //中奖(地面翻到正面朝上动作结束)
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
        //{//打印背景音乐的声明和实现
        //    CCLOG("-------------------------MUSIC--------------------------");
        //    using std::string;
        //    string declaration = "";
        //    for (auto var : GAME_BACKGROUND_MUSIC_PATH)
        //    {
        //        declaration += "void play" + specialSplit(var.first, '_') + "();\n";
        //    }
        //    CCLOG("%s", declaration.c_str());

        //    string implement = "";
        //    for (auto var : GAME_BACKGROUND_MUSIC_PATH)
        //    {
        //        implement += "void GameAudioController::play" + specialSplit(var.first, '_') +
        //            "()\n{\n    this->playBackgroundMusicWithKey(\"" + var.first + "\");\n}\n";
        //    }
        //    CCLOG("%s", implement.c_str());
        //}
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
    void GameAudioController::playAddSpecialPropUsedEffect()
    {
        this->playEffectWithKey("ADD_SPECIAL_PROP_USED_EFFECT");
    }
    void GameAudioController::playAddTenBubblePropUsedEffect()
    {
        this->playEffectWithKey("ADD_TEN_BUBBLE_PROP_USED_EFFECT");
    }
    void GameAudioController::playAimingLinePropUsedEffect()
    {
        this->playEffectWithKey("AIMING_LINE_PROP_USED_EFFECT");
    }
    void GameAudioController::playBombBombBubbleEliminatedEffect()
    {
        this->playEffectWithKey("BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playColorBubbleEliminatedEffect()
    {
        this->playEffectWithKey("COLOR_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playContactAddBubbleNumbleBubbleEffect()
    {
        this->playEffectWithKey("CONTACT_ADD_BUBBLE_NUMBLE_BUBBLE_EFFECT");
    }
    void GameAudioController::playContactBarrelBottomEffect()
    {
        this->playEffectWithKey("CONTACT_BARREL_BOTTOM_EFFECT");
    }
    void GameAudioController::playContactBarrelHeadEffect()
    {
        this->playEffectWithKey("CONTACT_BARREL_HEAD_EFFECT");
    }
    void GameAudioController::playContactBlackHoleBubbleEffect()
    {
        this->playEffectWithKey("CONTACT_BLACK_HOLE_BUBBLE_EFFECT");
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
    void GameAudioController::playDecalsChangeCardStateEffect()
    {
        this->playEffectWithKey("DECALS_CHANGE_CARD_STATE_EFFECT");
    }
    void GameAudioController::playDecalsSelectedCardEndEffect()
    {
        this->playEffectWithKey("DECALS_SELECTED_CARD_END_EFFECT");
    }
    void GameAudioController::playDecalsShuffleContactBorderEffect()
    {
        this->playEffectWithKey("DECALS_SHUFFLE_CONTACT_BORDER_EFFECT");
    }
    void GameAudioController::playEnterPropsAnimationEndEffect()
    {
        this->playEffectWithKey("ENTER_PROPS_ANIMATION_END_EFFECT");
    }
    void GameAudioController::playGameCompletedTaskFlyEndEffect()
    {
        this->playEffectWithKey("GAME_COMPLETED_TASK_FLY_END_EFFECT");
    }
    void GameAudioController::playGameStartEffect()
    {
        this->playEffectWithKey("GAME_START_EFFECT");
    }
    void GameAudioController::playGameVictoryLotteryEffect()
    {
        this->playEffectWithKey("GAME_VICTORY_LOTTERY_EFFECT");
    }
    void GameAudioController::playGameVictoryLotteryGiftPopEffect()
    {
        this->playEffectWithKey("GAME_VICTORY_LOTTERY_GIFT_POP_EFFECT");
    }
    void GameAudioController::playGameVictoryLotteryStartFlyEffect()
    {
        this->playEffectWithKey("GAME_VICTORY_LOTTERY_START_FLY_EFFECT");
    }
    void GameAudioController::playGameVictoryLotteryStartPopEffect()
    {
        this->playEffectWithKey("GAME_VICTORY_LOTTERY_START_POP_EFFECT");
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
    void GameAudioController::playMutiplesealBubbleEliminatedEffect()
    {
        this->playEffectWithKey("MUTIPLESEAL_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playPropBigBombBombBubbleEliminatedEffect()
    {
        this->playEffectWithKey("PROP_BIG_BOMB_BOMB_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playPropColorBombBubbleEliminatedEffect()
    {
        this->playEffectWithKey("PROP_COLOR_BOMB_BUBBLE_ELIMINATED_EFFECT");
    }
    void GameAudioController::playPuzzleFindAnswerEffect()
    {
        this->playEffectWithKey("PUZZLE_FIND_ANSWER_EFFECT");
    }
    void GameAudioController::playPuzzleUsedAddTimePropEffect()
    {
        this->playEffectWithKey("PUZZLE_USED_ADD_TIME_PROP_EFFECT");
    }
    void GameAudioController::playPuzzleUsedBigEyesPropEffect()
    {
        this->playEffectWithKey("PUZZLE_USED_BIG_EYES_PROP_EFFECT");
    }
    void GameAudioController::playPuzzleUsedSearchPropEffect()
    {
        this->playEffectWithKey("PUZZLE_USED_SEARCH_PROP_EFFECT");
    }
    void GameAudioController::playPuzzleVictoryEffect()
    {
        this->playEffectWithKey("PUZZLE_VICTORY_EFFECT");
    }
    void GameAudioController::playPuzzleVictoryGiftPopEffect()
    {
        this->playEffectWithKey("PUZZLE_VICTORY_GIFT_POP_EFFECT");
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
    void GameAudioController::playGamePuzzlePlaySceneMusic()
    {
        this->playBackgroundMusicWithKey("GAME_PUZZLE_PLAY_SCENE_MUSIC");
    }
    void GameAudioController::playGamePuzzleSelectedSceneMusic()
    {
        this->playBackgroundMusicWithKey("GAME_PUZZLE_SELECTED_SCENE_MUSIC");
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