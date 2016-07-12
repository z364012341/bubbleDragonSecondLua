#include "GameStoreItemFactory.h"
#include "UserDataManager.h"
#include "cocostudio\CocoStudio.h"
#include "SpriteTextureController.h"
#include "GameStoreCommodity.h"
#include "ui\UIButton.h"
#include "ui\UIScale9Sprite.h"
#include "ButtonEffectController.h"
#include "GameBuyStoreMannager.h"
const std::string BUY_BUTTON_LABEL_CAB_PATH = "PuzzleStoreItemBuyLabel.csb";
const std::string GAME_STORE_GIFT_ITEM_BUY_COST_LABEL_NAME = "numbleLabel";
const std::string GIFT_ITEM_TEXTURE_PATH_KEY = "gift_texture_path";
const std::string GAME_STORE_ITEM_DATA_PATH = "gameStoreItemData.plist";

const std::string STORE_COST_KEY = "cost"; //花费多少人民币
const std::string STORE_COST_TYPE_KEY = "cost_type"; //货币的种类
const std::string GAME_STORE_GIFT_DATA_KEY = "game_store_gift_data"; //礼包
const std::string GAME_STORE_DIAMOND_DATA_KEY = "game_store_diamond_data"; //钻石
const std::string GAME_STORE_PROPS_DATA_KEY = "game_store_props_data"; //道具
const std::string GAME_STORE_DIAMOND_DISCOUNT_KEY = "game_store_diamond_discount"; //砖石折扣
const std::string GAME_STORE_GIFT_ITEM_CSB_PATH = "GameStoreGiftItem.csb";
const float GAME_STORE_GIFT_COMMODITY_POSITION_RANGE = 550.0f;
namespace bubble_second {

    GameStoreItemFactory::GameStoreItemFactory()
    {
        {
            cocos2d::ValueVector gift_data;
            {
                cocos2d::ValueMap gift_item_data_0;
                gift_item_data_0[GIFT_ITEM_TEXTURE_PATH_KEY] = "libao_chaozhi.PNG";

                cocos2d::ValueVector gift_item_props_data;
                cocos2d::ValueMap gift_item_prop_data_0;
                gift_item_prop_data_0[BUBBLE_COLOR_BOMB_PROP_KEY] = 6;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_0));
                cocos2d::ValueMap gift_item_prop_data_1;
                gift_item_prop_data_1[BUBBLE_STAVES_PROP_KEY] = 7;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_1));
                cocos2d::ValueMap gift_item_prop_data_2;
                gift_item_prop_data_2[BUBBLE_BIG_BOMB_BOMB_PROP_KEY] = 8;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_2));
                cocos2d::ValueMap gift_item_prop_data_3;
                gift_item_prop_data_3[GAME_DIAMOND_KEY] = 288;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_3));

                gift_item_data_0[ITEM_PROPS_DATA_KEY] = gift_item_props_data;
                gift_item_data_0[STORE_COST_KEY] = 16;
                gift_item_data_0[TARGET_ID_KEY] = 0;
                gift_data.push_back(cocos2d::Value(gift_item_data_0));
            }
            {
                cocos2d::ValueMap gift_item_data_1;
                gift_item_data_1[GIFT_ITEM_TEXTURE_PATH_KEY] = "libao_tehui.PNG";

                cocos2d::ValueVector gift_item_props_data;
                cocos2d::ValueMap gift_item_prop_data_0;
                gift_item_prop_data_0[BUBBLE_WOODEN_HAMMER_PROP_KEY] = 5;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_0));
                cocos2d::ValueMap gift_item_prop_data_1;
                gift_item_prop_data_1[BUBBLE_BIG_BOMB_BOMB_PROP_KEY] = 6;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_1));
                cocos2d::ValueMap gift_item_prop_data_2;
                gift_item_prop_data_2[GAME_COIN_KEY] = 70000;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_2));
                cocos2d::ValueMap gift_item_prop_data_3;
                gift_item_prop_data_3[GAME_DIAMOND_KEY] = 180;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_3));

                gift_item_data_1[ITEM_PROPS_DATA_KEY] = gift_item_props_data;
                gift_item_data_1[STORE_COST_KEY] = 12;
                gift_item_data_1[TARGET_ID_KEY] = 0;
                gift_data.push_back(cocos2d::Value(gift_item_data_1));
            }
            {
                cocos2d::ValueMap gift_item_data_2;
                gift_item_data_2[GIFT_ITEM_TEXTURE_PATH_KEY] = "libao_changwan.PNG";

                cocos2d::ValueVector gift_item_props_data;
                cocos2d::ValueMap gift_item_prop_data_0;
                gift_item_prop_data_0[GAME_STRENGTH_KEY] = 18;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_0));
                cocos2d::ValueMap gift_item_prop_data_1;
                gift_item_prop_data_1[BUBBLE_STAVES_PROP_KEY] = 7;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_1));
                cocos2d::ValueMap gift_item_prop_data_2;
                gift_item_prop_data_2[BUBBLE_BIG_BOMB_BOMB_PROP_KEY] = 8;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_2));

                gift_item_data_2[ITEM_PROPS_DATA_KEY] = gift_item_props_data;
                gift_item_data_2[STORE_COST_KEY] = 5;
                gift_item_data_2[TARGET_ID_KEY] = 0;
                gift_data.push_back(cocos2d::Value(gift_item_data_2));
            }
            {
                cocos2d::ValueMap gift_item_data_3;
                gift_item_data_3[GIFT_ITEM_TEXTURE_PATH_KEY] = "libao_xinshou.PNG";

                cocos2d::ValueVector gift_item_props_data;
                cocos2d::ValueMap gift_item_prop_data_0;
                gift_item_prop_data_0[BUBBLE_COLOR_BOMB_PROP_KEY] = 1;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_0));
                cocos2d::ValueMap gift_item_prop_data_1;
                gift_item_prop_data_1[BUBBLE_BIG_BOMB_BOMB_PROP_KEY] = 1;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_1));
                cocos2d::ValueMap gift_item_prop_data_2;
                gift_item_prop_data_2[BUBBLE_WOODEN_HAMMER_PROP_KEY] = 1;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_2));
                cocos2d::ValueMap gift_item_prop_data_3;
                gift_item_prop_data_3[BUBBLE_STAVES_PROP_KEY] = 1;
                gift_item_props_data.push_back(cocos2d::Value(gift_item_prop_data_3));

                gift_item_data_3[ITEM_PROPS_DATA_KEY] = gift_item_props_data;
                gift_item_data_3[STORE_COST_KEY] = 0.1;
                gift_item_data_3[TARGET_ID_KEY] = 0;
                gift_data.push_back(cocos2d::Value(gift_item_data_3));
            }
            store_items_data_[GAME_STORE_GIFT_DATA_KEY] = gift_data;
        }
        {
            cocos2d::ValueVector diamond_data;
            {
                cocos2d::ValueMap diamond_item_data_0;

                cocos2d::ValueMap diamond_item_data;
                diamond_item_data[GAME_DIAMOND_KEY] = 810;

                diamond_item_data_0[ITEM_PROPS_DATA_KEY] = diamond_item_data;
                diamond_item_data_0[GAME_STORE_DIAMOND_DISCOUNT_KEY] = 5;
                diamond_item_data_0[STORE_COST_KEY] = 20;
                diamond_item_data_0[TARGET_ID_KEY] = 0;

                diamond_data.push_back(cocos2d::Value(diamond_item_data_0));
            }
            {
                cocos2d::ValueMap diamond_item_data_1;

                cocos2d::ValueMap diamond_item_data;
                diamond_item_data[GAME_DIAMOND_KEY] = 500;

                diamond_item_data_1[ITEM_PROPS_DATA_KEY] = diamond_item_data;
                diamond_item_data_1[GAME_STORE_DIAMOND_DISCOUNT_KEY] = 6;
                diamond_item_data_1[STORE_COST_KEY] = 15;
                diamond_item_data_1[TARGET_ID_KEY] = 0;

                diamond_data.push_back(cocos2d::Value(diamond_item_data_1));
            }
            {
                cocos2d::ValueMap diamond_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_DIAMOND_KEY] = 500;

                diamond_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                diamond_item_data[GAME_STORE_DIAMOND_DISCOUNT_KEY] = 6;
                diamond_item_data[STORE_COST_KEY] = 15;
                diamond_item_data[TARGET_ID_KEY] = 0;

                diamond_data.push_back(cocos2d::Value(diamond_item_data));
            }
            {
                cocos2d::ValueMap diamond_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_DIAMOND_KEY] = 285;

                diamond_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                diamond_item_data[GAME_STORE_DIAMOND_DISCOUNT_KEY] = 7;
                diamond_item_data[STORE_COST_KEY] = 10;
                diamond_item_data[TARGET_ID_KEY] = 0;

                diamond_data.push_back(cocos2d::Value(diamond_item_data));
            }
            {
                cocos2d::ValueMap diamond_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_DIAMOND_KEY] = 240;

                diamond_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                diamond_item_data[GAME_STORE_DIAMOND_DISCOUNT_KEY] = 5;
                diamond_item_data[STORE_COST_KEY] = 6;
                diamond_item_data[TARGET_ID_KEY] = 0;

                diamond_data.push_back(cocos2d::Value(diamond_item_data));
            }
            {
                cocos2d::ValueMap diamond_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_DIAMOND_KEY] = 75;

                diamond_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                diamond_item_data[GAME_STORE_DIAMOND_DISCOUNT_KEY] = 8;
                diamond_item_data[STORE_COST_KEY] = 6;
                diamond_item_data[TARGET_ID_KEY] = 0;

                diamond_data.push_back(cocos2d::Value(diamond_item_data));
            }
            {
                cocos2d::ValueMap diamond_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_DIAMOND_KEY] = 45;

                diamond_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                diamond_item_data[GAME_STORE_DIAMOND_DISCOUNT_KEY] = 9;
                diamond_item_data[STORE_COST_KEY] = 2;
                diamond_item_data[TARGET_ID_KEY] = 0;

                diamond_data.push_back(cocos2d::Value(diamond_item_data));
            }
            {
                cocos2d::ValueMap diamond_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_DIAMOND_KEY] = 20;

                diamond_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                diamond_item_data[GAME_STORE_DIAMOND_DISCOUNT_KEY] = 10;
                diamond_item_data[STORE_COST_KEY] = 1;
                diamond_item_data[TARGET_ID_KEY] = 0;

                diamond_data.push_back(cocos2d::Value(diamond_item_data));
            }
            store_items_data_[GAME_STORE_DIAMOND_DATA_KEY] = diamond_data;
        }
        {
            cocos2d::ValueVector props_data;
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[BUBBLE_COLOR_BOMB_PROP_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 20;
                props_item_data[TARGET_ID_KEY] = 0;


                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[BUBBLE_BIG_BOMB_BOMB_PROP_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 20;
                props_item_data[TARGET_ID_KEY] = 0;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[BUBBLE_WOODEN_HAMMER_PROP_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 15;
                props_item_data[TARGET_ID_KEY] = 0;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[BUBBLE_STAVES_PROP_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 20;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_STRENGTH_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 10;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_STRENGTH_KEY] = 5;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 30;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_STRENGTH_KEY] = 10;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 50;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[PUZZLE_SEARCH_PROP_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_COIN_KEY;
                props_item_data[STORE_COST_KEY] = 3000;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[PUZZLE_SEARCH_PROP_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_COIN_KEY;
                props_item_data[STORE_COST_KEY] = 3000;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[PUZZLE_BIG_EYES_PROP_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_COIN_KEY;
                props_item_data[STORE_COST_KEY] = 2000;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[PUZZLE_ADD_TIME_PROP_KEY] = 1;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_COIN_KEY;
                props_item_data[STORE_COST_KEY] = 3000;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[BUBBLE_COLOR_BOMB_PROP_KEY] = 3;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 50;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[BUBBLE_BIG_BOMB_BOMB_PROP_KEY] = 3;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 50;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[BUBBLE_WOODEN_HAMMER_PROP_KEY] = 5;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 60;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[BUBBLE_STAVES_PROP_KEY] = 3;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 50;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_COIN_KEY] = 30000;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 50;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_COIN_KEY] = 100000;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 120;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            {
                cocos2d::ValueMap props_item_data;

                cocos2d::ValueMap prop_data;
                prop_data[GAME_COIN_KEY] = 10000;

                props_item_data[STORE_COST_TYPE_KEY] = GAME_DIAMOND_KEY;
                props_item_data[STORE_COST_KEY] = 30;
                props_item_data[TARGET_ID_KEY] = 0;
                props_item_data[ITEM_PROPS_DATA_KEY] = prop_data;
                props_data.push_back(cocos2d::Value(props_item_data));
            }
            store_items_data_[GAME_STORE_PROPS_DATA_KEY] = props_data;
        }
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(store_items_data_, cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_STORE_ITEM_DATA_PATH);
    }


    GameStoreItemFactory::~GameStoreItemFactory()
    {
    }

    cocos2d::Vector<cocos2d::Node*> GameStoreItemFactory::getGiftListViewItems()
    {
        cocos2d::Vector<cocos2d::Node*> items;
        for (auto var : store_items_data_.at(GAME_STORE_GIFT_DATA_KEY).asValueVector())
        {
            cocos2d::ValueMap item_data = var.asValueMap();
            cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_STORE_GIFT_ITEM_CSB_PATH);
            SpriteTextureController::getInstance()->setSpriteTexture(item_data.at(GIFT_ITEM_TEXTURE_PATH_KEY).asString(), dynamic_cast<cocos2d::Sprite*>(csb_node->getChildByName("libaochangwan_15")));
            cocos2d::Node* commodity_bg = csb_node->getChildByName("shangchengkuang2_14");
            float commodity_y = commodity_bg->getContentSize().width / 2;
            float commodity_x_origin = 85.0f;
            for (auto commoditys_data : item_data.at(ITEM_PROPS_DATA_KEY).asValueVector())
            {
                cocos2d::ValueMap data = commoditys_data.asValueMap();
                GameStoreCommodity* commodity = GameStoreCommodity::createWithPropKeyAndNumble(data.begin()->first, data.begin()->second.asString());
                commodity->setPosition(cocos2d::Vec2(commodity_x_origin, commodity_y));
                commodity_x_origin += GAME_STORE_GIFT_COMMODITY_POSITION_RANGE / data.size();
                commodity_bg->addChild(commodity);
            }

            cocos2d::Node* button_label_node = cocos2d::CSLoader::createNode(BUY_BUTTON_LABEL_CAB_PATH);

            dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(GAME_STORE_GIFT_ITEM_BUY_COST_LABEL_NAME))->setString(item_data.at(STORE_COST_KEY).asString()+".00");

            cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("Button_2"));
            ButtonEffectController::setButtonZoomScale(button);
            button->getRendererNormal()->addChild(button_label_node);
            button_label_node->setPosition(cocos2d::Vec2(button->getRendererNormal()->getContentSize().width / 2, button->getRendererNormal()->getContentSize().height / 2));
            button->addClickEventListener([=](cocos2d::Ref*) {
                cocos2d::ValueMap buy_data;
                buy_data[TARGET_ID_KEY] = item_data.at(TARGET_ID_KEY);
                cocos2d::ValueMap commodity_data;
                for (auto var : item_data.at(ITEM_PROPS_DATA_KEY).asValueVector())
                {
                    commodity_data[var.asValueMap().begin()->first] = var.asValueMap().begin()->second;
                }
                buy_data[ITEM_PROPS_DATA_KEY] = commodity_data;
                GameBuyStoreMannager::getInstance()->buyProps(buy_data);
            });
            items.pushBack(csb_node);
        }
        return items;
    }
}