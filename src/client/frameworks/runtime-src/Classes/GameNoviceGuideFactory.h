//*******************************************************************************
//������   : GameNoviceGuideFactory
//����     : <���������Ĺ�����>
//-------------------------------------------------------------------------------
//��ע     : <��������item>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_NOVICE_GUIDE_FACTORY_H_
#define _GAME_NOVICE_GUIDE_FACTORY_H_
#include "BubbleSecondConstant.h"

namespace bubble_second {
    
    class GameNoviceGuideFactory
    {
    public:
        GETINSTANCE_FUNC(GameNoviceGuideFactory);
        ~GameNoviceGuideFactory();
        cocos2d::Node* createGameBeginNoviceGuide();
        cocos2d::Node* createGameEndNoviceGuide();
        cocos2d::Node* createGameCharactorSkillNoviceGuide();
    private:
        GameNoviceGuideFactory();
        cocos2d::Node* createNoviceGuideAlertWithPath(const std::string& path);
        template<typename T>
        cocos2d::Node* createNoviceGuideAlertWithDataAndIndex(const std::map<T, std::string>& data, T key);

    };
}
#endif