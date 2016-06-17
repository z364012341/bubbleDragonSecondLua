//*******************************************************************************
//������   : UserCoinInfoBoard
//����     : <��Ϸ�ؿ���������Ľ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _USER_COIN_INFO_BOARD_H_
#define _USER_COIN_INFO_BOARD_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UITextBMFont.h"
namespace bubble_second {
	class UserCoinInfoBoard : public cocos2d::Node
	{
	public:
		CREATE_FUNC(UserCoinInfoBoard);
		~UserCoinInfoBoard();
        void onEnter() override;
        void onExit() override;
	private:
		UserCoinInfoBoard();
		bool init();
        void playRandomTimeAnimation();
        void updateNumbleLabel();
    private:
        cocostudio::Armature* armature_ = nullptr;
        cocos2d::ui::TextBMFont* numble_label_ = nullptr;
        cocos2d::EventListenerCustom * listener_ = nullptr;
	};
}
#endif //_USER_COIN_INFO_BOARD_H_