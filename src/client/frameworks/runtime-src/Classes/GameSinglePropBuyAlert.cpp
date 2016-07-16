#include "GameSinglePropBuyAlert.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UIButton.h"
#include "XMLTool.h"
#include "SpriteTextureController.h"
#include "UserDataManager.h"
#include "GameAlertMask.h"
const std::string GAME_SINGLE_PROP_BUY_ALERT_CSB_PATH = "GameSinglePropBuyAlert.csb";
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
        return true;
    }

    void GameSinglePropBuyAlert::loadView()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_SINGLE_PROP_BUY_ALERT_CSB_PATH);
        this->addChild(csb_node);

        cocos2d::ui::Button* close_button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("Button_1_1"));
        close_button->addClickEventListener([=](cocos2d::Ref*) {
            this->removeFromParent();
        });

        cocos2d::Sprite* prop_sp = SpriteTextureController::getInstance()->createPropSpriteWithKey(prop_key_);
        cocos2d::Node* prop_bg = csb_node->getChildByName("goumaikuangzhengfangdi_3");
        prop_sp->setScale(prop_bg->getContentSize().width / prop_sp->getContentSize().width*0.8f);
        prop_sp->setPosition(prop_bg->getContentSize().width/2, prop_bg->getContentSize().height/2);
        prop_bg->addChild(prop_sp);

        numble_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName("numbleLabel"));

        cocos2d::Sprite* title = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROP_TO_TITLE_PATH.at(prop_key_));
        title->setPosition(csb_node->getChildByName("tanchuangtou_1")->getPosition());
        csb_node->addChild(title);
    }

    void GameSinglePropBuyAlert::updataNumbleLabel()
    {
        numble_label_->setString(XMLTool::convertIntToString(buy_numble_));
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