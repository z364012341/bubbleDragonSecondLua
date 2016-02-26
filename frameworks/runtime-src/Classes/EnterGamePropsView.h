//*******************************************************************************
//������   : EnterGamePropsView
//����     : <������ʾ���½ǵ���������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _ENTER_GAME_PROPS_VIEW_H_
#define _ENTER_GAME_PROPS_VIEW_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GamePropsNumbleView;
    class EnterGamePropsView : public cocos2d::Node
    {
    public:
        //CREATE_FUNC(EnterGamePropsView);
        //������ߵ�չʾ
        static EnterGamePropsView* create(cocos2d::Sprite* props);
        void addCostView(const cocos2d::Value& value);
        virtual ~EnterGamePropsView();
        void addMenuCallback(const cocos2d::ccMenuCallback& callback);
    protected:
        EnterGamePropsView();
        bool init(cocos2d::Sprite* props);
    private:
        void addBackground();
        void addPropsTexture(cocos2d::Sprite* props);
        void addPropsNumbleView();
    private:
        cocos2d::MenuItemSprite* background_ = nullptr;
        GamePropsNumbleView* props_numble_view_ = nullptr;
        cocos2d::Value props_value_;
        cocos2d::ccMenuCallback menu_callback_ = nullptr;
    };
}
#endif //_ENTER_GAME_PROPS_VIEW_H_