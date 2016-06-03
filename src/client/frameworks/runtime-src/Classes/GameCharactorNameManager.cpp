#include "GameCharactorNameManager.h"
#include "UserDataManager.h"
const std::string GAME_CHARACTER_ARMATURE_LAOHU_NAME = "laohu";
const std::string GAME_CHARACTER_ARMATURE_LAOHU2_NAME = "laohu2";
const std::string GAME_CHARACTER_ARMATURE_LAOHU3_NAME = "laohu3";
const std::string GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_NAME = "laohu-shengli";

const std::string GAME_CHARACTER_ARMATURE_MIAO_1_NAME = "xiaomao1";
const std::string GAME_CHARACTER_ARMATURE_MIAO_2_NAME = "xiaomao2";
const std::string GAME_CHARACTER_ARMATURE_MIAO_3_NAME = "xiaomao3";
const std::string GAME_CHARACTER_ARMATURE_MIAO_VICTORY_NAME = "shenglimao";

const std::string GAME_CHARACTER_ARMATURE_LAOSHU_1_NAME = "laoshu1";
const std::string GAME_CHARACTER_ARMATURE_LAOSHU_2_NAME = "laoshu2";
const std::string GAME_CHARACTER_ARMATURE_LAOSHU_3_NAME = "laoshu3";
const std::string GAME_CHARACTER_ARMATURE_LAOSHU_VICTORY_NAME = "laoshushengli";

const std::string GAME_CHARACTER_ARMATURE_TUZI_1_NAME = "tuzi1";
const std::string GAME_CHARACTER_ARMATURE_TUZI_2_NAME = "tuzi2";
const std::string GAME_CHARACTER_ARMATURE_TUZI_3_NAME = "tuzi3";
const std::string GAME_CHARACTER_ARMATURE_TUZI_VICTORY_NAME = "tuzishengli";

const std::string CHARCTOR_ARMATURE_KEY_1 = "armature_1";
const std::string CHARCTOR_ARMATURE_KEY_2 = "armature_2";
const std::string CHARCTOR_ARMATURE_KEY_3 = "armature_3";
const std::string CHARCTOR_ARMATURE_KEY_VICTORY = "armature_victory";
const std::string CHARCTOR_ARMATURE_KEY_INDEX = "armature_index";
const std::string CHARCTOR_LAOHU_ARMATURE_KEY = "aoao";
const std::string CHARCTOR_MIAO_ARMATURE_KEY = "miaopass";
const std::string CHARCTOR_LAOSHU_ARMATURE_KEY = "zhizhi";
const std::string CHARCTOR_TUZI_ARMATURE_KEY = "tutu";
const std::string NAMES_DATA_PATH = "res/charactorNamesData.plist";
namespace bubble_second {
    GameCharactorNameManager::GameCharactorNameManager()
    {
        //current_name_ = CHARCTOR_TUZI_ARMATURE_KEY;
        {
            cocos2d::ValueMap names_map;
            names_map[CHARCTOR_ARMATURE_KEY_1] = GAME_CHARACTER_ARMATURE_LAOHU_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_2] = GAME_CHARACTER_ARMATURE_LAOHU2_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_3] = GAME_CHARACTER_ARMATURE_LAOHU3_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_VICTORY] = GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_INDEX] = 0;
            charactor_armature_names_[CHARCTOR_LAOHU_ARMATURE_KEY] = names_map;
        }
        {               
            cocos2d::ValueMap names_map;
            names_map[CHARCTOR_ARMATURE_KEY_1] = GAME_CHARACTER_ARMATURE_MIAO_1_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_2] = GAME_CHARACTER_ARMATURE_MIAO_2_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_3] = GAME_CHARACTER_ARMATURE_MIAO_3_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_VICTORY] = GAME_CHARACTER_ARMATURE_MIAO_VICTORY_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_INDEX] = 1;
            charactor_armature_names_[CHARCTOR_MIAO_ARMATURE_KEY] = names_map;
        }
        {
            cocos2d::ValueMap names_map;
            names_map[CHARCTOR_ARMATURE_KEY_1] = GAME_CHARACTER_ARMATURE_LAOSHU_1_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_2] = GAME_CHARACTER_ARMATURE_LAOSHU_2_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_3] = GAME_CHARACTER_ARMATURE_LAOSHU_3_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_VICTORY] = GAME_CHARACTER_ARMATURE_LAOSHU_VICTORY_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_INDEX] = 3;
            charactor_armature_names_[CHARCTOR_LAOSHU_ARMATURE_KEY] = names_map;
        }
        {
            cocos2d::ValueMap names_map;
            names_map[CHARCTOR_ARMATURE_KEY_1] = GAME_CHARACTER_ARMATURE_TUZI_1_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_2] = GAME_CHARACTER_ARMATURE_TUZI_2_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_3] = GAME_CHARACTER_ARMATURE_TUZI_3_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_VICTORY] = GAME_CHARACTER_ARMATURE_TUZI_VICTORY_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_INDEX] = 2;
            charactor_armature_names_[CHARCTOR_TUZI_ARMATURE_KEY] = names_map;
        }
        //cocos2d::FileUtils::getInstance()->writeValueMapToFile(charactor_armature_names_, cocos2d::FileUtils::getInstance()->getWritablePath()+"charactorNamesData.plist");
    }


    GameCharactorNameManager::~GameCharactorNameManager()
    {
    }
    std::string GameCharactorNameManager::getCurrentArmatureName()
    {
        return current_name_;
    }
    std::string GameCharactorNameManager::getCurrentArmatureName1()
    {
        return charactor_armature_names_[this->getCurrentArmatureName()].asValueMap()[CHARCTOR_ARMATURE_KEY_1].asString();
    }
    std::string GameCharactorNameManager::getCurrentArmatureName2()
    {
        return charactor_armature_names_[this->getCurrentArmatureName()].asValueMap()[CHARCTOR_ARMATURE_KEY_2].asString();
    }
    std::string GameCharactorNameManager::getCurrentArmatureName3()
    {
        return charactor_armature_names_[this->getCurrentArmatureName()].asValueMap()[CHARCTOR_ARMATURE_KEY_3].asString();
    }
    std::string GameCharactorNameManager::getCurrentArmatureNameVictory()
    {
        return charactor_armature_names_[this->getCurrentArmatureName()].asValueMap()[CHARCTOR_ARMATURE_KEY_VICTORY].asString();
    }
    void GameCharactorNameManager::readNamesData()
    {
        charactor_armature_names_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(NAMES_DATA_PATH);
    }
    void GameCharactorNameManager::setCurrentArmatureNameWithIndex(int index)
    {
        assert(index >= 0);
        int charactor_index = -1;
        //CCLOG("unlock: %d", UserDataManager::getInstance()->getGameCharactorUnlockNumble());
        if (index < UserDataManager::getInstance()->getGameCharactorUnlockNumble())
        {
            charactor_index = index;
            UserDataManager::getInstance()->setLastGameCharactorIndex(charactor_index);
        }
        else
        {
            charactor_index = UserDataManager::getInstance()->getLastGameCharactorIndex();
        }
        for (auto var : charactor_armature_names_)
        {
            if (var.second.asValueMap().at(CHARCTOR_ARMATURE_KEY_INDEX).asInt() == charactor_index)
            {
                current_name_ = var.first;
                
                return;
            }
        }
        assert(false);
    }
}