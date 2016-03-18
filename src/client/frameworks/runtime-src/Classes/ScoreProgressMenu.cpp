#include "ScoreProgressMenu.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UIImageView.h"
#include "ScoreProgressStart.h"
#include "SpriteTextureController.h"
const std::string PROGRESS_TIMER_PATH = "jindutiao.png";//进度条
const std::string PROGRESS_TIMER_BACKGROUND_PATH = "jindutiaokuang.png";//进度条背景
float PROGRESS_TIMER_MIN = 25.0f;
float PROGRESS_TIMER_MAX = 75.0f;
float PROGRESS_TIMER_DISTANCE = PROGRESS_TIMER_MAX - PROGRESS_TIMER_MIN;
float PROGRESS_TIMER_OVAL_A = 111.0f;
float PROGRESS_TIMER_OVAL_POW_A = 12321.0f;
//float PROGRESS_TIMER_OVAL_B = 77.0f;
float PROGRESS_TIMER_OVAL_POW_B = 5929.0f;
namespace bubble_second {
    ScoreProgressMenu::ScoreProgressMenu():percent_(PROGRESS_TIMER_MIN)
    {
    }

    ScoreProgressMenu::~ScoreProgressMenu()
    {
    }

    bool ScoreProgressMenu::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->initScoreMenu();
        this->setName(GAME_TOP_INFO_NAME);
        this->getScoreProgressTimer()->setPercentage(percent_);
        return true;
    }
    void ScoreProgressMenu::initScoreMenu()
    {
        //score_progress_node_ = cocos2d::CSLoader::createNode(GAME_TOP_INFO_CSB);
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROGRESS_TIMER_BACKGROUND_PATH);
        bg->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_TOP);
        this->addChild(bg);

        cocos2d::Sprite* timerSprite = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROGRESS_TIMER_PATH);
        //timerSprite->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_TOP);
        score_progress_timer_ = cocos2d::ProgressTimer::create(timerSprite);
        score_progress_timer_->setReverseDirection(true);
        //score_progress_timer_->setMidpoint(cocos2d::Vec2(0.5, 1.0));
        //score_progress_timer_->setBarChangeRate(cocos2d::Vec2(0.5, 1));
        //score_progress_timer_->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_TOP);
        score_progress_timer_->setType(cocos2d::ProgressTimer::Type::RADIAL);

        this->addChild(score_progress_timer_);
    }

    void ScoreProgressMenu::initStartSprite()
    {
        for (auto var : this->getStartNumbleModule().getPercentModule())
        {
            ScoreProgressStart* start = ScoreProgressStart::createWithPercent(var.second);
            start->setPosition(this->getStartPositionWithPercent(var.second));
            this->addChild(start);
            start_sprite_map_.insert(var.first, start);
        }
    }

    cocos2d::Vec2 ScoreProgressMenu::getStartPositionWithPercent(float percent)
    {
        //auto image = dynamic_cast<cocos2d::ui::ImageView*>(score_progress_node_->getChildByName(SCORE_PROGRESS_BORDER_NAME));
        //(image);


        cocos2d::Rect rect = this->getScoreProgressTimer()->getBoundingBox();
        float x = PROGRESS_TIMER_OVAL_A*1.9 * percent - PROGRESS_TIMER_OVAL_A;
        float y = sqrt((1 - pow(x, 2)/ PROGRESS_TIMER_OVAL_POW_A)*PROGRESS_TIMER_OVAL_POW_B);
        return cocos2d::Vec2(x, -y);
    }

    void ScoreProgressMenu::initialStartNumble(StartNumbleModule start_numble)
    {
        start_numble_ = start_numble;
        this->initStartSprite();
    }

    cocos2d::ProgressTimer* ScoreProgressMenu::getScoreProgressTimer()
    {
        return score_progress_timer_;
    }

    void ScoreProgressMenu::increaseProgressTimer()
    {
        static float direction = 0.0f;
        if (this->isScheduled(GAME_SCORE_PROGRESS_SCHEDULE_KEY))
        {
            return;
        }
        //float percent = getScoreProgressTimer()->getPercentage();
        float percent = this->getPercentage();
        //direction = getScoreProgressTimer()->getPercentage() == 0.0f?1.0f:-1.0f;
        direction = percent == 0.0f ? 1.0f : -1.0f;
        this->schedule([=](float) {
            //this->getScoreProgressTimer()->setPercentage(percentage);
            this->setPercentage(this->getPercentage() + GAME_SCORE_PROGRESS_TIMER_PER_INCREASE_PERCENT*direction);
            //this->controlStartLight(getScoreProgressTimer()->getPercentage());
            this->controlStartLight(this->getPercentage());
            //if (this->isCompletedGoalPercent(getScoreProgressTimer()->getPercentage()))
            if (this->isCompletedGoalPercent(this->getPercentage()))
            {
                this->unschedule(GAME_SCORE_PROGRESS_SCHEDULE_KEY);
            }
            if (this->isCompletedBack(percent - GAME_SCORE_PROGRESS_TIMER_BACK_PERCENT))
            {
                direction = 1.0f;
            }
        }, GAME_SCORE_PROGRESS_SCHEDULE_KEY);
    }

    void ScoreProgressMenu::setGoalPercent(float percent)
    {
        percent_ = percent;
    }

    float ScoreProgressMenu::getGoalPercent()
    {
        return percent_;
    }

    void ScoreProgressMenu::setLastScore(int last_score)
    {
        last_score_ = last_score;
    }

    int ScoreProgressMenu::getLastScore()
    {
        return last_score_;
    }

    bool ScoreProgressMenu::isEqualLastScore(int score)
    {
        return last_score_ == score;
    }

    bool ScoreProgressMenu::isCompletedGoalPercent(float percent)
    {
        return percent >= this->getGoalPercent() || percent>=100.0f;
    }

    bool ScoreProgressMenu::isCompletedBack(float percent)
    {
        //return getScoreProgressTimer()->getPercentage() <= percent || getScoreProgressTimer()->getPercentage() <= 0.0f;
        return this->getPercentage() <= percent || this->getPercentage() <= 0.0f;
    }

    StartNumbleModule ScoreProgressMenu::getStartNumbleModule()
    {
        return start_numble_;
    }

    void ScoreProgressMenu::controlStartLight(float percent)
    {
        for (auto var : start_sprite_map_)
        {
            var.second->controlLightWithPercent(percent/100);
        }
    }

    void ScoreProgressMenu::setPercentage(float percent)
    {
        this->getScoreProgressTimer()->setPercentage(PROGRESS_TIMER_DISTANCE / 100 * percent + PROGRESS_TIMER_MIN);
    }

    float ScoreProgressMenu::getPercentage()
    {
        return (this->getScoreProgressTimer()->getPercentage() - PROGRESS_TIMER_MIN)/ PROGRESS_TIMER_DISTANCE * 100;
    }

    void ScoreProgressMenu::setScoreProgressTimerPercent(float score)
    {
        if (!this->isEqualLastScore(score))
        {
            this->setLastScore(score);
            this->setGoalPercent(getStartNumbleModule().getPercentWithScore(score));
            this->increaseProgressTimer();
        }
    }

    int ScoreProgressMenu::getStartOnNumble()
    {
        int numble = 0;
        for (auto var : start_sprite_map_)
        {
            if (var.second->startIsOn())
            {
                ++numble;
            }
        }
        return numble;
    }
}