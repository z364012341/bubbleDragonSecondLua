#include "GameVictoryLotteryStarts.h"
#include "SpriteTextureController.h"
#include "SmartScaleController.h"
#include "UserDataManager.h"
#include "GameVictoryLotteryGiftItem.h"
#include "GameVictoryLotteryStartItem.h"
#include "cocostudio\CocoStudio.h"
#include "GameAlertMask.h"
//const float STARTS_CIRCLE_RADIUS = 500.0f;
//const float START_ANGLE_DELTA = 11.0f;
const std::string GIFT_ARMATURE_NAME = "pintulibao2";
const float START_CONTRAROTATE_DURATION = 0.4f;
const float START_FLY_LOTTERY_DURATION = 0.5f;
const int LOTTERY_GIFT_DELTA = 6;
//const cocos2d::Vec2 TOP_POSITION(0.0f, STARTS_CIRCLE_RADIUS);
const cocos2d::Vec2 POS_0(-404.4f, 312.91f);
const cocos2d::Vec2 POS_1(-333.55f, 426.45f);
const cocos2d::Vec2 POS_2(-280.99f, 484.88f);
const cocos2d::Vec2 POS_3(-205.57f, 531.88f);
const cocos2d::Vec2 POS_4(-111.31f, 564.74f);
const cocos2d::Vec2 POS_5(0.0f, 575.4f);
const cocos2d::Vec2 POS_6(-POS_4.x, POS_4.y);
const cocos2d::Vec2 POS_7(-POS_3.x, POS_3.y);
const cocos2d::Vec2 POS_8(-POS_2.x, POS_2.y);
const cocos2d::Vec2 POS_9(-POS_1.x, POS_1.y);
const cocos2d::Vec2 POS_10(-POS_0.x, POS_0.y);
const std::vector<cocos2d::Vec2>LOTTERY_STARTS_POSITION_DATA = { POS_0, POS_1, POS_2, POS_3, POS_4, POS_5,POS_6, POS_7, POS_8, POS_9, POS_10 };
const float ROTATION_0 = -61.07f;
const float ROTATION_1 = -46.33f;
const float ROTATION_2 = -37.35f;
const float ROTATION_3 = -20.37f;
const float ROTATION_4 = -8.46f;
const float ROTATION_5 = 0.0f;
const float ROTATION_6 = -ROTATION_4;
const float ROTATION_7 = -ROTATION_3;
const float ROTATION_8 = -ROTATION_2;
const float ROTATION_9 = -ROTATION_1;
const float ROTATION_10 = -ROTATION_0;
const std::vector<float>LOTTERY_STARTS_ROTATION_DATA = { ROTATION_0, ROTATION_1, ROTATION_2, ROTATION_3, ROTATION_4, ROTATION_5, ROTATION_6, ROTATION_7, ROTATION_8, ROTATION_9, ROTATION_10 };
const float SCALE_0 = 0.2674f;
const float SCALE_1 = 0.3980f;
const float SCALE_2 = 0.4842f;
const float SCALE_3 = 0.6f;
const float SCALE_4 = 0.8f;
const float SCALE_5 = 1.0f;
const float SCALE_6 = SCALE_4;
const float SCALE_7 = SCALE_3;
const float SCALE_8 = SCALE_2;
const float SCALE_9 = SCALE_1;
const float SCALE_10 = SCALE_0;
const std::vector<float>LOTTERY_STARTS_SCALE_DATA = { SCALE_0, SCALE_1, SCALE_2, SCALE_3, SCALE_4, SCALE_5, SCALE_6, SCALE_7, SCALE_8, SCALE_9, SCALE_10 };

namespace bubble_second {
    GameVictoryLotteryStarts::GameVictoryLotteryStarts()
    {
    }

    bool bubble_second::GameVictoryLotteryStarts::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        total_start_numble_ = UserDataManager::getInstance()->getStageTotalStartScore();
        this->initStarts();
        this->initStartVisible();
        return true;
    }

    void GameVictoryLotteryStarts::initStarts()
    {
        for (int i = 0; i != LOTTERY_STARTS_POSITION_DATA.size(); i++)
        {
            this->addItemWithIndex(i);
        }
        this->initItemsColor();
        //this->initGift();
    }

    void GameVictoryLotteryStarts::initItemsColor()
    {
        int gray_begin_index = this->getGrayBeginIndex();
        for (int i = gray_begin_index; i != starts_container_.size(); i++)
        {
            //SpriteTextureController::getInstance()->setGrayShader(starts_container_.at(i));
            starts_container_.at(i)->setGrayEnabled(true);
        }
        //SpriteTextureController::getInstance()->setNormalShader(starts_container_.at(gray_begin_index - 1));
        starts_container_.at(gray_begin_index - 1)->setGrayEnabled(false);

    }

    void GameVictoryLotteryStarts::initStartVisible()
    {
        int gray_begin_index = this->getGrayBeginIndex();
        if (total_start_numble_ < gray_begin_index)
        {
            int begin_index = gray_begin_index - total_start_numble_;
            for (int i = 0; i < begin_index; i++)
            {
                starts_container_.at(i)->setVisible(false);
            }
        }
    }

    //void GameVictoryLotteryStarts::initGift()
    //{
    //    int git_index = this->getGrayBeginIndex() + (LOTTERY_GIFT_DELTA - total_start_numble_ % LOTTERY_GIFT_DELTA) - 1;
    //    this->setGiftTextureWithIndex(git_index);
    //}

    int GameVictoryLotteryStarts::getGrayBeginIndex()
    {
        return floor(LOTTERY_STARTS_POSITION_DATA.size() / 2.0f);;
    }

    //void GameVictoryLotteryStarts::setGiftTextureWithIndex(int index)
    //{
    //    if (starts_container_.find(index) == starts_container_.end())
    //    {
    //        return;
    //    }
    //    SpriteTextureController::getInstance()->setSpriteTexture(LOTTERY_GIFT_PATH, starts_container_.at(index));
    //}

    void GameVictoryLotteryStarts::addItemWithIndex(int index)
    {
        GameVictoryLotteryItemBase* item = this->createStartWithIndex(index);
        this->addChild(item);
        starts_container_.insert(starts_container_.size(), item);
    }

    GameVictoryLotteryItemBase * GameVictoryLotteryStarts::createStartWithIndex(int index)
    {
        GameVictoryLotteryItemBase* start = nullptr;
        if (index == this->getGrayBeginIndex() + (LOTTERY_GIFT_DELTA - total_start_numble_ % LOTTERY_GIFT_DELTA) - 1)
        {
            start = GameVictoryLotteryGiftItem::create();
        }
        else
        {
            start = GameVictoryLotteryStartItem::create();
        }
        this->setStartPosAndRotationAndScaleWithIndex(start, index);
        return start;
    }

    void GameVictoryLotteryStarts::contrarotateStarts()
    {
        GameVictoryLotteryItemBase* first_start = starts_container_.at(0);
        for (int i = 1; i != starts_container_.size(); i++)
        {
            GameVictoryLotteryItemBase* start = starts_container_.at(i);
            int next_index = i - 1;
            start->runAction(cocos2d::MoveTo::create(START_CONTRAROTATE_DURATION, this->getStartPositionWithIndex(next_index)));
            start->runAction(cocos2d::RotateTo::create(START_CONTRAROTATE_DURATION, LOTTERY_STARTS_ROTATION_DATA.at(next_index)));
            start->runAction(cocos2d::ScaleTo::create(START_CONTRAROTATE_DURATION, LOTTERY_STARTS_SCALE_DATA.at(next_index)));
            starts_container_.insert(next_index, start);
        }
        starts_container_.insert(starts_container_.size() - 1, first_start);
        this->setStartPosAndRotationAndScaleWithIndex(first_start, starts_container_.size() - 1);
        first_start->setVisible(true);
        //this->initItemsColor();
        first_start->setGrayEnabled(true);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(START_CONTRAROTATE_DURATION),
            cocos2d::CallFunc::create(CC_CALLBACK_0(GameVictoryLotteryStarts::flyStartsToLottery, this))));
    }

    void GameVictoryLotteryStarts::setStartPosAndRotationAndScaleWithIndex(cocos2d::Node* start, int index)
    {
        start->setPosition(this->getStartPositionWithIndex(index));
        start->setRotation(LOTTERY_STARTS_ROTATION_DATA.at(index));
        start->setScale(LOTTERY_STARTS_SCALE_DATA.at(index));
    }

    cocos2d::Vec2 GameVictoryLotteryStarts::getStartPositionWithIndex(int index)
    {
        return cocos2d::Vec2(LOTTERY_STARTS_POSITION_DATA.at(index).x, LOTTERY_STARTS_POSITION_DATA.at(index).y*SmartScaleController::getInstance()->getPlayAreaZoom());
    }

    void GameVictoryLotteryStarts::popGiftArmature(cocos2d::EventCustom* event)
    {
        cocostudio::Armature* armature = cocostudio::Armature::create(GIFT_ARMATURE_NAME);
        cocos2d::Node* node = cocos2d::Node::create();
        this->addChild(node);
        node->setPositionY(150.0f);
        node->addChild(armature);
        node->addChild(GameAlertMask::create(), -1);
        armature->getAnimation()->playWithIndex(0);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::MovementEventType::COMPLETE)
            {
                this->getEventDispatcher()->dispatchCustomEvent(EVENT_VICTORY_GIFT_ARMATURE_END);
                node->removeFromParent();
            }
        });

    }

    void GameVictoryLotteryStarts::flyStartsToLottery()
    {
        if (fly_points_.empty())
        {
            return;
        }
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath("tubiao01.png");
        sp->setPosition(fly_points_.front());
        fly_points_.pop_front();
        this->addChild(sp);
        GameVictoryLotteryItemBase* item = starts_container_.at(this->getGrayBeginIndex());
        sp->runAction(cocos2d::Sequence::create(cocos2d::MoveTo::create(START_FLY_LOTTERY_DURATION, item->getPosition()),
            cocos2d::CallFunc::create([=]() {
            sp->removeFromParent();
            item->lightenItem();
        }), nullptr));
    }

    void GameVictoryLotteryStarts::lightenStart()
    {
    }

    void GameVictoryLotteryStarts::flyStartsToLotteryBegin(std::deque<cocos2d::Vec2> points)
    {
        fly_points_ = points;
        //this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(2.0f), cocos2d::CallFunc::create([=]() {
            this->flyStartsToLottery();
        //}), nullptr));
    }
    void GameVictoryLotteryStarts::onEnter()
    {
        cocos2d::Node::onEnter();
        this->getEventDispatcher()->addCustomEventListener(EVENT_GAME_VICTORY_LETTERY_ITEM_LIGHTEN, [=](cocos2d::EventCustom* event) {
            this->contrarotateStarts();
        });
        this->getEventDispatcher()->addCustomEventListener(EVENT_POP_VICTORY_GIFT_ARMATURE, CC_CALLBACK_1(GameVictoryLotteryStarts::popGiftArmature, this));
    }
    void GameVictoryLotteryStarts::onExit()
    {
        cocos2d::Node::onExit();
        this->getEventDispatcher()->removeCustomEventListeners(EVENT_GAME_VICTORY_LETTERY_ITEM_LIGHTEN);
    }
    GameVictoryLotteryStarts::~GameVictoryLotteryStarts()
    {

    }
}