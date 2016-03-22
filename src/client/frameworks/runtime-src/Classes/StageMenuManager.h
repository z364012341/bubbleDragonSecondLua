//*******************************************************************************
//类名称   : StageMenuManager
//功能     : <分离精灵的纹理创建的逻辑>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAGE_MENU_MANAGER_H_
#define _STAGE_MENU_MANAGER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
	class StageMenuManager
	{
	public:
		GETINSTANCE_FUNC(StageMenuManager);
		~StageMenuManager();
		void setCurrentStageMenu(cocos2d::Node* menu);
		void setLastStageMenu(cocos2d::Node* menu);
		cocos2d::Vec2 getCurrentStageWorldPosition() const;
		cocos2d::Vec2 getLastStageWorldPosition() const;
	private:
		StageMenuManager();
	private:
		cocos2d::Node* current_menu_ = nullptr;
		cocos2d::Node* last_menu_ = nullptr;
	};
}
#endif //_STAGE_MENU_MANAGER_H_