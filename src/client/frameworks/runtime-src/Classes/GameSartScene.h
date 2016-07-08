//*******************************************************************************
//类名称   : GameSartScene
//功能     : <游戏的开始场景>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_START_SCENE_H_
#define _GAME_START_SCENE_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameSartScene : public cocos2d::Layer
    {
    public:
        //static cocos2d::Scene* createScene();
        CREATE_FUNC(GameSartScene);
        GameSartScene();
        ~GameSartScene();
    private:
        bool init();
    };
}
#endif