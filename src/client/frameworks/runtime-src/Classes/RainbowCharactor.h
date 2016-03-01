//*******************************************************************************
//������   : RainbowCharactor
//����     : <�ʺ��ӡ���������>
//-------------------------------------------------------------------------------
//��ע     :
//          
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _RAINBOW_CHARACTOR_H_
#define _RAINBOW_CHARACTOR_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio/CocoStudio.h"
namespace bubble_second {
    class RainbowSealBubble;
    class BaseBubble;
    class RainbowCharactor : public cocos2d::Node
    {
    public:
        //CREATE_FUNC(RainbowCharactor);
        static RainbowCharactor* createWithFile(const std::string& path)
        {
            RainbowCharactor *pRet = new(std::nothrow) RainbowCharactor();
            if (pRet && pRet->initWithFile(path))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
        ~RainbowCharactor();
        //��ʼ��ӡ
        void beginSealingCharactor(RainbowSealBubble* bubble);
        //��ӡת��
        void moveSealintCharactor(RainbowSealBubble* bubble, const cocos2d::Vec2& from_point);
        //�ı��ӡ����ɫ(�ı����ŵ�С����ɫ)
        void setRainbowColor(BubbleType color);
        //���ö�����·��
        void setArmaturePath(const std::string& path);
        std::string getArmaturePath();
    private:
        RainbowCharactor();
        //bool init();
        bool initWithFile(const std::string& path);
        void initTexture();
        void setSealedBubble(BaseBubble* bubble);
        BaseBubble* getSealedBubble();
        void addCharactorArmature();
        //void runFlyingAnimation(RainbowSealBubble* bubble, const cocos2d::Vec2& armature_point, bool armature_point_need_convert = true);
    private:
        //�������������е���
        BaseBubble* sealed_bubble_;
        cocos2d::Sprite* rainbow_swirl_;
        cocos2d::Sprite* rainbow_background_;
        std::string armature_path_;
    };
}
#endif //_RAINBOW_CHARACTOR_H_