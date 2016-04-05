//*******************************************************************************
//������   : PopScoreLabelComponent
//����     : <�����ķ�����ǩ>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _PopScore_Label_Component_H_
#define _PopScore_Label_Component_H_
#include "cocos2d.h"
#include "ui/UITextBMFont.h"
namespace bubble_second {
    class PopScoreLabelComponent : public cocos2d::Node
    {
    public:
        CREATE_FUNC(PopScoreLabelComponent);
        ~PopScoreLabelComponent();
    private:
        PopScoreLabelComponent();
        bool init();
    private:
        cocos2d::ui::TextBMFont* score_label_ = nullptr;
    };
}
#endif //_PopScore_Label_Component_H_