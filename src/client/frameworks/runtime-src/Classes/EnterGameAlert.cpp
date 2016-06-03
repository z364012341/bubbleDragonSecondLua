#include "EnterGameAlert.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
#include "GameStartButton.h"
#include "GameScene.h"
#include "GameCharactorNameManager.h"
#include "EnterPropsViewManager.h"
#include "cocostudio/CocoStudio.h"
#include "GameAlertMask.h"
#include "ButtonEffectController.h"
#include "ui\UIScale9Sprite.h"
#include "ui\UIHelper.h"
#include "StageNumbleBoardController.h"
#include "StageDataManager.h"
#include "UserDataManager.h"
const std::string ENTER_GAME_ALERT_CSB = "EnterGameAlert.csb";
//const std::string START_BUTTON_TOP_CSB = "GameStartMenuTop.csb";
//const std::string START_BUTTON_BOTTOM_CSB = "GameStartMenuBottom.csb";
//const std::string START_BUTTON_CLIPPINT_STENCIL_PATH = "startBubbleBG1.png";
const std::string ENTER_GAME_ALERT_START_NODE_NAME = "startMenuNode";
//const std::string ENTER_GAME_ALERT_START_BUTTON_NAME = "startButton";
const std::string ENTER_GAME_ALERT_CLOSE_BUTTON_NAME = "closeButton";
const std::string ENTER_GAME_ALERT_STAGE_NUMBLE_BOARD_NAME = "stageNumbleBoard";
const std::string ENTER_GAME_ALERT_STAGE_TYPE_LABEL_NAME = "stageTypeLabel";
const std::string SELECTED_CHARACTOR_PAGEVIEW_NAME = "charactorPageView";
const std::string CHARACTOR_SELECTED_ROOT_NAME = "FileNode_3";
const std::string PAGEVIEW_TURN_LEFT_BUTTON_NAME = "turnLeft";
const std::string PAGEVIEW_TURN_RIGHT_BUTTON_NAME = "turnRight";
const cocos2d::Vec2 COMMODITY_NODE_POS(-5.0f, -238.7f);
namespace bubble_second {
    //EnterGameAlert * EnterGameAlert::create(int cell_numble, int level, const StageType & type)
    //{
    //    EnterGameAlert *pRet = new(std::nothrow) EnterGameAlert();
    //    if (pRet && pRet->init())
    //    {
    //        pRet->autorelease();
    //        return pRet;
    //    }
    //    else
    //    {
    //        delete pRet;
    //        pRet = NULL;
    //        return NULL;
    //    }
    //}
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
    bool EnterGameAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create());
        this->loadView();
        this->initStartButton(StageDataManager::getInstance()->getCurrentCell(), StageDataManager::getInstance()->getCurrentLevel());
        this->initCloseButton();
        this->initStageNumbleLabel(StageDataManager::getInstance()->getCurrentLevel());
        this->initStageTypeLabel(StageDataManager::getInstance()->getCurrentStageType());
        cocos2d::Node* node = EnterPropsViewManager::getInstance()->createEnterPropsAlert();
        node->setPosition(COMMODITY_NODE_POS);
        this->addChild(node);
        return true;
    }

    void EnterGameAlert::loadView()
    {
        alert_csb_node_ = cocos2d::CSLoader::createNode(ENTER_GAME_ALERT_CSB);
        assert(alert_csb_node_);
        this->addChild(alert_csb_node_);
        ButtonEffectController::setButtonsZoomScale(alert_csb_node_);
        this->initCharactorPageView();

        left_button_ = dynamic_cast<cocos2d::ui::Button*>(alert_csb_node_->getChildByName(CHARACTOR_SELECTED_ROOT_NAME)->getChildByName(PAGEVIEW_TURN_LEFT_BUTTON_NAME));
        assert(left_button_);
        left_button_->addClickEventListener([=](cocos2d::Ref*) {
            charactor_pageview_->scrollToPage(charactor_pageview_->getCurrentPageIndex()-1);
            this->setDirectionalButtonsEnable(charactor_pageview_->getCurrentPageIndex() - 1);
        });

        right_button_ = dynamic_cast<cocos2d::ui::Button*>(alert_csb_node_->getChildByName(CHARACTOR_SELECTED_ROOT_NAME)->getChildByName(PAGEVIEW_TURN_RIGHT_BUTTON_NAME));
        assert(right_button_);
        right_button_->addClickEventListener([=](cocos2d::Ref*) {
            charactor_pageview_->scrollToPage(charactor_pageview_->getCurrentPageIndex() + 1);
            this->setDirectionalButtonsEnable(charactor_pageview_->getCurrentPageIndex() + 1);
        });
        this->setDirectionalButtonsEnable(charactor_pageview_->getCurrentPageIndex());
    }

    void EnterGameAlert::initStartButton(int cell_numble, int level)
    {
        GameStartButton* button = GameStartButton::createButtonStartForm();
		alert_csb_node_->getChildByName(ENTER_GAME_ALERT_START_NODE_NAME)->addChild(button);
		button->addButtonClickEventListener([=](Ref* target) {
            GameCharactorNameManager::getInstance()->setCurrentArmatureNameWithIndex(charactor_pageview_->getCurrentPageIndex());
		    cocos2d::Scene* scene = GameScene::createScene();
		    cocos2d::Director::getInstance()->replaceScene(scene);
		});
    }

    void EnterGameAlert::initCharactorPageView()
    {
        charactor_pageview_ = dynamic_cast<cocos2d::ui::PageView*>(alert_csb_node_->getChildByName(CHARACTOR_SELECTED_ROOT_NAME)->getChildByName(SELECTED_CHARACTOR_PAGEVIEW_NAME));
        assert(charactor_pageview_);
        charactor_pageview_->setOpacity(0);
        charactor_pageview_->runAction(cocos2d::FadeIn::create(1.0f));
        charactor_pageview_->setCurPageIndex(UserDataManager::getInstance()->getLastGameCharactorIndex());
        //int unlock_numble = UserDataManager::getInstance()->getGameCharactorUnlockNumble();
        cocos2d::Vector<cocos2d::ui::Layout*> pages = charactor_pageview_->getPages();
        for (int i = UserDataManager::getInstance()->getGameCharactorUnlockNumble(); i != pages.size(); i++)
        {
            cocos2d::Vector<cocos2d::Node*> children = pages.at(i)->getChildren();
            assert(children.size() == 1);
            assert(dynamic_cast<cocos2d::ui::Button*>(children.front()));
            dynamic_cast<cocos2d::ui::Button*>(children.front())->setBright(false);
        }
    }

    void bubble_second::EnterGameAlert::initCloseButton()
    {
        cocos2d::ui::Button* button = this->getCloseButton();
        button->addTouchEventListener([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                this->removeFromParent();
            }
        });
    }

    void EnterGameAlert::initStageNumbleLabel(int level)
    {
        StageNumbleBoardController::getInstance()->loadView(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_STAGE_NUMBLE_BOARD_NAME), level);
    }

    void EnterGameAlert::initStageTypeLabel(const StageType & type)
    {
        this->getStageTypeLabel()->setString(GameTextInfo::getInstance()->getTextInfoWithStageType(type));
    }

    void EnterGameAlert::setDirectionalButtonsEnable(int pageview_index)
    {
        left_button_->setEnabled(pageview_index != 0);
        right_button_->setEnabled(pageview_index != charactor_pageview_->getPages().size() - 1);

    }

    cocos2d::ui::Button * bubble_second::EnterGameAlert::getCloseButton()
    {
        return dynamic_cast<cocos2d::ui::Button*>(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_CLOSE_BUTTON_NAME));
    }

    cocos2d::ui::TextBMFont * EnterGameAlert::getStageTypeLabel()
    {
        return dynamic_cast<cocos2d::ui::TextBMFont*>(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_STAGE_TYPE_LABEL_NAME));
    }
}