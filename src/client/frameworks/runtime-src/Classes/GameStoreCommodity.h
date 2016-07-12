//*******************************************************************************
//������   : GameStoreCommodity
//����     : <�̳ǵ���Ʒչʾ, ��Ʒͼ����� "x����">
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_STORE_COMMODITY_H_
#define _GAME_STORE_COMMODITY_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameStoreCommodity : public cocos2d::Node
    {
    public:
        static GameStoreCommodity* createWithPropKeyAndNumble(const std::string& prop_key, const std::string& numble);
        ~GameStoreCommodity();
    private:
        GameStoreCommodity();
        bool initWithPropKeyAndNumble(const std::string& prop_key, const std::string& numble);
    };
}
#endif