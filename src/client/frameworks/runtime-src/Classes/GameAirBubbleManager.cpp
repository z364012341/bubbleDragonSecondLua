#include "GameAirBubbleManager.h"



namespace bubble_second {
    GameAirBubbleManager::GameAirBubbleManager()
    {
    }

    GameAirBubbleManager::~GameAirBubbleManager()
    {
    }
    void GameAirBubbleManager::addAirBubble(ColorBubble * bubble)
    {
        air_bubbles_.insert(bubble);
    }
    void GameAirBubbleManager::eraseAirBubble(ColorBubble * bubble)
    {
        air_bubbles_.erase(bubble);
    }
    void GameAirBubbleManager::clear()
    {
        air_bubbles_.clear();
    }
    void GameAirBubbleManager::checkAirBubblesOutOfRange()
    {
        auto tempBubbles = air_bubbles_;
        for (ColorBubble* bubble : tempBubbles)
        {
            if (bubble->getPositionY()<0)
            {
                bubble->contactBarrelBottom();
            }
        }
    }
}