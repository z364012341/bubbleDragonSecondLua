#include "AirBubbleManager.h"


namespace bubble_second {
    AirBubbleManager::AirBubbleManager()
    {
    }


    AirBubbleManager::~AirBubbleManager()
    {
    }

    void AirBubbleManager::addAirBubble(BaseBubble * bubble)
    {
        air_bubbles_.insert(bubble);
    }

    void AirBubbleManager::cutAirBubble(BaseBubble * bubble)
    {
        air_bubbles_.erase(bubble);
    }

    bool AirBubbleManager::isNoneAirBubble()
    {
        CCLOG("%d", air_bubbles_.size());
        if (air_bubbles_.size() == 1)
        {
            BaseBubble* bubble = *air_bubbles_.begin();
        }
        return air_bubbles_.empty();
    }


}