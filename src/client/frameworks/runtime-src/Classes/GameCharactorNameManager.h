//*******************************************************************************
//类名称   : GameCharactorNameManager
//功能     : <游戏角色动画名称管理>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_CHARACTOR_NAME_MANAGER_H_
#define _GAME_CHARACTOR_NAME_MANAGER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
const std::string CHARCTOR_LAOHU_ARMATURE_KEY = "aoao";
const std::string CHARCTOR_MIAO_ARMATURE_KEY = "miaopass";
const std::string CHARCTOR_LAOSHU_ARMATURE_KEY = "zhizhi";
const std::string CHARCTOR_TUZI_ARMATURE_KEY = "tutu";
namespace bubble_second {
    class GameCharactorNameManager
    {
    public:
        GETINSTANCE_FUNC(GameCharactorNameManager);
        ~GameCharactorNameManager();
        std::string getCurrentArmatureName();
        std::string getCurrentArmatureName1();
        std::string getCurrentArmatureName2();
        std::string getCurrentArmatureName3();
        std::string getCurrentArmatureNameVictory();
        std::string getCurrentArmatureSkillEvent();
        void initNamesData();
        void setCurrentArmatureNameWithIndex(int index);
        void dispatchUseCurrentArmatureSkill();
        BubbleType getCurrentSkillType();
    private:
        GameCharactorNameManager();
    private:
        std::string current_name_;
        cocos2d::ValueMap charactor_armature_names_;
    };
}
#endif //_GAME_CHARACTOR_NAME_MANAGER_H_