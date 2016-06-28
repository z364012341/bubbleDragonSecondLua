#include "UserStengthInfoBoard.h"
#include "UserDataManager.h"
#include "AddButton.h"
#include "XMLTool.h"
const std::string CSB_PATH = "UserStrengthInfo.csb";
const std::string NUMBLE_LABEL_NAME = "BitmapFontLabel_1";
const std::string COUNTDOWN_LABEL_NAME = "BitmapFontLabel_2";
const std::string ARMATURE_NODE_NAME = "ArmatureNode_1";
namespace bubble_second {
    UserStengthInfoBoard::UserStengthInfoBoard()
    {
    }

    bool UserStengthInfoBoard::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Node* csb = cocos2d::CSLoader::createNode(CSB_PATH);
        this->addChild(csb);
        csb->getChildByName(ADD_BUTTON_NODE_NAME)->addChild(AddButton::create());
        numble_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(csb->getChildByName(NUMBLE_LABEL_NAME));
        assert(numble_label_);
        countdown_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(csb->getChildByName(COUNTDOWN_LABEL_NAME));
        assert(countdown_label_);
        armature_ = dynamic_cast<cocostudio::Armature*>(csb->getChildByName(ARMATURE_NODE_NAME));
        assert(armature_);

        this->updateNumbleLabel();
        this->playRandomTimeAnimation();

        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        this->setPosition(cocos2d::Vec2(visible_size.width*0.1671f, visible_size.height*USER_INFO_BOARD_POS_Y_PERCENT));

        return true;
    }

    void UserStengthInfoBoard::updateNumbleLabel()
    {
        numble_label_->setString(XMLTool::convertIntToString(UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_STENGTH_KEY)));
    }

    UserStengthInfoBoard::~UserStengthInfoBoard()
    {
    }

    void UserStengthInfoBoard::onEnter()
    {
        cocos2d::Node::onEnter();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_UPDATE_PROPS_NUMBLE_LABEL, [=](cocos2d::EventCustom* event) {
            this->updateNumbleLabel();
        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener_, 1);
    }
    void UserStengthInfoBoard::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
    }

    void UserStengthInfoBoard::playRandomTimeAnimation()
    {
        int randomTime = cocos2d::random(1, 3);
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
}