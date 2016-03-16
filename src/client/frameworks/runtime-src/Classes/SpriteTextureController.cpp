#include "SpriteTextureController.h"
#include "CenteredMenuItemSprite.h"
#include "cocostudio\CocoStudio.h"
const std::string GAME_CHARACTER_ARMATURE_LAOHU_1_PATH = "laohu/laohu.ExportJson"; //老虎的动画
const std::string GAME_CHARACTER_ARMATURE_LAOHU_2_PATH = "laohu2/laohu2.ExportJson"; //老虎2的动画
const std::string GAME_CHARACTER_ARMATURE_LAOHU_3_PATH = "laohu3/laohu3.ExportJson"; //老虎3的动画
const std::string GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH = "laohu-shengli/laohu-shengli.ExportJson"; //老虎胜利的动画
const std::string GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH = "TX-yanwu/TX-yanwu.ExportJson"; //胜利烟雾的动画
namespace bubble_second {

    SpriteTextureController::SpriteTextureController()
    {
        stagetype_to_path_[kTopEliminate] = STAGETYPE_TEXTURE_TOPELIMINATE_PATH;
        stagetype_to_path_[kRescueAnimal] = STAGETYPE_TEXTURE_RESCUEANIMAL_PATH;
        stagetype_to_path_[kDestroyRainbowSeal] = STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH;
        stagetype_to_path_[kWindmill] = STAGETYPE_TEXTURE_WINDMILL_PATH;
        this->readGameSceneBackgroundFile();
    }

    void SpriteTextureController::readGameSceneBackgroundFile()
    {
        cell_to_path_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(GAME_SCENE_BACKGROUND_PATH);
    }

    SpriteTextureController::~SpriteTextureController()
    {
        removeArmatureFile();
    }

    void SpriteTextureController::setSpriteTexture(const std::string& path, cocos2d::Sprite* sprite)
    {
        sprite->setTexture(path);
        //更换纹理设置方法
        //if (path == "")
        //{
        //    sprite->setTexture(path);
        //}
        //else
        //{
        //    auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(path);
        //    sprite->setSpriteFrame(frame);
        //}
    }

    cocos2d::Sprite* SpriteTextureController::createGameSpriteWithPath(const std::string& path)
    {
        cocos2d::Sprite*sp = cocos2d::Sprite::create(path);
		if (!sp)
        {
            sp = cocos2d::Sprite::createWithSpriteFrameName(path);
        }
        return sp;
    }

    CenteredMenuItemSprite * SpriteTextureController::createMenuItemSprite(const std::string & path, const cocos2d::ccMenuCallback & callback)
    {
        cocos2d::Sprite* item_select = this->createGameSpriteWithPath(path);
        item_select->setScale(GAME_MENU_SELECT_SCALE);
        cocos2d::Sprite* item_normal = this->createGameSpriteWithPath(path);
        CenteredMenuItemSprite* item = CenteredMenuItemSprite::create(item_normal, item_select, [=](cocos2d::Ref*) {
        });
        return item;
    }

    cocos2d::Sprite * SpriteTextureController::createStageTypeSprite(const StageType & type)
    {
        return this->createGameSpriteWithPath(stagetype_to_path_[type]);
    }

    cocos2d::Sprite * SpriteTextureController::createGameBackgroundSprite(int cell_numble)
    {
        char str[10];
        sprintf(str, "%d", cell_numble);
        return this->createGameSpriteWithPath(cell_to_path_[str].asString());;
    }

    void SpriteTextureController::addResourcesTexture()
    {    
        //cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("StudioResPlist.plist");
        //cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("gameRes.plist");
        this->addArmatureFile();
    }

    void SpriteTextureController::addGameBackgroundTexture(int cell_numble)
    {
        char str[10];
        sprintf(str, "%d", cell_numble);
        cocos2d::Director::getInstance()->getTextureCache()->addImageAsync(cell_to_path_[str].asString(), nullptr);
    }

    void SpriteTextureController::addArmatureFile()
    {
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(LIGHTNING_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(ONE_ROUND_BOMB_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(TWO_ROUND_BOMB_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BLACK_HOLE_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BARREL_BOTTOM_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(RAINBOW_CHARACTOR_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(RAINBOW_BUBBLE_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(SCOREWIDGET_ARMATURE_BLUE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
		cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_1_PATH);
		cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_2_PATH);
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_3_PATH);
		cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH);
		cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH);

    }

    void SpriteTextureController::removeArmatureFile()
    {
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(LIGHTNING_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(ONE_ROUND_BOMB_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(TWO_ROUND_BOMB_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BLACK_HOLE_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BARREL_BOTTOM_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(RAINBOW_CHARACTOR_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(RAINBOW_BUBBLE_ARMATURE_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(SCOREWIDGET_ARMATURE_BLUE_PATH);
		cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_1_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
		cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_2_PATH);
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_3_PATH);
		cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH);
		cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH);
    }

}