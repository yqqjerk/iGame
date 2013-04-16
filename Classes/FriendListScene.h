#ifndef __FRIEND_LIST_SCENE_H__
#define __FRIEND_LIST_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "SimpleAudioEngine.h"
#include "XmlParser.h"
#include "CCTableView.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class FriendListScene : public cocos2d::CCLayer,
public CCTableViewDataSource,
public CCTableViewDelegate,
public CCNodeLoaderListener,
public CCBMemberVariableAssigner
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void requestFinishedCallback(CCNode* pSender,void *p);

    // implement the "static node()" method manually
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(FriendListScene,create);
    
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
	virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
	virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {}
	virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
	virtual cocos2d::CCSize cellSizeForTable(CCTableView *table);
	virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
	virtual unsigned int numberOfCellsInTableView(CCTableView *table);
    virtual void tableCellHighlight(CCTableView* table, CCTableViewCell* cell);
    
    CCTableView* mTableViewFriend;
};

#endif  // __HELLOWORLD_SCENE_H__