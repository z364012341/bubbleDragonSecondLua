#include "GameSettingAlert.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UIButton.h"
#include "GameAlertMask.h"
#include "UserDataManager.h"
#include "ButtonEffectController.h"
#include "GameHelpAlert.h"
#include "GameAboutAlert.h"
#include "GameAudioController.h"
const std::string GAME_SETTING_ALERT_CSB_PATH = "GameSettingAlert.csb";
const std::string MUSIC_CHECK_BOX_NAME = "CheckBox_1";
const std::string EFFECT_CHECK_BOX_NAME = "CheckBox_2";
const std::string RETURN_BUTTON_NAME = "Button_1";
const std::string HELP_BUTTON_NAME = "helpButton";
const std::string ABOUT_BUTTON_NAME = "aboutButton";
namespace bubble_second {
    GameSettingAlert::GameSettingAlert()
    {
    }


    GameSettingAlert::~GameSettingAlert()
    {
    }

    //void GameSettingAlert::onExit()
    //{
    //    cocos2d::Node::onExit();
    //    GameAudioController::getInstance()->setBackgroundMusicEnabled(music_checkbox_->isSelected());
    //    UserDataManager::getInstance()->setSoundEffectEnable(effect_checkbox->isSelected());
    //    //UserDataManager::getInstance()->saveUserData();
    //}

    bool GameSettingAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create(), -1);
        this->loadCSB();
        return true;
    }

    void GameSettingAlert::loadCSB()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_SETTING_ALERT_CSB_PATH);
        assert(csb_node);
        ButtonEffectController::setButtonsZoomScale(csb_node);
        this->addChild(csb_node);
        music_checkbox_ = dynamic_cast<cocos2d::ui::CheckBox*>(csb_node->getChildByName(MUSIC_CHECK_BOX_NAME));
        assert(music_checkbox_);
        music_checkbox_->setSelected(UserDataManager::getInstance()->isGameMusicEnable());
        music_checkbox_->addClickEventListener([=](cocos2d::Ref*) {GameAudioController::getInstance()->setBackgroundMusicEnabled(music_checkbox_->isSelected()); });

        effect_checkbox = dynamic_cast<cocos2d::ui::CheckBox*>(csb_node->getChildByName(EFFECT_CHECK_BOX_NAME));
        assert(effect_checkbox);
        effect_checkbox->setSelected(UserDataManager::getInstance()->isSoundEffectEnable());
        effect_checkbox->addClickEventListener([=](cocos2d::Ref*) {UserDataManager::getInstance()->setSoundEffectEnable(effect_checkbox->isSelected()); });


        cocos2d::ui::Button* return_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName(RETURN_BUTTON_NAME));
        assert(return_button);
        return_button->addClickEventListener([=](cocos2d::Ref*) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_SETTING_ALERT_CLOSE);
            this->removeFromParent();
        });
        cocos2d::ui::Button* help_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName(HELP_BUTTON_NAME));
        assert(help_button);
        help_button->addClickEventListener([=](cocos2d::Ref*) {
            //GameHelpAlert* help_alert = GameHelpAlert::create();
            //help_alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
            this->addChild(GameHelpAlert::create());
        });
        cocos2d::ui::Button* about_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName(ABOUT_BUTTON_NAME));
        assert(about_button);
        about_button->addClickEventListener([=](cocos2d::Ref*) {
            this->addChild(GameAboutAlert::create());
        });
    }
    
}