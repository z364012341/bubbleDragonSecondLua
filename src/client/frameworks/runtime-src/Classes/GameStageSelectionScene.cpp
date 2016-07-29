#include "GameStageSelectionScene.h"
#include "SpriteTextureController.h"
#include "GameStageSelectionCell.h"
#include "SmartScaleController.h"
#include "UserDataManager.h"
#include "StageDataManager.h"
#include "EnterGameAlert.h"
#include "GameSettingAlert.h"
#include "CCLuaEngine.h"
#include "StageNumble.h"
#include "ButtonEffectController.h"
#include "GameStageVehicle.h"
#include "StageMenuManager.h"
#include "UserCoinInfoBoard.h"
#include "UserDiamondInfoBoard.h"
#include "UserStrengthInfoBoard.h"
#include "GameAlertMask.h"
#include "StageSelectionMenu.h"
#include "GameStoreAlert.h"
#include "GameSignBoardAlert.h"
#include "GameNoviceGuideFactory.h"
#include "GameExitAlert.h"
const std::string GAME_STAGE_SELECTION_CSB_PATH = "GameStageSelectionLayer.csb";
const std::string STAGE_SCROLLVIEW_NAME = "StageScrollView";
const std::string STORE_ALERT_NAME = "STORE_ALERT_NAME";
const std::string SETTING_BUTTON_NAME = "SettingButton";
const std::string SETTING_BUTTON_LINE_NAME = "shengzi_3";
const std::string PUZZLE_BUTTON_NAME = "Puzzle";
const std::string DECALS_BUTTON_NAME = "Button_2_0";
const std::string STORE_BUTTON_NAME = "Button_2_1";
//const std::string SIGN_BUTTON_NAME = "CheckIn";
const std::string STRENGTH_INFO = "StrengthInfo";
//const std::string COIN_INFO = "CoinInfo";
//const std::string DIAMOND_INFO = "DiamondInfo";
const std::string RANKINGLIST_BUTTON = "RankingList";
const std::string GIFT_BUTTON = "Gift";
const std::string CHECKIN_BUTTON = "CheckIn";
const std::string CHALLENGEMODE_BUTTON = "ChallengeMode";
const std::string GAME_STAGE_SCROLLVIEW_BOTTOM_PATH = "StageSelectRes/episode000_hd.jpg";
const std::string GAME_STAGE_ALERT_RENDER_NODE_NAME = "alertNode";
const std::string SETTING_BUTTON_ARMATURE_RENDER_NODE_NAME = "armatureNode";
const std::string GAME_STAGE_SETTING_ANIMATION_NAME = "feichuan";
const float TOP_INFO_POS_Y_PERCENT = 0.9564f;
const float BUTTON_POS_Y_PERCENT_1 = 0.8343f;
const float BUTTON_POS_Y_PERCENT_2 = 0.6988f;
const float BUTTON_POS_Y_PERCENT_3 = 0.6988f;

namespace bubble_second {
    cocos2d::Vec2 GameStageSelectionScene::scrollview_offset_ = cocos2d::Vec2::ZERO;
    GameStageSelectionScene::GameStageSelectionScene()
    {
    }
    GameStageSelectionScene::~GameStageSelectionScene()
    {
    }

    cocos2d::Vec2 GameStageSelectionScene::getScorllViewOffset(int cell_numble)
    {
        //float pos_y = (-cell_vector_.at(cell_numble)->getPositionY() + GAME_STAGE_SCROLLVIEW_CELL_OFFSET_OFFSET)/*scale_zoom_*/;
        StageSelectionMenu* current_menu = StageMenuManager::getInstance()->getCurentStagemenu();
        cocos2d::Vec2 world_pos = current_menu->getParent()->convertToWorldSpace(current_menu->getPosition());
        float pos_y = MAX(0.0f, cell_vector_.at(cell_numble)->getPositionY() + cell_vector_.at(cell_numble)->convertToNodeSpace(world_pos).y - cocos2d::Director::getInstance()->getVisibleSize().height / 2);
        cocos2d::Vec2 point = cocos2d::Vec2(0.0f, -pos_y);
        return point;
        //return cell_position_vector_.at(cell_numble);
    }

    void GameStageSelectionScene::onEnter()
    {
        cocos2d::Layer::onEnter();
        this->addEventListenerCustom();
        this->addMouseEventListener();
        this->addKeyboardEventListener();
    }

    void GameStageSelectionScene::onExit()
    {
        cocos2d::Layer::onExit();
        this->removeEventListenerCustom();
    }

    //void GameStageSelectionScene::screenShot(const bool bIsSave)
    //{
    //    ////使用屏幕尺寸初始化一个空的渲染纹理对象  
    //    //cocos2d::Size sizeWin = cocos2d::Director::getInstance()->getWinSize();
    //    //cocos2d::RenderTexture* textureScreen = cocos2d::RenderTexture::create(sizeWin.width, sizeWin.height, cocos2d::Texture2D::PixelFormat::RGBA8888);
    //    ////清除数据并开始获取  
    //    ////textureScreen->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
    //    //textureScreen->begin();
    //    ////遍历场景节点对象，填充纹理到texure中  
    //    //cocos2d::Director::getInstance()->getRunningScene()->visit();
    //    ////结束获取  
    //    //textureScreen->end();

    //    //if (bIsSave)
    //    //{//保存为PNG图  
    //    //    textureScreen->saveToFile("ScreenShot.png", cocos2d::Image::Format::PNG, true, nullptr);
    //    //}
    //    ////cocos2d::utils::captureScreen([=](bool succeed, const std::string& outputFile) {}, "ScreenShot.png");
    //    cocos2d::utils::captureScreen(nullptr, "ScreenShot.png");
    //}

    cocos2d::Scene * bubble_second::GameStageSelectionScene::createScene()
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        GameStageSelectionScene* layer = GameStageSelectionScene::create();
        //layer->screenShot(true);
        scene->addChild(layer);
        return scene;
    }
    cocos2d::Scene * GameStageSelectionScene::createSceneNextStage()
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        GameStageSelectionScene* layer = GameStageSelectionScene::create();
        layer->enterNextStage();
        scene->addChild(layer);
        return scene;
    }
    cocos2d::Scene * GameStageSelectionScene::createSceneReplayStage()
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        GameStageSelectionScene* layer = GameStageSelectionScene::create();
        scene->addChild(layer);
        layer->popEnterGameAlert();
        return scene;
    }
    bool GameStageSelectionScene::init()
    {
        if (!cocos2d::Layer::init())
        {
            return false;
        }
        this->setName(GAME_STAGE_SELECTION_SCENE_NAME);
        this->loadView();
        this->addStageCell();
        this->addStageVehicle();
        cocos2d::Director::getInstance()->setDisplayStats(true);
        this->popSignBoardAlert();
        //stage_vehicle_->setPositionWithWorldPosition(StageMenuManager::getInstance()->getLastStageWorldPosition());
        //cocos2d::MoveBy * move = cocos2d::MoveBy::create(2.0f, StageMenuManager::getInstance()->getCurrentStagePositionDelta());
     //   stage_vehicle_->runAction(move);



        return true;
    }

    void GameStageSelectionScene::loadView()
    {
        using cocos2d::ui::Button;
        csb_node_ = cocos2d::CSLoader::createNode(GAME_STAGE_SELECTION_CSB_PATH);
        this->addChild(csb_node_);
        scrollview_ = dynamic_cast<ScrollView*>(csb_node_->getChildByName(STAGE_SCROLLVIEW_NAME));

        this->getSettingButton()->addClickEventListener(CC_CALLBACK_1(GameStageSelectionScene::settingButtonFunc, this));

        Button* puzzleButton = dynamic_cast<Button*>(csb_node_->getChildByName(PUZZLE_BUTTON_NAME));
        assert(puzzleButton);
        puzzleButton->addClickEventListener([=](Ref* target) {
            this->gotoPuzzleGame();
        });
        Button* decalsButton = dynamic_cast<Button*>(csb_node_->getChildByName(DECALS_BUTTON_NAME));
        assert(decalsButton);
        decalsButton->addClickEventListener([=](Ref*) {
            this->popDecalsBookAlert();
        });
        Button* storeButton = dynamic_cast<Button*>(csb_node_->getChildByName(STORE_BUTTON_NAME));
        assert(storeButton);
        storeButton->addClickEventListener([=](Ref*) {
            this->popStoreAlert();
        });
        //Button* signButton = dynamic_cast<Button*>(csb_node_->getChildByName(SIGN_BUTTON_NAME));
        //assert(signButton);
        //signButton->addClickEventListener([=](Ref*) {
            //this->popSignBoardAlert();
        //});

        this->layout();
    }

    cocos2d::ui::Button * bubble_second::GameStageSelectionScene::getSettingButton()
    {
        return dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(SETTING_BUTTON_NAME));
    }

    void GameStageSelectionScene::layout()
    {
        float visibleHeight = cocos2d::Director::getInstance()->getVisibleSize().height;
        //csb_node_->getChildByName(STRENGTH_INFO)->setPositionY(visibleHeight*TOP_INFO_POS_Y_PERCENT);

        //csb_node_->getChildByName(COIN_INFO)->addChild(UserCoinInfoBoard::create());
        //csb_node_->getChildByName(COIN_INFO)->setPositionY(visibleHeight*TOP_INFO_POS_Y_PERCENT);
        this->addChild(UserCoinInfoBoard::create());
        this->addChild(UserDiamondInfoBoard::create());
        this->addChild(UserStrengthInfoBoard::create());
        //csb_node_->getChildByName(DIAMOND_INFO)->addChild(UserDiamondInfoBoard::create());
        //csb_node_->getChildByName(DIAMOND_INFO)->setPositionY(visibleHeight*TOP_INFO_POS_Y_PERCENT);

        csb_node_->getChildByName(RANKINGLIST_BUTTON)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_1);
        csb_node_->getChildByName(GIFT_BUTTON)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_1);

        csb_node_->getChildByName(CHECKIN_BUTTON)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_2);
        csb_node_->getChildByName(PUZZLE_BUTTON_NAME)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_2);

        csb_node_->getChildByName(CHALLENGEMODE_BUTTON)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_3);

        ButtonEffectController::setButtonsZoomScale(csb_node_);
    }

    void GameStageSelectionScene::addStageCell()
    {
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        const float cell_x = visibleSize.width / 2;
        float cell_y = 0.0f;
        float scrollview_height = 0.0;
        GameStageSelectionCell *cell = nullptr;
        while (true)
        {
            cell = GameStageSelectionCell::create();
            if (!cell)
            {
                break;
            }
            cell->setPosition(cell_x, cell_y);
            //cell_position_vector_.push_back(cocos2d::Vec2(0.0f, cell_y));
            scrollview_->addChild(cell);
            cell_y += cell->getBackgroundHeight();
            scrollview_height += cell->getBackgroundHeight();
            cell_vector_.pushBack(cell);
        }
        cocos2d::Sprite* bottom_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_STAGE_SCROLLVIEW_BOTTOM_PATH);
        scrollview_bottom_height_ = bottom_sp->getBoundingBox().size.height;
        bottom_sp->setPosition(cell_x, scrollview_bottom_height_ / -2);
        //cocos2d::Layer *slayer = cocos2d::Layer::create();
        //slayer->addChild(bottom_sp);
        scrollview_->setInnerContainerSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize().width, scrollview_height));
        scrollview_->addChild(bottom_sp);
        //滚动方向  
        scrollview_->setDirection(ScrollView::Direction::VERTICAL);
        scrollview_->setBounceEnabled(true);
        scrollview_->setScrollBarEnabled(false);
        scrollview_->setContentSize(cocos2d::Size(cocos2d::Director::getInstance()->getVisibleSize()));
        scrollview_->addEventListener(CC_CALLBACK_2(GameStageSelectionScene::scrollViewMoveCallback, this));
        this->adjustingScrollviewPosition();
    }

    void GameStageSelectionScene::scrollViewMoveCallback(cocos2d::Ref *pSender, cocos2d::ui::ScrollView::EventType eventType)
    {
        ScrollView* view = dynamic_cast<ScrollView*>(pSender);
        auto layout = view->getInnerContainer();
        float currentY = layout->getPositionY();
        if (currentY > scrollview_bottom_height_)
        {
            layout->setPosition(cocos2d::Vec2(0.0f, scrollview_bottom_height_));
        }
        if (-currentY > layout->getContentSize().height - view->getContentSize().height)
        {
            layout->setPosition(cocos2d::Vec2(0, -layout->getContentSize().height + view->getContentSize().height));
        }
        scrollview_offset_ = layout->getPosition();
    }

    void GameStageSelectionScene::addEventListenerCustom()
    {
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        auto listener = cocos2d::EventListenerCustom::create(EVENT_POP_ENTER_GAME_ALERT, [=](cocos2d::EventCustom* event) {
            this->popEnterGameAlert();
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        dispatcher->addCustomEventListener(EVENT_SETTING_ALERT_CLOSE, [=](cocos2d::EventCustom* event) {
            this->setSettingButtonEnabled(true);
            setting_armature_->removeFromParent();
        });
        dispatcher->addCustomEventListener(EVENT_UNLOCK_STAGE_MENU, [=](cocos2d::EventCustom* event) {
            this->popEnterGameAlert();
        });
        dispatcher->addCustomEventListener(EVENT_POP_GAME_STORE, [=](cocos2d::EventCustom* event) {
            this->popStoreAlert();
        });
    }

    void GameStageSelectionScene::removeEventListenerCustom()
    {
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->removeCustomEventListeners(EVENT_POP_ENTER_GAME_ALERT);
        dispatcher->removeCustomEventListeners(EVENT_SETTING_ALERT_CLOSE);
        dispatcher->removeCustomEventListeners(EVENT_UNLOCK_STAGE_MENU);
        dispatcher->removeCustomEventListeners(EVENT_POP_GAME_STORE);
    }

    void GameStageSelectionScene::addMouseEventListener()
    {
        // 创建监听器
        auto mouseListener = cocos2d::EventListenerMouse::create();
        mouseListener->onMouseScroll = [=](cocos2d::Event *event) {
            cocos2d::EventMouse* event_mouse = (cocos2d::EventMouse*)event;
            float offs_y = MIN(0.0f, scrollview_->getInnerContainerPosition().y + event_mouse->getScrollY()*MOUSE_SCROLL_Y_SENSITIVITY);
            scrollview_->setInnerContainerPosition(cocos2d::Vec2(0.0f, offs_y));
        };
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
    }

    void GameStageSelectionScene::addKeyboardEventListener()
    {
        auto listener = cocos2d::EventListenerKeyboard::create();
        listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*) {
            if (code == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE)
            {
                if (this->getChildByName("GameExitAlertName") != nullptr)
                {
                    return;
                }
                    GameExitAlert* exit_alert = GameExitAlert::create();
                    exit_alert->setName("GameExitAlertName");
                    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
                    exit_alert->setPosition(visibleSize.width / 2, visibleSize.height / 2);
                    exit_alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
                    this->addChild(exit_alert);
            }
        };
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    }

    void GameStageSelectionScene::popEnterGameAlert()
    {
        if (!StageDataManager::getInstance()->isInStageNumbleRange(StageDataManager::getInstance()->getCurrentLevel()))
        {
            return;
        }
        EnterGameAlert* alert = EnterGameAlert::create();
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        this->getAlertRenderNode()->addChild(alert);
    }

    void GameStageSelectionScene::enterNextStage()
    {
        if (UserDataManager::getInstance()->isUnlockWithStageNumble(StageDataManager::getInstance()->getCurrentLevel()))
        {
            return;
        }
        UserDataManager::getInstance()->addUnlockStageNumble();
        StageMenuManager::getInstance()->getCurentStagemenu()->preUnlockStage();

        stage_vehicle_->moveVehicle(cocos2d::CallFunc::create([=]() {
            if (cell_vector_.at(StageDataManager::getInstance()->getCurrentCell())->isInCell(StageDataManager::getInstance()->getCurrentLevel()))
            {
                StageDataManager::getInstance()->setCurrentCell(StageDataManager::getInstance()->getCurrentCell());
            }
            else
            {
                StageDataManager::getInstance()->setCurrentCell(StageDataManager::getInstance()->getCurrentCell() + 1);
            }
            StageDataManager::getInstance()->setCurrentLevel(StageDataManager::getInstance()->getCurrentLevel() + 1);
            StageMenuManager::getInstance()->getCurentStagemenu()->unlockStage();
        }));
    }

    void bubble_second::GameStageSelectionScene::gotoPuzzleGame()
    {
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
        // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
        auto runtimeEngine = RuntimeEngine::getInstance();
        runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
        runtimeEngine->start();
#else
        //cocos2d::LuaEngine::getInstance()->executeScriptFile("src/ReplacePuzzlePlayScene.lua");
        cocos2d::LuaEngine::getInstance()->executeString("cc.Director:getInstance():replaceScene(require(PUZZLE_SELECTED_SCENE_PATH):createScene());");
#endif
    }

    void GameStageSelectionScene::popSettingAlert()
    {
        this->popAlert(GameSettingAlert::create());
    }

    void GameStageSelectionScene::popDecalsBookAlert()
    {
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
        // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
        auto runtimeEngine = RuntimeEngine::getInstance();
        runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
        runtimeEngine->start();
#else
        //cocos2d::LuaEngine::getInstance()->executeScriptFile("src/ReplacePuzzlePlayScene.lua");
        cocos2d::LuaEngine::getInstance()->executeScriptFile("src/app/popDecalsBookAlert.lua");
#endif
    }

    void GameStageSelectionScene::popStoreAlert()
    {
        if (this->getAlertRenderNode()->getChildByName(STORE_ALERT_NAME) == nullptr)
        {
            GameStoreAlert* store_alert = GameStoreAlert::create();
            store_alert->setName(STORE_ALERT_NAME);
            this->popAlert(store_alert);
        }
    }

    void GameStageSelectionScene::popAlert(cocos2d::Node * alert)
    {
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        this->getAlertRenderNode()->addChild(alert);
    }

    void GameStageSelectionScene::popSignBoardAlert()
    {
        GameSignBoardAlert* alert = GameSignBoardAlert::create();
        if (alert == nullptr)
        {
            return;
        }
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visibleSize.width / 2, visibleSize.height);
        alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        this->addChild(alert);
    }

    cocos2d::Node * GameStageSelectionScene::getAlertRenderNode()
    {
        return csb_node_->getChildByName(GAME_STAGE_ALERT_RENDER_NODE_NAME);
    }

    void GameStageSelectionScene::adjustingScrollviewPosition()
    {
        //static bool fire_flag = true;
        if (first_flag_)
        {//第一次要移动到最新的关卡
            //auto p = this->getScorllViewOffset(UserDataManager::getInstance()->getPresentCell());
            scrollview_->setInnerContainerPosition(this->getScorllViewOffset(UserDataManager::getInstance()->getPresentCell()));
            //scrollview_->setInnerContainerPosition(cocos2d::Vec2::ZERO);
            first_flag_ = false;
            StageMenuManager::getInstance()->getCurentStagemenu()->turnOnBlink();
        }
        else
        {
            scrollview_->setInnerContainerPosition(scrollview_offset_);
        }
    }

    void GameStageSelectionScene::addStageVehicle()
    {
        stage_vehicle_ = GameStageVehicle::create();
        scrollview_->addChild(stage_vehicle_);
        stage_vehicle_->setPositionWithWorldPosition(StageMenuManager::getInstance()->getCurrentStageWorldPosition());
    }

    void GameStageSelectionScene::settingButtonFunc(cocos2d::Ref * target)
    {
        //if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
        //{
            GameAlertMask* mask = GameAlertMask::createTransparentMask();
            this->getAlertRenderNode()->addChild(mask);
            this->setSettingButtonEnabled(false);
            setting_armature_ = cocostudio::Armature::create(GAME_STAGE_SETTING_ANIMATION_NAME);
            setting_armature_->setPosition(this->getSettingButton()->getPosition());
            csb_node_->getChildByName(SETTING_BUTTON_ARMATURE_RENDER_NODE_NAME)->addChild(setting_armature_);
            setting_armature_->getAnimation()->playWithIndex(0);
            this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.2f), cocos2d::CallFunc::create([=]() {
                this->popSettingAlert();
                mask->removeFromParent();
            })));
            //setting_armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            //    if (movementType == cocostudio::COMPLETE)
            //    {
            //        mask->removeFromParent();
            //    }
            //});
        //}
    }

    void GameStageSelectionScene::setSettingButtonEnabled(bool enabled)
    {
        this->getSettingButton()->setVisible(enabled);
        csb_node_->getChildByName(SETTING_BUTTON_LINE_NAME)->setVisible(enabled);
    }
    //void GameStageSelectionScene::popEnterPropsNoviceGuideAlert(cocos2d::Node * alert)
    //{
    //    if (alert == nullptr)
    //    {
    //        return;
    //    }
    //    if (alert_ != nullptr)
    //    {
    //        alert_->removeFromParent();
    //    }
    //    alert_ = alert;
    //    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    //    alert_->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    //    alert_->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
    //    this->addChild(alert_);
    //}
}