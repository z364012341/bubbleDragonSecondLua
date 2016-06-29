#include "UserDataManager.h"
#include "StageDataManager.h"
#include "md5.h"
#include "XMLTool.h"
#include "GameBuyStoreMannager.h"
#include "DecalsFactory.h"
const std::string GAME_STAGE_DATA_PATH = "stageData.plist";
const std::string GAME_USER_DATA_PATH = "userData.plist";
const std::string DECALS_USER_DATA_PATH = "decalsUserData.plist";
const std::string GAME_PUZZLE_STAGE_DATA_PATH = "puzzleStageBestScore.plist";
//const std::string USER_DATA_NICKNAME_KEY = "user_nickname";
const std::string USER_DATA_MUSIC_KEY = "GAME_MUSIC";
const std::string USER_DATA_SOUND_EFFECT_KEY = "SOUND_EFFECT";
const std::string HAVED_BUY_NEWBIE_GIFT_KEY = "buyNewbieGift";
const std::string GAME_CHARACTOR_UNLOCK_NUMBLE_KEY = "unlockCharactorNumble";
const std::string LAST_GAME_CHARACTOR_INDEX_KEY = "lastCharactor";
const std::string PROP_MD5_KEY = "md5";
const std::string PROP_MD5_SECRET_KEY = "*miaopass*";
const std::string STAGE_TOTAL_STARTS_KEY = "total_starts";
const std::string STRENGTH_COUNT_DOWN_TIME_KEY = "strength_count_down_time";
const int GAME_PROPS_DEFAULT_NUMBLE = 100;
const int GAME_STRENGTH_DEFAULT_NUMBLE = 5;
const std::map<std::string, int> PROPS_DEFAULT_NUMBLE_DATA = {
    { PUZZLE_SEARCH_PROP_KEY , GAME_PROPS_DEFAULT_NUMBLE },
    { PUZZLE_BIG_EYES_PROP_KEY , GAME_PROPS_DEFAULT_NUMBLE },
    { PUZZLE_ADD_TIME_PROP_KEY , GAME_PROPS_DEFAULT_NUMBLE },
    { BUBBLE_WOODEN_HAMMER_PROP_KEY , GAME_PROPS_DEFAULT_NUMBLE },
    { BUBBLE_COLOR_BOMB_PROP_KEY , GAME_PROPS_DEFAULT_NUMBLE },
    { BUBBLE_BIG_BOMB_BOMB_PROP_KEY , GAME_PROPS_DEFAULT_NUMBLE },
    { BUBBLE_STAVES_PROP_KEY , GAME_PROPS_DEFAULT_NUMBLE },
    { GAME_COIN_KEY , 0 },
    { GAME_STRENGTH_KEY , GAME_STRENGTH_DEFAULT_NUMBLE },
    { GAME_DIAMOND_KEY , 0 }
};
namespace bubble_second {
    UserDataManager::UserDataManager()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_BUY_PROPS_PAY_SUCCESS, [=](cocos2d::EventCustom* event) {
            if (GameBuyStoreMannager::getInstance()->isBuyPuzzleNewbiwGift())
            {
                this->buyNewbieGift();
            }
            for (auto var : buy_props_save_)
            {
                this->addPropsNumbleWithKey(var.first, var.second.asInt());
            }

        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_BUY_PROPS_PAY_FAIL, [=](cocos2d::EventCustom* event) {
            buy_props_save_.clear();
        });
    }

    UserDataManager::~UserDataManager()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_BUY_PROPS_PAY_SUCCESS);
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_BUY_PROPS_PAY_FAIL);
    }
    void UserDataManager::readStageFile()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getStageDataPath();
        if (file_utils->isFileExist(path))
        {
            stage_data_ = file_utils->getValueMapFromFile(path);
        }
    }
    void UserDataManager::readUserDataFile()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getUserDataPath();
        if (file_utils->isFileExist(path))
        {
            user_data_ = file_utils->getValueMapFromFile(path);
            if (user_data_[PROP_MD5_KEY].asString() != this->encryptionPropsNumble())
            {
                exit(-1);
            }
        }
    }
    std::string UserDataManager::getMD5Str(const std::string & input_str)
    {
        return MD5(input_str).hexdigest();
    }
    std::string UserDataManager::encryptionPropsNumble()
    {
        std::string str = PROP_MD5_SECRET_KEY;
        for (auto var : PROPS_DEFAULT_NUMBLE_DATA)
        {
            str += XMLTool::convertIntToString(this->getPropsNumbleWithKey(var.first));
        }
        return this->getMD5Str(PROP_MD5_SECRET_KEY + str);
    }
    void UserDataManager::readDecalsData()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getDecalsDataPath();
        if (file_utils->isFileExist(path))
        {
            decals_data_ = file_utils->getValueMapFromFile(path);
        }
    }
    //cocos2d::ValueVector UserDataManager::getCharactorDecalsData()
    //{
    //    return this->getDecalsData(DECALS_CHARACTOR_KEY);
    //    //return decals_data_[DECALS_CHARACTOR_KEY].asValueVector();
    //}
    //cocos2d::ValueVector UserDataManager::getTreasureDecalsData()
    //{
    //    return this->getDecalsData(DECALS_TREASURE_KEY);
    //    //return decals_data_[DECALS_TREASURE_KEY].asValueVector();
    //}
    cocos2d::ValueVector UserDataManager::getDecalsData(const std::string & decals_type)
    {
        if (decals_data_.find(decals_type) == decals_data_.end())
        {
            return cocos2d::ValueVector(0);
        }
        return decals_data_[decals_type].asValueVector();
    }

    void UserDataManager::setDecalsUserData(const cocos2d::ValueVector& data, const std::string & decals_type)
    {
        decals_data_[decals_type] = data;
        this->saveDecalsUserData();
    }

    time_t UserDataManager::getStrengthLastTime()
    {
        //if (user_data_.find(STRENGTH_COUNT_DOWN_TIME_KEY) != user_data_.end())
        //{
        //    return user_data_.at(STRENGTH_COUNT_DOWN_TIME_KEY).asInt();
        //}
        //return time(0);
        cocos2d::Data d = cocos2d::UserDefault::getInstance()->getDataForKey(STRENGTH_COUNT_DOWN_TIME_KEY.c_str());
        if (d.isNull())
        {
            return time(0);
        }
        time_t lastExitTime = *((time_t*)d.getBytes());
        return lastExitTime;
    }

    void UserDataManager::saveStrengthLastTime()
    {
        time_t t = time(0);
        cocos2d::Data data;
        data.copy((unsigned char *)&t, sizeof(t));
        cocos2d::UserDefault::getInstance()->setDataForKey(STRENGTH_COUNT_DOWN_TIME_KEY.c_str(), data);
        cocos2d::UserDefault::getInstance()->flush();
    }

    void UserDataManager::saveDecalsUserData()
    {
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(decals_data_, this->getDecalsDataPath());
    }

    std::string UserDataManager::getDecalsDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + DECALS_USER_DATA_PATH;
    }
    int UserDataManager::getPropsNumbleWithKey(const std::string & key)
    {
        if (user_data_.find(key) != user_data_.end())
        {
            return user_data_.at(key).asInt();
        }
        return PROPS_DEFAULT_NUMBLE_DATA.at(key);
    }
    void UserDataManager::setPropsNumbleWithKey(const std::string & key, int numble)
    {
        user_data_[key] = numble;
        this->saveUserData();
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_UPDATE_PROPS_NUMBLE_LABEL);
    }
    void UserDataManager::addPropsNumbleWithKey(const std::string & key, int numble)
    {
        if (key == DECALS_CHARACTOR_KEY || key == DECALS_TREASURE_KEY)
        {
            DecalsFactory::getInstance()->saveNextDecal(key);
            return;
        }
        this->setPropsNumbleWithKey(key, this->getPropsNumbleWithKey(key) + numble);
    }
    void UserDataManager::cutPropsNumbleWithKey(const std::string& key)
    {
        this->setPropsNumbleWithKey(key, this->getPropsNumbleWithKey(key)-1);
    }
    void UserDataManager::setBuyPropsKeyAndNumble(cocos2d::ValueMap data)
    {
        buy_props_save_ = data;
    }
    void UserDataManager::buyNewbieGift()
    {
        cocos2d::UserDefault::getInstance()->setBoolForKey(HAVED_BUY_NEWBIE_GIFT_KEY.c_str(), true);
        cocos2d::UserDefault::getInstance()->flush();
    }
    bool UserDataManager::canBuyNewbieGift()
    {
        return !cocos2d::UserDefault::getInstance()->getBoolForKey(HAVED_BUY_NEWBIE_GIFT_KEY.c_str());
    }
    int UserDataManager::getGameCharactorUnlockNumble()
    {
        if (user_data_.find(GAME_CHARACTOR_UNLOCK_NUMBLE_KEY) != user_data_.end())
        {
            return user_data_.at(GAME_CHARACTOR_UNLOCK_NUMBLE_KEY).asInt();
        }
        return 4; //先返回一个默认值, 增加解锁系统的时候在更改
    }
    int UserDataManager::getLastGameCharactorIndex()
    {
        return cocos2d::UserDefault::getInstance()->getIntegerForKey(LAST_GAME_CHARACTOR_INDEX_KEY.c_str());
    }
    void UserDataManager::setLastGameCharactorIndex(int index)
    {
        cocos2d::UserDefault::getInstance()->setIntegerForKey(LAST_GAME_CHARACTOR_INDEX_KEY.c_str(), index);
        cocos2d::UserDefault::getInstance()->flush();
    }
    int UserDataManager::getStartNumbleWithLevel(int level)
    {
        char levelStr[10];
        sprintf(levelStr, "%d", level);
        if (stage_data_.find(levelStr) != stage_data_.end())
        {
            return stage_data_.at(levelStr).asInt();
        }
        return 0;
    }
    void UserDataManager::setPresentCell(int cell_numble)
    {
        present_cell_ = cell_numble;
    }
    int UserDataManager::getPresentCell()
    {
        return present_cell_;
    }
    //void UserDataManager::setUserNickname(const std::string & name)
    //{
    //    user_data_[USER_DATA_NICKNAME_KEY] = name;
    //}
    //std::string UserDataManager::getUserNickname() const
    //{
    //    if (user_data_.find(USER_DATA_NICKNAME_KEY) != user_data_.end())
    //    {
    //        return user_data_.at(USER_DATA_NICKNAME_KEY).asString();
    //    }
    //    return "";
    //}
    void UserDataManager::setGameMusicEnable(bool flag)
    {
        cocos2d::UserDefault::getInstance()->setBoolForKey(USER_DATA_MUSIC_KEY.c_str(), flag);
        cocos2d::UserDefault::getInstance()->flush();
    }
    bool UserDataManager::isGameMusicEnable()
    {
        return cocos2d::UserDefault::getInstance()->getBoolForKey(USER_DATA_MUSIC_KEY.c_str());
    }
    void UserDataManager::setSoundEffectEnable(bool flag)
    {
        cocos2d::UserDefault::getInstance()->setBoolForKey(USER_DATA_SOUND_EFFECT_KEY.c_str(), flag);
        cocos2d::UserDefault::getInstance()->flush();
    }
    bool UserDataManager::isSoundEffectEnable()
    {
        return cocos2d::UserDefault::getInstance()->getBoolForKey(USER_DATA_SOUND_EFFECT_KEY.c_str());
    }
    void UserDataManager::saveUserData()
    {
        std::string path = getUserDataPath();
        user_data_[PROP_MD5_KEY] = this->encryptionPropsNumble();
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(user_data_, path);

    }
    bool UserDataManager::isCompletedGame()
    {
        return this->getStagePassCount() == StageDataManager::getInstance()->getStageTotalNumble();
    }
    void UserDataManager::writeStageDataToFile()
    {
        std::string path = getStageDataPath();
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(stage_data_, path);
    }
    void UserDataManager::updateStageData(int level, int start_numble)
    {
        std::string  levelStr = XMLTool::convertIntToString(level);
        if (stage_data_.find(levelStr) != stage_data_.end() && stage_data_[levelStr].asInt() >= start_numble)
        {
            return;
        }
        //if (level-1 == stage_data_.size())
        //{
            stage_data_[levelStr] = cocos2d::Value(start_numble);
            this->writeStageDataToFile();
            this->updateStageTotalStartScore();
        //}
    }
    void UserDataManager::updateStageTotalStartScore()
    {
        int total = 0;
        for (auto var : stage_data_)
        {
            total += var.second.asInt();
        }
        cocos2d::UserDefault::getInstance()->setIntegerForKey(STAGE_TOTAL_STARTS_KEY.c_str(), total);
        cocos2d::UserDefault::getInstance()->flush();
    }
    int UserDataManager::getStageTotalStartScore()
    {
        return cocos2d::UserDefault::getInstance()->getIntegerForKey(STAGE_TOTAL_STARTS_KEY.c_str());;
    }
    int UserDataManager::getStageStartNumbleWithLevel(int level)
    {
        return stage_data_[XMLTool::convertIntToString(level)].asInt();
    }
    void UserDataManager::readDataFile()
    {
        this->readStageFile();
        this->readUserDataFile();
        this->readPuzzleStageBestScore();
        this->readDecalsData();
        unlock_stage_numble_ = this->getStagePassCount();
        this->updateStageTotalStartScore();
    }
    std::string UserDataManager::getStageDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_STAGE_DATA_PATH;
    }
    std::string UserDataManager::getUserDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_USER_DATA_PATH;
    }
    std::string UserDataManager::getPuzzleStageDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_PUZZLE_STAGE_DATA_PATH;
    }
    int UserDataManager::getStagePassCount()
    {
        return stage_data_.size();
    }
    void UserDataManager::addUnlockStageNumble()
    {
        unlock_stage_numble_++;
    }
    bool UserDataManager::isUnlockWithStageNumble(int stage_numble)
    {
        return stage_numble <= unlock_stage_numble_;
    }
    void UserDataManager::insertPuzzleStageData(const std::string & key, int consumingTime)
    {
        if (puzzle_stage_data_.find(key) == puzzle_stage_data_.end() || puzzle_stage_data_[key].asInt()>consumingTime)
        {
            puzzle_stage_data_[key] = cocos2d::Value(consumingTime);
            this->savePuzzleStageData();
        }
    }
    void UserDataManager::savePuzzleStageData()
    {
        std::string path = getPuzzleStageDataPath();
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(puzzle_stage_data_, path);
    }
    void UserDataManager::readPuzzleStageBestScore()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getPuzzleStageDataPath();
        if (file_utils->isFileExist(path))
        {
            puzzle_stage_data_ = file_utils->getValueMapFromFile(path);
        }
    }
    int UserDataManager::getPuzzleStageBestScoreWithKey(const std::string & key)
    {
        //if (puzzle_stage_data_.find(key) != puzzle_stage_data_.end())
        //{
            return puzzle_stage_data_.at(key).asInt();
        //}
        //return 99999;

    }
    const std::string UserDataManager::getPuzzleSearchPropKey()
    {
        return PUZZLE_SEARCH_PROP_KEY;
    }
    const std::string UserDataManager::getPuzzleBigEyesPropKey()
    {
        return PUZZLE_BIG_EYES_PROP_KEY;
    }
    const std::string UserDataManager::getPuzzleAddTimePropKey()
    {
        return PUZZLE_ADD_TIME_PROP_KEY;
    }

    const std::string UserDataManager::getDecalsCharactorKey()
    {
        return DECALS_CHARACTOR_KEY;
    }

    const std::string UserDataManager::getDecalsTreasureKey()
    {
        return DECALS_TREASURE_KEY;
    }
    
}