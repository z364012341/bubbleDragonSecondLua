//*******************************************************************************
//类名称   : GameScene
//功能     : <游戏的战斗场景>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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
    {//道具的使用状态
        notUseForError = 0, //因为跟状态有关, 所以不是用0的枚举
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
        //设置图标的状态, 是否被点击使用之类的
        void setPropsState(PropsState state);
        PropsState getPropsState();
        //发射之后
        void haveUsedProperty(cocos2d::EventCustom*);
    private:
        //void addNumbleButton();
        void addNumbleLabel();
        void initHandle();
        void addTouchEventListener();
        void removeTouchEventListener();
        //void setNumbleLabelStringWithNumble(int numble);
        //void  updateNumbleLabel();
        //初始化道具的图标
        void initIcon();
        //使用道具的动画
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