#include "BlackObstacleBubble.h"



namespace bubble_second {
    BlackObstacleBubble::BlackObstacleBubble()
    {
    }


    BlackObstacleBubble::~BlackObstacleBubble()
    {
    }
    bool BlackObstacleBubble::init()
    {
        if (!ColorBubble::initWithTypeAndCloud(kBubbleBlackObstacle))
        {
            return false;
        }
        return true;
    }
}