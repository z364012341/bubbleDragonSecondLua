//*******************************************************************************
//类名称   : BombPropertyBubble
//功能     : <一炸炸两圈的炸弹道具, 发射出去的那个>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BOMB_PROPERTY_BUBBLE_H_
#define _BOMB_PROPERTY_BUBBLE_H_
#include "cocos2d.h"
#include "ColorBubble.h"
#include "cocostudio/CocoStudio.h"
const std::string TWO_ROUND_BOMB_EFFECT_NAME = "zhadanTX"; //炸2圈特效的名字
const std::string BOMB_BUBBLE_BOMB_BOMB_NAME = "baozhaTX";
namespace bubble_second {
    class BombPropertyBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(BombPropertyBubble);
        virtual ~BombPropertyBubble();
    public:
        void dispatchEventAfterShooted() override;
        void bubbleEliminate(int = 0) override;
        float playTheSpecialEffects() override;
        void downFromAir() override;
        void setBubbleTexture(BubbleType) override;
        std::string getBubbleSightingDevicePointPath() override;
        BombPropertyBubble();
    protected:
        bool init();
    private:
        cocostudio::Armature *armature_ = nullptr;
    };
}
#endif //_BOMB_PROPERTY_BUBBLE_H_