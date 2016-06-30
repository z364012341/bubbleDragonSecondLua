#include "StrengthCountDownLabel.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
#include "UserDataManager.h"
const int STENGTH_NUMBLE_MAX = 5;
const int PER_STENGTH_MINUTE = 6;
const int PER_STENGTH_SECOND = PER_STENGTH_MINUTE * 60;

namespace bubble_second {
    bool StrengthCountDownLabel::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        label_ = SpriteTextureController::getInstance()->createWhitePurpleFnt("");
        label_->setScale(0.55f);
        this->addChild(label_);
        return true;
    }
    StrengthCountDownLabel::StrengthCountDownLabel()
    {
    }

    void StrengthCountDownLabel::countDownBegin()
    {
        if (is_begin_flag_)
        {
            return;
        }
        is_begin_flag_ = true;
        //time_t last_time = last_tiem;
        time_t current_time = time(0);
        time_t delta_time = current_time - UserDataManager::getInstance()->getStrengthLastTime();
        if (delta_time >= (STENGTH_NUMBLE_MAX - strength_numble_)*PER_STENGTH_SECOND)
        {
            UserDataManager::getInstance()->setPropsNumbleWithKey(GAME_STRENGTH_KEY, STENGTH_NUMBLE_MAX);
            this->countDownEnd();
        }
        else
        {
            if (delta_time > PER_STENGTH_SECOND)
            {
                UserDataManager::getInstance()->addPropsNumbleWithKey(GAME_STRENGTH_KEY, delta_time / PER_STENGTH_SECOND);
            }
            time_t count_down_time = PER_STENGTH_SECOND - delta_time % PER_STENGTH_SECOND;
            this->countDownWithTime(count_down_time);
        }

    }

    void StrengthCountDownLabel::countDownEnd()
    {
        UserDataManager::getInstance()->saveStrengthLastTime();
        is_begin_flag_ = false;
    }

    void StrengthCountDownLabel::countDownWithTime(time_t tiem)
    {
        assert(tiem >= 0);
        count_down_time_ = tiem == 0 ? PER_STENGTH_SECOND : tiem;
        cocos2d::Repeat* repeat = cocos2d::Repeat::create(cocos2d::Sequence::createWithTwoActions(cocos2d::CallFunc::create([=]() {
            this->setCountDownLabel(count_down_time_--);
        }), cocos2d::DelayTime::create(1.0f)), count_down_time_);
        this->runAction(cocos2d::Sequence::createWithTwoActions(repeat, cocos2d::CallFunc::create([=]() {
            this->countDownEnd();
            UserDataManager::getInstance()->addPropsNumbleWithKey(GAME_STRENGTH_KEY, 1);
            //this->countDownWithTime(PER_STENGTH_SECOND);
        })));
    }

    void StrengthCountDownLabel::setCountDownLabel(time_t tiem)
    {
        int minute = tiem / 60;
        int second = tiem % 60;
        char str[10];
        sprintf(str, "%02d:%02d", minute, second);
        label_->setString(str);
    }


    StrengthCountDownLabel::~StrengthCountDownLabel()
    {
    }
    void StrengthCountDownLabel::onEnter()
    {
        cocos2d::Node::onEnter();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_UPDATE_PROPS_NUMBLE_LABEL, [=](cocos2d::EventCustom* event) {
            this->updateLabel();
        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener_, 1);
        //this->updateLabel();

    }
    void StrengthCountDownLabel::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
        //UserDataManager::getInstance()->saveStrengthLastTime(time(0) - PER_STENGTH_SECOND + count_down_time_);

    }
    void StrengthCountDownLabel::updateLabel()
    {
        int last_numble = strength_numble_;
        strength_numble_ = UserDataManager::getInstance()->getPropsNumbleWithKey(GAME_STRENGTH_KEY);
        if (strength_numble_ == STENGTH_NUMBLE_MAX)
        {
            label_->setString(GameTextInfo::getInstance()->getTextInfoWithKey(GAME_STRENGTH_MAX_KEY));
            count_down_time_ = 0;
        }
        else
        {
            if (last_numble == STENGTH_NUMBLE_MAX && strength_numble_ == STENGTH_NUMBLE_MAX - 1)
            {
                UserDataManager::getInstance()->saveStrengthLastTime();
            }
            this->countDownBegin();
        }
    }
}