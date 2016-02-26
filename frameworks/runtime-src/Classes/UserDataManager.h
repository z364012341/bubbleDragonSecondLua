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
namespace bubble_second {
    class UserDataManager
    {
    public:
        GETINSTANCE_FUNC(UserDataManager);
        UserDataManager();
        //��ȡ��ͨ���ؿ�������
        int getStagePassCount();
        void updateStageData(int level, int start_numble);
        void readDataFile();
        int getStartNumbleWithLevel(int level);
        void setPresentCell(int cell_numble);
        int getPresentCell();
        void setUserNickname(const std::string& name);
        std::string getUserNickname() const;
        void setGameMusicEnable(bool flag);
        //�Ƿ񲥷�����
        bool isGameMusicEnable();
        void setSoundEffect(bool flag);
        //�Ƿ񲥷���Ч����
        bool isSoundEffectEnable();
        //�����������
        void saveUserData();
        //��Ϸ�Ƿ�ͨ��
        bool isCompletedGame();
    private:
        ~UserDataManager();
        void writeStageDataToFile();
        std::string getStageDataPath() const;
        std::string getUserDataPath() const;
        void readStageFile();
        void readUserDataFile();
    private:
        cocos2d::ValueMap stage_data_;
        int present_cell_ = 0;
        cocos2d::ValueMap user_data_;
    };
}
#endif //_USER_DATA_MANAGER_H_