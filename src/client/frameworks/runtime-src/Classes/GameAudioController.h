//*******************************************************************************
//������   : GameAudioController
//����     : <��Ϸ��������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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

        void playBombBombBubbleEliminatedEffect();
        void playColorBubbleEliminatedEffect();
        void playContactBarrelBottomEffect();
        void playContactBarrelHeadEffect();
        void playContactMutiplesealButtleEffect();
        void playContactRainbowsealBubbleEffect();
        void playContactScoreWidgetEffect();
        void playDarkCloudBubbleEliminatedEffect();
        void playGameCompletedTaskFlyEndEffect();
        void playGameStartEffect();
        void playGameVictoryStartTurnOnEffect();
        void playGameWoodenhammerAttackEffect();
        void playLightningBubbleEliminatedEffect();
        void playPropBigBombBombBubbleEliminatedEffect();
        void playPropColorBombBubbleEliminatedEffect();
        void playRainbowsealBubbleEliminatedEffect();
        void playSkillBigBombBombBubbleEliminatedEffect();
        void playSkillColorBombBubbleEliminatedEffect();
        void playSkillDyingBubbleEliminatedEffect();
        void playSkillStavesBubbleEliminatedEffect();
        void playStageButtonEffect();
        void playStageUnlockEffect();
    private:
        GameAudioController();
        void playEffectWithKey(const std::string& key);
    };
}
#endif