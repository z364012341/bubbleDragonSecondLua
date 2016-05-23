//*******************************************************************************
//类名称   : PropsNumbleShow
//功能     : <游戏的战斗场景>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _PROPS_NUMBLE_SHOW_H_
#define _PROPS_NUMBLE_SHOW_H_
#include "cocos2d.h"
#include "ui\UITextAtlas.h"
namespace bubble_second {
    class PropsNumbleShow : public cocos2d::Node
    {
    public:
        CREATE_FUNC(PropsNumbleShow);
        ~PropsNumbleShow();
    private:
        PropsNumbleShow();
        bool init();
    private:
        cocos2d::ui::TextAtlas* props_numble_label_ = nullptr;
    };
}
#endif //_PROPS_NUMBLE_SHOW_H_
