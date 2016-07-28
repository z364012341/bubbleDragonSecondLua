#include "LoadingScene.h"
#include "StageDataManager.h"
#include "GameTextInfo.h"
#include "UserDataManager.h"
#include "SpriteTextureController.h"
#include "GameStageSelectionScene.h"
#include "SmartScaleController.h"
#include "ScoreWidgetManager.h"
#include "PuzzleStageDataManager.h"
#include "PuzzleStoreItemFactory.h"
#include "DecalsFactory.h"
#include "GameCharactorNameManager.h"
#include "GameSartScene.h"
#include "GameStoreItemFactory.h"
#include "GameAudioController.h"
//#include "json/rapidjson.h"
//#include "json/document.h"
namespace bubble_second {
    cocos2d::Scene * LoadingScene::createScene()
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        LoadingScene* layer = LoadingScene::create();
        scene->addChild(layer);
        return scene;
    }

    LoadingScene::LoadingScene()
    {
        //cocos2d::Data data = cocos2d::CCFileUtils::getInstance()->getDataFromFile("tt.json");
        //unsigned char *pBytes = data.getBytes();
        //char *buf = new char[data.getSize() + 1];
        //strncpy(buf, (char*)data.getBytes(), data.getSize());
        //buf[data.getSize()] = 0;
        //rapidjson::Document document;
        //document.Parse<rapidjson::kParseDefaultFlags>(buf);    
        //delete[] buf;
        //if (document.HasParseError())
        //    return;
        //rapidjson::Value &optionValue = document["result_data"]["options"][0]["judge_opt_title"];
        ////if (optionValue.IsArray())
        //auto sssss = optionValue.GetString();
        //CCLOG("---------------%s", optionValue.GetString());
        ////for (int i = 0; i < optionValue.Size(); i++)
        ////{
        ////    std::string title = optionValue[i]["judge_opt_title"].GetString();

        ////}
        //rapidjson::Document document2;
        //document2.Parse<rapidjson::kParseDefaultFlags>(optionValue.GetString());
        //if (document2.HasParseError())
        //    return;
        //rapidjson::Value &optionValue2 = document2[0]["tpl_order"];
        //auto s1 = optionValue2.GetString();
        //CCLOG(s1);
    }

    LoadingScene::~LoadingScene()
    {
    }

    bool LoadingScene::init()
    {
        if (!Layer::init())
        {
            return false;
        }
        this->addBackground();
        this->runAction(cocos2d::CallFunc::create([=]() {
            this->beginLoading();
        }));
        return true;
    }

    void LoadingScene::beginLoading()
    {
        GameAudioController::getInstance()->loadAudioFile();
        GameAudioController::getInstance()->playGameLaunchMusic();
        StageDataManager::getInstance()->initStageData();
        GameTextInfo::getInstance()->plistToMap();
        UserDataManager::getInstance()->readDataFile();
        SpriteTextureController::getInstance()->addResourcesTexture();
        ScoreWidgetManager::getInstance()->readBoneDateFromFile();
        PuzzleStageDataManager::getInstance()->loadPuzzleStageData();
        PuzzleStoreItemFactory::getInstance()->loadItemData();
        DecalsFactory::getInstance()->loadDecalsData();
        GameCharactorNameManager::getInstance()->initNamesData();
        GameStoreItemFactory::getInstance()->loadItemsData();

        cocos2d::Scene* scene = GameStageSelectionScene::createScene();
        scene->addChild(GameSartScene::create());
        cocos2d::Director::getInstance()->replaceScene(scene);
    }

    void LoadingScene::addBackground()
    {
        auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        cocos2d::LayerColor* layer = cocos2d::LayerColor::create(cocos2d::Color4B::ORANGE, visibleSize.width, visibleSize.height);
        this->addChild(layer);


        cocos2d::Label* label = cocos2d::Label::createWithSystemFont("   Loading...", "", 80 * SmartScaleController::getInstance()->getPlayAreaZoom());
        label->setPosition(visibleSize.width/2, visibleSize.height/2);
        this->addChild(label);
    }
}