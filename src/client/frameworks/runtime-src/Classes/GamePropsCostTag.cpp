#include "GamePropsCostTag.h"
#include "cocostudio\CocoStudio.h"
#include "GameTextInfo.h"
#include "UserDataManager.h"
#include "ui\UITextBMFont.h"
#include "SpriteTextureController.h"
//const std::string TAG_CSB_PATH = "GamePropsCoinTag.csb";
//const std::string COIN_SPRITE_NAME = "jinbi_3";
//const std::string DIAMOND_SPRITE_NAME = "zuanshi_6";
//const std::string SELECTED_SPRITE_NAME = "selected_sprite";
//const std::string NUMBLE_LABEL_NAME = "cost_label";
const std::string SELECTED_SPRITE_PATH = "xuanzhong.PNG";
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
        int numble = cost_numble_;
        if (this->getSelectedState())
        {
            numble *= -1;
        }
        this->getEventDispatcher()->dispatchCustomEvent(EVENT_ROLL_COIN_BOARD_LABEL, &numble);
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
    int GamePropsCostTag::getCostNumble()
    {
        return cost_numble_;
    }
    bool GamePropsCostTag::initWithKey(const std::string & prop_key)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::ValueMap commodity_data = GameTextInfo::getInstance()->getCommodityDataWithKey(prop_key);
        this->initWithCostTypeAndNumble(commodity_data.begin()->first, commodity_data.begin()->second);
        return true;
    }
    bool GamePropsCostTag::initWithCostTypeAndNumble(const std::string & cost_type, cocos2d::Value numble)
    {
        assert(cost_type == GAME_DIAMOND_KEY || cost_type == GAME_COIN_KEY);
        //cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(TAG_CSB_PATH);
        //this->addChild(csb_node);

        cost_key_ = cost_type;
        cost_numble_ = numble.asInt();
        //SpriteTextureController::getInstance()->setSpriteTexture(SpriteTextureController::getInstance()->getPropPathWithKey(cost_key_), dynamic_cast<cocos2d::Sprite*>(csb_node->getChildByName(COIN_SPRITE_NAME)));

        selected_sprite_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(SELECTED_SPRITE_PATH);
        selected_sprite_->setPosition(90.0f, 23.0f);
        selected_sprite_->setVisible(false);
        selected_sprite_->setScale(2.0f);
        this->addChild(selected_sprite_, 1);
        //cocos2d::ui::TextBMFont* numble_label = dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(NUMBLE_LABEL_NAME));
        //numble_label->setString(numble.asString());
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createPropSpriteWithKey(cost_key_);
        cocos2d::ui::TextBMFont* numble_label = SpriteTextureController::getInstance()->createWhitePurpleFnt(numble.asString());
        float width = sp->getContentSize().width + numble_label->getContentSize().width;
        sp->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_LEFT);
        sp->setPositionX(width/-2);
        this->addChild(sp);
        numble_label->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_RIGHT);
        numble_label->setPositionX(width / 2);
        this->addChild(numble_label);

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
    GamePropsCostTag * GamePropsCostTag::createWithCostTypeAndNumble(const std::string & cost_type, cocos2d::Value numble)
    {
        GamePropsCostTag *pRet = new(std::nothrow) GamePropsCostTag();
        if (pRet && pRet->initWithCostTypeAndNumble(cost_type, numble))
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
    void GamePropsCostTag::onEnter()
    {
        cocos2d::Node::onEnter();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_ENTER_PROPS_PAY, [=](cocos2d::EventCustom* event) {
            if (this->getSelectedState())
            {
                this->pay();
            }
        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener_, 1);

    }
    void GamePropsCostTag::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
    }
}