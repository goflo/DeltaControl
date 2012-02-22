/*
 File:    DeltaControl.cpp
 */
#include "DeltaControl.h"
//#include "model/ControlCenter.h"
//#include "model/Telephone.h"
//#include "model/Table.h"
//#include "model/Monitor.h"
#include <OgreResourceGroupManager.h>

#include "lib/DotSceneLoader.h"


//-------------------------------------------------------------------------------------
DeltaControl::DeltaControl(void) {
}
//-------------------------------------------------------------------------------------
DeltaControl::~DeltaControl(void) {
}

//-------------------------------------------------------------------------------------
void DeltaControl::createScene(void) {

	mSceneMgr->setSkyBox(true, "StormySkyBox");

	// Terrain* terrain = new Terrain(mSceneMgr);
//	mControlCenter = new ControlCenter(mSceneMgr);
//	mCharacter = new CharacterController(mCamera);
//
//	mTable = new Table(mSceneMgr);
//	mMonitor = new Monitor(mSceneMgr, mCharacter);
//	mPhone = new Telephone(mSceneMgr, mCharacter, "phone1");

	DotSceneLoader* sceneLoader = new DotSceneLoader();
	Ogre::SceneNode* roomNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("room1");
	roomNode->setPosition(0,0,0);
	sceneLoader->parseDotScene("TCOO_Scene.scene",Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, mSceneMgr, roomNode);

}

bool DeltaControl::frameRenderingQueued(const Ogre::FrameEvent& evt)
{

	bool ret = BaseApplication::frameRenderingQueued(evt);
	//mPhone->highlight(mPhone->canUse());
	//mCharacter->setMove(!mControlCenter->intersects(mCharacter->getBoundingBox()));
	//mMonitor->highlight(mMonitor->canUse());
	return ret;
}


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char *argv[])
#endif
		{
	// Create application object
	DeltaControl app;

	try {
		app.go();
	} catch (Ogre::Exception& e) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
		std::cerr << "An exception has occured: "
				<< e.getFullDescription().c_str() << std::endl;
#endif
	}

	return 0;
}

#ifdef __cplusplus
}
#endif
