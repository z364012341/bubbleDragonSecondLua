//*******************************************************************************
//类名称   : BaseBubble
//功能     : <作为泡泡的基类使用>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BASE_BUBBLE_H_
#define _BASE_BUBBLE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class ScoreWidget;
    class BaseBubble : public cocos2d::Sprite
    {
    public:   
        //bool initWithType(int type);
        BaseBubble();
        virtual ~BaseBubble();
        //CREATE_FUNC(BaseBubble);
        //static BaseBubble* createWithType(int type)
        //{ 
        //    BaseBubble *pRet = new(std::nothrow) BaseBubble();
        //    if (pRet && pRet->initWithType(type))
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

    public:
        //添加静态刚体
        virtual void addBubbleStaticBody();
        //添加动态刚体, 为了使小球从空中掉落
        virtual void addBubbleDynamicBody();
        //添加大风车肛体
        //virtual cocos2d::PhysicsBody* addBubbleWindmillBody();
        //添加作为发射小球的刚体
        //virtual void addBubblePrepareBody();
        //空堕
        virtual void downFromAir();
        //小球正常消除
        virtual void bubbleEliminate(int combo = 0);
        void bubbleEliminateInSequence(int combo = 0, float time = 0);
        void disposeAirShootBubble();
        //需要从地图中移除
        virtual bool needRemoveFromBubbleMap();
        //播放消除前的动画, 一般就是特殊泡泡才有这个动画
        virtual float playTheSpecialEffects();
		//拷贝
		BaseBubble* clone();
        //获取武器放上去的位置
        virtual cocos2d::Vec2 getBubblePropsWeaponPosition();
    public:
        void setBubbleType(int type);
        void setEliminateDelayTime(float time);
        float getEliminateDelayTime();
        virtual BubbleType getBubbleType();
        //index
        void setBubbleIndex(cocos2d::Vec2);
        cocos2d::Vec2 getBubbleIndex() const;
        //cocos2d::Vec2 getPointInMapNode();
        //播放撞击动画
        virtual void runBubbleEffect(const std::string& name, const cocos2d::Vec2& point);
        //自己的类型是否是普通的彩色小球
        bool isColorBubbleType();
        //自己类型是否是组件形式
        bool isComponentBubbleType();
        //自己是否掉落挂点
        bool isSuspensionPoint();
        //是否风车的轴心点
        bool isWindmillBubble();
        //类型是否相同
        bool isEqualType(BubbleType type);
        bool isIndexlargeThen(const cocos2d::Vec2& index);
        //增加点击事件
        virtual void addTouchEventListener();
        virtual void removeTouchEventListener();
        //获取小球的组件数量
        int getBubbleComponentNumble();
        void setBubbleComponentNumble(int numble);
        //设置flag , 判断是否已经碰撞过了
        void hadContacted();
        bool isHadContacted();
        //是否可以被道具消除
        virtual bool isEliminateByProperty();
        //获取瞄准线的图片的路径
        virtual std::string getBubbleSightingDevicePointPath();
        //是否是发射小球
        bool isShootBubble();
    protected:
        //重载比较运算符以便使用std::find
        //bool operator==(const BaseBubble& bubble);
        virtual bool init();
        virtual void setBubbleTexture(BubbleType type);
        //void setRepeatContactWidget(ScoreWidget* widget);
        void runLongContactEffect(const cocos2d::Vec2& point);
        void runShortContactEffect(const cocos2d::Vec2& point);
        //撞击特效action
        void runContactAction(const cocos2d::Vec2& point);
        //计算撞击特效的方向
        cocos2d::Vec2 getEffectDistance(const cocos2d::Vec2& point, float distance);
        void setSupensionPoint(bool flag);
        //设置发射小球flag
        void setShootBubble(bool flag);

    protected:
        std::map<std::string, std::function<void(const cocos2d::Vec2& point)>> key_to_handle_effect_;
    private:
        void initHandleEffect();
        void topEliminateBubbleFly();
    private:
        BubbleType bubble_type_;
        cocos2d::Vec2 bubble_in_map_index_;
        float run_eliminate_action_dalay_;
        bool suspension_flag_;
        int bubble_component_numble_;
        bool had_contacted_ = false;
        bool shoot_bubble_flag_ = false;
        bool once_eliminate_flag_ = false;
    };
}
#endif //_BASE_BUBBLE_H_
