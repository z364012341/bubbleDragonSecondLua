//*******************************************************************************
//类名称   : BlackObstacleBubble
//功能     : <黑色障碍物小球>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BLACK_OBSTACLE_BUBBLE_H_
#define _BLACK_OBSTACLE_BUBBLE_H_
#include "ColorBubble.h"
namespace bubble_second {
    class BlackObstacleBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(BlackObstacleBubble);
        BlackObstacleBubble();
        ~BlackObstacleBubble();
    private:
        bool init();
    };
}
#endif