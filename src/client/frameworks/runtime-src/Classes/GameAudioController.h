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
    private:
        GameAudioController();

    };
}
#endif