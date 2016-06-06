#include "ExhibitionNumble.h"
#include "cocostudio\CocoStudio.h"
#include "XMLTool.h"
const std::string EXHIBITION_NUMBLE_CSB_PATH = "ExhibitionNumble.csb";
const std::string NUMBLE_LABEL_NAME = "AtlasLabel_1";
namespace bubble_second {
    ExhibitionNumble::ExhibitionNumble()
    {
    }

    bool ExhibitionNumble::init(int numbel)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->loadCSB();
        this->setString(XMLTool::convertIntToString(numbel));
        return true;
    }

    void ExhibitionNumble::loadCSB()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(EXHIBITION_NUMBLE_CSB_PATH);
        assert(csb_node);
        this->addChild(csb_node);
        numble_label_ = dynamic_cast<cocos2d::ui::TextAtlas*>(csb_node->getChildByName(NUMBLE_LABEL_NAME));
        assert(numble_label_);
    }


    ExhibitionNumble * ExhibitionNumble::create(int numble)
    {
        ExhibitionNumble *pRet = new(std::nothrow) ExhibitionNumble();
        if (pRet && pRet->init(numble))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }

    ExhibitionNumble::~ExhibitionNumble()
    {
    }
    void ExhibitionNumble::setString(const std::string & str)
    {
        numble_label_->setString(str);
    }
}