//*******************************************************************************
//类名称   : GameCharecter
//功能     : <游戏场景中的人物>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_CHARACTOR_H_
#define _GAME_CHARACTOR_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
const std::string GAME_CHARACTER_ARMATURE_LAOHU_NAME = "laohu";
const std::string GAME_CHARACTER_ARMATURE_LAOHU2_NAME = "laohu2";
const std::string GAME_CHARACTER_LAOHU_ANIMATION_STANDBY_NAME = "daiji-01-1";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_1 = "rengqiu01";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_2 = "rengqiu-02";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_3 = "rengqiu-03";
const float CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_1 = 40.0f;
const float CHARACTER_ARMATURE_SCALE = 0.37f;
namespace bubble_second {
    class GameCharacter : public cocos2d::Node
    {
    public:
        //static GameCharacter* createWithName(const std::string& name)
        //{ 
        //    GameCharacter *pRet = new(std::nothrow) GameCharacter();
        //    if (pRet && pRet->initWithName(name))
        //    {
        //        pRet->autorelease();
        //        return pRet;
        //    }
        //    else
        //    {
        //        delete pRet;
        //        pRet = NULL;
        //        return NULL;
        //    }
        //}
        CREATE_FUNC(GameCharacter);
        GameCharacter();
        ~GameCharacter();
    public:
		void playShootBubbleAnimation(cocos2d::EventCustom* event);
        void playLegendaryAnimation();
        void playVictoryAnimation();
        void playDefeatAnimation();
	protected:
		void onEnter() override;
		void onExit() override;
    private:
        bool init();
		void addEventListenerCustom();
		void removeEventListenerCustom();
        void addCharacterArmature();
        void playStandbyAnimation();
        cocostudio::Armature* getCharactorArmature();
		cocostudio::Armature* getCharactorArmature2();
        void playNotLoopAnimationWithName(const std::string& name);
        void playLoopAnimationWithName(const std::string& name);
        void setDefeatFlag(bool flag);
        bool isDefeat();
		//根据角度播放发射动画
		void playShootAnimation1();
		void playShootAnimation2();
		void playShootAnimation3();
    private:
        cocostudio::Armature* charactor_armature_1_;
		cocostudio::Armature* charactor_armature_2_;
        bool defeat_flag_ = false;
    };
}
#endif //_GAME_CHARACTOR_H_