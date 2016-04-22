//*******************************************************************************
//类名称   : StageTypeLogo
//功能     : <关卡类型logo>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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