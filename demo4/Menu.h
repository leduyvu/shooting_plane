#include "HelloWorldScene.h"
#ifndef __MENU_H__
#define __MENU_H__

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
USING_NS_CC;
class Menu : public cocos2d::CCLayer {
public:
    ~Menu();
    Menu();
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    void playGame();
    void quit();
    
};

#endif // __HELLO_WORLD_H__
