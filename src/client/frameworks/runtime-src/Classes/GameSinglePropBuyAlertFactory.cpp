#include "GameSinglePropBuyAlertFactory.h"


namespace bubble_second {

    GameSinglePropBuyAlertFactory::GameSinglePropBuyAlertFactory()
    {
    }


    GameSinglePropBuyAlertFactory::~GameSinglePropBuyAlertFactory()
    {
    }
    void GameSinglePropBuyAlertFactory::popGameSinglePropBuyAlertWithKey(const std::string & prop_key)
    {
        prop_key_ = prop_key;
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_POP_GAME_STORE);
    }
    GameSinglePropBuyAlert * GameSinglePropBuyAlertFactory::createGameSinglePropBuyAlert()
    {
        assert(prop_key_ != "");
        auto alert = GameSinglePropBuyAlert::createWithPropKey(prop_key_);
        prop_key_ = "";
        return alert;
    }
}