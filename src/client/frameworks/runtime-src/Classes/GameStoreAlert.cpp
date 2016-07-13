#include "GameStoreAlert.h"
#include "cocostudio\CocoStudio.h"
#include "GameAlertMask.h"
#include "GameStoreItemFactory.h"
#include "ButtonEffectController.h"
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
        ButtonEffectController::setButtonsZoomScale(csb_node);
        this->addChild(csb_node);

        gift_item_ = csb_node->getChildByName("gift_item");
        assert(gift_item_);
        gift_listview_ = dynamic_cast<cocos2d::ui::ListView*>(gift_item_->getChildByName("gift_ListView"));
        assert(gift_listview_);
        this->addListViewItems(gift_listview_, GameStoreItemFactory::getInstance()->getGiftListViewItems());
        gift_button_ = dynamic_cast<cocos2d::ui::Button *>(csb_node->getChildByName("gift_button"));
        assert(gift_button_);
        gift_button_->addClickEventListener([=](cocos2d::Ref*) {
            this->changeGoodsShelfDisplay(gift_item_, gift_button_);
        });

        diamond_item_ = csb_node->getChildByName("diamond_item");
        assert(diamond_item_);
        diamond_listview_ = dynamic_cast<cocos2d::ui::ListView*>(diamond_item_->getChildByName("diamond_ListView"));
        assert(diamond_listview_);
        this->addListViewItems(diamond_listview_, GameStoreItemFactory::getInstance()->getDiamondListViewItems());
        diamond_button_ = dynamic_cast<cocos2d::ui::Button *>(csb_node->getChildByName("diamond_button"));
        assert(diamond_button_);
        diamond_button_->addClickEventListener([=](cocos2d::Ref*) {
            this->changeGoodsShelfDisplay(diamond_item_, diamond_button_);
        });

        props_item_ = csb_node->getChildByName("props_item");
        assert(props_item_);
        props_listview_ = dynamic_cast<cocos2d::ui::ListView*>(props_item_->getChildByName("props_ListView"));
        assert(props_listview_);
        this->addListViewItems(props_listview_, GameStoreItemFactory::getInstance()->getPropsListViewItems());
        props_button_ = dynamic_cast<cocos2d::ui::Button *>(csb_node->getChildByName("props_button"));
        assert(props_button_);
        props_button_->addClickEventListener([=](cocos2d::Ref*) {
            this->changeGoodsShelfDisplay(props_item_, props_button_);
        });

        cocos2d::ui::Button* close_button = dynamic_cast<cocos2d::ui::Button *>(csb_node->getChildByName("closeButton"));
        assert(close_button);
        close_button->addClickEventListener([=](cocos2d::Ref*) {
            this->removeFromParent();
        });
    }

    void GameStoreAlert::addListViewItems(cocos2d::ui::ListView * listview, cocos2d::Vector<cocos2d::Node*> items)
    {
        listview->setScrollBarEnabled(false);
        for (auto item_node : items)
        {
            cocos2d::ui::Layout* layout = cocos2d::ui::Layout::create();
            float scale = listview->getContentSize().width / item_node->getContentSize().width;
            item_node->setScale(scale);
            layout->setContentSize(item_node->getContentSize()*scale);
            layout->addChild(item_node);
            listview->pushBackCustomItem(layout);
        }
    }

    void GameStoreAlert::setSelectedItemVisibleFalse()
    {
        gift_item_->setVisible(false);
        diamond_item_->setVisible(false);
        props_item_->setVisible(false);

        gift_button_->setVisible(true);
        diamond_button_->setVisible(true);
        props_button_->setVisible(true);

        gift_listview_->jumpToTop();
        diamond_listview_->jumpToTop();
        props_listview_->jumpToTop();
    }

    void GameStoreAlert::changeGoodsShelfDisplay(cocos2d::Node * tag_item, cocos2d::ui::Button * tag_button)
    {
        this->setSelectedItemVisibleFalse();
        tag_item->setVisible(true);
        tag_button->setVisible(false);
    }


    GameStoreAlert::~GameStoreAlert()
    {
    }
}