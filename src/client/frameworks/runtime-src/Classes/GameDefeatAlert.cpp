#include "GameDefeatAlert.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UITextBMFont.h"
#include "ui\UIButton.h"
#include "StageNumbleBoardController.h"
#include "StageDataManager.h"
#include "SpriteTextureController.h"
#include "GameScoreController.h"
#include "XMLTool.h"
#include "GameAlertMask.h" 
#include "ButtonEffectController.h"
const std::string GAME_DEFEAT_ALERT_CSB_PATH = "GameDefeatAlert.csb";
namespace bubble_second {
    GameDefeatAlert::GameDefeatAlert()
    {
    }


    GameDefeatAlert::~GameDefeatAlert()
    {
    }

    bool GameDefeatAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->loadCSB();
        this->addChild(GameAlertMask::create(), -1);
        return true;
    }

    void GameDefeatAlert::loadCSB()
    {
        csb_node_ = cocos2d::CSLoader::createNode(GAME_DEFEAT_ALERT_CSB_PATH);
        this->addChild(csb_node_);
        StageNumbleBoardController::getInstance()->loadView(csb_node_->getChildByName("FileNode_4"), StageDataManager::getInstance()->getCurrentLevel());
        csb_node_->getChildByName("stageTypeSprite")->addChild(SpriteTextureController::getInstance()->createStageTypeSprite(StageDataManager::getInstance()->getCurrentStageType()));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node_->getChildByName("completedNumble"))->setString(XMLTool::convertIntToString(GameScoreController::getInstance()->getCompletedTaskNumble()));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node_->getChildByName("taskNumble"))->setString(XMLTool::convertIntToString(GameScoreController::getInstance()->getGameTaskNumble()));
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName("replayNode"))->addClickEventListener([=](cocos2d::Ref*) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_REPLAY);
        });
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName("Button_8"))->addClickEventListener([=](cocos2d::Ref*) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_DEFEAT_RETURN);
        });
        ButtonEffectController::setButtonsZoomScale(csb_node_);
    }

   
}