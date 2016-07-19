#include "UserCoinInfoBoard.h"
#include "AddButton.h"
#include "BubbleSecondConstant.h"
#include "UserDataManager.h"
#include "XMLTool.h"
const std::string CSB_PATH = "UserCoinInfo.csb";
const std::string COIN_NODE_NAME = "coinNode";
const int ROLL_COIN_LABEL_ACTION_TAG = 233;
namespace bubble_second {
    UserCoinInfoBoard::UserCoinInfoBoard()
    {
    }


    UserCoinInfoBoard::~UserCoinInfoBoard()
    {
    }

    bool UserCoinInfoBoard::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Node* csb = cocos2d::CSLoader::createNode(CSB_PATH);
        csb->getChildByName(ADD_BUTTON_NODE_NAME)->addChild(AddButton::create());
        numble_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(csb->getChildByName("BitmapFontLabel_2"));
        assert(numble_label_);
        this->updateNumbleLabel();
        this->addChild(csb);

        armature_ = dynamic_cast<cocostudio::Armature*>(csb->getChildByName(COIN_NODE_NAME));
        this->playRandomTimeAnimation();
        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        this->setPosition(cocos2d::Vec2(visible_size.width*0.512f, visible_size.height*USER_INFO_BOARD_POS_Y_PERCENT));
        return true;
    }

    void UserCoinInfoBoard::playRandomTimeAnimation()
    {
        int randomTime = cocos2d::random(2, 12);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(randomTime), cocos2d::CallFunc::create([=]() {
            armature_->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    this->playRandomTimeAnimation();
                }
            });
        })));
    }
    void UserCoinInfoBoard::updateNumbleLabel()
    {
        //this->rollCoinLabelNumbleEnd();
        coin_numble_offset_ = 0;
        this->setNumbleLabelString(UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_COIN_KEY));
    }
    void UserCoinInfoBoard::setNumbleLabelString(int numble)
    {
        //coin_numble_ = numble;
        numble_label_->setString(XMLTool::convertIntToString(numble));
    }
    void UserCoinInfoBoard::rollCoinLabelNumble(cocos2d::EventCustom * event)
    {
        coin_numble_offset_ += *static_cast<int*>(event->getUserData());
        this->setNumbleLabelString(UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_COIN_KEY) + coin_numble_offset_);
        //this->rollCoinLabelNumbleBegin();
    }
    //void UserCoinInfoBoard::rollCoinLabelNumbleBegin()
    //{
        //int goal_numble = UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_COIN_KEY) + coin_numble_offset_;
        //int cur_numble = XMLTool::convertStringToInt(numble_label_->getString());
        //int speed = 1;
        //if (goal_numble < cur_numble)
        //{
        //    speed *= -1;
        //}
        //cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::CallFunc::create([=]() {
        //    //coin_numble_ += speed;
        //    //numble_label_->setString(XMLTool::convertIntToString(coin_numble_));
        //    this->setNumbleLabelString(coin_numble_ + speed);
        //    if (coin_numble_ == goal_numble)
        //    {
        //        this->rollCoinLabelNumbleEnd();
        //    }
        //}), cocos2d::DelayTime::create(0.001f));
        //cocos2d::RepeatForever* repeat = cocos2d::RepeatForever::create(seq);
        //repeat->setTag(ROLL_COIN_LABEL_ACTION_TAG);
        //this->rollCoinLabelNumbleEnd();
        //this->runAction(repeat);
    //}
    //void UserCoinInfoBoard::rollCoinLabelNumbleEnd()
    //{
    //    this->stopActionByTag(ROLL_COIN_LABEL_ACTION_TAG);
    //}
    void UserCoinInfoBoard::onEnter()
    {
        cocos2d::Node::onEnter();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_UPDATE_PROPS_NUMBLE_LABEL, [=](cocos2d::EventCustom* event) {
            this->updateNumbleLabel();
        });
        this->getEventDispatcher()->addEventListenerWithFixedPriority(listener_, 1);
        this->getEventDispatcher()->addCustomEventListener(EVENT_ROLL_COIN_BOARD_LABEL, CC_CALLBACK_1(UserCoinInfoBoard::rollCoinLabelNumble, this));
        this->updateNumbleLabel();
    }
    void UserCoinInfoBoard::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
        this->getEventDispatcher()->removeCustomEventListeners(EVENT_ROLL_COIN_BOARD_LABEL);
    }
}