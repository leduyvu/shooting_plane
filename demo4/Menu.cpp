#include "Menu.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
//#include <string.h>

using namespace cocos2d;
using namespace CocosDenshion;

#define PTM_RATIO 32
USING_NS_CC;
enum {
    kTagParentNode = 1,
};

Menu::Menu()
{
    setTouchEnabled( true );
    setAccelerometerEnabled( true );
    //CCMenuItemLabel *pCloseItem
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    CCSprite *nen = CCSprite::create("eeee.png");
    nen->setPosition(ccp(s.width/2, s.height/2));
    addChild(nen,1);
    CCLabelTTF *play = CCLabelTTF::create("play", "time new roman", 40);
    play->setColor(ccc3(255, 255, 0));
    CCMenuItemLabel *mPlay = CCMenuItemLabel::create(play, this, menu_selector(Menu::playGame));
    CCLabelTTF *exit = CCLabelTTF::create("exit", "time new roman", 40);
    exit->setColor(ccc3(255, 255, 0));
    CCMenuItemLabel *mExit = CCMenuItemLabel::create(exit, this, menu_selector(Menu::quit));
    
    
  //  CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
  //                                                        "CloseNormal.png",
  //                                                        "CloseSelected.png",
  //                                                        this,
   //                                                       menu_selector(Menu::playGame) );
    mPlay->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width/2, 190) );
    mExit->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width/2, 150) );
    CCMenu *pMenu = CCMenu::create(mPlay, mExit, NULL);
    // create menu, it's an autorelease object
    //CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
}

Menu::~Menu()
{
    removeAllChildren();
}
// Create scene
CCScene* Menu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    // add layer as a child to scene
    CCLayer* layer = new Menu();
    //layer->setColor(ccc3(255,255,255));
    scene->addChild(layer);
    layer->release();
    // gun->setPosition(ccp(200,200));
    return scene;
}
void Menu::playGame()
{
    CCScene *newScene = HelloWorld::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5,newScene));
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

    #endif
}
void Menu::quit()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(1);
#endif
}
