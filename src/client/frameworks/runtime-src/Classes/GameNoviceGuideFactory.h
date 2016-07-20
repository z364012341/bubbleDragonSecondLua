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
        cocos2d::Node* createGameBeginNoviceGuide();
        cocos2d::Node* createGameEndNoviceGuide();
        cocos2d::Node* createGameCharactorSkillNoviceGuide();
    private:
        GameNoviceGuideFactory();
        cocos2d::Node* createNoviceGuideAlertWithPath(const std::string& path);
        template<typename T>
        cocos2d::Node* createNoviceGuideAlertWithDataAndIndex(const std::map<T, std::string>& data, T key);

    };
}
#endif