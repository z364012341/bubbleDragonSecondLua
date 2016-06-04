//*******************************************************************************
//类名称   : GameSettingAlert
//功能     : <游戏设置面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SETTING_ALERT_H_
#define _GAME_SETTING_ALERT_H_
#include "cocos2d.h"
#include "ui\UICheckBox.h"
namespace bubble_second {
    class GameSettingAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameSettingAlert);
        virtual ~GameSettingAlert();
        void onExit() override;
    private:
        GameSettingAlert();
        bool init();
        void loadCSB();
    private:
        cocos2d::ui::CheckBox* music_checkbox_ = nullptr;
        cocos2d::ui::CheckBox* effect_checkbox = nullptr;
    };
}
#endif //_GAME_SETTING_ALERT_H_