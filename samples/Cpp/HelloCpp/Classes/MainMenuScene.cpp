#include "MainMenuScene.h"
#include "AppMacros.h"
USING_NS_CC;

#define LINE_SPACE          30
#define MENU_COUNT 6

const std::string g_aMenuNames[MENU_COUNT] = {
	"Play Now",
	"Menu",
	"Multiplayer",
	"High Scors",
	"Trophies",
	"Settings",
};

CCScene* MainMenuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainMenuScene *layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // add background 
    CCSprite* pSprite = CCSprite::create("background@2x.png");
	pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

	// add dots' logo
	CCSprite* pLogo = CCSprite::create("dots_logo@2x.png");
	pLogo->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height + origin.y + pLogo->getContentSize().height));
	this->addChild(pLogo, 0);

	// logo's action
	CCPoint ptLogoFinal = ccp(visibleSize.width/2 + origin.x, visibleSize.height * 3 / 4 + origin.y);
	CCPoint ptLogoMiddle = ccp(visibleSize.width/2 + origin.x, visibleSize.height * 2 / 3 + origin.y);
	CCActionInterval*  action1 = CCMoveTo::create(0.5f, ptLogoMiddle);
	CCActionInterval*  action2 = CCMoveBy::create(0.2f, ccp(0, 50));
	CCActionInterval*  action3 = CCMoveBy::create(0.2f, ccp(0, -25));
	CCActionInterval*  action4 = CCMoveBy::create(0.2f, ccp(0, 12));
	CCActionInterval*  action5 = CCMoveBy::create(0.2f, ccp(0, -7));
	// run logo's action
	pLogo->runAction( CCSequence::create(action1, action2, action3, action4, action5, NULL));

	// dots menu
	m_pItemMenu = CCMenu::create();
	for (int i = 0; i < MENU_COUNT; ++i)
	{
		
		CCLabelTTF* label = CCLabelTTF::create(g_aMenuNames[i].c_str(), "fonts/Josefin Sans Bold.ttf", 12);
		label->setColor(ccBLACK);
		aaMenuItemLabel* pMenuItem = new aaMenuItemLabel();
		pMenuItem->initWithLabel(label, this, menu_selector(MainMenuScene::menuCallback));
		pMenuItem->autorelease();

		m_pItemMenu->addChild(pMenuItem, i + 10000);
		pMenuItem->setPosition( ccp( 0, (- i * LINE_SPACE) ));
	}

	m_pItemMenu->setPosition(ccp(visibleSize.width/2 + origin.x, origin.y+50));
	this->addChild(m_pItemMenu, 0);

    
    return true;
}


void MainMenuScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainMenuScene::menuCallback(CCObject* pSender)
{

}

//////////////////////////////////////////////////////////////////////////


void aaMenuItemLabel::selected()
{
	// subclass to change the default action
	if(m_bEnabled && m_pLabel)
	{
		CCMenuItem::selected();

		((CCLabelTTF*)m_pLabel)->setColor(ccc3(69, 186, 175));
	}
}

void aaMenuItemLabel::unselected()
{
	// subclass to change the default action
	if(m_bEnabled && m_pLabel)
	{
		CCMenuItem::unselected();
		((CCLabelTTF*)m_pLabel)->setColor(ccBLACK);
	}
}