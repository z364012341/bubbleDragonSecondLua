#include "GameStageSelectionScene.h"
#include "SpriteTextureController.h"
#include "GameStageSelectionCell.h"
#include "SmartScaleController.h"
#include "UserDataManager.h"
#include "StageDataManager.h"
#include "EnterGameAlert.h"
#include "GameSettingAlert.h"
#include "cocostudio\CocoStudio.h"
#include "CCLuaEngine.h"
#include "StageNumble.h"
#include "ui\UIButton.h"
const std::string GAME_STAGE_SELECTION_CSB_PATH = "GameStageSelectionLayer.csb";
const std::string STAGE_SCROLLVIEW_NAME = "StageScrollView";
const std::string SETTING_BUTTON_NAME = "SettingButton";
const std::string PUZZLE_BUTTON_NAME = "Puzzle";
const std::string STRENGTH_INFO = "StrengthInfo";
const std::string COIN_INFO = "CoinInfo";
const std::string DIAMOND_INFO = "DiamondInfo";
const std::string RANKINGLIST_BUTTON = "RankingList";
const std::string GIFT_BUTTON = "Gift";
const std::string CHECKIN_BUTTON = "CheckIn";
const std::string CHALLENGEMODE_BUTTON = "ChallengeMode";
const float TOP_INFO_POS_Y_PERCENT = 0.9564f;
const float BUTTON_POS_Y_PERCENT_1 = 0.8343f;
const float BUTTON_POS_Y_PERCENT_2 = 0.6988f;
const float BUTTON_POS_Y_PERCENT_3 = 0.6988f;
namespace bubble_second {
    cocos2d::Vec2 GameStageSelectionScene::scrollview_offset_ = cocos2d::Vec2::ZERO;
    GameStageSelectionScene::GameStageSelectionScene()
    {
        //scale_zoom_ = 1.0f;
    }
    GameStageSelectionScene::~GameStageSelectionScene()
    {
    }

    cocos2d::Vec2 GameStageSelectionScene::getScorllViewOffset(int cell_numble)
    {
        float pos_y = (-cell_vector_.at(cell_numble)->getPositionY() + GAME_STAGE_SCROLLVIEW_CELL_OFFSET_OFFSET)/*scale_zoom_*/;
        cocos2d::Vec2 point = cocos2d::Vec2(0.0f, pos_y);
        return point;
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

    cocos2d::Scene * bubble_second::GameStageSelectionScene::createScene()
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        GameStageSelectionScene* layer = GameStageSelectionScene::create();
        scene->addChild(layer);
        return scene;
    }
    cocos2d::Scene * GameStageSelectionScene::createSceneWithStageData(StageData data)
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        GameStageSelectionScene* layer = GameStageSelectionScene::create();
        layer->enterNextStage(data);
        scene->addChild(layer);
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
        cocos2d::Director::getInstance()->setDisplayStats(false);
        return true;
    }

    void GameStageSelectionScene::loadView()
    {
        using cocos2d::ui::Button;
        csb_node_ = cocos2d::CSLoader::createNode(GAME_STAGE_SELECTION_CSB_PATH);
        this->addChild(csb_node_);
        scrollview_ = dynamic_cast<ScrollView*>(csb_node_->getChildByName(STAGE_SCROLLVIEW_NAME));

        Button* settingButton = dynamic_cast<Button*>(csb_node_->getChildByName(SETTING_BUTTON_NAME));
        settingButton->addTouchEventListener([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                this->popSettingAlert();
            }
        });
        Button* puzzleButton = dynamic_cast<Button*>(csb_node_->getChildByName(PUZZLE_BUTTON_NAME));
        puzzleButton->addTouchEventListener([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                this->gotoPuzzleGame();
            }
        });

        this->layout();
    }

    void GameStageSelectionScene::layout()
    {
        float visibleHeight = cocos2d::Director::getInstance()->getVisibleSize().height;
        csb_node_->getChildByName(STRENGTH_INFO)->setPositionY(visibleHeight*TOP_INFO_POS_Y_PERCENT);
        csb_node_->getChildByName(COIN_INFO)->setPositionY(visibleHeight*TOP_INFO_POS_Y_PERCENT);
        csb_node_->getChildByName(DIAMOND_INFO)->setPositionY(visibleHeight*TOP_INFO_POS_Y_PERCENT);

        csb_node_->getChildByName(RANKINGLIST_BUTTON)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_1);
        csb_node_->getChildByName(GIFT_BUTTON)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_1);

        csb_node_->getChildByName(CHECKIN_BUTTON)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_2);
        csb_node_->getChildByName(PUZZLE_BUTTON_NAME)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_2);

        csb_node_->getChildByName(CHALLENGEMODE_BUTTON)->setPositionY(visibleHeight*BUTTON_POS_Y_PERCENT_3);

    }

    void GameStageSelectionScene::addStageCell()
    {
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        float cell_x = visibleSize.width / 2;
        float cell_y = GAME_STAGE_SCROLLVIEW_CELL_HEIGHT / 2;
        float scrollview_height = 0.0;
        cocos2d::Layer *slayer = cocos2d::Layer::create();
        GameStageSelectionCell *cell = nullptr;
        while (true)
        {
            cell = GameStageSelectionCell::create();
            if (!cell)
            {
                break;
            }
            cell->setPosition(cell_x, cell_y);
            scrollview_->addChild(cell);
            cell_y += GAME_STAGE_SCROLLVIEW_CELL_HEIGHT;
            scrollview_height += GAME_STAGE_SCROLLVIEW_CELL_HEIGHT;
            cell_vector_.pushBack(cell);
        }
        cocos2d::Sprite* bottom_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_STAGE_SCROLLVIEW_BOTTOM_PATH);
        scrollview_bottom_height_ = bottom_sp->getBoundingBox().size.height;
        bottom_sp->setPosition(cell_x, scrollview_bottom_height_ / -2);
        slayer->addChild(bottom_sp);
        scrollview_->setInnerContainerSize(cocos2d::Size(750, scrollview_height));
        scrollview_->addChild(slayer);
        //滚动方向  
        scrollview_->setDirection(ScrollView::Direction::VERTICAL);
        scrollview_->setBounceEnabled(true);
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
            StageData data = *static_cast<StageData*>(event->getUserData());
            this->popEnterGameAlert(data);
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
    }

    void GameStageSelectionScene::removeEventListenerCustom()
    {
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->removeCustomEventListeners(EVENT_POP_ENTER_GAME_ALERT);
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
                if (cocos2d::Node* alert = this->getChildByName(GAME_BASE_ALERT_NAME))
                {
                    alert->removeFromParent();
                }
                else
                {
                    cocos2d::Director::getInstance()->end();
                }
            }
        };
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    }

    void GameStageSelectionScene::popEnterGameAlert(StageData data)
    {
        if (!StageDataManager::getInstance()->isInStageNumbleRange(data.level_numble))
        {
            return;
        }
        StageType type = StageDataManager::getInstance()->getStageTypeWithNumble(data.level_numble);
        EnterGameAlert* alert = EnterGameAlert::create(data.cell_numble, data.level_numble, type);
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        alert->setScale(SmartScaleController::getInstance()->getFixedHeightZoom());
        this->addChild(alert, UI_ZORDER_MENU);
    }

    void GameStageSelectionScene::enterNextStage(StageData data)
    {
        StageData next_data;
        if (cell_vector_.at(data.cell_numble)->isInCell(data.level_numble))
        {
            next_data.cell_numble = data.cell_numble;
        }
        else
        {
            next_data.cell_numble = data.cell_numble + 1;
        }
        next_data.level_numble = data.level_numble + 1;
        this->popEnterGameAlert(next_data);
    }

    void bubble_second::GameStageSelectionScene::gotoPuzzleGame()
    {
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
            // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
            auto runtimeEngine = RuntimeEngine::getInstance();
            runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
            runtimeEngine->start();
#else
			cocos2d::LuaEngine::getInstance()->executeScriptFile("src/ReplacePuzzlePlayScene.lua");
#endif
    }

    void GameStageSelectionScene::popSettingAlert()
    {
        GameSettingAlert* alert = GameSettingAlert::create();
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visibleSize.width / 2, visibleSize.height / 2);
        this->addChild(alert, UI_ZORDER_MENU);
    }

    void GameStageSelectionScene::adjustingScrollviewPosition()
    {
        static bool fire_flag = true;
        if (fire_flag)
        {//第一次要移动到最新的关卡
			scrollview_->setInnerContainerPosition(getScorllViewOffset(UserDataManager::getInstance()->getPresentCell()));
            fire_flag = false;
        }
        else
        {
			scrollview_->setInnerContainerPosition(scrollview_offset_);
        }
    }
}