//*******************************************************************************
//������   : GamePropsCostTag
//����     : <���ߵļ۸��ǩ>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_PROPS_COST_TAG_H_
#define _GAME_PROPS_COST_TAG_H_
#include "cocos2d.h"
namespace bubble_second {
    class GamePropsCostTag : public cocos2d::Node
    {
    public:
        static GamePropsCostTag* createWithKey(const std::string& prop_key);
        //����cost_type�ǻ�������, ��ʯ���߽��, numble������
        static GamePropsCostTag* createWithCostTypeAndNumble(const std::string& cost_type, cocos2d::Value numble);
        static GamePropsCostTag* createDecalsLotteryBeginTag();
        static GamePropsCostTag* createDecalsLotteryContinueTag();
        GamePropsCostTag();
        ~GamePropsCostTag();
        void onEnter() override;
        void onExit() override;
        void changeSelectedState();
        bool getSelectedState();
        //�Ƿ����㹻��Ǯ֧��
        bool canPay();
        //�۷�
        void pay();

        int getCostNumble();
    private:
        bool initWithKey(const std::string& prop_key);
        bool initWithCostTypeAndNumble(const std::string& cost_type, cocos2d::Value numble);
    private:
        cocos2d::Sprite* selected_sprite_ = nullptr;
        std::string cost_key_ = "";
        int cost_numble_ = 0;
        cocos2d::EventListenerCustom * listener_ = nullptr;
    };
}
#endif