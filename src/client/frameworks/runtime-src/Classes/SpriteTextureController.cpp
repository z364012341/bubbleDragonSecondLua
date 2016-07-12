#include "SpriteTextureController.h"
#include "UserDataManager.h"
#include "cocostudio\CocoStudio.h"
#include "DecalsFactory.h"
const std::string GAME_COIN_PATH = "jinbi.PNG"; //���
const std::string GAME_DIAMOND_PATH = "zuanshi.PNG"; //��ʯ
const std::string GAME_NUMBLE_FONT_PATH = "fonts/typeface-export.fnt";
const std::string GAME_CHARACTER_ARMATURE_LAOHU_1_PATH = "laohu/laohu.ExportJson"; //�ϻ��Ķ���
const std::string GAME_CHARACTER_ARMATURE_LAOHU_2_PATH = "laohu2/laohu2.ExportJson"; //�ϻ�2�Ķ���
const std::string GAME_CHARACTER_ARMATURE_LAOHU_3_PATH = "laohu3/laohu3.ExportJson"; //�ϻ�3�Ķ���
const std::string GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH = "laohu-shengli/laohu-shengli.ExportJson"; //�ϻ�ʤ���Ķ���

const std::string GAME_CHARACTER_ARMATURE_MIAO_1_PATH = "xiaomao1/xiaomao1.ExportJson"; //�����Ķ���
const std::string GAME_CHARACTER_ARMATURE_MIAO_2_PATH = "xiaomao2/xiaomao2.ExportJson"; //����2�Ķ���
const std::string GAME_CHARACTER_ARMATURE_MIAO_3_PATH = "xiaomao3/xiaomao3.ExportJson"; //����3�Ķ���
const std::string GAME_CHARACTER_ARMATURE_MIAO_VICTORY_PATH = "shenglimao/shenglimao.ExportJson";

const std::string GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH = "TX-yanwu/TX-yanwu.ExportJson"; //ʤ������Ķ���
const std::string SCOREWIDGET_ARMATURE_PATH = "mifeng/mifeng.ExportJson"; //�÷ֹҼ��Ķ���
const std::string GAME_CHARACTER_ARMATURE_FIRE_BALLOON_ARMATURE_PATH = "qiting/qiting.ExportJson"; //������Ķ���
const std::string GAME_STAGE_BUTTON_ARMATURE_PATH = "guankaanniu/guankaanniu.ExportJson"; //�ؿ���ť�Ķ���
const std::string GAME_SETTING_BUTTON_ARMATURE_PATH = "feichuan/feichuan.ExportJson"; //�������ð�ť�Ķ���
const std::string GAME_STAGE_BUTTON_UNLOCK_ARMATURE_PATH = "guankaanniu/guankaanniu.ExportJson";    //�ؿ���������
const std::string MENU_STAGETYPE_TEXTURE_TOPELIMINATE_PATH = "tubiao01.png";
const std::string GAME_CURRENT_STAGE_BUTTON_HALO_ARMATURE_PATH = "anniu-TX/anniu-TX.ExportJson";    //��ǰ�ؿ���Ȧ����
const std::string STAGE_CELL_RABBIT_ARMATURE_PATH = "tuzizuan/tuzizuan.ExportJson";    //���Ӷ���
const std::string WINDMILL_BUBBLE_ARMATURE_PATH = "laoshu/laoshu.ExportJson";    //�糵����
const std::string MUTIPLE_SEAL_3_BUBBLE_ARMATURE_PATH = "wa/wa.ExportJson"; //���ط�ӡ��Ķ���
const std::string MUTIPLE_SEAL_7_BUBBLE_ARMATURE_PATH = "xiongda/xiongda.ExportJson"; //���ط�ӡ��Ķ���
const std::string MUTIPLE_SEAL_1_BUBBLE_ARMATURE_PATH = "1gebianfu/1gebianfu.ExportJson"; //���ط�ӡ��Ķ���
const std::string RAINBOW_CHARACTOR_ARMATURE_PATH = "langda/langda.ExportJson"; //�ʺ��ӡ������
const std::string BLACK_HOLE_BUBBLE_EFFECT_PATH = "heidongpaopao/heidongpaopao.ExportJson"; //�ڶ���Ч��·��
const std::string BLACK_HOLE_BUBBLE_ANIMATION_ELIMANATE_NAME = "heidongTX/heidongTX.ExportJson";
const std::string WOODEN_HAMMER_WEAPON_ARMATURE_NAME = "chuizi/chuizi.ExportJson";
const std::string STAVES_WEAPON_ARMATURE_NAME = "fazhang/fazhang.ExportJson";
const std::string ADD_TEN_BUBBLE_NUMBLE_ARMATURE_NAME = "jiabudaoju/jiabudaoju.ExportJson";
const std::string AIMING_LINE_COMMODITY_ARMATURE_NAME = "miaozhunxian/miaozhunxian.ExportJson";
const std::string TWO_ROUND_BOMB_EFFECT_PATH = "zhadanTX/zhadanTX.ExportJson"; //ը2Ȧ��Ч��·��
const std::string BOMB_BOMB_BUBBLE_CENTER_FIRE_PATH = "huoqiuTX/huoqiuTX.ExportJson";
const std::string SCORE_WIDGET_UPDATE_PATH = "yun3/yun3.ExportJson";
//const std::string PUZZLE_SEARCH_PROP_PATH = "fangdajing/fangdajing.ExportJson";
//const std::string PUZZLE_BIG_EYES_PROP_PATH = "yanjingTX/yanjingTX.ExportJson";
//const std::string PUZZLE_ADD_TIME_PROP_PATH = "pintunaozhong/pintunaozhong.ExportJson"; 
const std::string PUZZLE_MOVE_ANSWER_PATH = "pintuTX3/pintuTX3.ExportJson";
const std::string ADD_SPECIAL_PROP_ARMATURE_PATH = "pingzidaoju/pingzidaoju.ExportJson"; //+3������߶���

const std::map<std::string, std::string> PROP_KEY_TO_PATH = {
    { PUZZLE_SEARCH_PROP_KEY, PUZZLE_SEARCH_PROP_PATH },
    { PUZZLE_BIG_EYES_PROP_KEY, PUZZLE_BIG_EYES_PROP_PATH },
    { PUZZLE_ADD_TIME_PROP_KEY, PUZZLE_ADD_TIME_PROP_PATH },
    { BUBBLE_WOODEN_HAMMER_PROP_KEY, PROPS_WOODEN_HAMMER_PATH },
    { BUBBLE_COLOR_BOMB_PROP_KEY, PROPS_COLOR_BOMB_PATH },
    { BUBBLE_BIG_BOMB_BOMB_PROP_KEY, PROPS_BOMB_BOMB_PATH },
    { BUBBLE_STAVES_PROP_KEY, PROPS_STAVES_PATH },
    { GAME_COIN_KEY, GAME_COIN_PATH } ,
    { GAME_DIAMOND_KEY, GAME_DIAMOND_PATH } ,
    { GAME_STRENGTH_KEY, GAME_FATIGUE_PATH }
};
const std::map<StageType, std::string> STAGETYPE_TO_GAME_PATH = {
//��Ϸ���Ͻǵ�logo��path
    { kTopEliminate, STAGETYPE_TEXTURE_TOPELIMINATE_PATH },
    { kRescueAnimal, STAGETYPE_TEXTURE_RESCUEANIMAL_PATH },
    { kDestroyRainbowSeal, STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH },
    { kWindmill, STAGETYPE_TEXTURE_WINDMILL_PATH }
};
const std::map<StageType, std::string> STAGE_MENU_STAGETYPE_TO_PATH = {
    //��Ϸ�ؿ�ѡ��ť�ϵ�logo��path
    { kTopEliminate, MENU_STAGETYPE_TEXTURE_TOPELIMINATE_PATH },
    { kRescueAnimal, STAGETYPE_TO_GAME_PATH.at(kRescueAnimal) },
    { kDestroyRainbowSeal, STAGETYPE_TO_GAME_PATH.at(kDestroyRainbowSeal) },
    { kWindmill, STAGETYPE_TO_GAME_PATH.at(kWindmill) }
};
namespace bubble_second {
    SpriteTextureController::SpriteTextureController()
    {
        //stagetype_to_path_[kTopEliminate] = STAGETYPE_TEXTURE_TOPELIMINATE_PATH;
        //stagetype_to_path_[kRescueAnimal] = STAGETYPE_TEXTURE_RESCUEANIMAL_PATH;
        //stagetype_to_path_[kDestroyRainbowSeal] = STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH;
        //stagetype_to_path_[kWindmill] = STAGETYPE_TEXTURE_WINDMILL_PATH;

        //stage_menu_stagetype_to_path_[kTopEliminate] = MENU_STAGETYPE_TEXTURE_TOPELIMINATE_PATH;
        //stage_menu_stagetype_to_path_[kRescueAnimal] = STAGETYPE_TEXTURE_RESCUEANIMAL_PATH;
        //stage_menu_stagetype_to_path_[kDestroyRainbowSeal] = STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH;
        //stage_menu_stagetype_to_path_[kWindmill] = STAGETYPE_TEXTURE_WINDMILL_PATH;

        //prop_key_to_path_[PUZZLE_SEARCH_PROP_KEY] = PUZZLE_SEARCH_PROP_PATH;
        //prop_key_to_path_[PUZZLE_BIG_EYES_PROP_KEY] = PUZZLE_BIG_EYES_PROP_PATH;
        //prop_key_to_path_[PUZZLE_ADD_TIME_PROP_KEY] = PUZZLE_ADD_TIME_PROP_PATH;
        //prop_key_to_path_[BUBBLE_WOODEN_HAMMER_PROP_KEY] = PROPS_WOODEN_HAMMER_PATH;
        //prop_key_to_path_[BUBBLE_COLOR_BOMB_PROP_KEY] = PROPS_COLOR_BOMB_PATH;
        //prop_key_to_path_[BUBBLE_BIG_BOMB_BOMB_PROP_KEY] = PROPS_BOMB_BOMB_PATH;
        //prop_key_to_path_[BUBBLE_STAVES_PROP_KEY] = PROPS_STAVES_PATH;
        //prop_key_to_path_[GAME_COIN_KEY] = GAME_COIN_PATH;


        armature_path_.push_back(LIGHTNING_BUBBLE_EFFECT_PATH);
        armature_path_.push_back(ONE_ROUND_BOMB_EFFECT_PATH);
        armature_path_.push_back(TWO_ROUND_BOMB_EFFECT_PATH);
        armature_path_.push_back(BLACK_HOLE_BUBBLE_EFFECT_PATH);
        //armature_path_.push_back(BARREL_BOTTOM_EFFECT_PATH);
        armature_path_.push_back(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
        armature_path_.push_back(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
        //armature_path_.push_back(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
        armature_path_.push_back(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
        armature_path_.push_back(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
        armature_path_.push_back(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
        armature_path_.push_back(RAINBOW_CHARACTOR_ARMATURE_PATH);
        armature_path_.push_back(RAINBOW_BUBBLE_ARMATURE_PATH);
        armature_path_.push_back(MUTIPLE_SEAL_3_BUBBLE_ARMATURE_PATH);
        armature_path_.push_back(MUTIPLE_SEAL_1_BUBBLE_ARMATURE_PATH);
        armature_path_.push_back(SCOREWIDGET_ARMATURE_PATH);
        //armature_path_.push_back(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_LAOHU_1_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_LAOHU_2_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_LAOHU_3_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_MIAO_1_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_MIAO_2_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_MIAO_3_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_MIAO_VICTORY_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_PATH);
        armature_path_.push_back(GAME_CHARACTER_ARMATURE_FIRE_BALLOON_ARMATURE_PATH);
        armature_path_.push_back(GAME_STAGE_BUTTON_ARMATURE_PATH);
        armature_path_.push_back(GAME_SETTING_BUTTON_ARMATURE_PATH);
        armature_path_.push_back(GAME_STAGE_BUTTON_UNLOCK_ARMATURE_PATH);
        armature_path_.push_back(GAME_CURRENT_STAGE_BUTTON_HALO_ARMATURE_PATH);
        armature_path_.push_back(STAGE_CELL_RABBIT_ARMATURE_PATH);
        armature_path_.push_back(WINDMILL_BUBBLE_ARMATURE_PATH);
        armature_path_.push_back(MUTIPLE_SEAL_7_BUBBLE_ARMATURE_PATH);
        armature_path_.push_back(BLACK_HOLE_BUBBLE_ANIMATION_ELIMANATE_NAME);
        armature_path_.push_back(WOODEN_HAMMER_WEAPON_ARMATURE_NAME);
        armature_path_.push_back(STAVES_WEAPON_ARMATURE_NAME);
        armature_path_.push_back(ADD_TEN_BUBBLE_NUMBLE_ARMATURE_NAME);
        armature_path_.push_back(AIMING_LINE_COMMODITY_ARMATURE_NAME);
        armature_path_.push_back(BOMB_BOMB_BUBBLE_CENTER_FIRE_PATH);
        armature_path_.push_back(SCORE_WIDGET_UPDATE_PATH);
        armature_path_.push_back("fangdajing/fangdajing.ExportJson");
        armature_path_.push_back("yanjingTX/yanjingTX.ExportJson");
        armature_path_.push_back("pintunaozhong/pintunaozhong.ExportJson");
        armature_path_.push_back(PUZZLE_MOVE_ANSWER_PATH);
        armature_path_.push_back(ADD_SPECIAL_PROP_ARMATURE_PATH);
        armature_path_.push_back("miaozhunxian/miaozhunxian.ExportJson");  //��׼�ߵ��߶���
        armature_path_.push_back("laoshu1/laoshu1.ExportJson");  //��������Ķ���
        armature_path_.push_back("laoshu2/laoshu2.ExportJson");
        armature_path_.push_back("laoshu3/laoshu3.ExportJson");
        armature_path_.push_back("laoshushengli/laoshushengli.ExportJson");
        armature_path_.push_back("tuzi1/tuzi1.ExportJson");  //��������Ķ���
        armature_path_.push_back("tuzi2/tuzi2.ExportJson");
        armature_path_.push_back("tuzi3/tuzi3.ExportJson");
        armature_path_.push_back("tuzishengli/tuzishengli.ExportJson");
        armature_path_.push_back("pintulibao/pintulibao.ExportJson");
        armature_path_.push_back("ranseqiu/ranseqiu.ExportJson");
        armature_path_.push_back("juesejinengTX2/juesejinengTX2.ExportJson");
        armature_path_.push_back("juesejinengTX4/juesejinengTX4.ExportJson");
        armature_path_.push_back("juesejinengTX1/juesejinengTX1.ExportJson");
        armature_path_.push_back("jinengkuang/jinengkuang.ExportJson");
        armature_path_.push_back("choujiangkapianguang/choujiangkapianguang.ExportJson");
        armature_path_.push_back("baoshi TX/baoshi TX.ExportJson");
        armature_path_.push_back("pintulibao2/pintulibao2.ExportJson");
        armature_path_.push_back("shandian/shandian.ExportJson");
        armature_path_.push_back("shandian02/shandian02.ExportJson");
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
        //�����������÷���
        //if (path == "")
        //{
        //    sprite->setTexture(path);
        //}
        //else
        //{
        //    auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(path);
        //    sprite->setSpriteFrame(frame);
        //}
        //cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(path)
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

    //CenteredMenuItemSprite * SpriteTextureController::createMenuItemSprite(const std::string & path, const cocos2d::ccMenuCallback & callback)
    //{
    //    cocos2d::Sprite* item_select = this->createGameSpriteWithPath(path);
    //    item_select->setScale(GAME_MENU_SELECT_SCALE);
    //    cocos2d::Sprite* item_normal = this->createGameSpriteWithPath(path);
    //    CenteredMenuItemSprite* item = CenteredMenuItemSprite::create(item_normal, item_select, [=](cocos2d::Ref*) {
    //    });
    //    return item;
    //}

    cocos2d::Sprite * SpriteTextureController::createStageTypeSprite(const StageType & type)
    {
        return this->createGameSpriteWithPath(STAGETYPE_TO_GAME_PATH.at(type));
    }

    cocos2d::Sprite* SpriteTextureController::createMenuStageTypeSprite(const StageType& type)
    {
        return this->createGameSpriteWithPath(STAGE_MENU_STAGETYPE_TO_PATH.at(type));
    }

    //cocos2d::Sprite* SpriteTextureController::createStageTypeSprite(const StageType& type)
    //{
    //    this->setSpriteTexture(stagetype_to_path_[type], sp);
    //}

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
        this->readGameSceneBackgroundFile();
        this->addArmatureFile();
        //cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("puzzle_ui.plist");
    }

    void SpriteTextureController::setGrayShader(cocos2d::Sprite * sprite)
    {
        auto fileUtiles = cocos2d::FileUtils::getInstance();
        std::string fragmentFullPath = fileUtiles->fullPathForFilename(GREY_SCALE_FSH_PATH.c_str());
        std::string fragSource = fileUtiles->getStringFromFile(fragmentFullPath);
        cocos2d::GLProgram* shader_program = cocos2d::GLProgram::createWithByteArrays(cocos2d::ccPositionTextureColor_noMVP_vert, fragSource.c_str());
        cocos2d::GLProgramState* program_state = cocos2d::GLProgramState::getOrCreateWithGLProgram(shader_program);
        sprite->setGLProgramState(program_state);
    }

    void SpriteTextureController::setNormalShader(cocos2d::Sprite * sprite)
    {
        auto fileUtiles = cocos2d::FileUtils::getInstance();
        std::string fragmentFullPath = fileUtiles->fullPathForFilename(NORMAL_FSH_PATH.c_str());
        std::string fragSource = fileUtiles->getStringFromFile(fragmentFullPath);
        cocos2d::GLProgram* shader_program = cocos2d::GLProgram::createWithByteArrays(cocos2d::ccPositionTextureColor_noMVP_vert, fragSource.c_str());
        cocos2d::GLProgramState* program_state = cocos2d::GLProgramState::getOrCreateWithGLProgram(shader_program);
        sprite->setGLProgramState(program_state);
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
    //    //��ģ�������ͼƬ�����һ��ͼƬ 
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
        //cocos2d::utils::captureScreen();
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

        //cocos2d::RenderTexture* textureScreen = cocos2d::RenderTexture::create(100, 100);
        //cocos2d::Texture2D* t = new cocos2d::Texture2D;
        //t->initWithImage(textureScreen->newImage(true));
        //textureScreen->newImage(true);
        //cocos2d::Sprite::createWithTexture(t);
        //cocos2d::Sprite* sp = cocos2d::Sprite::createWithTexture(textureScreen->getSprite());
        //cocos2d::Sprite::createWithTexture(textureScreen->getSprite()->getTexture());
    }

    //cocos2d::RenderTexture* SpriteTextureController::SpriteBlurer(cocos2d::Sprite* pSprite, const float fRadius, const float fSampleNum)
    //{
    //    //ģ��������ʱ����  
    //    auto pSptBlur = SpriteBlur::create(pSprite, fRadius, fSampleNum);
    //    pSptBlur->setRotationSkewX(180.0f);
    //    pSptBlur->setPositionX(pSptBlur->getContentSize().width / 2);
    //    pSptBlur->setPositionY(pSptBlur->getContentSize().height / 2);
    //    //ʹ�þ���ߴ��ʼ��һ���յ���Ⱦ�������  
    //    cocos2d::RenderTexture* textureScreen = cocos2d::RenderTexture::create(pSptBlur->getContentSize().width, pSptBlur->getContentSize().height);
    //    //��ʼ��ȡ  
    //    textureScreen->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
    //    //�����ڵ�����������texure��  
    //    pSptBlur->visit();
    //    //������ȡ  
    //    textureScreen->end();
    //    return textureScreen;
    //}

    //void SpriteTextureController::screenShot(const bool bIsSave)
    //{
    //    //ʹ����Ļ�ߴ��ʼ��һ���յ���Ⱦ�������  
    //    cocos2d::Size sizeWin = cocos2d::Director::getInstance()->getWinSize();
    //    cocos2d::RenderTexture* textureScreen = cocos2d::RenderTexture::create(sizeWin.width, sizeWin.height, cocos2d::Texture2D::PixelFormat::RGBA8888);
    //    //������ݲ���ʼ��ȡ  
    //    //textureScreen->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
    //    textureScreen->begin();
    //    //���������ڵ�����������texure��  
    //    cocos2d::Director::getInstance()->getRunningScene()->visit();
    //    //������ȡ  
    //    textureScreen->end();

    std::string SpriteTextureController::getPropPathWithKey(const std::string & key)
    {
        return std::string();
    }

    //    if (bIsSave)
    //    {//����ΪPNGͼ  
    //        textureScreen->saveToFile("ScreenShot.png", cocos2d::Image::Format::PNG, true, nullptr);
    //    }
    //    //cocos2d::utils::captureScreen([=](bool succeed, const std::string& outputFile) {}, "ScreenShot.png");
    //}     
    //cocos2d::Sprite * SpriteTextureController::getScreenShot()
    //{
    //    cocos2d::Size sizeWin = cocos2d::Director::getInstance()->getWinSize();
    //    cocos2d::RenderTexture* textureScreen = cocos2d::RenderTexture::create(sizeWin.width, sizeWin.height, cocos2d::Texture2D::PixelFormat::RGBA8888);
    //    //������ݲ���ʼ��ȡ  
    //    //textureScreen->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
    //    textureScreen->begin();
    //    //���������ڵ�����������texure��  
    //    cocos2d::Director::getInstance()->getRunningScene()->visit();
    //    //������ȡ  
    //    textureScreen->end();
    //    return nullptr;
    //}
    cocos2d::Sprite* SpriteTextureController::createPropSpriteWithKey(const std::string& key)
    {
        if (PROP_KEY_TO_PATH.find(key) == PROP_KEY_TO_PATH.end())
        {
            return  DecalsFactory::getInstance()->createNextDecalWithType(key);
        }
        return this->createGameSpriteWithPath(PROP_KEY_TO_PATH.at(key));
    }
    cocos2d::ui::TextBMFont * SpriteTextureController::createWhitePurpleFnt(const std::string & str)
    {
        return cocos2d::ui::TextBMFont::create(str, GAME_NUMBLE_FONT_PATH);;
    }
}