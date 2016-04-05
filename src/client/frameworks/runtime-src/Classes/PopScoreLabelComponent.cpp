#include "PopScoreLabelComponent.h"


namespace bubble_second {
    PopScoreLabelComponent::PopScoreLabelComponent()
    {
    }


    PopScoreLabelComponent::~PopScoreLabelComponent()
    {
    }

    bool PopScoreLabelComponent::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        return true;
    }
}