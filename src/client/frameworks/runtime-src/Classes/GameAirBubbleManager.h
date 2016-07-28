//*******************************************************************************
//������   : GameAirBubbleManager
//����     : <��Ϸ���е���С�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_AIR_BUBBLE_MANAGER_H_
#define _GAME_AIR_BUBBLE_MANAGER_H_
#include "BubbleSecondConstant.h"
#include "ColorBubble.h"
namespace bubble_second {
    class GameAirBubbleManager
    {
    public:
        GETINSTANCE_FUNC(GameAirBubbleManager);
        ~GameAirBubbleManager();
        void addAirBubble(ColorBubble* bubble);
        void eraseAirBubble(ColorBubble* bubble);
        void clearAirBubbles();
        void clearPrepareAirNumble();
        void checkAirBubblesOutOfRange();
        //����С���ڿ�����
        void addPrepareBubbleAirNumble();
        void cutPrepareBubbleAirNumble();
        bool isNoShootBubbleInAir();
    private:
        GameAirBubbleManager();
    private:
        std::set<ColorBubble*> air_bubbles_;
        int prepare_bubble_in_air_numble_ = 0;
    };
}
#endif 