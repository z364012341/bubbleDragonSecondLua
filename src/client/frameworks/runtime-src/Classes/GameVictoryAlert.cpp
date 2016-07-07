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
#include "UserDataManager.h"
const std::string GAME_VICTORY_ALERT_CSB_PATH = "GameVictoryAlert.csb";
const std::string GAME_VICTORY_ALERT_SCORE_LABEL_NAME = "BitmapFontLabel_10_0";
const std::string GAME_VICTORY_ALERT_COIN_LABEL_NAME = "BitmapFontLabel_10";
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
        this->initCoinLabel(level);
        this->addLotteryStarts();
        this->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        this->flyStartToLottery(level, start_numble);
        UserDataManager::getInstance()->updateStageData(level, start_numble);
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
        //if (start_numble < 3)
        //{
        //    start_3_->setVisible(false);
        //} 
        //if (start_numble < 2)
        //{
        //    start_2_->setVisible(false);
        //}
        //if (start_numble < 1)
        //{
        //    start_1_->setVisible(false);
        //}
        for (int i = start_numble; i < starts_.size(); i++)
        {
            starts_.at(i)->setVisible(false);
        }
        this->playStart1PopAction();
        this->playStart2PopAction();
        this->playStart3PopAction();
    }

    void GameVictoryAlert::initCoinLabel(int level)
    {
        int add_coin = GAME_VICTORY_ADD_COIN_FORMULA(level);
        UserDataManager::getInstance()->addPropsNumbleWithKey(GAME_COIN_KEY, add_coin);
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node_->getChildByName("zitiao_17")->getChildByName(GAME_VICTORY_ALERT_COIN_LABEL_NAME))->setString(XMLTool::convertIntToString(add_coin));
    }

    void GameVictoryAlert::addLotteryStarts()
    {
        lottery_starts_ = GameVictoryLotteryStarts::create();
        lottery_starts_->setScale(1/SmartScaleController::getInstance()->getPlayAreaZoom());
        this->addChild(lottery_starts_);
    }

    void GameVictoryAlert::flyStartToLottery(int level, int start_numble)
    {
        int best_start_numble = UserDataManager::getInstance()->getStageStartNumbleWithLevel(level);
        if (start_numble <= best_start_numble)
        {
            return;
        }
        int start_numble_delta = start_numble - best_start_numble;
        for (int i = starts_.size() - 1; i > starts_.size() - start_numble_delta -1; i--)
        {
            fly_starts_points_.insert(fly_starts_points_.begin(), starts_.at(i)->getPosition());
            //points.insert(points.begin(), starts_.at(i)->getParent()->convertToWorldSpace(starts_.at(i)->getPosition()));
        }
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(pop_start_total_time_), cocos2d::CallFunc::create([=]() {
            //lottery_starts_->flyStartsToLotteryBegin(points);
            this->flyStartToLotteryBegin();
        }), nullptr));
    }

    void GameVictoryAlert::flyStartToLotteryBegin()
    {
        if (fly_starts_points_.empty())
        {
            return;
        }
        lottery_starts_->flyStartsToLotteryBegin(fly_starts_points_.front());
        fly_starts_points_.pop_front();
    }

    void GameVictoryAlert::playStartPopAction(cocos2d::Node * start, float delay)
    {
        pop_start_total_time_ += delay;
        start->setScale(0.1f);
        start->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(delay), cocos2d::ScaleTo::create(START_POP_DURATION, 1.2f), cocos2d::ScaleTo::create(0.1f, 1.0f), nullptr));
    }

    void GameVictoryAlert::playStart1PopAction()
    {
        //cocos2d::Node* start = csb_node_->getChildByName(ALERT_STAR_NODE_1_NAME);
        this->playStartPopAction(start_1_, START_POP_DURATION/2);
    }

    void GameVictoryAlert::playStart2PopAction()
    {
        this->playStartPopAction(start_2_, START_POP_DURATION);
    }

    void GameVictoryAlert::playStart3PopAction()
    {
        this->playStartPopAction(start_3_, START_POP_DURATION*2);
    }

    void GameVictoryAlert::loadView()
    {
        csb_node_ = cocos2d::CSLoader::createNode(GAME_VICTORY_ALERT_CSB_PATH);
        this->addChild(csb_node_);
        ButtonEffectController::setButtonsZoomScale(csb_node_);
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName("Button_1"))->addClickEventListener([=](cocos2d::Ref*) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_DEFEAT_RETURN);
        });
        start_1_ = csb_node_->getChildByName(ALERT_STAR_NODE_1_NAME);
        starts_.pushBack(start_1_);
        start_2_ = csb_node_->getChildByName(ALERT_STAR_NODE_2_NAME);
        starts_.pushBack(start_2_);
        start_3_ = csb_node_->getChildByName(ALERT_STAR_NODE_3_NAME);
        starts_.pushBack(start_3_);

    }

    void GameVictoryAlert::setNextCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback)
    {
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(ALERT_NEXT_NODE_NAME)->getChildByName(ALERT_NEXT_BUTTON_NAME))->addTouchEventListener(callback);
    }

    void GameVictoryAlert::setReplayCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback)
    {
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(ALERT_REPLAY_NODE_NAME))->addTouchEventListener(callback);
    }
    void GameVictoryAlert::onEnter()
    {
        cocos2d::Node::onEnter();
        this->getEventDispatcher()->addCustomEventListener(EVENT_CONTRAROTATE_STARTS_END, [=](cocos2d::EventCustom* event) {
            this->flyStartToLotteryBegin();
        });
    }
    void GameVictoryAlert::onExit()
    {
        cocos2d::Node::onExit();
        this->getEventDispatcher()->removeCustomEventListeners(EVENT_CONTRAROTATE_STARTS_END);
    }
}