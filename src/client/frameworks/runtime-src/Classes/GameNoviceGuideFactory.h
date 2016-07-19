//*******************************************************************************
//类名称   : GameNoviceGuideFactory
//功能     : <新手引导的工厂类>
//-------------------------------------------------------------------------------
//备注     : <负责生成item>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_NOVICE_GUIDE_FACTORY_H_
#define _GAME_NOVICE_GUIDE_FACTORY_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameNoviceGuideFactory
    {
    public:
        GETINSTANCE_FUNC(GameNoviceGuideFactory);
        ~GameNoviceGuideFactory();
        cocos2d::Node* createGameBeginNoviceGuide(int stage_index);
    private:
        GameNoviceGuideFactory();
    private:
        cocos2d::ValueMap begin_guide_data_vm_;
        std::map<int, std::string> begin_guide_data_;
    };
}
#endif