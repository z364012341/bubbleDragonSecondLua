#include "GameTextInfo.h"
const std::map<StageType, std::string> STAGE_TYPE_TO_KEY = {
    { kTopEliminate , GAME_TEXT_TOP_ELIMINATE },
    { kRescueAnimal , GAME_TEXT_RESCUE_ANIMAL },
    { kDestroyRainbowSeal , GAME_TEXT_BEAT_THE_ROBBER },
    { kWindmill , GAME_TEXT_RESCUE_GHOST }
};
namespace bubble_second {
    GameTextInfo::GameTextInfo()
    {
    }

    GameTextInfo::~GameTextInfo()
    {
    }

    void GameTextInfo::plistToMap()
    {
        //cocos2d::LanguageType type = cocos2d::Application::getInstance()->getCurrentLanguage();
        //switch (type)
        //{
        //case cocos2d::LanguageType::CHINESE:
            plist_map_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(GAME_TEXT_INFO_PLIST_CHINESE_PATH);
        //    //plist_map_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(GAME_TEXT_INFO_PLIST_ENGLISH_PATH);
        //    break;
        //default:
        //    plist_map_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(GAME_TEXT_INFO_PLIST_ENGLISH_PATH);
        //    break;
        //}
        //commodity_map_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(GAME_COMMODITY_PLIST_PATH);
    }

    std::string GameTextInfo::getTextInfoWithKey(const std::string& key) const
    {
        return plist_map_.at(key).asString();
    }
    std::string GameTextInfo::getTextInfoWithStageType(const StageType & type)
    {
        return getTextInfoWithKey(STAGE_TYPE_TO_KEY.at(type));
    }
    //std::string GameTextInfo::getCommodityCoinNumbleWithKey(const std::string & key) const
    //{
    //    return getCommodityCoinValueWithKey(key).asString();
    //}
    //std::string GameTextInfo::getCommodityDiamondNumbleWithKey(const std::string & key) const
    //{
    //    return commodity_map_.at(key).asValueMap().at(COMMODITY_DIAMOND_KEY).asString();
    //}
    //cocos2d::Value GameTextInfo::getCommodityCoinValueWithKey(const std::string & key) const
    //{
    //    return this->getCommodityDataWithKey(key).at(COMMODITY_COIN_KEY);
    //}
    //cocos2d::ValueMap GameTextInfo::getCommodityDataWithKey(const std::string & key) const
    //{
    //    return commodity_map_.at(key).asValueMap();
    //}
}