#include "AddBubbleNumbleCommodity.h"
//#include "SpriteTextureController.h"

const std::string ENTER_GAME_PROPS_VIEW_ADD_BUBBLE_PROPS_PATH = GAME_COMMODITY_TEN_BUBBLE_PATH;
const std::string ADD_BUBBLE_NUMBLE_COMMODITY_CSB_PATH = "AddBubbleNumbleCommodity.csb";
namespace bubble_second {
    AddBubbleNumbleCommodity::AddBubbleNumbleCommodity()
    {
    }


    AddBubbleNumbleCommodity::~AddBubbleNumbleCommodity()
    {
    }

    bool AddBubbleNumbleCommodity::init()
    {
        if (!EnterGamePropsView::init(ADD_BUBBLE_NUMBLE_COMMODITY_CSB_PATH))
        {
            return false;
        }
        this->setCostLabelStringWithKey(COMMODITY_ADD_10_BUBBLE_KEY);
        this->setName(ADD_BUBBLE_NUMBLE_COMMODITY_NAME);
        return true;
    }
}