#include "GameNoviceGuideFactory.h"
#include "XMLTool.h"
#include "SpriteTextureController.h"
#include "GameStartButton.h"
#include "GameAlertMask.h"
namespace bubble_second {
    GameNoviceGuideFactory::GameNoviceGuideFactory()
    {
        begin_guide_data_vm_["1"] = "xsydyx01.png";
        begin_guide_data_vm_["2"] = "xsydyx02.png";
        begin_guide_data_vm_["3"] = "xsydyx03.png";
        begin_guide_data_vm_["4"] = "xsydyx04.png";
        begin_guide_data_vm_["5"] = "xsydyx05.png";
        begin_guide_data_vm_["6"] = "xsydyx06.png";
        begin_guide_data_vm_["7"] = "xsydyx07.png";
        begin_guide_data_vm_["8"] = "xsydyx08.png";
        begin_guide_data_vm_["9"] = "xsydyx09.png";
        begin_guide_data_vm_["10"] = "xsydyx10.png";
        begin_guide_data_vm_["11"] = "xsydyx11.png";
        begin_guide_data_vm_["12"] = "xsydyx12.png";
        begin_guide_data_vm_["14"] = "xsydyx14.png";
        begin_guide_data_vm_["16"] = "xsydyx06.png";
        begin_guide_data_vm_["17"] = "xsydyx17.png";
        begin_guide_data_vm_["18"] = "xsydyx18.png";
        begin_guide_data_vm_["21"] = "xsydyx21.png";
        begin_guide_data_vm_["22"] = "xsydyx22.png";
        begin_guide_data_vm_["27"] = "xsydyx27.png";
        begin_guide_data_vm_["42"] = "xsydyx47.png";
        begin_guide_data_vm_["57"] = "xsydyx57.png";
        begin_guide_data_vm_["72"] = "xsydyx71.png";
        begin_guide_data_vm_["132"] = "xsydyx132.png";
        for (auto var : begin_guide_data_vm_)
        {
            begin_guide_data_[XMLTool::convertStringToInt(var.first)] = var.second.asString();
        }
    }


    GameNoviceGuideFactory::~GameNoviceGuideFactory()
    {
    }
    cocos2d::Node * GameNoviceGuideFactory::createGameBeginNoviceGuide(int stage_index)
    {
        if (begin_guide_data_.find(stage_index) == begin_guide_data_.end())
        {
            return nullptr;
        }
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(begin_guide_data_[stage_index]);
        GameStartButton* button = GameStartButton::createButtonStartForm();
        button->addButtonClickEventListener([=](cocos2d::Ref*) {cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CONTINUE); });
        cocos2d::Node* node = cocos2d::Node::create();
        node->addChild(bg);
        button->setPositionY(-200.0f);
        node->addChild(button);
        node->addChild(GameAlertMask::create(), -1);
        return node;
    }
}