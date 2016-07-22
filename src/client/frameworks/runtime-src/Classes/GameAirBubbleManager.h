//*******************************************************************************
//类名称   : GameAirBubbleManager
//功能     : <游戏空中掉落小球管理>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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
        void clear();
        void checkAirBubblesOutOfRange();
    private:
        GameAirBubbleManager();
    private:
        std::set<ColorBubble*> air_bubbles_;
    };
}
#endif 