//*******************************************************************************
//类名称   : PuzzleUserDataManager
//功能     : <拼图游戏用户分数管理>
//-------------------------------------------------------------------------------
//备注     :
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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