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
namespace bubble_second {
    class UserDataManager
    {
    public:
        GETINSTANCE_FUNC(UserDataManager);
        UserDataManager();
        //获取已通过关卡的数量
        int getStagePassCount();
        void updateStageData(int level, int start_numble);
        void readDataFile();
        int getStartNumbleWithLevel(int level);
        void setPresentCell(int cell_numble);
        int getPresentCell();
        void setUserNickname(const std::string& name);
        std::string getUserNickname() const;
        void setGameMusicEnable(bool flag);
        //是否播放音乐
        bool isGameMusicEnable();
        void setSoundEffect(bool flag);
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
        int getPuzzleSearchPropNumble();
        int getPuzzleBigEyesPropNumble();
        int getPuzzleAddTimePropNumble();
    private:
        ~UserDataManager();
        void writeStageDataToFile();
        std::string getStageDataPath() const;
        std::string getUserDataPath() const;
        std::string getPuzzleStageDataPath() const;
        void readStageFile();
        void readUserDataFile();
        //获取道具数量
        int getPropsNumbleWithKey(const std::string& key);
    private:
        cocos2d::ValueMap stage_data_;
        int present_cell_ = 0;
        cocos2d::ValueMap user_data_;
        int unlock_stage_numble_ = 0;
        cocos2d::ValueMap puzzle_stage_data_;
    };
}
#endif //_USER_DATA_MANAGER_H_