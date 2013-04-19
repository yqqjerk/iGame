#ifndef __LOGINSCENE_SCENE_H__
#define __LOGINSCENE_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "SimpleAudioEngine.h"
#include "XmlParser.h"
#include "common.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class LoginScene : public cocos2d::CCLayer,
public CCBSelectorResolver,
public CCBMemberVariableAssigner,
public CCNodeLoaderListener
{
public:
    LoginScene();
    ~LoginScene();
    
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void requestFinishedCallback(CCNode* pSender,void *p);

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LoginScene, create);
    
    void menuBarBtnClicked(CCObject *pSender);
    void buttonClicked(CCObject *pSender, CCControlEvent pCCControlEvent);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
	void doSubmit();
	void parseJson();

	CCEditBox *m_txtAccount;
	CCEditBox *m_txtPassword;

	CCControlSwitch *chkRememberPwd;
};

#endif  // __LOGINSCENE_SCENE_H__