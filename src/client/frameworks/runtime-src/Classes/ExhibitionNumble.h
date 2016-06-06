//*******************************************************************************
//������   : ExhibitionNumble
//����     : <�׵���ɫlabel���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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
