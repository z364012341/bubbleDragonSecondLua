#include "DecalsFactory.h"
#include "UserDataManager.h"
#include "SpriteTextureController.h"
const std::string DECALS_DATA_PATH = "res/decalsData.plist";
const std::string DECALS_CHARACTOR_DATA_KEY = "decals_charactor";
const std::string DECALS_TREASURE_DATA_KEY = "decals_treasure";
const std::string DECALS_DATA_PATH_KEY = "path";
const std::string DECALS_DATA_GOOD_KEY = "goods";
namespace bubble_second {
    DecalsFactory::DecalsFactory()
    {
        //numble_to_index_[1] = cocos2d::Vec2(1, 1);
        //numble_to_index_[2] = cocos2d::Vec2(2, 1);
        //numble_to_index_[3] = cocos2d::Vec2(1, 2);
        //numble_to_index_[4] = cocos2d::Vec2(2, 2);
        //numble_to_index_[5] = cocos2d::Vec2(1, 3);
        //numble_to_index_[6] = cocos2d::Vec2(3, 1);
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

    cocos2d::Sprite * DecalsFactory::createDecalBackground(cocos2d::Sprite* decal, const std::string & path, int numble)
    {

        cocos2d::Vec2 index = this->convertDecalNumbleToIndex(numble, path);
        cocos2d::Vec2 max_index = this->getDecalsMaxIndexWithPath(path);
        cocos2d::Sprite* bg = SpriteTextureController::getInstance()->createGameSpriteWithPath("decals_bg.png");
        float width = bg->getContentSize().width / max_index.x;
        float height = decal->getContentSize().height;
        if (index.y == 1 || index.y == max_index.y)
        {
            height = 225.0f;
        }
        float x = width*(index.x - 1);
        float y = height;
        float ar_y = 0.5f;
        if (index.y == max_index.y)
        {
            y = bg->getContentSize().height - height;
            ar_y = 1.0f;
        }
        else if (index.y == 1)
        {
            y = 0.0f;
            ar_y = 0.0f;
        }
        bg->setTextureRect(cocos2d::Rect(x, y, width, height));
        float ar_x = 0.5;
        if (index.x == max_index.x && max_index.x>1 && index.y == 1)
        {
            ar_x = 0.0f;
            decal->setPosition(cocos2d::Vec2::ZERO);
            decal->setAnchorPoint(cocos2d::Vec2(ar_x, ar_y));
            bg->addChild(decal);
        }
        else if (index.x == 1 && max_index.x>1 && index.y == 1)
        {
            ar_x = 1.0f;
            decal->setAnchorPoint(cocos2d::Vec2(ar_x, ar_y));
            decal->setPosition(cocos2d::Vec2(bg->getContentSize().width, 0.0f));
            bg->addChild(decal);
        }
        else if (index.x == 1 && max_index.x==1 && index.y == 1)
        {
            decal->setAnchorPoint(cocos2d::Vec2(ar_x, ar_y));
            decal->setPosition(cocos2d::Vec2(bg->getContentSize().width/2, 0.0f));
            bg->addChild(decal);
        }
        else if (index.x == max_index.x && max_index.x>1 && index.y == max_index.y)
        { //右下角
            ar_x = 0.0f;
            decal->setPosition(cocos2d::Vec2(0.0f, bg->getContentSize().height));
            decal->setAnchorPoint(cocos2d::Vec2(ar_x, ar_y));
            bg->addChild(decal);
        }
        else if (index.x == 1 && max_index.x>1 && index.y == max_index.y)
        {
            ar_x = 1.0f;
            decal->setAnchorPoint(cocos2d::Vec2(ar_x, ar_y));
            decal->setPosition(cocos2d::Vec2(bg->getContentSize().width, bg->getContentSize().height));
            bg->addChild(decal);
        }
        else if (index.x == 1 && max_index.x == 1 && index.y == max_index.y)
        {
            decal->setAnchorPoint(cocos2d::Vec2(ar_x, ar_y));
            decal->setPosition(cocos2d::Vec2(bg->getContentSize().width / 2, bg->getContentSize().height));
            bg->addChild(decal);
        }
        else if (index.x == 1 && max_index.x > 1 && index.y < max_index.y && index.y > 1)
        {
            ar_x = 1.0f;
            decal->setAnchorPoint(cocos2d::Vec2(ar_x, ar_y));
            decal->setPosition(cocos2d::Vec2(bg->getContentSize().width, bg->getContentSize().height/2));
            bg->addChild(decal);
        }
        else if (index.x == max_index.x && max_index.x > 1 && index.y < max_index.y && index.y > 1)
        {
            ar_x = 0.0f;
            decal->setAnchorPoint(cocos2d::Vec2(ar_x, ar_y));
            decal->setPosition(cocos2d::Vec2(0, bg->getContentSize().height/2));
            bg->addChild(decal);
        }
        else
        {
            decal->setPosition(cocos2d::Vec2(bg->getContentSize().width/2, bg->getContentSize().height / 2));
            bg->addChild(decal);
        }
        if (max_index.x > 1)
        {
            bg->setScale(0.75f);
        }
        return bg;
    }


    DecalsFactory::~DecalsFactory()
    {
    }
    cocos2d::Sprite * DecalsFactory::createDecal(const std::string & path, int index_x, int index_y)
    {
        assert(index_x>0 && index_y>0);
        cocos2d::Sprite* sp = cocos2d::Sprite::create(path);
        cocos2d::Vec2 max_index = this->getDecalsMaxIndexWithPath(path);
        float x_offset = sp->getContentSize().width / max_index.x;
        float y_offset = sp->getContentSize().height / max_index.y;
        sp->setTextureRect(cocos2d::Rect(x_offset*(index_x-1), y_offset*(index_y - 1), x_offset, y_offset));
        return sp;
    }
    cocos2d::Sprite * DecalsFactory::createDecalWithNumble(const std::string & path, int numble)
    {
        return this->createDecal(path, this->convertDecalNumbleToIndex(numble, path).x, this->convertDecalNumbleToIndex(numble, path).y);
    }
    cocos2d::Vec2 DecalsFactory::convertDecalNumbleToIndex(int numble, const std::string & path)
    {
        cocos2d::Vec2 max_index = this->getDecalsMaxIndexWithPath(path);

        int x = numble % (int)max_index.x == 0 ? max_index.x : numble % (int)max_index.x;
        int y = ceil(numble/ max_index.x);
        return cocos2d::Vec2(x, y);
    }
    void DecalsFactory::loadDecalsData()
    {
        assert(cocos2d::FileUtils::getInstance()->isFileExist(DECALS_DATA_PATH));
        decals_data_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(DECALS_DATA_PATH);
    }
    cocos2d::ValueVector DecalsFactory::getDecalsCharactorData()
    {
        return decals_data_[DECALS_CHARACTOR_DATA_KEY].asValueVector();
    }
    cocos2d::ValueVector DecalsFactory::getDecalsTreasureData()
    {
        return decals_data_[DECALS_TREASURE_DATA_KEY].asValueVector();
        //return decals_data_[DECALS_TREASURE_DATA_KEY].asValueVector();
    }
    cocos2d::Vec2 DecalsFactory::getDecalsMaxIndexWithPath(const std::string & path)
    {
        for (auto type_vector : decals_data_)
        {
            for (auto data : type_vector.second.asValueVector())
            {
                if (data.asValueMap()[DECALS_DATA_PATH_KEY].asString() == path)
                {
                    return cocos2d::Vec2(data.asValueMap()["x"].asInt(), data.asValueMap()["y"].asInt());
                }
            }
        }
        assert(false);
        return cocos2d::Vec2(-1, -1);
    }
    cocos2d::Sprite * DecalsFactory::createCharactorNextDecal()
    {
        cocos2d::ValueVector charactor_vector = UserDataManager::getInstance()->getCharactorDecalsData();
        if (charactor_vector.empty())
        {
            auto path = this->getDecalsCharactorData()[charactor_vector.size()].asValueMap()[DECALS_DATA_PATH_KEY].asString();
            return this->createDecalBackground(this->createDecalWithNumble(path, 1), path, 1);
        }
        else
        {
            cocos2d::ValueMap charactor_user_data = charactor_vector.back().asValueMap();
            cocos2d::ValueVector goods_data = charactor_user_data[DECALS_DATA_GOOD_KEY].asValueVector();
            cocos2d::Vec2 max_index = this->getDecalsMaxIndexWithPath(charactor_user_data[DECALS_DATA_PATH_KEY].asString());
            if (goods_data.size() < max_index.x * max_index.y)
            {
                auto path = charactor_user_data[DECALS_DATA_PATH_KEY].asString();
                int numble = goods_data.size() + 1;
                return this->createDecalBackground(this->createDecalWithNumble(path, numble), path, numble);
            }      
            else if (goods_data.size() == max_index.x * max_index.y)
            {
                auto path = this->getDecalsCharactorData()[charactor_vector.size()].asValueMap()[DECALS_DATA_PATH_KEY].asString();
                return this->createDecalBackground(this->createDecalWithNumble(path, 1), path, 1);
            }
        }
        assert(false);
        return nullptr;
    }
    cocos2d::Sprite * DecalsFactory::createTreasureNextDecal()
    {//如有修改需提取方法
        cocos2d::ValueVector charactor_vector = UserDataManager::getInstance()->getTreasureDecalsData();
        if (charactor_vector.empty())
        {
            auto path = this->getDecalsTreasureData()[charactor_vector.size()].asValueMap()[DECALS_DATA_PATH_KEY].asString();
            return this->createDecalBackground(this->createDecalWithNumble(path, 1), path, 1);
        }
        else
        {
            cocos2d::ValueMap charactor_user_data = charactor_vector.back().asValueMap();
            cocos2d::ValueVector goods_data = charactor_user_data[DECALS_DATA_GOOD_KEY].asValueVector();
            cocos2d::Vec2 max_index = this->getDecalsMaxIndexWithPath(charactor_user_data[DECALS_DATA_PATH_KEY].asString());
            if (goods_data.size() < max_index.x * max_index.y)
            {
                auto path = charactor_user_data[DECALS_DATA_PATH_KEY].asString();
                int numble = goods_data.size() + 1;
                return this->createDecalBackground(this->createDecalWithNumble(path, numble), path, numble);
            }
            else if (goods_data.size() == max_index.x * max_index.y)
            {
                auto path = this->getDecalsTreasureData()[charactor_vector.size()].asValueMap()[DECALS_DATA_PATH_KEY].asString();
                return this->createDecalBackground(this->createDecalWithNumble(path, 1), path, 1);
            }
        }
        assert(false);
        return nullptr;
    }
}