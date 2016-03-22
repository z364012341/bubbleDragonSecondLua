#include "GameStageVehicle.h"
#include "BubbleSecondConstant.h"
const std::string FIRE_BALLON_ARMATURE_NAME = "qiting";
const std::string FIRE_BALLON_ANIMATION_STANDBY_NAME = "daiji";
namespace bubble_second {
	GameStageVehicle::GameStageVehicle()
	{
	}


	GameStageVehicle::~GameStageVehicle()
	{
	}

	bool GameStageVehicle::init()
	{
		if (!cocos2d::Node::init())
		{
			return false;
		}
		this->addArmature();
		return true;
	}

	void GameStageVehicle::addArmature()
	{
		vehicle_armature_ = cocostudio::Armature::create(FIRE_BALLON_ARMATURE_NAME);
		this->addChild(vehicle_armature_);
		this->playStandbyAnimation();
	}

	void GameStageVehicle::playStandbyAnimation()
	{
		vehicle_armature_->getAnimation()->play(FIRE_BALLON_ANIMATION_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
	}
}