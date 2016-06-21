//*******************************************************************************
//������   : GameCharactorSkillButton
//����     : <��Ϸ��ɫ���ܰ�ť>
//-------------------------------------------------------------------------------
//��ע     : <>
//           
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_CHARACTOR_SKILL_BUTTON_H_
#define _GAME_CHARACTOR_SKILL_BUTTON_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameCharactorSkillButton : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameCharactorSkillButton);
        ~GameCharactorSkillButton();
    private:
        GameCharactorSkillButton();
        bool init();
    private:
        std::map<std::string, std::map<std::string, std::string>> charactor_to_path_;
    };
}
#endif