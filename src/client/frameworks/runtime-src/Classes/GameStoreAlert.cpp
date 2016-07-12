#include "GameStoreAlert.h"
#include "cocostudio\CocoStudio.h"
#include "GameAlertMask.h"
#include "GameStoreItemFactory.h"
#include "ui\UILayout.h"
const std::string GAME_STORE_ALERT_CSB_PATH = "GameStoreAlert.csb";
namespace bubble_second {
    GameStoreAlert::GameStoreAlert()
    {
    }

    bool GameStoreAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create(), -1);
        this->loadView();
        return true;
    }

    void GameStoreAlert::loadView()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_STORE_ALERT_CSB_PATH);
        this->addChild(csb_node);
        gift_item_ = csb_node->getChildByName("gift_item");
        assert(gift_item_);
        gift_listview_ = dynamic_cast<cocos2d::ui::ListView*>(gift_item_->getChildByName("gift_ListView"));
        assert(gift_listview_);
        this->addListViewItems(gift_listview_, GameStoreItemFactory::getInstance()->getGiftListViewItems());
    }

    void GameStoreAlert::addListViewItems(cocos2d::ui::ListView * listview, cocos2d::Vector<cocos2d::Node*> items)
    {
        listview->setScrollBarEnabled(false);
        for (auto item_node : items)
        {
            cocos2d::ui::Layout* layout = cocos2d::ui::Layout::create();
            layout->setContentSize(item_node->getContentSize());
            layout->addChild(item_node);
            listview->pushBackCustomItem(layout);
        }
    }


    GameStoreAlert::~GameStoreAlert()
    {
    }
}