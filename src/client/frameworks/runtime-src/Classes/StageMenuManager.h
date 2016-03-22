//*******************************************************************************
//������   : StageMenuManager
//����     : <���뾫������������߼�>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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