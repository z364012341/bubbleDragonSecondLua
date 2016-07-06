#include "StageNumbleBoardController.h"
#include "ui\UITextBMFont.h"
#include "XMLTool.h"
const std::string ENTER_GAME_ALERT_STAGE_NUMBLE_LABEL_NAME = "stageNumbleLabel";
namespace bubble_second {
    StageNumbleBoardController::StageNumbleBoardController()
    {
    }


    StageNumbleBoardController::~StageNumbleBoardController()
    {
    }

    void StageNumbleBoardController::loadView(cocos2d::Node* node, int numble)
    {
        dynamic_cast<cocos2d::ui::TextBMFont*>(node->getChildByName(ENTER_GAME_ALERT_STAGE_NUMBLE_LABEL_NAME))->setString(XMLTool::convertIntToString(numble));
    }
}