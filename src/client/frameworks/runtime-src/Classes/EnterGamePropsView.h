//*******************************************************************************
//������   : EnterGamePropsView
//����     : <����������Ʒչʾ�Ļ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _ENTER_GAME_PROPS_VIEW_H_
#define _ENTER_GAME_PROPS_VIEW_H_
#include "cocos2d.h"
#include "ui\UIButton.h"
#include "ui\UITextBMFont.h"
#include "EnterPropsViewManager.h"
//#include "GameTextInfo.h"
#include "UserDataManager.h"
const std::string ADD_BUBBLE_NUMBLE_ANIMATION_NAME = "jiabudaoju";
const std::string ADD_SPECIAL_ANIMATION_NAME = "pingzidaoju";
const std::string AIMING_LINE_COMMODITY_ANIMATION_NAME = "miaozhunxian";
namespace bubble_second {
    class GamePropsCostTag;
    class EnterGamePropsView : public cocos2d::Node
    {
    public:
        static cocos2d::Node* createCommodityArmature(const std::string& animation_name, const std::string& end_event_name);
        virtual ~EnterGamePropsView();
    protected:
        EnterGamePropsView();
        bool init(const std::string& prop_key);
        void buttonClickCallfunc(cocos2d::Ref*);
        //������߽���
        void disposedEnterPropsUnlock();
    private:
        void loadView();
    private:
        cocos2d::ui::Button* button_ = nullptr;
        GamePropsCostTag* cost_tag_ = nullptr;
        std::string prop_key_ = "";
        //cocos2d::ui::TextBMFont* cost_label_ = nullptr;
    };
}
#endif //_ENTER_GAME_PROPS_VIEW_H_