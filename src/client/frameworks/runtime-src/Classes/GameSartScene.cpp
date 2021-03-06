#include "GameSartScene.h"
#include "cocostudio\CocoStudio.h"
#include "GameStartButton.h"
#include "GameStageSelectionScene.h"
#include "SmartScaleController.h"
#include "GameAlertMask.h"
const std::string  GAME_SART_SCENE_CSB_PATH = "GameStartLayer.csb";
const std::string  GAME_LOGO_NAME = "logopaopaolong_1";
namespace bubble_second {
    //cocos2d::Scene * GameSartScene::createScene()
    //{
    //    cocos2d::Scene* scene = cocos2d::Scene::create();
    //    GameSartScene* layer = GameSartScene::create();
    //    scene->addChild(layer);
    //    return scene;
    //}
    GameSartScene::GameSartScene()
    {
    }


    GameSartScene::~GameSartScene()
    {
    }
    bool GameSartScene::init()
    {
        if (!cocos2d::Layer::init())
        {
            return false;
        }
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(GAME_SART_SCENE_CSB_PATH);
        this->addChild(csb_node);
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        csb_node->getChildByName(GAME_LOGO_NAME)->setPositionY(visibleSize.height*0.8352f);
        //auto a = 1 / SmartScaleController::getInstance()->getPlayAreaZoom();
        //csb_node->getChildByName("Sprite_2")->setScale(SmartScaleController::getInstance()->getFixedHeightZoom());

        GameStartButton* button = GameStartButton::createButtonPinkForm();
        button->setPosition(visibleSize.width*0.5f, visibleSize.height*0.3f);
        this->addChild(button);
        button->addButtonClickEventListener([=](cocos2d::Ref*) {
            this->removeFromParent();
        });

        GameAlertMask* mask = GameAlertMask::createTransparentMask();
        mask->setPosition(visibleSize.width/2, visibleSize.height/2);
        this->addChild(mask, -1);
        return true;
    }

}