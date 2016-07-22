//*******************************************************************************
//文件名         : <BarrelHead.h>
//文件实现功能  : <下方水桶ui的桶的头部边缘>
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