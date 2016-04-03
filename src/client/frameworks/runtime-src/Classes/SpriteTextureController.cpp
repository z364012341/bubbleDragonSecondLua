#include "SpriteTextureController.h"
#include "CenteredMenuItemSprite.h"
#include "cocostudio\CocoStudio.h"
#include "SpriteBlur.h"
const std::string GAME_CHARACTER_ARMATURE_LAOHU_1_PATH = "laohu/laohu.ExportJson"; //老虎的动画
const std::string GAME_CHARACTER_ARMATURE_LAOHU_2_PATH = "laohu2/laohu2.ExportJson"; //老虎2的动画
const std::string GAME_CHARACTER_ARMATURE_LAOHU_3_PATH = "laohu3/laohu3.ExportJson"; //老虎3的动画
const std::string GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH = "laohu-shengli/laohu-shengli.ExportJson"; //老虎胜利的动画
const std::string GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH = "TX-yanwu/TX-yanwu.ExportJson"; //胜利烟雾的动画
const std::string SCOREWIDGET_ARMATURE_PATH = "mifeng/mifeng.ExportJson"; //得分挂件的动画
const std::string GAME_CHARACTER_ARMATURE_FIRE_BALLOON_ARMATURE_PATH = "qiting/qiting.ExportJson"; //热气球的动画
const std::string GAME_STAGE_BUTTON_ARMATURE_PATH = "guankaanniu/guankaanniu.ExportJson"; //关卡按钮的动画
const std::string GAME_SETTING_BUTTON_ARMATURE_PATH = "feichuan/feichuan.ExportJson"; //气球设置按钮的动画
const std::string GAME_STAGE_BUTTON_UNLOCK_ARMATURE_PATH = "guankaanniu/guankaanniu.ExportJson";    //关卡解锁动画
const std::string MENU_STAGETYPE_TEXTURE_TOPELIMINATE_PATH = "tubiao01.png";
const std::string GAME_CURRENT_STAGE_BUTTON_HALO_ARMATURE_PATH = "anniu-TX/anniu-TX.ExportJson";    //当前关卡光圈动画
const std::string STAGE_CELL_RABBIT_ARMATURE_PATH = "tuzizuan/tuzizuan.ExportJson";    //兔子动画
namespace bubble_second {

    SpriteTextureController::SpriteTextureController()
    {
        stagetype_to_path_[kTopEliminate] = STAGETYPE_TEXTURE_TOPELIMINATE_PATH;
        stagetype_to_path_[kRescueAnimal] = STAGETYPE_TEXTURE_RESCUEANIMAL_PATH;
        stagetype_to_path_[kDestroyRainbowSeal] = STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH;
        stagetype_to_path_[kWindmill] = STAGETYPE_TEXTURE_WINDMILL_PATH;

        stage_menu_stagetype_to_path_[kTopEliminate] = MENU_STAGETYPE_TEXTURE_TOPELIMINATE_PATH;
        stage_menu_stagetype_to_path_[kRescueAnimal] = STAGETYPE_TEXTURE_RESCUEANIMAL_PATH;
        stage_menu_stagetype_to_path_[kDestroyRainbowSeal] = STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH;
        stage_menu_stagetype_to_path_[kWindmill] = STAGETYPE_TEXTURE_WINDMILL_PATH;
        this->readGameSceneBackgroundFile();

        armature_path_.push_back(LIGHTNING_BUBBLE_EFFECT_PATH);
        armature_path_.push_back(ONE_ROUND_BOMB_EFFECT_PATH);
        armature_path_.push_back(TWO_ROUND_BOMB_EFFECT_PATH);
        armature_path_.push_back(BLACK_HOLE_BUBBLE_EFFECT_PATH);
        armature_path_.push_back(BARREL_BOTTOM_EFFECT_PATH);
        armature_path_.push_back(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
        armature_path_.push_back(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
        armature_path_.push_back(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
        armature_path_.push_back(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
        armature_path_.push_back(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
        armature_path_.push_back(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
        armature_path_.push_back(RAINBOW_CHARACTOR_ARMATURE_PATH);
        armature_path_.push_back(RAINBOW_BUBBLE_ARMATURE_PATH);
        armature_path_.push_back(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
        armature_path_.push_back(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
        armature_path_.push_back(SCOREWIDGET_ARMATURE_PATH);
        armature_path_.push_back(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_LAOHU_1_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_LAOHU_2_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_LAOHU_3_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_FIRE_BALLOON_ARMATURE_PATH);
        armature_path_.push_back(GAME_STAGE_BUTTON_ARMATURE_PATH);
        armature_path_.push_back(GAME_SETTING_BUTTON_ARMATURE_PATH);
        armature_path_.push_back(GAME_STAGE_BUTTON_UNLOCK_ARMATURE_PATH);
        armature_path_.push_back(GAME_CURRENT_STAGE_BUTTON_HALO_ARMATURE_PATH);
        armature_path_.push_back(STAGE_CELL_RABBIT_ARMATURE_PATH);
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

    cocos2d::Sprite* SpriteTextureController::createMenuStageTypeSprite(const StageType& type)
    {
        return this->createGameSpriteWithPath(stage_menu_stagetype_to_path_[type]);
    }

    void SpriteTextureController::setStageTypeSprite(cocos2d::Sprite* sp, const StageType& type)
    {
        this->setSpriteTexture(stagetype_to_path_[type], sp);
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

    //void SpriteTextureController::addGameBackgroundTexture(int cell_numble)
    //{
    //    char str[10];
    //    sprintf(str, "%d", cell_numble);
    //    cocos2d::Director::getInstance()->getTextureCache()->addImageAsync(cell_to_path_[str].asString(), nullptr);
    //}

    //cocos2d::Sprite * SpriteTextureController::createGameBlurBackground()
    //{
    //    cocos2d::RenderTexture* textureScreen = this->ScreenShot(false, nullptr);
    //    cocos2d::RenderTexture* textureBlur = this->SpriteBlurer(textureScreen->getSprite());
    //    //将模糊化后的图片保存成一张图片 
    //    cocos2d::Sprite* blurSprite = cocos2d::Sprite::createWithSpriteFrame(textureBlur->getSprite()->getSpriteFrame());
    //    blurSprite->setRotation(180.0f);
    //    blurSprite->setFlippedX(true);
    //    return blurSprite;
    //}

    void SpriteTextureController::addArmatureFile()
    {
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(LIGHTNING_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(ONE_ROUND_BOMB_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(TWO_ROUND_BOMB_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BLACK_HOLE_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BARREL_BOTTOM_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(RAINBOW_CHARACTOR_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(RAINBOW_BUBBLE_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(SCOREWIDGET_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_1_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_2_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_3_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_FIRE_BALLOON_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_STAGE_BUTTON_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_SETTING_BUTTON_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_STAGE_BUTTON_UNLOCK_ARMATURE_PATH);
        for (auto var : armature_path_)
        {
            cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(var);
        }
    }

    void SpriteTextureController::removeArmatureFile()
    {
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(LIGHTNING_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(ONE_ROUND_BOMB_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(TWO_ROUND_BOMB_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BLACK_HOLE_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BARREL_BOTTOM_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(RAINBOW_CHARACTOR_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(RAINBOW_BUBBLE_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(SCOREWIDGET_ARMATURE_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_1_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_2_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_3_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_FIRE_BALLOON_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_STAGE_BUTTON_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_SETTING_BUTTON_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_STAGE_BUTTON_UNLOCK_ARMATURE_PATH);
        for (auto var : armature_path_)
        {
            cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(var);
        }
    }

    //cocos2d::RenderTexture* SpriteTextureController::SpriteBlurer(cocos2d::Sprite* pSprite, const float fRadius, const float fSampleNum)
    //{
    //    //模糊化的临时精灵  
    //    auto pSptBlur = SpriteBlur::create(pSprite, fRadius, fSampleNum);
    //    pSptBlur->setRotationSkewX(180.0f);
    //    pSptBlur->setPositionX(pSptBlur->getContentSize().width / 2);
    //    pSptBlur->setPositionY(pSptBlur->getContentSize().height / 2);
    //    //使用精灵尺寸初始化一个空的渲染纹理对象  
    //    cocos2d::RenderTexture* textureScreen = cocos2d::RenderTexture::create(pSptBlur->getContentSize().width, pSptBlur->getContentSize().height);
    //    //开始获取  
    //    textureScreen->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
    //    //遍历节点对象，填充纹理到texure中  
    //    pSptBlur->visit();
    //    //结束获取  
    //    textureScreen->end();
    //    return textureScreen;
    //}

    //cocos2d::RenderTexture* SpriteTextureController::ScreenShot(const bool bIsSave, std::function<void(cocos2d::RenderTexture*, const std::string&)> pFuncCallback)

    //{
    //    //使用屏幕尺寸初始化一个空的渲染纹理对象  
    //    cocos2d::Size sizeWin = cocos2d::Director::getInstance()->getWinSize();
    //    cocos2d::RenderTexture* textureScreen = cocos2d::RenderTexture::create(sizeWin.width, sizeWin.height, cocos2d::Texture2D::PixelFormat::RGBA8888);
    //    //清除数据并开始获取  
    //    //textureScreen->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
    //    textureScreen->begin();
    //    //遍历场景节点对象，填充纹理到texure中  
    //    cocos2d::Director::getInstance()->getRunningScene()->visit();
    //    //结束获取  
    //    textureScreen->end();

    //    if (bIsSave)
    //    {//保存为PNG图  
    //        textureScreen->saveToFile("ScreenShot.png", cocos2d::Image::Format::PNG, true, pFuncCallback);
    //    }
    //    else
    //    {
    //        if (nullptr != pFuncCallback)
    //        {
    //            pFuncCallback(textureScreen, "");
    //        }
    //    }
    //    //cocos2d::utils::captureScreen([=](bool succeed, const std::string& outputFile) {}, "ScreenShot.png");
    //    return textureScreen;
    //}

}