#include "GameUnitPriceManager.h"
#include "UserDataManager.h"


namespace bubble_second {
    GameUnitPriceManager::GameUnitPriceManager()
    {
        {
            cocos2d::ValueMap price_data_AL;
            price_data_AL[GAME_COIN_KEY] = 2000;
            store_unit_price_data_[BUBBLE_AIMING_LINE_PROP_KEY] = price_data_AL;
        }
        {
            cocos2d::ValueMap price_data_ASB;
            price_data_ASB[GAME_COIN_KEY] = 3000;
            store_unit_price_data_[BUBBLE_ADD_SPECIAL_BUBBLE_PROP_KEY] = price_data_ASB;
        }
        {
            cocos2d::ValueMap price_data_ABN;
            price_data_ABN[GAME_COIN_KEY] = 3000;
            store_unit_price_data_[BUBBLE_ADD_BUBBLE_NUMBLE_PROP_KEY] = price_data_ABN;
        }
        {
            cocos2d::ValueMap price_data;
            price_data[GAME_DIAMOND_KEY] = 1;
            store_unit_price_data_[COMMODITY_DECALS_LOTTERY_BEGIN_KEY] = price_data;
        }
        {
            cocos2d::ValueMap price_data;
            price_data[GAME_DIAMOND_KEY] = 1;
            store_unit_price_data_[COMMODITY_DECALS_LOTTERY_CONTINUE_KEY] = price_data;
        }
        {
            cocos2d::ValueMap price_data;
            price_data[GAME_DIAMOND_KEY] = 30;
            store_unit_price_data_[GAME_DEFEAT_BUY_CONTINUE_KEY] = price_data;
        }
    }


    GameUnitPriceManager::~GameUnitPriceManager()
    {
    }

    void bubble_second::GameUnitPriceManager::addUnitPriceData(cocos2d::ValueMap price_data, const std::string & key)
    {
        store_unit_price_data_[key] = price_data;
    }
    cocos2d::ValueMap GameUnitPriceManager::getPropUnitPriceData(const std::string& prop_key)
    {
        return store_unit_price_data_.at(prop_key).asValueMap();
    }
}