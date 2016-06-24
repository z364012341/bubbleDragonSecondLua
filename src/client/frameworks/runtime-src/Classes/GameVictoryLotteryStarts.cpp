#include "GameVictoryLotteryStarts.h"
#include "SpriteTextureController.h"
const std::string LOTTERY_START_PATH = "faguangxingxing.PNG";
const float STARTS_CIRCLE_RADIUS = 500.0f;
const float START_ANGLE_DELTA = 11.0f;
cocos2d::Vec2 TOP_POSITION(0.0f, STARTS_CIRCLE_RADIUS);
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
        this->initStarts();
        return true;
    }

    void GameVictoryLotteryStarts::initStarts()
    {
        for (int i = -4; i < 8; i++)
        {
            this->addStartWithAngle(START_ANGLE_DELTA*i);
        }
    }

    void GameVictoryLotteryStarts::addStartWithAngle(float angle)
    {
        cocos2d::Sprite* start = SpriteTextureController::getInstance()->createGameSpriteWithPath(LOTTERY_START_PATH);
        start->setPosition(TOP_POSITION.rotateByAngle(cocos2d::Vec2::ZERO, CC_DEGREES_TO_RADIANS(-angle)));
        start->setRotation(angle);
        float numble = 1-abs(angle / 100);
        start->setScale(numble*numble);
        this->addChild(start);
        SpriteTextureController::getInstance()->setGrayShader(start);
    }


    GameVictoryLotteryStarts::~GameVictoryLotteryStarts()
    {

    }
}