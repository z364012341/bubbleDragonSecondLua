#include "EnterGameAlert.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
//#include "CenteredMenuItemSprite.h"
#include "GameScene.h"
#include "EnterPropsViewManager.h"
#include "cocostudio/CocoStudio.h"
#include "GameAlertMask.h"
#include "ButtonEffectController.h"
#include "ui\UIScale9Sprite.h"
#include "StageNumbleBoardController.h"
const std::string ENTER_GAME_ALERT_CSB = "EnterGameAlert.csb";
const std::string START_BUTTON_TOP_CSB = "GameStartMenuTop.csb";
const std::string START_BUTTON_BOTTOM_CSB = "GameStartMenuBottom.csb";
const std::string START_BUTTON_CLIPPINT_STENCIL_PATH = "startBubbleBG1.png";
const std::string ENTER_GAME_ALERT_START_NODE_NAME = "startMenuNode";
const std::string ENTER_GAME_ALERT_START_BUTTON_NAME = "startButton";
const std::string ENTER_GAME_ALERT_CLOSE_BUTTON_NAME = "closeButton";
const std::string ENTER_GAME_ALERT_STAGE_NUMBLE_BOARD_NAME = "stageNumbleBoard";
const std::string ENTER_GAME_ALERT_STAGE_TYPE_LABEL_NAME = "stageTypeLabel";
const cocos2d::Vec2 COMMODITY_NODE_POS(-5.0f, -238.7f);
namespace bubble_second {
    EnterGameAlert * EnterGameAlert::create(int cell_numble, int level, const StageType & type)
    {
        EnterGameAlert *pRet = new(std::nothrow) EnterGameAlert();
        if (pRet && pRet->init(cell_numble, level, type))
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
    EnterGameAlert::EnterGameAlert()
    {
    }

    EnterGameAlert::~EnterGameAlert()
    {
    }

    //void EnterGameAlert::onExit()
    //{
    //    GameBaseAlert::onExit();
    //    cocos2d::Director::getInstance()->getTextureCache()->removeUnusedTextures();
    //}

    //void EnterGameAlert::setBeginCallback(const cocos2d::ccMenuCallback & callback)
    //{
    //    begin_item_->setCallback(callback);
    //}
    bool EnterGameAlert::init(int cell_numble, int level, const StageType & type)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        //this->addBackground();
        //this->addTopLabel(level);
        //this->addStageTypeLabel(type);
        //this->addCharactor();
        //this->addPropsShow();
        //this->addButtonItem();
        //this->setBeginCallback([=](cocos2d::Ref*) {
        //    cocos2d::Scene* scene = GameScene::createScene(cell_numble, level);
        //    cocos2d::Director::getInstance()->replaceScene(scene);
        //});
        //this->setCancelCallback([=](cocos2d::Ref*) {
        //    this->removeFromParent();
        //});
        this->addChild(GameAlertMask::create());
        this->loadView();
        this->initStartButton(cell_numble, level);
        this->initCloseButton();
        this->initStageNumbleLabel(level);
        this->initStageTypeLabel(type);
        //SpriteTextureController::getInstance()->addGameBackgroundTexture(cell_numble);
        cocos2d::Node* node = EnterPropsViewManager::getInstance()->createEnterPropsAlert();
        node->setPosition(COMMODITY_NODE_POS);
        this->addChild(node);
        return true;
    }

    void EnterGameAlert::loadView()
    {
        alert_csb_node_ = cocos2d::CSLoader::createNode(ENTER_GAME_ALERT_CSB);
        this->addChild(alert_csb_node_);
        ButtonEffectController::setButtonsZoomScale(alert_csb_node_);
    }

    void EnterGameAlert::initStartButton(int cell_numble, int level)
    {
        //cocos2d::ui::Button* button = this->getStartButton();
        ////button->setZoomScale(GAME_BUTTON_ZOOM_SCALE);
        ////ButtonEffectController::setButtonZoomScale(button, GAME_BUTTON_ZOOM_SCALE);
        //button->addTouchEventListener([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
        //    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
        //    {
        //        cocos2d::Scene* scene = GameScene::createScene(cell_numble, level);
        //        cocos2d::Director::getInstance()->replaceScene(scene);
        //    }
        //});

		cocos2d::Node* button_top = cocos2d::CSLoader::createNode(START_BUTTON_TOP_CSB);
		auto action = cocos2d::CSLoader::createTimeline(START_BUTTON_TOP_CSB);
		button_top->runAction(action);
		action->gotoFrameAndPlay(0, true);

		cocos2d::ClippingNode* clipping = cocos2d::ClippingNode::create(SpriteTextureController::getInstance()->createGameSpriteWithPath(START_BUTTON_CLIPPINT_STENCIL_PATH));
		clipping->setAlphaThreshold(0);
		clipping->addChild(button_top);
		start_node_ = cocos2d::CSLoader::createNode(START_BUTTON_BOTTOM_CSB);
		//start_node_->addChild(clipping);
		alert_csb_node_->getChildByName(ENTER_GAME_ALERT_START_NODE_NAME)->addChild(start_node_);
		cocos2d::ui::Button* button = this->getStartButton();
		clipping->setPosition(button->getContentSize().width / 2, button->getContentSize().height/2);
		button->getRendererNormal()->addChild(clipping);
		ButtonEffectController::setButtonZoomScale(button);
		button->addTouchEventListener([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
		    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		    {
		        cocos2d::Scene* scene = GameScene::createScene(cell_numble, level);
		        cocos2d::Director::getInstance()->replaceScene(scene);
		    }
		});
    }

    void bubble_second::EnterGameAlert::initCloseButton()
    {
        cocos2d::ui::Button* button = this->getCloseButton();
        //button->setZoomScale(GAME_BUTTON_ZOOM_SCALE);
        button->addTouchEventListener([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                this->removeFromParent();
            }
        });
    }

    void EnterGameAlert::initStageNumbleLabel(int level)
    {
        //std::string str1 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_1_KEY);
        //std::string str2 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_2_KEY);
        //char str[20];
        //sprintf(str, "%d", level);
        //this->getStageNumbleLabel()->setString(str);
        StageNumbleBoardController::getInstance()->loadView(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_STAGE_NUMBLE_BOARD_NAME), level);
    }

    void EnterGameAlert::initStageTypeLabel(const StageType & type)
    {
        this->getStageTypeLabel()->setString(GameTextInfo::getInstance()->getTextInfoWithStageType(type));
    }

    //void EnterGameAlert::initEnterProps()
    //{
    //    cocos2d::Node*  commodity = alert_csb_node_->getChildByName(AIMING_LINE_COMMODITY_NAME);
    //    cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(commodity->getChildByName("FileNode_1")->getChildByName("Button_3"));
    //}

    cocos2d::ui::Button * EnterGameAlert::getStartButton()
    {
		return dynamic_cast<cocos2d::ui::Button*>(start_node_->getChildByName(ENTER_GAME_ALERT_START_BUTTON_NAME));
    }

    cocos2d::ui::Button * bubble_second::EnterGameAlert::getCloseButton()
    {
        return dynamic_cast<cocos2d::ui::Button*>(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_CLOSE_BUTTON_NAME));
    }

    //cocos2d::ui::TextBMFont * EnterGameAlert::getStageNumbleLabel()
    //{
    //    return dynamic_cast<cocos2d::ui::TextBMFont*>(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_STAGE_NUMBLE_BOARD_NAME)->getChildByName(ENTER_GAME_ALERT_STAGE_NUMBLE_LABEL_NAME));
    //}

    cocos2d::ui::TextBMFont * EnterGameAlert::getStageTypeLabel()
    {
        return dynamic_cast<cocos2d::ui::TextBMFont*>(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_STAGE_TYPE_LABEL_NAME));
    }

    //void EnterGameAlert::addTopLabel(int level)
    //{
    //    //文字
    //    std::string str1 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_1_KEY);
    //    std::string str2 = GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_LEVEL_NUMBLE_2_KEY);
    //    char str[20];
    //    sprintf(str, "%s  %d  %s", str1.c_str(), level, str2.c_str());
    //    cocos2d::Label* top_label = cocos2d::Label::createWithSystemFont(str, "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
    //    top_label->setTextColor(GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR);
    //    top_label->setPosition(this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG)->getPosition());
    //    this->addChild(top_label);
    //}
    //void EnterGameAlert::addStageTypeLabel(const StageType & type)
    //{
    //    //文字
    //    std::string str = GameTextInfo::getInstance()->getTextInfoWithStageType(type);
    //    cocos2d::Label* type_label = cocos2d::Label::createWithSystemFont(str, "", GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE);
    //    type_label->setTextColor(GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_COLOR);
    //    cocos2d::Node* top_node = this->getChildByTag(GAME_ALERT_TOP_BACKGROUND_TAG);
    //    float x = top_node->getPositionX();
    //    float y = top_node->getPositionY() - top_node->getBoundingBox().size.height*0.75f;
    //    type_label->setPosition(x, y);
    //    this->addChild(type_label);
    //}
    //void EnterGameAlert::addCharactor()
    //{
    //    {
    //        cocos2d::Sprite* charactor_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_VICTORY_ALERT_FLASH_LIGHT_BACKGROUND_PATH);
    //        this->addChild(charactor_bg);
    //    }
    //    {
    //        cocos2d::Sprite* charactor_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_ALERT_CHARACTOR_PATH);
    //        //cocos2d::Rect rect = charactor_sp->getBoundingBox();
    //        //charactor_sp->setTextureRect(cocos2d::Rect(0.0f, 0.0f, rect.size.width, rect.size.height*0.7f));
    //        charactor_sp->setPosition(ENTER_GAME_ALERT_CHARACTOR_POSITION);
    //        charactor_sp->setTag(ENTER_GAME_ALERT_CHARACTOR_TAG);
    //        this->addChild(charactor_sp);
    //    }
    //}
    //void EnterGameAlert::addPropsShow()
    //{
    //    //背景
    //    cocos2d::Sprite* props_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_ALERT_PROPS_BACKGROUND_PATH);
    //    cocos2d::Node* node = this->getChildByTag(ENTER_GAME_ALERT_CHARACTOR_TAG);
    //    float y = node->getPositionY() - node->getBoundingBox().size.height / 6 - props_bg->getBoundingBox().size.height / 2.15f;
    //    props_bg->setPosition(node->getPositionX(), y);
    //    this->addChild(props_bg, 1);
    //    //选择道具 的背景
    //    cocos2d::Sprite* props_label_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_ALERT_PROPS_LABEL_BACKGROUND_PATH);
    //    props_label_bg->setScale(0.35f);
    //    props_label_bg->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    //    cocos2d::Rect rect = props_bg->getBoundingBox();
    //    props_label_bg->setPosition(rect.origin.x, rect.origin.y + rect.size.height*0.95);
    //    this->addChild(props_label_bg);
    //    //选择道具 字
    //    cocos2d::Label* props_label = cocos2d::Label::createWithSystemFont(
    //        GameTextInfo::getInstance()->getTextInfoWithKey(GAME_TEXT_SELECT_PROPS_LABEL_KEY), "", ENTER_GAME_ALERT_PROPS_LABEL_FONTSIZE);
    //    props_label->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    //    props_label->setPosition(rect.origin.x+10.0f, rect.origin.y + rect.size.height);
    //    this->addChild(props_label);
    //    //道具展示
    //    //EnterGamePropsView* sight_props = EnterGamePropsView::create(SpriteTextureController::getInstance()->createGameSpriteWithPath("fzx.png"));
    //    //sight_props->setPosition(rect.origin.x + rect.size.width*0.2f, rect.origin.y + rect.size.height*0.6f);
    //    //this->addChild(sight_props, 3);
    //    cocos2d::Node* props_node = EnterPropsViewManager::getInstance()->createEnterPropsAlert();
    //    props_node->setPosition(-10.0f, rect.origin.y + rect.size.height*0.6f);
    //    this->addChild(props_node, 1);
    //}

    //void EnterGameAlert::addButtonItem()
    //{
    //    {//x按钮
    //        this->addCancelButton();
    //    }
    //    {//开始按钮
    //        begin_item_ = SpriteTextureController::getInstance()->createMenuItemSprite(ENTER_GAME_ALERT_BEGIN_BUTTON_PATH);
    //        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(begin_item_);
    //        menu->setPosition(this->getChildByTag(ENTER_GAME_ALERT_CHARACTOR_TAG)->getPositionX(), ENTER_GAME_ALERT_BEGIN_BUTTON_POSITION_Y);
    //        this->addChild(menu);
    //    }
    //}
}