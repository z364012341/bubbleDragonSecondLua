//*******************************************************************************
//�ļ���         : <BarrelHead.h>
//�ļ�ʵ�ֹ���  : <�·�ˮͰui��Ͱ��ͷ����Ե>
//*******************************************************************************
#ifndef _BARREL_HEAD_H_
#define _BARREL_HEAD_H_
#include "cocos2d.h"
namespace bubble_second {
    class BarrelHead : public cocos2d::Node
    {
    public:
        CREATE_FUNC(BarrelHead);
        ~BarrelHead();
        void contactOnce();
    private:
        BarrelHead();
        bool init();
    };
}
#endif