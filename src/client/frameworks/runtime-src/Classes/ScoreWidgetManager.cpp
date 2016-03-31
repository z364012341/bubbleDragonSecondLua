#include "ScoreWidgetManager.h"
#include "ScoreWidget.h"
#include "GameScoreController.h"
const float WIDGET_POSITION_RANGE_RIGHT_MAX = GAME_DESIGN_RESOLUTION_WIDTH / 2 - BUBBLE_RADIUS - SCORE_WIDGET_BODY_RADIUS + 5.0f;
const float WIDGET_POSITION_RANGE_RIGHT_MIN = GAME_DESIGN_RESOLUTION_WIDTH / 2 - BUBBLE_RADIUS * 2 - SCORE_WIDGET_BODY_RADIUS - 5.0f;
const float WIDGET_POSITION_RANGE_LEFT_MAX = -WIDGET_POSITION_RANGE_RIGHT_MIN;
const float WIDGET_POSITION_RANGE_LEFT_MIN = -WIDGET_POSITION_RANGE_RIGHT_MAX;
//得分挂件
//const std::string SCORE_WIDGET_BONE_HEAD_NAME = "Layer11"; //骨骼名字
//const std::string SCORE_WIDGET_BONE_BODY_NAME = "Layer10";
//const std::string SCORE_WIDGET_BONE_BG_NAME = "Layer21";
//const std::string SCORE_WIDGET_BONE_EAR1_NAME = "Layer13";
//const std::string SCORE_WIDGET_BONE_EAR2_NAME = "Layer12";
//const std::string SCORE_WIDGET_RES_PATH = "score_widget_res/"; //资源的相对路径
//const std::string SCORE_WIDGET_HEAD_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-tou.png"; //蓝色的头的路径
//const std::string SCORE_WIDGET_HEAD_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-tou.png";
//const std::string SCORE_WIDGET_HEAD_GREEN_PATH = SCORE_WIDGET_RES_PATH + "LV-H-tou.png";
//
//const std::string SCORE_WIDGET_BODY_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-shenti.png";
//const std::string SCORE_WIDGET_BODY_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-shenti.png";
//const std::string SCORE_WIDGET_BODY_GREEN_PATH = SCORE_WIDGET_RES_PATH + "LV-H-shenti.png";
//
//const std::string SCORE_WIDGET_BG_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-guang.png";
//const std::string SCORE_WIDGET_BG_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-guang.png";
//const std::string SCORE_WIDGET_BG_GREEN_PATH = SCORE_WIDGET_RES_PATH + "L-H-guang.png";
//
//const std::string SCORE_WIDGET_EAR1_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-r01.png";
//const std::string SCORE_WIDGET_EAR1_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-r01.png";
//const std::string SCORE_WIDGET_EAR1_GREEN_PATH = SCORE_WIDGET_RES_PATH + "LV-H-r01.png";
//
//const std::string SCORE_WIDGET_EAR2_BLUE_PATH = SCORE_WIDGET_RES_PATH + "L-H-r02.png";
//const std::string SCORE_WIDGET_EAR2_PINK_PATH = SCORE_WIDGET_RES_PATH + "Fen-H-r02.png";
//const std::string SCORE_WIDGET_EAR2_GREEN_PATH = SCORE_WIDGET_RES_PATH + "LV-H-r02.png";
namespace bubble_second {
    ScoreWidgetManager::ScoreWidgetManager():widget_total_(0)
    {
        //this->addEventListenerCustom();
        combo_to_type_[0] = kScoreWidgetLow;
        combo_to_type_[1] = kScoreWidgetLow;
        combo_to_type_[2] = kScoreWidgetLow;
        combo_to_type_[3] = kScoreWidgetLow;
        combo_to_type_[4] = kScoreWidgetMiddle;
        combo_to_type_[5] = kScoreWidgetMiddle;
        combo_to_type_[6] = kScoreWidgetHigh;
        widget_update_sequence_.push_back(kScoreWidgetLow);
        widget_update_sequence_.push_back(kScoreWidgetMiddle);
        widget_remove_sequence_.push_back(kScoreWidgetHigh);
        widget_remove_sequence_.push_back(kScoreWidgetMiddle);
        widget_remove_sequence_.push_back(kScoreWidgetLow);

        //std::map<ScoreWidgetType, std::string> type_to_head;
        //type_to_head[kScoreWidgetLow] = SCORE_WIDGET_HEAD_BLUE_PATH;
        //type_to_head[kScoreWidgetMiddle] = SCORE_WIDGET_HEAD_PINK_PATH;
        //type_to_head[kScoreWidgetHigh] = SCORE_WIDGET_HEAD_GREEN_PATH;

        //std::map<ScoreWidgetType, std::string> type_to_body;
        //type_to_body[kScoreWidgetLow] = SCORE_WIDGET_BODY_BLUE_PATH;
        //type_to_body[kScoreWidgetMiddle] = SCORE_WIDGET_BODY_PINK_PATH;
        //type_to_body[kScoreWidgetHigh] = SCORE_WIDGET_BODY_GREEN_PATH;

        //std::map<ScoreWidgetType, std::string> type_to_bg;
        //type_to_bg[kScoreWidgetLow] = SCORE_WIDGET_BG_BLUE_PATH;
        //type_to_bg[kScoreWidgetMiddle] = SCORE_WIDGET_BG_PINK_PATH;
        //type_to_bg[kScoreWidgetHigh] = SCORE_WIDGET_BG_GREEN_PATH;

        //std::map<ScoreWidgetType, std::string> type_to_ear_1;
        //type_to_ear_1[kScoreWidgetLow] = SCORE_WIDGET_EAR1_BLUE_PATH;
        //type_to_ear_1[kScoreWidgetMiddle] = SCORE_WIDGET_EAR1_PINK_PATH;
        //type_to_ear_1[kScoreWidgetHigh] = SCORE_WIDGET_EAR1_GREEN_PATH;

        //std::map<ScoreWidgetType, std::string> type_to_ear_2;
        //type_to_ear_2[kScoreWidgetLow] = SCORE_WIDGET_EAR2_BLUE_PATH;
        //type_to_ear_2[kScoreWidgetMiddle] = SCORE_WIDGET_EAR2_PINK_PATH;
        //type_to_ear_2[kScoreWidgetHigh] = SCORE_WIDGET_EAR2_GREEN_PATH;

        //bonename_to_map_[SCORE_WIDGET_BONE_HEAD_NAME] = type_to_head;
        //bonename_to_map_[SCORE_WIDGET_BONE_BODY_NAME] = type_to_body;
        //bonename_to_map_[SCORE_WIDGET_BONE_BG_NAME] = type_to_bg;
        //bonename_to_map_[SCORE_WIDGET_BONE_EAR1_NAME] = type_to_ear_1;
        //bonename_to_map_[SCORE_WIDGET_BONE_EAR2_NAME] = type_to_ear_2;

        /*cocos2d::ValueMap bee_bone_data;

        cocos2d::ValueMap bee_bone_1; 
        bee_bone_1["low"] = "low/mifengguai_0001_MiFeng-yanpi2.png";
        bee_bone_1["middle"] = "middle/mifengguai_0001_MiFeng-yanpi2.png";
        bee_bone_1["high"] = "high/mifengguai_0001_MiFeng-yanpi2.png";
        bee_bone_data["Layer48"] = bee_bone_1;

        cocos2d::ValueMap bee_bone_2; 
        bee_bone_2["low"] = "low/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_2["middle"] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_2["high"] = "high/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_data["Layer46"] = bee_bone_2;

        cocos2d::ValueMap bee_bone_3; 
        bee_bone_3["low"] = "low/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_3["middle"] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_3["high"] = "high/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_data["Layer46"] = bee_bone_3;

        cocos2d::ValueMap bee_bone_4; 
        bee_bone_4["low"] = "low/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_4["middle"] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_4["high"] = "high/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_data["Layer46"] = bee_bone_4;

        cocos2d::ValueMap bee_bone_5; 
        bee_bone_5["low"] = "low/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_5["middle"] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_5["high"] = "high/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_data["Layer46"] = bee_bone_5;

        cocos2d::ValueMap bee_bone_6; 
        bee_bone_6["low"] = "low/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_6["middle"] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_6["high"] = "high/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_data["Layer46"] = bee_bone_6;

        cocos2d::ValueMap bee_bone_7; 
        bee_bone_7["low"] = "low/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_7["middle"] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_7["high"] = "high/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_data["Layer46"] = bee_bone_7;

        cocos2d::ValueMap bee_bone_8; 
        bee_bone_8["low"] = "low/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_8["middle"] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_8["high"] = "high/mifengguai_0000_MiFeng-yanpi1.png";
        bee_bone_data["Layer46"] = bee_bone_8; */

        //cocos2d::ValueMap bee_bone_data;

        type_to_key_[kScoreWidgetLow] = "low";
        type_to_key_[kScoreWidgetMiddle] = "middle";
        type_to_key_[kScoreWidgetHigh] = "high";
        {
            cocos2d::ValueMap bee_low_data;
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "mifengguai_0001_MiFeng-yanpi2.png";
                bee_low_data["Layer48"] = bone_data; }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "mifengguai_0000_MiFeng-yanpi1.png";
                bee_low_data["Layer46"] = bone_data;
            }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "新建文件夹 (12)/mifengguai_0003_MiFeng-yanpi4.png";
                bone_data[1] = "新建文件夹 (12)/mifengguai_0009_MiFeng-yanpi1.png";
                bone_data[2] = "新建文件夹 (12)/mifengguai_0004_MiFeng-yanpi3.png";
                bone_data[3] = "新建文件夹 (12)/mifengguai_0006_MiFeng-yanpi2.png";
                bee_low_data["Layer17"] = bone_data;
            }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "新建文件夹 (12)/mifengguai_0013_MiFeng-body.png";
                bee_low_data["Layer16"] = bone_data;
            }
            bee_bone_data_["low"] = bee_low_data;
        }
        {
            cocos2d::ValueMap bee_low_data;
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "middle/mifengguai_0001_MiFeng-yanpi2.png";
                bee_low_data["Layer48"] = bone_data; }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
                bee_low_data["Layer46"] = bone_data;
            }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "middle/mifengguai_0003_MiFeng-yanpi4.png";
                bone_data[1] = "middle/mifengguai_0009_MiFeng-yanpi1.png";
                bone_data[2] = "middle/mifengguai_0004_MiFeng-yanpi3.png";
                bone_data[3] = "middle/mifengguai_0006_MiFeng-yanpi2.png";
                bee_low_data["Layer17"] = bone_data;
            }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "middle/mifengguai_0013_MiFeng-body.png";
                bee_low_data["Layer16"] = bone_data;
            }
            bee_bone_data_["middle"] = bee_low_data;
        }
        {
            cocos2d::ValueMap bee_high_data;
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "high/mifengguai_0001_MiFeng-yanpi2.png";
                bee_high_data["Layer48"] = bone_data; }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "high/mifengguai_0000_MiFeng-yanpi1.png";
                bee_high_data["Layer46"] = bone_data;
            }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "high/mifengguai_0003_MiFeng-yanpi4.png";
                bone_data[1] = "high/mifengguai_0009_MiFeng-yanpi1.png";
                bone_data[2] = "high/mifengguai_0004_MiFeng-yanpi3.png";
                bone_data[3] = "high/mifengguai_0006_MiFeng-yanpi2.png";
                bee_high_data["Layer17"] = bone_data;
            }
            {
                cocos2d::ValueMapIntKey bone_data;
                bone_data[0] = "high/mifengguai_0013_MiFeng-body.png";
                bee_high_data["Layer16"] = bone_data;
            }
            bee_bone_data_["high"] = bee_high_data;
        }
    }

    ScoreWidgetManager::~ScoreWidgetManager()
    {
    }

    void ScoreWidgetManager::clear()
    {
        for (auto iter_1 = score_widget_map_.begin(); iter_1 != score_widget_map_.end(); ++iter_1)
        {
            iter_1->second.clear();
        }
        widget_total_ = 0;
    }

    void ScoreWidgetManager::changeScoreWidgetArmatureDisplay(cocostudio::Armature* armature, const ScoreWidgetType& type)
    {
        for (auto var1: bee_bone_data_[type_to_key_[type]].asValueMap())
        {
            for (auto var2 : var1.second.asIntKeyMap())
            {
                auto path = var2.second.asString();
                if (type == kScoreWidgetLow)
                {
                    armature->getBone(var1.first)->addDisplay(cocostudio::Skin::createWithSpriteFrameName(var2.second.asString()), var2.first);
                }
                else
                {
                    armature->getBone(var1.first)->addDisplay(cocostudio::Skin::create(armature->getName() + "/" + var2.second.asString()), var2.first);
                }
                
            }
        }
    }

    void ScoreWidgetManager::removeTwoScoreWidget()
    {
        //关闭用以测试
        int time = 0;
        //for (auto iter_1 = score_widget_vector_.begin(); iter_1 != score_widget_vector_.end(); ++iter_1)
        //{
        //    for (auto iter = iter_1->begin(); iter != iter_1->end(); )
        //    {
        //        if (time != SCORE_WIDGET_NOT_COMBO_NUMBLE)
        //        {
        //            (*iter)->removeScoreWidget();
        //            iter = iter_1->erase(iter);
        //            --widget_total_;
        //            ++time;
        //            continue;
        //        }
        //        return;   
        //    }
        //}
        for (auto var : widget_remove_sequence_)
        {
            for (auto iter = score_widget_map_[var].begin(); iter != score_widget_map_[var].end(); )
            {
                if (time != SCORE_WIDGET_NOT_COMBO_NUMBLE)
                {
                    (*iter)->removeScoreWidget();
                    iter = score_widget_map_[var].erase(iter);
                    --widget_total_;
                    ++time;
                    continue;
                }
                return;
            }
        }
    }

    //void ScoreWidgetManager::addEventListenerCustom()
    //{
    //    cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    //    auto listener = cocos2d::EventListenerCustom::create(EVENT_MAP_LOADED, CC_CALLBACK_1(ScoreWidgetManager::clear, this));
    //    dispatcher->addEventListenerWithFixedPriority(listener, 1);
    //}

    ScoreWidget* ScoreWidgetManager::getNewScoreWidget()
    {
        if (widget_total_ < 6)
        {
            ++widget_total_;
            const ScoreWidgetType& type = combo_to_type_[GameScoreController::getInstance()->getEliminateCombo()];
            ScoreWidget* widget = ScoreWidget::createWithType(type);
            widget->setSelfPosition(this->getScoreWidgetPosition());
            score_widget_map_[type].pushBack(widget);
            return widget;
        }
        else
        {
            //for (auto iter_1 = score_widget_vector_.begin(); iter_1 != --score_widget_vector_.end(); ++iter_1)
            //{//最高级的不用升级
            //    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2)
            //    {
            //        ScoreWidget* widget = *iter_2;
            //        iter_1->erase(iter_2);              
            //        score_widget_vector_[widget->getType()].pushBack(widget);
            //        //先移动vector里面的元素在升级, 因为升级会初始化连击次数
            //        widget->updateScoreWidgetType();
            //        return nullptr;
            //    }
            //}
            ScoreWidget* widget = nullptr;
            for (auto var : widget_update_sequence_)
            {
                for (auto iter = score_widget_map_[var].begin(); iter != score_widget_map_[var].end(); ++iter)
                {
                    widget = *iter;
                    score_widget_map_[var].erase(iter);
                    widget->updateScoreWidgetType();
                    score_widget_map_[widget->getType()].pushBack(widget);
                    widget = nullptr;
                    return nullptr;
                }
            }
        }
        return nullptr;
    }

    //cocos2d::Vec2 ScoreWidgetManager::getScoreWidgetPositionWithVector(const cocos2d::Vector<cocos2d::Node*>& vector)
    //{
    //    int vector_size = vector.size();
    //    cocos2d::Vec2 point;
    //    int numble = 0;
    //    do
    //    {
    //        point = vector.at(cocos2d::random(0, vector_size - 1))->getPosition()
    //            + cocos2d::Vec2(cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS),
    //                cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS));
    //        ++numble;
    //    } while (this->isNearbyExistence(point)/* && numble < 999*/);
    //    return point;
    //}

    cocos2d::Vec2 ScoreWidgetManager::getScoreWidgetPosition()
    {
        int vector_size = this->getWidgetPointsSeed().size();
        cocos2d::Vec2 point;
        int numble = 0;
        do
        {
            point = this->getWidgetPointsSeed().at(cocos2d::random(0, vector_size - 1))->getPosition()
                + cocos2d::Vec2(cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS),
                    cocos2d::random(SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS*2));
            ++numble;
        } while (this->isNearbyExistence(point)/* && numble < 999*/);
        return point;
    }

    bool ScoreWidgetManager::isNearbyExistence(const cocos2d::Vec2& point)
    {
        bool borderFlag = this->isNearByBorder(point);
        if (borderFlag)
        {
            return true;
        }
        for (auto var_1 : score_widget_map_)
        {
            for (auto var_2 : var_1.second)
            {
                if (var_2->getSelfPosition().distance(point) < TWO_SCORE_WIDGET_DISTANCE)
                {    
                    return true;
                }
            }
        }
        return false;
    }

    bool ScoreWidgetManager::isNearByBorder(const cocos2d::Vec2 & point)
    {
        return (WIDGET_POSITION_RANGE_LEFT_MIN<point.x && point.x<WIDGET_POSITION_RANGE_LEFT_MAX) || (WIDGET_POSITION_RANGE_RIGHT_MIN<point.x && point.x<WIDGET_POSITION_RANGE_RIGHT_MAX);
    }

    int ScoreWidgetManager::getScoreWidgetTotal()
    {
        return widget_total_;
    }

    int ScoreWidgetManager::getScoreWidgetTotalWithType(const ScoreWidgetType& type)
    {
        return score_widget_map_[type].size();
    }

    void ScoreWidgetManager::setWidgetPointsSeed(WidgetPointsSeed seed)
    {
        widget_points_seed_ = seed;
    }

    WidgetPointsSeed ScoreWidgetManager::getWidgetPointsSeed()
    {
        return widget_points_seed_;
    }

    //const WidgetBonePathMap & ScoreWidgetManager::getWidgetBonePathMap()
    //{
    //    return bonename_to_map_;
    //}

}