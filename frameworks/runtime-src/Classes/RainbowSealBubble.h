//*******************************************************************************
//�ļ���       : <RainbowSealBubble.h>
//�ļ�ʵ�ֹ���  : <�������Դ��ʺ��ӡ, �ֻز���>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _RAINBOW_SEAL_BUBBLE_H_
#define _RAINBOW_SEAL_BUBBLE_H_
#include "BaseComponentBubble.h"
namespace bubble_second {
    class RainbowCharactor;
    class BaseBubble;
    class RainbowSealBubble : public BaseComponentBubble
    {
    public:
        CREATE_FUNC(RainbowSealBubble);
        ~RainbowSealBubble();
        //int getBubbleComponentNumble() override;
        BubbleVector disposeRainbowSeal(BubbleType color);
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
        //�ı���ɫ
        void changeRainbowColor();
        void setSealedCharactor(RainbowCharactor* charactor);
        RainbowCharactor* getSealedCharactor();
        //float playTheSpecialEffects();
    private:
        RainbowSealBubble();
        bool init();
        //������ɫ
        void setRainbowColor(BubbleType color);
        BubbleType getRainbowColor();
        //�Ƿ����ӡ��ɫ���
        bool isEqualRainbowColor(BubbleType color);
        //�Ƿ��Ѿ���ӡ������
        bool isSealing();
        //���Ӵ�������
        void addStandbyAnimation();
    private:
        //��ӡ��ɫ
        BubbleType rainbow_color_;
        bool first_flag_;
        //�����ӡ������
        RainbowCharactor* sealed_charactor_;

    };
}
#endif //_RAINBOW_SEAL_BUBBLE_H_