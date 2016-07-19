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
        cocos2d::Node* createGameBeginNoviceGuide(int stage_index);
    private:
        GameNoviceGuideFactory();
    private:
        cocos2d::ValueMap begin_guide_data_vm_;
        std::map<int, std::string> begin_guide_data_;
    };
}
#endif