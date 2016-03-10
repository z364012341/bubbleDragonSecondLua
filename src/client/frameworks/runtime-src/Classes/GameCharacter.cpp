#include "GameCharacter.h"
#include "GameCharacterFactory.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"

namespace bubble_second {
	GameCharacter::GameCharacter()
	{
		charactor_armature_1_ = nullptr;
		charactor_armature_2_ = nullptr;
	}


	GameCharacter::~GameCharacter()
	{
	}

	//void GameCharacter::onEnter()
	//{
	//    Sprite::onEnter();
	//}

	//void GameCharacter::onExit()
	//{
	//    Sprite::onExit();
	//    cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
	//}

	//bool GameCharacter::initWithName(const std::string& name)
	//{
	//    if (!Sprite::init())
	//    {
	//        return false;
	//    }
	//    this->setTypeWithName(name);

	//    auto listener = cocos2d::EventListenerTouchOneByOne::create();
	//    listener->setSwallowTouches(true);
	//    listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::touchToChangeTexture, GamePlayController::getInstance());
	//    listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::touchToMoveCharecter, GamePlayController::getInstance());
	//    cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	//    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	//    return true;
	//}

	//void GameCharacter::setTypeWithName(const std::string& name)
	//{
	//    SpriteTextureController::getInstance()->setSpriteTexture(GameCharacterFactory::getInstance()->getPathWithName(name), this);
	//    this->setName(name);
	//}

	//bool GameCharacter::touchToChangeTexture(cocos2d::Touch* touch, cocos2d::Event* event)
	//{   
	//    //auto sprite = dynamic_cast<cocos2d::Sprite*>(event->getCurrentTarget());
	//    auto gamescene = dynamic_cast<GameScene*>(this->getParent()->getParent());
	//    if (cocos2d::Rect(touch->getLocation(), cocos2d::Size(0.0f, 0.0f)).intersectsRect(this->getSelfRect()))
	//    {
	//        this->setTypeWithName(GameCharacterFactory::getInstance()->getChangePathWithName(this->getName()));
	//        return true;
	//    }

	//    return false;
	//}
	//void GameCharacter::changeTexture()
	//{
	//    //this->setTypeWithName(GameCharacterFactory::getInstance()->getChangePathWithName(this->getName()));
	//}
	bool GameCharacter::init()
	{
		if (!cocos2d::Node::init())
		{
			return false;
		}
		this->addCharacterArmature();
		this->playStandbyAnimation();
		return true;
	}

	void GameCharacter::onEnter()
	{
		cocos2d::Node::onEnter();
		this->addEventListenerCustom();
	}

	void GameCharacter::onExit()
	{
		cocos2d::Node::onExit();
		this->removeEventListenerCustom();
	}

	void GameCharacter::addEventListenerCustom()
	{
		auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
		dispatcher->addCustomEventListener(EVENT_SHOOT_PREPARE_BUBBLE, CC_CALLBACK_1(GameCharacter::playShootBubbleAnimation, this));
	}

	void GameCharacter::removeEventListenerCustom()
	{
		auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
		dispatcher->removeCustomEventListeners(EVENT_SHOOT_PREPARE_BUBBLE);
	}

	void GameCharacter::addCharacterArmature()
	{
		charactor_armature_1_ = cocostudio::Armature::create(GAME_CHARACTER_ARMATURE_LAOHU_NAME);
		charactor_armature_1_->setScale(CHARACTER_ARMATURE_SCALE);
		//charactor_armature_1_->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
		this->addChild(charactor_armature_1_);

		charactor_armature_2_ = cocostudio::Armature::create(GAME_CHARACTER_ARMATURE_LAOHU2_NAME);
		charactor_armature_2_->setScale(CHARACTER_ARMATURE_SCALE);
		charactor_armature_2_->setVisible(false);
		this->addChild(charactor_armature_2_);
	}
	void GameCharacter::playStandbyAnimation()
	{
		auto armature = this->getCharactorArmature();
		armature->getAnimation()->play(GAME_CHARACTER_LAOHU_ANIMATION_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
		//this->playLoopAnimationWithName(GAME_CHARACTER_LAOHU_ANIMATION_STANDBY_NAME);
	}
	void GameCharacter::playShootBubbleAnimation(cocos2d::EventCustom* event)
	{
        GamePlayController::getInstance()->shootPrepareBubble();
        float angle = *static_cast<float*>(event->getUserData());
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(CHARACTER_SHOOT_BUBBLE_DELAYTIME), cocos2d::CallFunc::create([=]() {
            //CCLOG("angle: %f", angle);
            if (angle >= CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_1)
            {
                this->playShootAnimation1();
            }
            else if (angle >= -10.0f)
            {
                this->playShootAnimation2();
            }
            else
            {
                this->playShootAnimation3();
            }
        }));
        this->runAction(seq);
	}

	void GameCharacter::playShootAnimation1()
	{
		this->playNotLoopAnimationWithName(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_1);
	}

	void GameCharacter::playShootAnimation2()
	{
		this->playNotLoopAnimationWithName(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_2);
	}

	void GameCharacter::playShootAnimation3()
	{
		this->getCharactorArmature()->setVisible(false);
		cocostudio::Armature* armature = this->getCharactorArmature2();
		armature->setVisible(true);
		//armature->getAnimation()->stop();
		armature->getAnimation()->play(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_3, SPECIAL_BUBBLE_EFFECT_DURATION, false);
		armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
			if (movementType == cocostudio::COMPLETE && !isDefeat())
			{
				armature->setVisible(false);
				this->getCharactorArmature()->setVisible(true);
			}
		});
	}

    void GameCharacter::playLegendaryAnimation()
    {
        //this->playNotLoopAnimationWithName(GAME_CHARACTER_ANIMATION_LEGENDARY_NAME);
    }

    void GameCharacter::playVictoryAnimation()
    {
        this->playLoopAnimationWithName(GAME_CHARACTER_ANIMATION_VICTORY_NAME);
    }

    void GameCharacter::playDefeatAnimation()
    {
        //auto armature = this->getCharactorArmature();
        //armature->getAnimation()->stop();
        //this->setDefeatFlag(true);
        //armature->getAnimation()->play(GAME_CHARACTER_ANIMATION_DEFEAT_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
    }

    cocostudio::Armature * GameCharacter::getCharactorArmature()
    {
        return charactor_armature_1_;
    }

	cocostudio::Armature * GameCharacter::getCharactorArmature2()
	{
		return charactor_armature_2_;
	}

    void GameCharacter::playNotLoopAnimationWithName(const std::string& name)
    {
        auto armature = this->getCharactorArmature();
        armature->getAnimation()->stop();
        armature->getAnimation()->play(name, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE && !isDefeat())
            {
                this->playStandbyAnimation();
            }
        });
    }

    void GameCharacter::playLoopAnimationWithName(const std::string & name)
    {
        //auto armature = this->getCharactorArmature();
        //armature->getAnimation()->stop();
        //armature->getAnimation()->play(name, SPECIAL_BUBBLE_EFFECT_DURATION, true);
    }

    void GameCharacter::setDefeatFlag(bool flag)
    {
        defeat_flag_ = flag;
    }

    bool GameCharacter::isDefeat()
    {
        return defeat_flag_;
    }
}