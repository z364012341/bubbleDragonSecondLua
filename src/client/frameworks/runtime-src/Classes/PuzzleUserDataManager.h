//*******************************************************************************
//������   : PuzzleUserDataManager
//����     : <ƴͼ��Ϸ�û���������>
//-------------------------------------------------------------------------------
//��ע     :
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _PUZZLE_USER_DATA_MANAGER_H_
#define _PUZZLE_USER_DATA_MANAGER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class PuzzleUserDataManager
    {
    public:
        GETINSTANCE_FUNC(PuzzleUserDataManager);
        ~PuzzleUserDataManager();
    private:
        PuzzleUserDataManager();
    private:
        cocos2d::ValueMap
    };
}
#endif //_PUZZLE_USER_DATA_MANAGER_H_