#include "GameSignBoardAlert.h"
#include "cocostudio\CocoStudio.h"
#include "GameAlertMask.h" 
#include "ui\UIButton.h"
const std::string GAME_SIGN_BOARD_ALERT_CSB_PATH = "GameSignBoardAlert.csb";
namespace bubble_second {
    GameSignBoardAlert::GameSignBoardAlert()
    {
    }

    bool GameSignBoardAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_SIGN_BOARD_ALERT_CSB_PATH);
        this->addChild(csb_node);
        GameAlertMask* mask = GameAlertMask::create();
        mask->setPositionY(csb_node->getChildByName("qiandaoban_1")->getContentSize().height/-2);
        this->addChild(mask, -1);

        cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("Button_1"));
        button->addClickEventListener([=](cocos2d::Ref*) {
            this->removeFromParent();
        });
        return true;
    }


    GameSignBoardAlert::~GameSignBoardAlert()
    {
    }
}