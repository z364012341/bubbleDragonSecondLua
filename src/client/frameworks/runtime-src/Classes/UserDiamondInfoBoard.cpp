#include "UserDiamondInfoBoard.h"
#include "AddButton.h"
#include "BubbleSecondConstant.h"
#include "UserDataManager.h"
#include "XMLTool.h"
const std::string CSB_PATH = "UserDiamondInfo.csb";
const std::string DIAMOND_NODE_NAME = "diamondNode";
namespace bubble_second {
    UserDiamondInfoBoard::UserDiamondInfoBoard()
    {
    }


    UserDiamondInfoBoard::~UserDiamondInfoBoard()
    {
    }

    bool UserDiamondInfoBoard::init()
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

        armature_ = dynamic_cast<cocostudio::Armature*>(csb->getChildByName(DIAMOND_NODE_NAME));
        this->playRandomTimeAnimation();

        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        this->setPosition(cocos2d::Vec2(visible_size.width*0.8511f, visible_size.height*USER_INFO_BOARD_POS_Y_PERCENT));
        return true;
    }

    void UserDiamondInfoBoard::playRandomTimeAnimation()
    {
        int randomTime = cocos2d::random(5, 15);
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
    void UserDiamondInfoBoard::updateNumbleLabel()
    {
        numble_label_->setString(XMLTool::convertIntToString(UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_DIAMOND_KEY)));
    }
    void UserDiamondInfoBoard::onEnter()
    {
        cocos2d::Node::onEnter();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_UPDATE_PROPS_NUMBLE_LABEL, [=](cocos2d::EventCustom* event) {
            this->updateNumbleLabel();
        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener_, 1);
        this->updateNumbleLabel();
    }
    void UserDiamondInfoBoard::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
    }
}