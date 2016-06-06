//*******************************************************************************
//类名称   : ExhibitionNumble
//功能     : <白底棕色label面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _EXHIBITION_NUMBLE_H_
#define _EXHIBITION_NUMBLE_H_
#include "cocos2d.h"
#include "ui\UITextAtlas.h"
namespace bubble_second {
    class ExhibitionNumble : public cocos2d::Node
    {
    public:
        //CREATE_FUNC(ExhibitionNumble);
        static ExhibitionNumble* create(int numble = 0);
        ~ExhibitionNumble();
        void setString(const std::string& str);
    private:
        ExhibitionNumble();
        bool init(int numbel);
        void loadCSB();
    private:
        cocos2d::ui::TextAtlas* numble_label_ = nullptr;
    };
}
#endif //_EXHIBITION_NUMBLE_H_
