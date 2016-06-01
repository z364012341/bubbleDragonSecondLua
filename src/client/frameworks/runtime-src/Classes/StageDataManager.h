//*******************************************************************************
//������   : StageDataManager
//����     : <��Ϸ�ؿ���Ϣ������>
//-------------------------------------------------------------------------------
//��ע     : <����������,������ײ�ʹ����Ļص�>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAGE_DATA_MANAGER_H_
#define _STAGE_DATA_MANAGER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class StageDataModule;
    class StageDataManager
    {
    public:
        GETINSTANCE_FUNC(StageDataManager);
        ~StageDataManager();
        void initStageData();
        StageDataModule* getStageDataWithNumble(int numble);
        //��ȡ�ܹؿ���
        int getStageTotalNumble();
        //��ȡ�ؿ�������
        StageType getStageTypeWithNumble(int numble);
        //�Ƿ��ǹؿ���
        bool isInStageNumbleRange(int numble);
        void setCurrentCell(int numble);
        int getCurrentCell();
        void setCurrentLevel(int numble);
        int getCurrentLevel();
        StageType getCurrentStageType();
    private:
        StageDataManager();
        void addStageDataModule(StageDataModule* module);
    private:
        cocos2d::Vector<StageDataModule*> stage_data_map_;
        int current_cell_ = 0;
        int current_level_ = 0;
    };
}
#endif //_STAGE_DATA_MANAGER_H_