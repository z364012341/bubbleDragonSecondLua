//*******************************************************************************
//������   : GameSartScene
//����     : <��Ϸ�Ŀ�ʼ����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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