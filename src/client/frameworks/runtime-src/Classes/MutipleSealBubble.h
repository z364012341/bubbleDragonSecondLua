//*******************************************************************************
//�ļ���       : <MutipleSealBubble.h>
//�ļ�ʵ�ֹ���  : <�������Դ����ط�ӡ, ��������ʧȥ�ҵ�����ӡ>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _MUTIPLE_SEAL_BUBBLE_H_
#define _MUTIPLE_SEAL_BUBBLE_H_
#include "BaseComponentBubble.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class MutipleSealBubble : public BaseComponentBubble
    {
    public:
        static MutipleSealBubble* createWithComponentNumble(int numble)
        {
            MutipleSealBubble *pRet = new(std::nothrow) MutipleSealBubble();
            if (pRet && pRet->initWithComponentNumble(numble))
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
        ~MutipleSealBubble();
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
        void setBubbleTexture(BubbleType type) override;
        void addBubbleStaticBody() override;
    private:
        MutipleSealBubble();
        bool initWithComponentNumble(int numble);
		void playStandbyAnimation();
		void runBubbleEffect(const std::string& name, const cocos2d::Vec2& point) override;
	private:
        cocostudio::Armature *armature_;
    };
}
#endif //_MUTIPLE_SEAL_BUBBLE_H_