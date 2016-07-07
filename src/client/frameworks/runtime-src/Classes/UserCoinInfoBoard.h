//*******************************************************************************
//类名称   : UserCoinInfoBoard
//功能     : <游戏关卡场景上面的金币面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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
        //随机的流光动画
        void playRandomTimeAnimation();
        void updateNumbleLabel();
        void setNumbleLabelString(int numble);
        //金币label的数字滚动增加或者减少
        void rollCoinLabelNumble(cocos2d::EventCustom* event);
        //void rollCoinLabelNumbleBegin();
        //void rollCoinLabelNumbleEnd();
    private:
        cocostudio::Armature* armature_ = nullptr;
        cocos2d::ui::TextBMFont* numble_label_ = nullptr;
        //int coin_numble_ = 0;
        cocos2d::EventListenerCustom * listener_ = nullptr;
        int coin_numble_offset_ = 0;
	};
}
#endif //_USER_COIN_INFO_BOARD_H_