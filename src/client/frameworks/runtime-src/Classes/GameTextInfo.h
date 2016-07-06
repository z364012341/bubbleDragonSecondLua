//*******************************************************************************
//������   : GameTextInfo
//����     : <��Ϸ������Ϣ��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_TEXT_INFO_H_
#define _GAME_TEXT_INFO_H_
#include "BubbleSecondConstant.h"
const std::string GAME_TEXT_LEVEL_NUMBLE_1_KEY = "alert_level_1";
const std::string GAME_TEXT_LEVEL_NUMBLE_2_KEY = "alert_level_2";
const std::string COMMODITY_ADD_10_BUBBLE_KEY = "add_10_bubble";   //��10����
const std::string COMMODITY_AIMING_LINE_KEY = "aiming_line"; //��׼�ߵ���
const std::string COMMODITY_ADD_SPECIAL_KEY = "add_special_bubble"; //��3����������
const std::string COMMODITY_DECALS_LOTTERY_BEGIN_KEY = "decals_lottery_begin"; //��ֽ�齱��ʼ����
const std::string COMMODITY_DECALS_LOTTERY_CONTINUE_KEY = "decals_lottery_continue"; //��ֽ�����齱����
const std::string GAME_STRENGTH_MAX_KEY = "strength_max"; //����ȫ��
namespace bubble_second {
    class GameTextInfo
    {
    public:
        GETINSTANCE_FUNC(GameTextInfo);
        ~GameTextInfo();
        std::string getTextInfoWithKey(const std::string& key) const;
        std::string getTextInfoWithStageType(const StageType& type);
        //std::string getCommodityCoinNumbleWithKey(const std::string& key) const;
        //std::string getCommodityDiamondNumbleWithKey(const std::string& key) const;
        //cocos2d::Value getCommodityCoinValueWithKey(const std::string& key) const;
        cocos2d::ValueMap getCommodityDataWithKey(const std::string& key) const;
        void plistToMap();
    private:
        GameTextInfo();
    private:
        cocos2d::ValueMap plist_map_;
        cocos2d::ValueMap commodity_map_;
    };
}
#endif //_GAME_TEXT_INFO_H_