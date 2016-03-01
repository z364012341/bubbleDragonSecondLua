//*******************************************************************************
//������   : GameCharecter
//����     : <��Ϸ�����е�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//           
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_CHARACTOR_H_
#define _GAME_CHARACTOR_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
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
        void playShootBubbleAnimation();
        void playLegendaryAnimation();
        void playVictoryAnimation();
        void playDefeatAnimation();
    private:
        bool init();
        void addCharacterArmature();
        void playStandbyAnimation();
        cocostudio::Armature* getCharactorArmature();
        void playNotLoopAnimationWithName(const std::string& name);
        void playLoopAnimationWithName(const std::string& name);
        void setDefeatFlag(bool flag);
        bool isDefeat();
        
    private:
        cocostudio::Armature* charactor_armature_;
        bool defeat_flag_ = false;
    };
}
#endif //_GAME_CHARACTOR_H_