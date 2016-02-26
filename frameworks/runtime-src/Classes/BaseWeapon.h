//*******************************************************************************
//������   : BaseWeapon
//����     : <��Ϸ�������Ļ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BASE_WEAPON_H_
#define _BASE_WEAPON_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    //class BaseBubble;
    class BaseWeapon : public cocos2d::Sprite
    {
    public:
        CREATE_FUNC(BaseWeapon);
        BaseWeapon();
        virtual ~BaseWeapon();
        //void setSelectBubble(BaseBubble* bubble);
        virtual bool inAttackRange(BubbleType color);
        virtual void attackBubble();
    protected:
        bool init();
    //private:
    //    BaseBubble* select_bubble_;
    };
}
#endif //_BASE_WEAPON_H_