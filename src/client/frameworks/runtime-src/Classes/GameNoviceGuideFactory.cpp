#include "GameNoviceGuideFactory.h"
#include "XMLTool.h"
#include "SpriteTextureController.h"
#include "GameStartButton.h"
#include "GameAlertMask.h"
#include "StageDataManager.h"
#include "GameCharactorNameManager.h"
#include "UserDataManager.h"
const std::map<int, std::string> BEGIN_GUIDE_DATA = {
    { 1 , "xsydyx01.png" },
    { 2 , "xsydyx02.png" },
    { 3 , "xsydyx03.png" },
    { 4 , "xsydyx04.png" },
    { 5 , "xsydyx05.png" },
    { 6 , "xsydyx06.png" },
    { 7 , "xsydyx07.png" },
    { 8 , "xsydyx08.png" },
    { 9 , "xsydyx09.png" },
    { 10 , "xsydyx10.png" },
    { 11 , "xsydyx11.png" },
    { 12 , "xsydyx12.png" },
    { 14 , "xsydyx14.png" },
    { 16 , "xsydyx16.png" },
    { 17 , "xsydyx17.png" },
    { 18 , "xsydyx18.png" },
    { 21 , "xsydyx21.png" },
    { 22 , "xsydyx22.png" },
    { 27 , "xsydyx27.png" },
    { 42 , "xsydyx42.png" },
    { 57 , "xsydyx57.png" },
    { 72 , "xsydyx71.png" },
    { 132 , "xsydyx132.png" },
};
const std::map<int, std::string> END_GUIDE_DATA = {
    { 6,"xsydyx06sl.png" },
    { 8,"xsydyx08sl.png" },
    { 10,"xsydyx10sl.png" },
    { 13,"xsydyx13sl.png" },
    { 15,"xsydyx15sl.png" },
    { 16,"xsydyx16sl.png" },
    { 20,"xsydyx20sl.png" },
};
const std::map<std::string, std::string> CHARACTOR_SKILL_GUIDE_DATA = {
    { CHARCTOR_LAOHU_ARMATURE_KEY , "xsydjs1.png" },
    { CHARCTOR_MIAO_ARMATURE_KEY , "xsydjs2.png" },
    { CHARCTOR_TUZI_ARMATURE_KEY , "xsydjs3.png" },
    { CHARCTOR_LAOSHU_ARMATURE_KEY , "xsydjs4.png"},
};
namespace bubble_second {
    GameNoviceGuideFactory::GameNoviceGuideFactory()
    {
    }

    cocos2d::Node * GameNoviceGuideFactory::createNoviceGuideAlertWithPath(const std::string & path)
    {
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(path);
        GameStartButton* button = GameStartButton::createButtonStartForm();
        button->addButtonClickEventListener([=](cocos2d::Ref*) {cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CONTINUE); });
        cocos2d::Node* node = cocos2d::Node::create();
        node->addChild(bg);
        button->setPositionY(-250.0f);
        node->addChild(button);
        node->addChild(GameAlertMask::create(), -1);
        return node;
    }
    template<typename T>
    cocos2d::Node * GameNoviceGuideFactory::createNoviceGuideAlertWithDataAndIndex(const std::map<T, std::string>& data, T key)
    {
        if (data.find(key) == data.end())
        {
            return nullptr;
        }
        return this->createNoviceGuideAlertWithPath(data.at(key));
    }

    GameNoviceGuideFactory::~GameNoviceGuideFactory()
    {
    }
    cocos2d::Node * GameNoviceGuideFactory::createGameBeginNoviceGuide()
    {
        return this->createNoviceGuideAlertWithDataAndIndex(BEGIN_GUIDE_DATA, StageDataManager::getInstance()->getCurrentLevel());
    }
    cocos2d::Node * GameNoviceGuideFactory::createGameEndNoviceGuide()
    {
        return this->createNoviceGuideAlertWithDataAndIndex(END_GUIDE_DATA, StageDataManager::getInstance()->getCurrentLevel());
    }
    cocos2d::Node * GameNoviceGuideFactory::createGameCharactorSkillNoviceGuide()
    {
        return this->createNoviceGuideAlertWithDataAndIndex(CHARACTOR_SKILL_GUIDE_DATA, GameCharactorNameManager::getInstance()->getCurrentArmatureName());
    }
}