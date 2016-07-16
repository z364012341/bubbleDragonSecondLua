#include "GameSignBoardAlert.h"
#include "cocostudio\CocoStudio.h"
#include "GameAlertMask.h" 
#include "ui\UIButton.h"
#include "SpriteTextureController.h"
#include "UserDataManager.h"
#include "ButtonEffectController.h"
const std::string GAME_SIGN_BOARD_ALERT_CSB_PATH = "GameSignBoardAlert.csb";
const std::string GAME_SIGN_BOARD_TODAY_BOARD_PATH = "qiandaojintian.png";
const int GAME_SIGN_IN_TOTAL_TIMES = 7; //一共7次签到
const std::map<int, std::string> SIGN_BOARDS_NAME = {
    { 1 , "board_1" },
    { 2 , "board_2" },
    { 3 , "board_3" },
    { 4 , "board_4" },
    { 5 , "board_5" },
    { 6 , "board_6" },
    { 7 , "board_7" }
};
const std::map<int, std::map<std::string, int>> SIGN_TO_REWARD_DATA = {
    { 1 , { { GAME_COIN_KEY , 888 } } },
    { 2 , { { BUBBLE_WOODEN_HAMMER_PROP_KEY , 1 } } },
    { 3 , { { BUBBLE_COLOR_BOMB_PROP_KEY , 1 },{ GAME_COIN_KEY , 2888 } } },
    { 4 , { { BUBBLE_BIG_BOMB_BOMB_PROP_KEY , 1 } } },
    { 5 , { { GAME_DIAMOND_KEY , 18 } } },
    { 6 , { { GAME_COIN_KEY , 6888 } } },
    { 7 , { { BUBBLE_STAVES_PROP_KEY , 1 },{ GAME_COIN_KEY , 8888 } } }
};
namespace bubble_second {
    GameSignBoardAlert::GameSignBoardAlert()
    {
    }

    bool GameSignBoardAlert::init()
    {
        if (!cocos2d::Node::init() || !this->isNeedSignIn())
        {
            return false;
        }
        csb_node_ = cocos2d::CSLoader::createNode(GAME_SIGN_BOARD_ALERT_CSB_PATH);
        this->addChild(csb_node_);
        GameAlertMask* mask = GameAlertMask::create();
        mask->setPositionY(csb_node_->getChildByName("qiandaoban_1")->getContentSize().height / -2);
        this->addChild(mask, -1);

        cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName("Button_1"));
        ButtonEffectController::setButtonZoomScale(button);
        button->addClickEventListener([=](cocos2d::Ref*) {
            UserDataManager::getInstance()->saveGameSignLastDay();
            int numble = sign_day_ + 1;
            if (numble > GAME_SIGN_IN_TOTAL_TIMES)
            {
                numble = 1;
            }
            UserDataManager::getInstance()->setPropsNumbleWithKey(GAME_SIGN_DAY_NUMBLE_KEY, numble);
            this->addSignInReward();
            this->removeFromParent();
        });

        this->initTodayBoard();
        return true;
    }

    void GameSignBoardAlert::initTodayBoard()
    {
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_SIGN_BOARD_TODAY_BOARD_PATH);
        sign_day_ = UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_SIGN_DAY_NUMBLE_KEY);
        sp->setPosition(csb_node_->getChildByName(SIGN_BOARDS_NAME.at(sign_day_))->getPosition());
        csb_node_->addChild(sp);
    }

    bool GameSignBoardAlert::isNeedSignIn()
    {
        //bool a = !UserDataManager::getInstance()->isTheSameSignInDay();
        return UserDataManager::getInstance()->isLaterTheLastSignInDay();
    }

    void GameSignBoardAlert::addSignInReward()
    {
        for (auto var : SIGN_TO_REWARD_DATA.at(sign_day_))
        {
            UserDataManager::getInstance()->addPropsNumbleWithKey(var.first, var.second);
        }
    }


    GameSignBoardAlert::~GameSignBoardAlert()
    {
    }
}