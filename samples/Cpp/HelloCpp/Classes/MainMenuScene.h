#ifndef __MAINMENUSCENE_SCENE_H__
#define __MAINMENUSCENE_SCENE_H__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::CCLayer
{
public:
	cocos2d::CCMenu *m_pItemMenu;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);


	void menuCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(MainMenuScene);

	
};

class aaMenuItemLabel : public cocos2d::CCMenuItemLabel
{
public:
	aaMenuItemLabel(){};
	virtual ~aaMenuItemLabel(){};

	virtual void selected();
	virtual void unselected();
};

#endif // __MAINMENUSCENE_SCENE_H__
