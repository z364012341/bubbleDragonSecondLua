#include "BubbleFactory.h"
#include "LightningBubble.h"
#include "ColorBubble.h"
#include "DarkCloudBubble.h"
#include "BlackHoleBubble.h"
#include "BombBombBubble.h"
#include "ColorBombBubble.h"
#include "BombPropertyBubble.h"
#include "NullBubble.h"
#include "RainbowSealBubble.h"
#include "MutipleSealBubble.h"
#include "WindmillBubble.h"
#include "AddBubbleNumbleBubble.h"
#include "SkillDyeingBubble.h"
#include "SkillColorBombBubble.h"
#include "SkillBigBombBubble.h"
#include "SkillStavesBubble.h"
#include "BlackObstacleBubble.h"
const std::map<int, std::string> KEY_TO_PATH = {
    {kBubbleTransparent, BUBBLE_NO_COLOR_PATH},
    {kBubbleYellow, BUBBLE_YELLOW_PATH},
    {kBubblePurple, BUBBLE_PURPLE_PATH},
    {kBubbleBlue, BUBBLE_BLUE_PATH},
    {kBubbleRed, BUBBLE_RED_PATH},
    {kBubbleGreen, BUBBLE_GREEN_PATH},
    {kBubbleOrange, BUBBLE_ORANGE_PATH},
    {kBubblePinkDeprecated, BUBBLE_PINK_PATH},
    {kBubbleLightning, BUBBLE_LIGHTNING_PATH},
    {kBubbleDarkCloud, BUBBLE_DARKCLOUD_PATH},
    {kBubbleBlackHole, BUBBLE_BLACKHOLE_PATH},
    {kBubbleBombBomb, BUBBLE_BOMB_BOMB_PATH},
    {kBubbleColorBomb, PROPS_COLOR_BOMB_PATH},
    {kBubbleBombBombProperty, PROPS_BOMB_BOMB_PATH},
    {kBubbleRainbowSeal, BUBBLE_RAINBOW_SEAL_PATH},
    {kBubbleComponent, BUBBLE_NO_COLOR_PATH},
    {kBubbleMutipleSeal1, BUBBLE_MUTIPLE_SEAL_1_PATH},
    {kBubbleMutipleSeal3, BUBBLE_MUTIPLE_SEAL_3_PATH},
    {kBubbleMutipleSeal7, BUBBLE_MUTIPLE_SEAL_7_PATH},
    {kBubbleWindmill, ""},
    {kBubbleAddNumbleBubble, ADD_BUBBLE_NUMBLE_BUBBLE_PATH} ,
    { kBubbleBlackObstacle, BLACK_OBSTACLE_BUBBLE_PATH }
};
const std::map<int, std::function<bubble_second::BaseBubble*(int, int)>> KEY_TO_HANDLE_MAP = {
    { kBubbleTransparent , [=](int, int) {return bubble_second::NullBubble::create(); } },
    { kBubbleYellow, [=](int type, int cloud) {return bubble_second::ColorBubble::createWithType(type, cloud); } },
    { kBubblePurple, [=](int type, int cloud) {return bubble_second::ColorBubble::createWithType(type, cloud); } },
    { kBubbleBlue, [=](int type, int cloud) {return bubble_second::ColorBubble::createWithType(type, cloud); } },
    { kBubbleRed, [=](int type, int cloud) {return bubble_second::ColorBubble::createWithType(type, cloud); } },
    { kBubbleGreen, [=](int type, int cloud) {return bubble_second::ColorBubble::createWithType(type, cloud); } },
    { kBubbleOrange, [=](int type, int cloud) {return bubble_second::ColorBubble::createWithType(type, cloud); } },
    { kBubblePinkDeprecated, [=](int type, int cloud) {return bubble_second::ColorBubble::createWithType(type, cloud); } },
    { kBubbleLightning, [=](int, int) {return bubble_second::LightningBubble::create(); } },
    { kBubbleDarkCloud, [=](int, int) {return bubble_second::DarkCloudBubble::create(); } },
    { kBubbleBlackHole, [=](int, int) {return bubble_second::BlackHoleBubble::create(); } },
    { kBubbleBombBomb, [=](int, int) {return bubble_second::BombBombBubble::create(); } },
    { kBubbleColorBomb, [=](int, int) {return bubble_second::ColorBombBubble::create(); } },
    { kBubbleBombBombProperty, [=](int, int) {return bubble_second::BombPropertyBubble::create(); } },
    { kBubbleRainbowSeal, [=](int, int) {return bubble_second::RainbowSealBubble::create(); } },
    { kBubbleMutipleSeal1, [=](int, int) {return bubble_second::MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_1); } },
    { kBubbleMutipleSeal3, [=](int, int) {return bubble_second::MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3); } },
    { kBubbleMutipleSeal7, [=](int, int) {return bubble_second::MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_7); } },
    { kBubbleWindmill, [=](int, int) {return  bubble_second::WindmillBubble::create(); } },
    { kBubbleAddNumbleBubble, [=](int, int) {return  bubble_second::AddBubbleNumbleBubble::create(); } },
    { kBubbleSkillDyeingBubble, [=](int, int) {return  bubble_second::SkillDyeingBubble::create(); } },
    { kBubbleSkillColorBombBubble, [=](int, int) {return  bubble_second::SkillColorBombBubble::create(); } },
    { kBubbleSkillBigBombBubble, [=](int, int) {return  bubble_second::SkillBigBombBubble::create(); } },
    { kBubbleSkillStavesBubble, [=](int, int) {return  bubble_second::SkillStavesBubble::create(); } },
    { kBubbleBlackObstacle, [=](int, int) {return  bubble_second::BlackObstacleBubble::create(); } }
};
namespace bubble_second {
    BubbleFactory::BubbleFactory()
    {
        //this->initHandleMap();
        //this->initBubblePath();
    }
    BubbleFactory::~BubbleFactory()
    {
    }

    //void BubbleFactory::initHandleMap()
    //{
        //key_to_handle_map_[kBubbleTransparent] = [=](int, int) {return NullBubble::create(); };
        //key_to_handle_map_[kBubbleYellow] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        //key_to_handle_map_[kBubblePurple] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        //key_to_handle_map_[kBubbleBlue] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        //key_to_handle_map_[kBubbleRed] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        //key_to_handle_map_[kBubbleGreen] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        //key_to_handle_map_[kBubbleOrange] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        //key_to_handle_map_[kBubblePinkDeprecated] = [=](int type, int cloud) {return ColorBubble::createWithType(type, cloud); };
        //key_to_handle_map_[kBubbleLightning] = [=](int, int) {return LightningBubble::create(); };
        //key_to_handle_map_[kBubbleDarkCloud] = [=](int, int) {return DarkCloudBubble::create(); };
        //key_to_handle_map_[kBubbleBlackHole] = [=](int, int) {return BlackHoleBubble::create(); };
        //key_to_handle_map_[kBubbleBombBomb] = [=](int, int) {return BombBombBubble::create(); };
        //key_to_handle_map_[kBubbleColorBomb] = [=](int, int) {return ColorBombBubble::create(); };
        //key_to_handle_map_[kBubbleBombBombProperty] = [=](int, int) {return BombPropertyBubble::create(); };
        //key_to_handle_map_[kBubbleRainbowSeal] = [=](int, int) {return RainbowSealBubble::create(); };
        //key_to_handle_map_[kBubbleMutipleSeal1] = [=](int, int) {return MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_1); };
        //key_to_handle_map_[kBubbleMutipleSeal3] = [=](int, int) {return MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3); };
        //key_to_handle_map_[kBubbleMutipleSeal7] = [=](int, int) {return MutipleSealBubble::createWithComponentNumble(BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_7); };
        //key_to_handle_map_[kBubbleWindmill] = [=](int, int) {return  WindmillBubble::create(); };
        //key_to_handle_map_[kBubbleAddNumbleBubble] = [=](int, int) {return  AddBubbleNumbleBubble::create(); };
        //key_to_handle_map_[kBubbleSkillDyeingBubble] = [=](int, int) {return  SkillDyeingBubble::create(); };
        //key_to_handle_map_[kBubbleSkillColorBombBubble] = [=](int, int) {return  SkillColorBombBubble::create(); };
        //key_to_handle_map_[kBubbleSkillBigBombBubble] = [=](int, int) {return  SkillBigBombBubble::create(); };
        //key_to_handle_map_[kBubbleSkillStavesBubble] = [=](int, int) {return  SkillStavesBubble::create(); };
        //key_to_handle_map_[kBubbleBlackObstacle] = [=](int, int) {return  BlackObstacleBubble::create(); };
    //}

    //void bubble_second::BubbleFactory::initBubblePath()
    //{
    //    key_to_path[kBubbleTransparent] = BUBBLE_NO_COLOR_PATH;
    //    key_to_path[kBubbleYellow] = BUBBLE_YELLOW_PATH;
    //    key_to_path[kBubblePurple] = BUBBLE_PURPLE_PATH;
    //    key_to_path[kBubbleBlue] = BUBBLE_BLUE_PATH;
    //    key_to_path[kBubbleRed] = BUBBLE_RED_PATH;
    //    key_to_path[kBubbleGreen] = BUBBLE_GREEN_PATH;
    //    key_to_path[kBubbleOrange] = BUBBLE_ORANGE_PATH;
    //    key_to_path[kBubblePinkDeprecated] = BUBBLE_PINK_PATH;
    //    key_to_path[kBubbleLightning] = BUBBLE_LIGHTNING_PATH;
    //    key_to_path[kBubbleDarkCloud] = BUBBLE_DARKCLOUD_PATH;
    //    key_to_path[kBubbleBlackHole] = BUBBLE_BLACKHOLE_PATH;
    //    key_to_path[kBubbleBombBomb] = BUBBLE_BOMB_BOMB_PATH;
    //    key_to_path[kBubbleColorBomb] = PROPS_COLOR_BOMB_PATH;
    //    key_to_path[kBubbleBombBombProperty] = PROPS_BOMB_BOMB_PATH;
    //    key_to_path[kBubbleRainbowSeal] = BUBBLE_RAINBOW_SEAL_PATH;
    //    key_to_path[kBubbleComponent] = BUBBLE_NO_COLOR_PATH;
    //    key_to_path[kBubbleMutipleSeal1] = BUBBLE_MUTIPLE_SEAL_1_PATH;
    //    key_to_path[kBubbleMutipleSeal3] = BUBBLE_MUTIPLE_SEAL_3_PATH;
    //    key_to_path[kBubbleMutipleSeal7] = BUBBLE_MUTIPLE_SEAL_7_PATH;
    //    key_to_path[kBubbleWindmill] = "";
    //    key_to_path[kBubbleAddNumbleBubble] = ADD_BUBBLE_NUMBLE_BUBBLE_PATH;

    //}

    BaseBubble* BubbleFactory::createBubbleWithType(int type, int cloud)
    {
        BaseBubble* bubble = nullptr;
        if (KEY_TO_HANDLE_MAP.find(type) != KEY_TO_HANDLE_MAP.end())
        {
            bubble = KEY_TO_HANDLE_MAP.at(type)(type, cloud);
        }
        return bubble;
    }

    BaseBubble* BubbleFactory::createBubbleWithType(int type, cocos2d::Vec2 index, cocos2d::Vec2 point, int cloud)
    {
        BaseBubble* bubble = this->createBubbleWithType(type, cloud);
        if (!bubble)
        {
            return nullptr;
        }
        bubble->setBubbleIndex(index);
        bubble->setPosition(point);
        return bubble;
    }

    std::string BubbleFactory::getPathWithType(int type)
    {
        return KEY_TO_PATH.at(type);
    }
}