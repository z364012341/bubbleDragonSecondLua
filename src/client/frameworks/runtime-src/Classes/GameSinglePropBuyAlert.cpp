#include "GameSinglePropBuyAlert.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UIButton.h"
#include "ui\UIScale9Sprite.h"
#include "XMLTool.h"
#include "SpriteTextureController.h"
#include "UserDataManager.h"
#include "GameAlertMask.h"
#include "ButtonEffectController.h"
#include "GameBuyStoreMannager.h"
#include "GameStoreItemFactory.h"
const std::string GAME_SINGLE_PROP_BUY_ALERT_CSB_PATH = "GameSinglePropBuyAlert.csb";
const std::string GAME_SINGLE_PROP_BUY_BUTTON_ITEM_CSB_PATH = "PropBuyButtonItem.csb";
const std::map<std::string, std::string> PROP_TO_TITLE_PATH = {
    { BUBBLE_COLOR_BOMB_PROP_KEY , "fonts/goumaicaiqiuwenzi.PNG" },
    { BUBBLE_WOODEN_HAMMER_PROP_KEY , "fonts/goumaixiaomuchuiwenzi.PNG" },
    { BUBBLE_STAVES_PROP_KEY , "fonts/goumaimofabangwenzi.PNG" },
    { BUBBLE_BIG_BOMB_BOMB_PROP_KEY , "fonts/goumaizhadanwenzi.PNG" },
    { PUZZLE_SEARCH_PROP_KEY , "fonts/wenzikuaisutishi.png" },
    { PUZZLE_ADD_TIME_PROP_KEY , "fonts/wenzishijiandaoliu.png" },
    { PUZZLE_BIG_EYES_PROP_KEY , "fonts/wenzitiankongzhiyan.png"}
};
namespace bubble_second {
    GameSinglePropBuyAlert::GameSinglePropBuyAlert()
    {
    }

    bool GameSinglePropBuyAlert::initWithPropKey(const std::string& prop_key)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        prop_key_ = prop_key;
        this->loadView();
        this->addChild(GameAlertMask::create(), -1);
        this->updataNumbleLabel();
        return true;
    }

    void GameSinglePropBuyAlert::loadView()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_SINGLE_PROP_BUY_ALERT_CSB_PATH);
        this->addChild(csb_node);
        ButtonEffectController::setButtonsZoomScale(csb_node);

        cocos2d::ui::Button* close_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("Button_1_1"));
        close_button->addClickEventListener([=](cocos2d::Ref*) {
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_CONTINUE);
        });

        cocos2d::Sprite* prop_sp = SpriteTextureController::getInstance()->createPropSpriteWithKey(prop_key_);
        cocos2d::Node* prop_bg = csb_node->getChildByName("goumaikuangzhengfangdi_3");
        prop_sp->setScale(prop_bg->getContentSize().width / prop_sp->getContentSize().width*0.8f);
        prop_sp->setPosition(prop_bg->getContentSize().width / 2, prop_bg->getContentSize().height / 2);
        prop_bg->addChild(prop_sp);

        numble_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName("numbleLabel"));

        cocos2d::Sprite* title = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROP_TO_TITLE_PATH.at(prop_key_));
        title->setPosition(csb_node->getChildByName("tanchuangtou_1")->getPosition());
        csb_node->addChild(title);

        cocos2d::ui::Button* add_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("addButton"));
        add_button->addClickEventListener([=](cocos2d::Ref*) {
            this->addBuyNumble();
        });

        cocos2d::ui::Button* cut_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("cutButton"));
        cut_button->addClickEventListener([=](cocos2d::Ref*) {
            this->cutBuyNumble();
        });

        cocos2d::Node* button_label_node = cocos2d::CSLoader::createNode(GAME_SINGLE_PROP_BUY_BUTTON_ITEM_CSB_PATH);
        cost_data_ = GameStoreItemFactory::getInstance()->getPropUnitPriceData(prop_key_);
        SpriteTextureController::getInstance()->setSpriteTexture(SpriteTextureController::getInstance()->getPropPathWithKey(cost_data_.begin()->first), dynamic_cast<cocos2d::Sprite*>(button_label_node->getChildByName("jinbi_1")));
        cost_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName("numbleLabel"));
        cocos2d::ui::Button* buy_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("Button_4"));
        buy_button->getRendererNormal()->addChild(button_label_node);
        button_label_node->setPosition(cocos2d::Vec2(buy_button->getRendererNormal()->getContentSize().width / 2, buy_button->getRendererNormal()->getContentSize().height / 2));
        buy_button->addClickEventListener([=](cocos2d::Ref*) {
            if (buy_numble_ > 0)
            {
                cocos2d::ValueMap buy_data;
                cocos2d::ValueMap commodity_data;
                commodity_data[prop_key_] = buy_numble_;
                buy_data[ITEM_PROPS_DATA_KEY] = commodity_data;
                buy_data[STORE_COST_TYPE_KEY] = cost_data_.begin()->first;
                buy_data[STORE_COST_KEY] = this->getTotalCost();
                GameBuyStoreMannager::getInstance()->buyPropsWithTokens(buy_data);
            }
            this->getEventDispatcher()->dispatchCustomEvent(EVENT_CONTINUE);
        });
    }

    void GameSinglePropBuyAlert::updataNumbleLabel()
    {
        numble_label_->setString(XMLTool::convertIntToString(buy_numble_));
        this->updataCostLabel();
    }

    void GameSinglePropBuyAlert::updataCostLabel()
    {
        cost_label_->setString(XMLTool::convertIntToString(this->getTotalCost()));
    }

    int GameSinglePropBuyAlert::getTotalCost()
    {
        return this->calculateBuyCost(buy_numble_);
    }

    int GameSinglePropBuyAlert::calculateBuyCost(int numble)
    {
        return numble*cost_data_.begin()->second.asInt();
    }

    void GameSinglePropBuyAlert::addBuyNumble()
    {
        if (this->calculateBuyCost(buy_numble_ + 1) <= UserDataManager::getInstance()->getPropsNumbleWithKey(cost_data_.begin()->first))
        {
            buy_numble_ = MIN(buy_numble_ + 1, 99);
            this->updataNumbleLabel();
        }
    }

    void GameSinglePropBuyAlert::cutBuyNumble()
    {
        buy_numble_ = MAX(buy_numble_ - 1, 0);
        this->updataNumbleLabel();
    }

    GameSinglePropBuyAlert * GameSinglePropBuyAlert::createWithPropKey(const std::string& prop_key)
    {
        GameSinglePropBuyAlert* p = new (std::nothrow) GameSinglePropBuyAlert();
        if (p && p->initWithPropKey(prop_key))
        {
            p->autorelease();
            return p;
        }
        delete p;
        p = nullptr;
        return nullptr;
    }

    GameSinglePropBuyAlert::~GameSinglePropBuyAlert()
    {
    }
}