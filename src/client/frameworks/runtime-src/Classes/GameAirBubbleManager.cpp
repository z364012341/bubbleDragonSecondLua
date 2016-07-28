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
    void GameAirBubbleManager::clearAirBubbles()
    {
        air_bubbles_.clear();
    }
    void GameAirBubbleManager::clearPrepareAirNumble()
    {
        prepare_bubble_in_air_numble_ = 0;
    }
    void GameAirBubbleManager::checkAirBubblesOutOfRange()
    {
        auto tempBubbles = air_bubbles_;
        for (ColorBubble* bubble : tempBubbles)
        {
            if (bubble->getPositionY() < 0)
            {
                bubble->contactBarrelBottom();
            }
        }
    }
    void GameAirBubbleManager::addPrepareBubbleAirNumble()
    {
        prepare_bubble_in_air_numble_++;
    }
    void GameAirBubbleManager::cutPrepareBubbleAirNumble()
    {
        prepare_bubble_in_air_numble_--;
        assert(prepare_bubble_in_air_numble_ >= 0);
    }
    bool GameAirBubbleManager::isNoShootBubbleInAir()
    {
        return prepare_bubble_in_air_numble_ == 0;
    }
}