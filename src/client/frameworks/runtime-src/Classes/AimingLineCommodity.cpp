#include "AimingLineCommodity.h"
//#include "SpriteTextureController.h"
#include "GameTextInfo.h"
const std::string AIMING_LIME_COMMODITY_CSB_PATH = "AimingLineCommodity.csb";
namespace bubble_second {
    AimingLineCommodity::AimingLineCommodity()
    {
    }

    AimingLineCommodity::~AimingLineCommodity()
    {
    }

    bool AimingLineCommodity::init()
    {
        if (!EnterGamePropsView::init(AIMING_LIME_COMMODITY_CSB_PATH))
        {
            return false;
        }
        //this->addCostView(GameTextInfo::getInstance()->getCommodityCoinValueWithKey(COMMODITY_AIMING_LINE_KEY));
        this->setName(AIMING_LINE_COMMODITY_NAME);
        return true;
    }
}