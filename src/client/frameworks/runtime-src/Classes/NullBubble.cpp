#include "NullBubble.h"


namespace bubble_second {
    NullBubble::NullBubble()
    {
    }


    NullBubble::~NullBubble()
    {
    }
    void NullBubble::bubbleEliminate(int combo)
    {
        return;
    }
    void NullBubble::downFromAir()
    {
    }
    bool NullBubble::needRemoveFromBubbleMap()
    {
        return false;
    }
    bool NullBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleTransparent);
        this->setSupensionPoint(true);
        return true;
    }
}