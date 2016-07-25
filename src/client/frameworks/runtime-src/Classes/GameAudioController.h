//*******************************************************************************
//类名称   : GameAudioController
//功能     : <游戏声音控制>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_AUDIO_CONTROLLER_H_
#define _GAME_AUDIO_CONTROLLER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameAudioController
    {
    public:
        GETINSTANCE_FUNC(GameAudioController);
        ~GameAudioController();
        void loadAudioFile();
        void setBackgroundMusicEnabled(bool enabled);

        void playAddSpecialPropUsedEffect();
        void playAddTenBubblePropUsedEffect();
        void playAimingLinePropUsedEffect();
        void playBombBombBubbleEliminatedEffect();
        void playColorBubbleEliminatedEffect();
        void playContactAddBubbleNumbleBubbleEffect();
        void playContactBarrelBottomEffect();
        void playContactBarrelHeadEffect();
        void playContactBlackHoleBubbleEffect();
        void playContactRainbowsealBubbleEffect();
        void playContactScoreWidgetEffect();
        void playDarkCloudBubbleEliminatedEffect();
        void playDecalsChangeCardStateEffect();
        void playDecalsSelectedCardEndEffect();
        void playDecalsShuffleContactBorderEffect();
        void playEnterPropsAnimationEndEffect();
        void playGameCompletedTaskFlyEndEffect();
        void playGameStartEffect();
        void playGameVictoryLotteryEffect();
        void playGameVictoryLotteryGiftPopEffect();
        void playGameVictoryLotteryStartFlyEffect();
        void playGameVictoryLotteryStartPopEffect();
        void playGameVictoryStartTurnOnEffect();
        void playGameWoodenhammerAttackEffect();
        void playLightningBubbleEliminatedEffect();
        void playMutiplesealBubbleEliminatedEffect();
        void playPropBigBombBombBubbleEliminatedEffect();
        void playPropColorBombBubbleEliminatedEffect();
        void playPuzzleFindAnswerEffect();
        void playPuzzleUsedAddTimePropEffect();
        void playPuzzleUsedBigEyesPropEffect();
        void playPuzzleUsedSearchPropEffect();
        void playPuzzleVictoryEffect();
        void playPuzzleVictoryGiftPopEffect();
        void playRainbowsealBubbleEliminatedEffect();
        void playSkillBigBombBombBubbleEliminatedEffect();
        void playSkillColorBombBubbleEliminatedEffect();
        void playSkillDyingBubbleEliminatedEffect();
        void playSkillStavesBubbleEliminatedEffect();
        void playStageButtonEffect();
        void playStageUnlockEffect();


        void playGameDestroyRainbowsealMusic();
        void playGameLaunchMusic();
        void playGamePuzzlePlaySceneMusic();
        void playGamePuzzleSelectedSceneMusic();
        void playGameRescueAnimalMusic();
        void playGameStageCellFirstMusic();
        void playGameStageCellFourthMusic();
        void playGameStageCellSecondMusic();
        void playGameStageCellThirdMusic();
        void playGameTopEliminateMusic();
        void playGameWindmillMusic();



        void playStageCellBackgroundMusic(int cell_numble);
        void playStageTypeBackgroundMusic(StageType type);
    private:
        GameAudioController();
        void playEffectWithKey(const std::string& key);
        void playBackgroundMusicWithKey(const std::string& key);

        //void playGameStageCellFirstMusic();
        //void playGameStageCellFourthMusic();
        //void playGameStageCellSecondMusic();
        //void playGameStageCellThirdMusic();

        //void playGameRescueAnimalMusic();
        //void playGameTopEliminateMusic();
        //void playGameDestroyRainbowsealMusic();
        //void playGameWindmillMusic();
    private:
        std::string current_music_key_ = "";
    };
}
#endif