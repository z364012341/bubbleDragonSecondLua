#include "PuzzleStoreItemFactory.h"
#include "cocostudio\CocoStudio.h"
#include "XMLTool.h"
#include "ui\UITextBMFont.h"
#include "ui\UIButton.h"
#include "ui\UIScale9Sprite.h"
#include "ButtonEffectController.h"
const std::string PUZZLE_STORE_ITEM_DATA_PATH = "res/puzzleStoreItemData.plist";
const std::string PUZZLE_STORE_ITEM_CAB_PATH = "PuzzleStoreitem.csb";
const std::string BUY_BUTTON_CAB_PATH = "PuzzleStoreItemBuyLabel.csb";
const std::string SHOWNAME_KEY = "showName";
const std::string STORE_NUMBLE_KEY = "numble";
const std::string STORE_NAME_KEY = "storeName";
const std::string STORE_DESCRIPTION_KEY = "description";
const std::string STORE_COST_KEY = "cost";
const std::string STORE_NUMBLE_NAME = "BitmapFontLabel_2_0";
const std::string STORE_NAME_LABEL_NAME = "BitmapFontLabel_1";
const std::string STORE_DESCRIPTION_LABEL_NAME = "BitmapFontLabel_1_0";
const std::string BUY_COST_LABEL_NAME = "numbleLabel";
const std::string BUY_BUTTON_NAME = "Button_1";
namespace bubble_second {
    PuzzleStoreItemFactory::PuzzleStoreItemFactory()
    {
    }


    cocos2d::Node * PuzzleStoreItemFactory::createItemWithIndex(int index)
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(PUZZLE_STORE_ITEM_CAB_PATH);
        cocos2d::ValueMap data = item_data_.at(XMLTool::convertIntToString(index)).asValueMap();
        csb_node->getChildByName(data.at(SHOWNAME_KEY).asString())->setVisible(true);

        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_NUMBLE_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_NUMBLE_NAME))->setString(data.at(STORE_NUMBLE_KEY).asString());

        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_NAME_LABEL_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_NAME_LABEL_NAME))->setString(data.at(STORE_NAME_KEY).asString());

        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_DESCRIPTION_LABEL_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_DESCRIPTION_LABEL_NAME))->setString(data.at(STORE_DESCRIPTION_KEY).asString());

        cocos2d::Node* button_label_node = cocos2d::CSLoader::createNode(BUY_BUTTON_CAB_PATH);
        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(BUY_COST_LABEL_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(BUY_COST_LABEL_NAME))->setString(data.at(STORE_COST_KEY).asString());

        assert(dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName(BUY_BUTTON_NAME)));
        cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName(BUY_BUTTON_NAME));
        ButtonEffectController::setButtonZoomScale(button);
        button->getRendererNormal()->addChild(button_label_node);
        button_label_node->setPosition(cocos2d::Vec2(button->getRendererNormal()->getContentSize().width/2, button->getRendererNormal()->getContentSize().height / 2));
        return csb_node;
    }

    PuzzleStoreItemFactory::~PuzzleStoreItemFactory()
    {
    }
    void PuzzleStoreItemFactory::loadItemData()
    {
        assert(cocos2d::FileUtils::getInstance()->isFileExist(PUZZLE_STORE_ITEM_DATA_PATH));
        item_data_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(PUZZLE_STORE_ITEM_DATA_PATH);  
    }
    int PuzzleStoreItemFactory::getItemTotal()
    {
        return item_data_.size();
    }
}