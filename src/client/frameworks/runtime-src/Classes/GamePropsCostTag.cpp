#include "GamePropsCostTag.h"
#include "cocostudio\CocoStudio.h"
#include "GameTextInfo.h"
#include "UserDataManager.h"
#include "ui\UITextBMFont.h"
const std::string TAG_CSB_PATH = "GamePropsCoinTag.csb";
const std::string COIN_SPRITE_NAME = "jinbi_3";
const std::string DIAMOND_SPRITE_NAME = "zuanshi_6";
const std::string SELECTED_SPRITE_NAME = "selected_sprite";
const std::string NUMBLE_LABEL_NAME = "cost_label";
namespace bubble_second {
    GamePropsCostTag::GamePropsCostTag()
    {
    }


    GamePropsCostTag::~GamePropsCostTag()
    {
    }
    void GamePropsCostTag::changeSelectedState()
    {
        selected_sprite_->setVisible(!selected_sprite_->isVisible());
    }
    bool GamePropsCostTag::getSelectedState()
    {
        return selected_sprite_->isVisible();
    }
    bool GamePropsCostTag::canPay()
    {
        return cost_numble_ <= UserDataManager::getInstance()->getPropsNumbleWithKey(cost_key_);
    }
    void GamePropsCostTag::pay()
    {
        UserDataManager::getInstance()->cutPropsNumbleWithKey(cost_key_, cost_numble_);
    }
    bool GamePropsCostTag::initWithKey(const std::string & prop_key)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(TAG_CSB_PATH);
        this->addChild(csb_node);

        cocos2d::ValueMap commodity_data = GameTextInfo::getInstance()->getCommodityDataWithKey(prop_key);
        cost_key_ = commodity_data.begin()->first;
        assert(cost_key_ == GAME_COIN_KEY || cost_key_ == GAME_DIAMOND_KEY);
        cost_numble_ = commodity_data.begin()->second.asInt();
        assert(cost_numble_>=0);
        if (cost_key_ == GAME_DIAMOND_KEY)
        {
            csb_node->getChildByName(COIN_SPRITE_NAME)->setVisible(false);
            csb_node->getChildByName(DIAMOND_SPRITE_NAME)->setVisible(true);
        }

        selected_sprite_ = dynamic_cast<cocos2d::Sprite*>(csb_node->getChildByName(SELECTED_SPRITE_NAME));

        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(NUMBLE_LABEL_NAME))->setString(commodity_data.begin()->second.asString());
        return true;
    }
    GamePropsCostTag* GamePropsCostTag::createWithKey(const std::string& prop_key)
    {
        GamePropsCostTag *pRet = new(std::nothrow) GamePropsCostTag();
        if (pRet && pRet->initWithKey(prop_key))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    GamePropsCostTag * GamePropsCostTag::createDecalsLotteryBeginTag()
    {
        return GamePropsCostTag::createWithKey(COMMODITY_DECALS_LOTTERY_BEGIN_KEY);
    }
    GamePropsCostTag * GamePropsCostTag::createDecalsLotteryContinueTag()
    {
        return GamePropsCostTag::createWithKey(COMMODITY_DECALS_LOTTERY_CONTINUE_KEY);
    }
}