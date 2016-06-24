#include "GameVictoryAlert.h"
#include "SmartScaleController.h"
//#include "CenteredMenuItemSprite.h"
//#include "GameTextInfo.h"  
//#include "GameSamsung.h"
#include "ButtonEffectController.h"
#include "GameAlertMask.h"
#include "ui\UIButton.h"
#include "ui\UITextBMFont.h"
#include "XMLTool.h"
#include "StageNumbleBoardController.h"
#include "GameVictoryLotteryStarts.h"
const std::string GAME_VICTORY_ALERT_CSB_PATH = "GameVictoryAlert.csb";
const std::string GAME_VICTORY_ALERT_SCORE_LABEL_NAME = "BitmapFontLabel_10_0";
const std::string GAME_VICTORY_ALERT_STAGE_LABEL_NODE_NAME = "FileNode_4";
const std::string ALERT_NEXT_NODE_NAME = "nextNode";
const std::string ALERT_NEXT_BUTTON_NAME = "Button_1";
const std::string ALERT_REPLAY_NODE_NAME = "replayNode";
const std::string ALERT_STAR_NODE_1_NAME = "star_1";
const std::string ALERT_STAR_NODE_2_NAME = "star_2";
const std::string ALERT_STAR_NODE_3_NAME = "star_3";
constexpr float START_POP_DURATION = 0.2f;
//const std::string ALERT_REPLAY_BUTTON_NAME = "Button_1";
namespace bubble_second {
    GameVictoryAlert::GameVictoryAlert()
    {
    }

    GameVictoryAlert::~GameVictoryAlert()
    {
    }

    GameVictoryAlert * bubble_second::GameVictoryAlert::create(int level, int score, int start_numble)
    {
        GameVictoryAlert *pRet = new(std::nothrow) GameVictoryAlert();
        if (pRet && pRet->init(level, score, start_numble))
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

    bool GameVictoryAlert::init(int level, int score, int start_numble)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create());
        this->loadView();
        this->initTopLabel(level);
        this->initScoreLabel(score);
        this->initStart(start_numble);
        this->addLotteryStarts();
        this->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        return true;
    }

    void GameVictoryAlert::initTopLabel(int numble)
    {
        //ÎÄ×Ö
        StageNumbleBoardController::getInstance()->loadView(csb_node_->getChildByName(GAME_VICTORY_ALERT_STAGE_LABEL_NODE_NAME), numble);
    }

    void GameVictoryAlert::initScoreLabel(int score)
    {
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node_->getChildByName(GAME_VICTORY_ALERT_SCORE_LABEL_NAME))->setString(XMLTool::convertIntToString(score));
    }

    void GameVictoryAlert::initStart(int start_numble)
    {
        if (start_numble < 3)
        {
            csb_node_->getChildByName(ALERT_STAR_NODE_3_NAME)->setVisible(false);
        } 
        if (start_numble < 2)
        {
            csb_node_->getChildByName(ALERT_STAR_NODE_2_NAME)->setVisible(false);
        }
        if (start_numble < 1)
        {
            csb_node_->getChildByName(ALERT_STAR_NODE_1_NAME)->setVisible(false);
        }
        this->playStart1PopAction();
        this->playStart2PopAction();
        this->playStart3PopAction();
    }

    void GameVictoryAlert::addLotteryStarts()
    {
        auto lottery = GameVictoryLotteryStarts::create();
        lottery->setScale(1/SmartScaleController::getInstance()->getPlayAreaZoom());
        this->addChild(lottery);
    }

    void GameVictoryAlert::playStartPopAction(cocos2d::Node * start, float delay)
    {
        start->setScale(0.1f);
        start->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(delay), cocos2d::ScaleTo::create(START_POP_DURATION, 1.2f), cocos2d::ScaleTo::create(0.1f, 1.0f), nullptr));
    }

    void GameVictoryAlert::playStart1PopAction()
    {
        cocos2d::Node* start = csb_node_->getChildByName(ALERT_STAR_NODE_1_NAME);
        this->playStartPopAction(start, 0.1f);
    }

    void GameVictoryAlert::playStart2PopAction()
    {
        this->playStartPopAction(csb_node_->getChildByName(ALERT_STAR_NODE_2_NAME), START_POP_DURATION);
    }

    void GameVictoryAlert::playStart3PopAction()
    {
        this->playStartPopAction(csb_node_->getChildByName(ALERT_STAR_NODE_3_NAME), START_POP_DURATION*2);
    }

    void GameVictoryAlert::loadView()
    {
        csb_node_ = cocos2d::CSLoader::createNode(GAME_VICTORY_ALERT_CSB_PATH);
        this->addChild(csb_node_);
        ButtonEffectController::setButtonsZoomScale(csb_node_);
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName("Button_1"))->addClickEventListener([=](cocos2d::Ref*) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_DEFEAT_RETURN);
        });
    }

    void GameVictoryAlert::setNextCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback)
    {
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(ALERT_NEXT_NODE_NAME)->getChildByName(ALERT_NEXT_BUTTON_NAME))->addTouchEventListener(callback);
    }

    void GameVictoryAlert::setReplayCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback)
    {
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(ALERT_REPLAY_NODE_NAME))->addTouchEventListener(callback);
    }

}