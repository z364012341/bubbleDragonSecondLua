//*******************************************************************************
//类名称   : GamePlayController
//功能     : <游戏场景控制器类, 负责碰撞和触摸处理>
//-------------------------------------------------------------------------------
//备注     : <场景控制类,负责碰撞和触摸的回调>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_PLAY_CONTROLLER_H_
#define _GAME_PLAY_CONTROLLER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameBubbleMap;
    class BubbleColorPicker;
    class BaseBubble;
    class GameScene;
    typedef BaseBubble WeaponBox;  
    typedef int TouchDirection;
    class GamePlayController //: public cocos2d::Layer
    {
    public:
        ~GamePlayController();
        GETINSTANCE_FUNC(GamePlayController);
    public:
        //gamescene的点击响应
        bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);// final;
        void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);// final;
        void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);// final;
        //碰撞
        bool onContactBegin(cocos2d::PhysicsContact& contact);
        void onContactSeparate(cocos2d::PhysicsContact& contact);
        //用于交换发射小球的点击响应
        bool exchangePrepareBubbleOnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
        void exchangePrepareBubbleOnTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
        void exchangePrepareBubbleOnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
        ////点击更换角色和宠物的图片
        //bool touchToChangeTexture(cocos2d::Touch *touch, cocos2d::Event *event);
        //void touchToMoveCharecter(cocos2d::Touch *touch, cocos2d::Event *event);
        //点击道具的响应
        bool touchPropertyBegan(cocos2d::Touch *touch, cocos2d::Event *event);
        void touchPropertyMoved(cocos2d::Touch *touch, cocos2d::Event *event);
        void touchPropertyEnded(cocos2d::Touch *touch, cocos2d::Event *event);
        //点击选择小球
        bool touchSelectBubble(cocos2d::Touch *touch, cocos2d::Event *event);
    public://初始化相关的成员函数
        //设置准备发射的小球
        void setPrepareBubble(BaseBubble* color_bubble);
        void clearPrepareBubble();
        BaseBubble* getPrepareBubble();
        //加载关卡地图数据
        void loadStageMap(int numble);
        //设置是否能点击发射小球
        void setBubbleShootEnabled(bool flag);
        //获取是否能点击发射小球
        bool getBubbleShootEnabled();
        //添加取色
        void addPrepareColor(BaseBubble* bubble);
        void addPrepareColorWithType(BubbleType type);
        //减少一个取色
        void subtractPrepareColor(BaseBubble* bubble);
        void subtractPrepareColorWithType(BubbleType type);
        //取色
        BubbleType getBubbleColorFromPicker();
        //BubbleType getBubbleColorInRange();
        //设置颜色范围
        void setBubbleColorRange();
        //处理小球消除后的颜色
        void prepareBubbleChangeType(BaseBubble* pre_second_bubble);
        //处理特殊泡泡的掉落
        void disposeBuffBubbleDown(BaseBubble* bubble);
        //多重封印消除时会掉落周围一圈小球
        void disposeRainbowSealBubbleEliminate(const cocos2d::Vec2& bubble_index);
        //处理周围的氤氲泡泡
        void disposeDarkCloudBubble(const cocos2d::Vec2& contact_index);
        //对空中泡泡进行检测
        void checkAirBubbles();
        //调整地图面板
        void adjustGameScenePosition();
        //检测屏幕内的泡泡
        void findBubblesInVisibleSize();
        //处理法杖选中的同色小球
        //void disposeSelectSameBubbles();
        //处理使用单手锤道具
        void disposeUseWoodenHammer();
        //设置武器选择的小球
        void setSelectBubble(WeaponBox* bubble);
        //处理使用魔法杖
        void disposeUseStaves();
        //旋转喵准器
        void disposeSightingDevice(const cocos2d::Vec2& touch_location, bool touch_began = false);
        //处理胜利
        void disposeVictory(); 
        //处理失败
        void disposeDefeat();
        //使用加特殊泡泡的道具
        void usedAddSpecialBubbleProps();
        //需要换准备球
        bool needExchangePrepareBubble(bool exchange_flag);

        void setTouchDirection(TouchDirection direction);
        TouchDirection getTouchDirection();
		//设置代理
        void setGameSceneDelegate(GameScene* scene_delegate);
		//发射小球
		void shootPrepareBubble();
        //获取顶部区域位置
        float getPlayAreaMaxY();
        //获取发射的准确位置
        cocos2d::Vec2 getShootingInitialPosition();
        //射线检测
        //void gamePhysicsRayCast(cocos2d::PhysicsRayCastCallbackFunc func, const cocos2d::Vec2 & point1, const cocos2d::Vec2 & point2);
        //道具中心小球
        //void disposeMinYCenterBubble();
        //判断失败
        void disposeCheckGameDefeat();
    private:
        //把准备的小球发射出去
		void dispatchShootEvent(const cocos2d::Vec2& touch_location);
        //根据方向获取点击的真正位置
        cocos2d::Vec2 getRealTouchPoint(const cocos2d::Vec2& touch_location);
        //根据输入的参数来分离两个node
        cocos2d::Vector<cocos2d::Node*> separateContactNodeWithName(const std::string& name, 
            cocos2d::Node* node_a, cocos2d::Node* node_b);
        cocos2d::Vector<cocos2d::Node*> separateContactNodeWithTag(int tag,
            cocos2d::Node* node_a, cocos2d::Node* node_b);
        //判断是否不用交换小球并且可以发射小球
        bool canShootingBubble(const cocos2d::Vec2& touch_location);
        //判断球是否可以发射
        bool isShootBubbleEnable(const cocos2d::Vec2& touch_location);
        //判断是否在发射区域
        bool isInShootArea(const cocos2d::Vec2& touch_location);
        //转换touch的坐标
        cocos2d::Vec2 convertGLToNodeSpace(const cocos2d::Vec2& touch_location, cocos2d::Node* node);
        //判断是否点击到这个target
        bool touchOnIt(const cocos2d::Vec2& point, cocos2d::Node* sprite);
        //获取两个点的角度
        //float getAngleWithVectors(const cocos2d::Vec2& point_1, const cocos2d::Vec2& point_2);
        //获取一个点跟发射小球的角度
        float getPrepareBubbleAngle(const cocos2d::Vec2& point);
        //获取喵准器的旋转角度
        float getTouchAngleForPrepareBubble(const cocos2d::Vec2& touch_location);
        bool isTouchUnderside();
        //设置方向
        void setTouchDirection(const cocos2d::Vec2& touch_point);

        //控制瞄准开关
        void turnOnSightingDevice(cocos2d::Vec2 point);
        void turnOffSightingDevice();
    private://碰撞相关的成员函数
        GamePlayController();
        void initHandleMap();
        typedef void(GamePlayController::*contactHandle)(cocos2d::Node*, cocos2d::Node*);
        void addContactHandleWithTwoNames(contactHandle handle, const std::string& name_1, const std::string& name_2);
        //碰到彩色的普通小球
        void disposeContactWithColorBubble(BaseBubble* flying_bubble, BaseBubble* contacted_bubble);
        //处理碰撞到小球的事件
        void disposeContactWithBubble(cocos2d::Node* flying_node, cocos2d::Node* contact_node);
        //处理碰撞到桶底的事件
        void disposeContactWithBarrelBottom(cocos2d::Node* barrel_node, cocos2d::Node* bubble_node);
        //处理碰到桶盖
        void disposeContactWithBarrelHead(cocos2d::Node* barrel_node, cocos2d::Node* bubble_node);
        //处理碰到得分挂件
        void disposeContactWithScoreWidget(cocos2d::Node* widget_node, cocos2d::Node* bubble_node);
        //处理碰到闪电小球
        //void disposeContactWithLightningBubble(BaseBubble* flying_node, BaseBubble* lightning_node);
        //处理碰到黑洞小球
        void disposeContactWithBlackHoleBubble(BaseBubble* flying_node, BaseBubble* lightning_node);
        //处理使用彩色爆炸小球
        void disposeUsingPropertyBubble(BaseBubble* flying_node, BaseBubble* contact_node);
        //处理碰到检测刚体
        //void disposeBubbleCast(cocos2d::Node* cast_node, cocos2d::Node* bubble_node);
        //是否可以交换小球
        bool exchangePrepareEnabled(const cocos2d::Vec2& touch_point/*, cocos2d::Node* event_node*/);
        bool touchInGunsight(const cocos2d::Vec2& touch_point);
        bool touchInGrass(const cocos2d::Vec2& touch_point);
        //处理碰撞面准点
        void disposeSightingPointContactBubble(cocos2d::Node* sight_node, cocos2d::Node* other_node);
        //void disposeSightingPointContactBorder(cocos2d::Node* sight_node, cocos2d::Node* other_node);
        //处理风车转转小球碰到边界
        void disposeWindmillBubbleBorder(cocos2d::Node* border_node, cocos2d::Node* other_node);
        void disposeContactWindmillBorder(cocos2d::Node* node_1, cocos2d::Node* node_2);
        //处理下落模式碰到边界
        void disposeFallBubbleBorder(cocos2d::Node* border_node, cocos2d::Node* other_node);
        //处理染色球
        void disposeUsingDyeingBubble(BaseBubble* dyeing_bubble, BaseBubble* bubble);
        //处理法杖球
        void disposeUsingStavesBubble(BaseBubble* staves_bubble, BaseBubble* bubble);

    private:
        enum Direction
        {
            kUnderside = -1,
            kUpside = 1
        };
        GameBubbleMap* bubble_map_ = nullptr;
        BaseBubble* prepare_bubble_;
        BubbleColorPicker* color_picker_ = nullptr;
        typedef void(GamePlayController::*pHandle)(BaseBubble*, BaseBubble*);
        std::map<BubbleType, pHandle> key_to_handle_map_;
        bool shoot_bubble_enabled_;
        //std::map<std::string, float> name_to_exchange_distance_;
        //std::map<BubbleType, pHandle> PROPS_TO_HANDLE;
        WeaponBox* select_bubble_;
        TouchDirection direction_;
        std::map<std::string, std::map<std::string, std::function<void(cocos2d::Node*, cocos2d::Node*)>>> name_to_contact_handle_;
        GameScene* game_scene_delegate_ = nullptr;

        const std::map<BubbleType, pHandle> PROPS_TO_HANDLE = {
            { kBubbleColorBomb , &bubble_second::GamePlayController::disposeUsingPropertyBubble },
            { kBubbleBombBombProperty , &bubble_second::GamePlayController::disposeUsingPropertyBubble },
            { kBubbleSkillDyeingBubble , &bubble_second::GamePlayController::disposeUsingDyeingBubble },
            { kBubbleSkillStavesBubble , &bubble_second::GamePlayController::disposeUsingStavesBubble }
        };
    };
}
#endif //_GAME_PLAY_CONTROLLER_H_