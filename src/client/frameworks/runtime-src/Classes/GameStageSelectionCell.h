//*******************************************************************************
//������   : GameStageSelectionCell
//����     : <�����ؿ�cell>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б���
//*******************************************************************************
#ifndef _GAME_STAGE_SELECTION_CELL_H_
#define _GAME_STAGE_SELECTION_CELL_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameStageSelectionCell : public cocos2d::Node
    {
    public:
        static GameStageSelectionCell* create();
        ~GameStageSelectionCell();
        //�жϴ������Ĺؿ��Ƿ��Ǳ�cell��
        bool isInCell(int level);
    private:
        GameStageSelectionCell();
        bool init();
        bool addBackground(int cell_numble);
        bool addSelectionMenu(int cell_numble);
        void setLevelMax(int level);
        int getLevelMax();
    private:
        cocos2d::Node* background_node_ = nullptr;
        int level_max_ = 0;
    };
}
#endif //_GAME_STAGE_SELECTION_CELL_H_