#include "DecalsFactory.h"
//#include "SpriteTextureController.h"

namespace bubble_second {
    DecalsFactory::DecalsFactory()
    {
        numble_to_index_[1] = cocos2d::Vec2(1, 1);
        numble_to_index_[2] = cocos2d::Vec2(2, 1);
        numble_to_index_[3] = cocos2d::Vec2(1, 2);
        numble_to_index_[4] = cocos2d::Vec2(2, 2);
        numble_to_index_[5] = cocos2d::Vec2(1, 3);
        numble_to_index_[6] = cocos2d::Vec2(3, 1);
        //cocos2d::ValueMap data;
        //cocos2d::ValueVector charactor_data;
        //charactor_data.push_back(cocos2d::Value(1));
        //charactor_data.push_back(cocos2d::Value(2));
        //charactor_data.push_back(cocos2d::Value(3));
        //cocos2d::ValueMap decals_data;
        //decals_data["path"] = "decals (1).png";
        //decals_data["goods"] = charactor_data;
        //cocos2d::ValueVector decals_vector;
        //decals_vector.push_back(cocos2d::Value(decals_data));
        //data["decals_charactor"] = decals_vector;
        //cocos2d::FileUtils::getInstance()->writeValueMapToFile(data, cocos2d::FileUtils::getInstance()->getWritablePath() + "decalsUserData.plist");
    }


    DecalsFactory::~DecalsFactory()
    {
    }
    cocos2d::Sprite * DecalsFactory::createDecal(const std::string & path, int index_x, int index_y)
    {
        assert(index_x>0 && index_y>0);
        cocos2d::Sprite* sp = cocos2d::Sprite::create(path);
        float x_offset = sp->getContentSize().width / 2;
        float y_offset = sp->getContentSize().height / 3;

        sp->setTextureRect(cocos2d::Rect(x_offset*(index_x-1), y_offset*(index_y - 1), x_offset, y_offset));
        return sp;
    }
    cocos2d::Sprite * DecalsFactory::createDecalWithNumble(const std::string & path, int numble)
    {
        return this->createDecal(path, this->convertDecalNumbleToIndex(numble).x, this->convertDecalNumbleToIndex(numble).y);
    }
    cocos2d::Vec2 DecalsFactory::convertDecalNumbleToIndex(int numble)
    {
        return numble_to_index_[numble];
    }
}