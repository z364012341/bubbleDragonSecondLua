#include "StageMenuManager.h"

namespace bubble_second {
	StageMenuManager::StageMenuManager()
	{
	}

	StageMenuManager::~StageMenuManager()
	{
	}

	void StageMenuManager::setCurrentStageMenu(cocos2d::Node* menu)
	{
		current_menu_ = menu;
	}

	void StageMenuManager::setLastStageMenu(cocos2d::Node* menu)
	{
		last_menu_ = menu;
	}

	cocos2d::Vec2 StageMenuManager::getCurrentStageWorldPosition() const
	{
		return current_menu_->getParent()->convertToWorldSpace(current_menu_->getPosition());
	}

	cocos2d::Vec2 StageMenuManager::getLastStageWorldPosition() const
	{
		return last_menu_->getParent()->convertToWorldSpace(last_menu_->getPosition());
	}
}