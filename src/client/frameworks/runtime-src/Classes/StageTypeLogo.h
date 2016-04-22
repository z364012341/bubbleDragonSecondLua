//*******************************************************************************
//������   : StageTypeLogo
//����     : <�ؿ�����logo>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAGE_TYPE_LOGO_H_
#define _STAGE_TYPE_LOGO_H_
//#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class StageTypeLogo : public cocos2d::Node
    {
    public:
        static StageTypeLogo* create(const StageType& type);
        ~StageTypeLogo();
        void onEnter() override;
        void onExit() override;
    private:
        StageTypeLogo();
        bool initWithType(const StageType& type);
        void mutipleSealBubbleFly(cocos2d::EventCustom* event);
    };
}
#endif //_STAGE_TYPE_LOGO_H_