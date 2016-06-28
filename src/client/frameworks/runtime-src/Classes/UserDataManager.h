//*******************************************************************************
//类名称   : UserDataManager
//功能     : <用于数据持久化>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _USER_DATA_MANAGER_H_
#define _USER_DATA_MANAGER_H_
#include "BubbleSecondConstant.h"
const std::string PUZZLE_SEARCH_PROP_KEY = "search";
const std::string PUZZLE_BIG_EYES_PROP_KEY = "bigEyes";
const std::string PUZZLE_ADD_TIME_PROP_KEY = "addTime";
const std::string BUBBLE_ADD_BUBBLE_NUMBLE_PROP_KEY = "addBubbleNumble";
const std::string BUBBLE_AIMING_LINE_PROP_KEY = "aimingLine";
const std::string BUBBLE_ADD_SPECIAL_BUBBLE_PROP_KEY = "addSpecialBubble";
const std::string BUBBLE_WOODEN_HAMMER_PROP_KEY = "woodenHammer";
const std::string BUBBLE_COLOR_BOMB_PROP_KEY = "colorBomb";
const std::string BUBBLE_BIG_BOMB_BOMB_PROP_KEY = "bigBombBomb";
const std::string BUBBLE_STAVES_PROP_KEY = "staves";
const std::string GAME_COIN_KEY = "coin";
const std::string GAME_STENGTH_KEY = "stength";
const std::string GAME_DIAMOND_KEY = "diamond";
const std::string DECALS_CHARACTOR_KEY = "decals_charactor";
const std::string DECALS_TREASURE_KEY = "decals_treasure";
namespace bubble_second {
    class UserDataManager
    {
    public:
        GETINSTANCE_FUNC(UserDataManager);
        static const std::string getPuzzleSearchPropKey();
        static const std::string getPuzzleBigEyesPropKey();
        static const std::string getPuzzleAddTimePropKey();
        static const std::string getDecalsCharactorKey();
        static const std::string getDecalsTreasureKey();
        UserDataManager();
        //获取已通过关卡的数量
        int getStagePassCount();
        void updateStageData(int level, int start_numble);
        void updateStageTotalStartScore();
        int getStageTotalStartScore();
        int getStageStartNumbleWithLevel(int level);
        void readDataFile();
        int getStartNumbleWithLevel(int level);
        void setPresentCell(int cell_numble);
        int getPresentCell();
        //void setUserNickname(const std::string& name);
        //std::string getUserNickname() const;
        void setGameMusicEnable(bool flag);
        //是否播放音乐
        bool isGameMusicEnable();
        void setSoundEffectEnable(bool flag);
        //是否播放特效声音
        bool isSoundEffectEnable();
        //保存玩家数据
        void saveUserData();
        //游戏是否通关
        bool isCompletedGame();
        //+1解锁关卡
        void addUnlockStageNumble();
        bool isUnlockWithStageNumble(int stage_numble);
        //拼图关卡数据
        void insertPuzzleStageData(const std::string& key, int consumingTime);
        void savePuzzleStageData();
        void readPuzzleStageBestScore();
        int getPuzzleStageBestScoreWithKey(const std::string& key);
        //道具数量
        int getPropsNumbleWithKey(const std::string& key);
        void setPropsNumbleWithKey(const std::string& key, int numble);
        void addPropsNumbleWithKey(const std::string& key, int numble);
        void cutPropsNumbleWithKey(const std::string& key);

        void setBuyPropsKeyAndNumble(cocos2d::ValueMap data);
        //新手礼包
        void buyNewbieGift();
        bool canBuyNewbieGift();
        //获取人物解锁数量
        int getGameCharactorUnlockNumble();
        //人物上一次选择的人物序号
        int getLastGameCharactorIndex();
        void setLastGameCharactorIndex(int index);
        //读取贴纸用户数据
        void readDecalsData();
        //cocos2d::ValueVector getCharactorDecalsData();
        //cocos2d::ValueVector getTreasureDecalsData();
        cocos2d::ValueVector getDecalsData(const std::string& decals_type);
        void setDecalsUserData(const cocos2d::ValueVector& data, const std::string& decals_type);
    private:
        ~UserDataManager();
        void writeStageDataToFile();
        std::string getStageDataPath() const;
        std::string getUserDataPath() const;
        std::string getPuzzleStageDataPath() const;
        void readStageFile();
        void readUserDataFile();
        std::string getMD5Str(const std::string& input_str);
        std::string encryptionPropsNumble();
        void saveDecalsUserData();

        std::string getDecalsDataPath() const;

    private:
        cocos2d::ValueMap stage_data_;
        int present_cell_ = 0;
        cocos2d::ValueMap user_data_;
        int unlock_stage_numble_ = 0;
        cocos2d::ValueMap puzzle_stage_data_;
        cocos2d::ValueMap buy_props_save_;
        cocos2d::ValueMap decals_data_;
        
    };
}
#endif //_USER_DATA_MANAGER_H_