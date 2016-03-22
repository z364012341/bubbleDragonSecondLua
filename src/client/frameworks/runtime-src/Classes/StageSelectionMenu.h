//*******************************************************************************
//������   : StageSelectionMenu
//����     : <�ؿ���ѡ��ť>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAGE_SELECTION_MENU_H_
#define _STAGE_SELECTION_MENU_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameSamsung;
    enum HalfMoonSlashDirection
    {
      kLeft = -1,
      kRight = 1
    };
    class StageSelectionMenu : public cocos2d::Node
    {
    public:
        static StageSelectionMenu* create(int cell_numble, int level, const StageType& type);
        ~StageSelectionMenu();
        void turnOnBlink();
        //����ѡ��ť�ܲ��ܵ�
        void setSelectionMenuEnable(bool flag);
		bool isCurrentStage();
    private:
        StageSelectionMenu();
        bool init(int cell_numble, int level, const StageType& type);
        void addButton(int cell_numble, int level, const StageType& type);
        //����״̬
        void setMenuState(int cell_numble, int level);
        void setButtonEnable(bool flag);
        void addSamsung(int start_numble);
        void addStageLabel(int level);
        bool isButtonEnable();
        void addStageTypeTexture(const StageType& type);
        //���ߵİ���ն
        void halfMoonSlash(const HalfMoonSlashDirection& direction);
        //���㸸��layer
        cocos2d::Node* getSelectionLayer();
    private:
        GameSamsung* samsung_ = nullptr;
        cocos2d::Sprite* button_sp_ = nullptr;
        cocos2d::Vec2 touch_begin_position_;
        bool touch_enable_ = true;
        bool menu_enable_ = true;
        int cell_numble_ = 0;
        int level_numble_ = 0;
		//bool is_current_stage_flag_ = false;
    };
}
#endif //_STAGE_SELECTION_MENU_H_