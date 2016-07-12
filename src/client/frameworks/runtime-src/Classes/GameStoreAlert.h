//*******************************************************************************
//������   : GameStoreAlert
//����     : <��Ϸ���̳����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_STORE_ALERT_H_
#define _GAME_STORE_ALERT_H_
#include "cocos2d.h"
#include "ui\UIListView.h"
namespace bubble_second {
    class GameStoreAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameStoreAlert);
        ~GameStoreAlert();
    private:
        GameStoreAlert();
        bool init();
        void loadView();
        void addListViewItems(cocos2d::ui::ListView* listview, cocos2d::Vector<cocos2d::Node*> items);
    private:
        cocos2d::Node* gift_item_ = nullptr;
        cocos2d::ui::ListView* gift_listview_ = nullptr;
    };
}
#endif