//*******************************************************************************
//类名称   : SpriteTextureController
//功能     : <分离精灵的纹理创建的逻辑>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _SPRITE_TEXTURE_CONTROLLER_H_
#define _SPRITE_TEXTURE_CONTROLLER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class CenteredMenuItemSprite;
    class SpriteTextureController
    {
    public:
        GETINSTANCE_FUNC(SpriteTextureController);
        ~SpriteTextureController();
        void setSpriteTexture(const std::string& path, cocos2d::Sprite* sprite);
        cocos2d::Sprite* createGameSpriteWithPath(const std::string& path);
        //std::string addGameSearchPath(const std::string& path);
        CenteredMenuItemSprite* createMenuItemSprite(const std::string& path, const cocos2d::ccMenuCallback& callback = nullptr);
        cocos2d::Sprite* createStageTypeSprite(const StageType& type);
        void setStageTypeSprite(cocos2d::Sprite* sp, const StageType& type);
        cocos2d::Sprite* createGameBackgroundSprite(int cell_numble);
        //加载纹理
        void addResourcesTexture();
        void addGameBackgroundTexture(int cell_numble);
        cocos2d::Sprite* createGameBlurBackground();
    private:
        SpriteTextureController();
        void readGameSceneBackgroundFile();
        void addArmatureFile();
        void removeArmatureFile();
        //模糊
        cocos2d::RenderTexture* SpriteBlurer(cocos2d::Sprite* pSprite, const float fRadius = 8.0f, const float fSampleNum = 8.0f);
        //截屏
        cocos2d::RenderTexture* ScreenShot(const bool bIsSave, std::function<void(cocos2d::RenderTexture*, const std::string&)> pFuncCallback);
    private:
        std::map<StageType, std::string> stagetype_to_path_;
        cocos2d::ValueMap cell_to_path_;
    };
}
#endif //_SPRITE_TEXTURE_CONTROLLER_H_