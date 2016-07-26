//*******************************************************************************
//������   : GameScene
//����     : <��Ϸ��ս������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BASE_PROPERTY_H_
#define _BASE_PROPERTY_H_
#include "cocos2d.h"
#include "SpriteTextureController.h"
#include "UserDataManager.h"
//#include "ui\UIButton.h"
//#include "ui\UITextAtlas.h"
namespace bubble_second {
    enum PropsState
    {//���ߵ�ʹ��״̬
        notUseForError = 0, //��Ϊ��״̬�й�, ���Բ�����0��ö��
        kUsing,
        kNotUsed
    };
    typedef bool TouchEnabled;
    typedef bool isUsing;
    class PropsNumbleShow;
    class BaseProperty  : public cocos2d::Sprite
    {
    public:
        static BaseProperty* createWithPropKey(const std::string& key)
        {
            BaseProperty *pRet = new(std::nothrow) BaseProperty();
            if (pRet && pRet->initWithPropKey(key))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
        //CREATE_FUNC(BaseProperty);
        virtual ~BaseProperty();
        void onExit() override;
    public:
        virtual void touchItem();
        //void actionBegan();
        virtual void cancelUseItem();
        //void actionEnded();
        isUsing itemIsUsing();
        void setPropertyEnabled(bool flag);
        bool isPropertyEnabled();
    protected:
        BaseProperty();
        bool initWithPropKey(const std::string& key);
        virtual void useItem();
        //����ͼ���״̬, �Ƿ񱻵��ʹ��֮���
        void setPropsState(PropsState state);
        PropsState getPropsState();
        //����֮��
        void haveUsedProperty(cocos2d::EventCustom*);
    private:
        //void addNumbleButton();
        void addNumbleLabel();
        void initHandle();
        void addTouchEventListener();
        void removeTouchEventListener();
        //void setNumbleLabelStringWithNumble(int numble);
        //void  updateNumbleLabel();
        //��ʼ�����ߵ�ͼ��
        void initIcon();
        //ʹ�õ��ߵĶ���
        void playUsingAction();
        void stopUsingAction();
    private:
        //cocos2d::ui::Button* button_;
        std::map<PropsState, std::function<void()>> state_to_handle_;
        PropsState use_state_;
        TouchEnabled touch_flag_;
        //cocos2d::Menu* menu_;
        bool touch_enable_ = true;
        PropsNumbleShow* props_numble_label_ = nullptr;
        std::string property_key_ = "";
        cocos2d::Sprite* icon_sprite_ = nullptr;
    };
}
#endif //_BASE_PROPERTY_H_