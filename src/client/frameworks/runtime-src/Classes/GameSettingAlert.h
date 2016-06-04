//*******************************************************************************
//������   : GameSettingAlert
//����     : <��Ϸ�������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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