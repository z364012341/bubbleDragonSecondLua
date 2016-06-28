//*******************************************************************************
//������   : UserDataManager
//����     : <�������ݳ־û�>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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
        //��ȡ��ͨ���ؿ�������
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
        //�Ƿ񲥷�����
        bool isGameMusicEnable();
        void setSoundEffectEnable(bool flag);
        //�Ƿ񲥷���Ч����
        bool isSoundEffectEnable();
        //�����������
        void saveUserData();
        //��Ϸ�Ƿ�ͨ��
        bool isCompletedGame();
        //+1�����ؿ�
        void addUnlockStageNumble();
        bool isUnlockWithStageNumble(int stage_numble);
        //ƴͼ�ؿ�����
        void insertPuzzleStageData(const std::string& key, int consumingTime);
        void savePuzzleStageData();
        void readPuzzleStageBestScore();
        int getPuzzleStageBestScoreWithKey(const std::string& key);
        //��������
        int getPropsNumbleWithKey(const std::string& key);
        void setPropsNumbleWithKey(const std::string& key, int numble);
        void addPropsNumbleWithKey(const std::string& key, int numble);
        void cutPropsNumbleWithKey(const std::string& key);

        void setBuyPropsKeyAndNumble(cocos2d::ValueMap data);
        //�������
        void buyNewbieGift();
        bool canBuyNewbieGift();
        //��ȡ�����������
        int getGameCharactorUnlockNumble();
        //������һ��ѡ����������
        int getLastGameCharactorIndex();
        void setLastGameCharactorIndex(int index);
        //��ȡ��ֽ�û�����
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