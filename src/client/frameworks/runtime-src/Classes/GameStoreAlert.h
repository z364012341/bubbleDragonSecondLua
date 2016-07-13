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
#include "ui\UIButton.h"
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
        //�����е�ѡ��״̬�ı�ǩ����Ϊ���ɼ�(�׵��ִ������Ǹ�)
        void setSelectedItemVisibleFalse();
        //�����ť�л���ʾ�ı�ǩ��listview
        void changeGoodsShelfDisplay(cocos2d::Node* tag_item, cocos2d::ui::Button* tag_button);
    private:
        cocos2d::Node* gift_item_ = nullptr;
        cocos2d::Node* diamond_item_ = nullptr;
        cocos2d::Node* props_item_ = nullptr;

        cocos2d::ui::ListView* gift_listview_ = nullptr;
        cocos2d::ui::ListView* diamond_listview_ = nullptr;
        cocos2d::ui::ListView* props_listview_ = nullptr;

        cocos2d::ui::Button* gift_button_ = nullptr;
        cocos2d::ui::Button* diamond_button_ = nullptr;
        cocos2d::ui::Button* props_button_ = nullptr;
    };
}
#endif