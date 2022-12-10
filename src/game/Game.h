#pragma once
#include "OgreHlmsDatablock.h"
#include "OgrePrerequisites.h"
#include "TutorialGameState.h"


class SETTINGS;
class GAME;
class App;
class Scene;

namespace Ogre
{
	class Terra;
	class HlmsPbsTerraShadows;
	class TextureGpu;
	class HlmsDatablock;
}
namespace MyGUI
{
    class Gui;
	class Ogre2Platform;
}


namespace Demo
{

	enum IblQuality  // reflections
	{
		MipmapsLowest,
		IblLow,
		IblHigh
	};


	class TerrainGame : public TutorialGameState
	{
		//  vars
		Ogre::Vector3 camPos;

		//  input
		int mArrows[11] = {0,0,0,0,0,0,0,0,0,0},
			mKeys[4] = {0,0,0,0};  // sun keys
		int param = 0;  // to adjust
		bool left = false, right = false;  // arrows
		bool shift = false, ctrl = false;
		
		int idTrack = 0, idCar = 0;

		//  terrain
		// Listener to make PBS objects also be affected by terrain's shadows
		Ogre::HlmsPbsTerraShadows *mHlmsPbsTerraShadows = 0;

		//  wireframe
		Ogre::HlmsMacroblock macroblockWire;
		bool wireTerrain = false;

		void generateDebugText();
		Ogre::String generateFpsDebugText();

	public:
		Ogre::Terra *mTerra = 0;

    	MyGUI::Gui* mGui = 0;
    	MyGUI::Ogre2Platform* mPlatform = 0;

		TerrainGame();
		void InitGui();

		//  SR
		SETTINGS* pSet = 0;
		GAME* pGame = 0;
		App* pApp = 0;
		
		Scene* sc = 0;  // in pApp->scn ..

		void LoadDefaultSet(SETTINGS* settings, std::string setFile);
		void Init();
		void Destroy();


		//  main
		void createScene01() override;
		void destroyScene() override;

		void update( float timeSinceLast ) override;

		//  events
		void keyPressed( const SDL_KeyboardEvent &arg ) override;
		void keyReleased( const SDL_KeyboardEvent &arg ) override;
	public:


		//  reflection cube  ----
		Ogre::Camera *mCubeCamera = 0;
		Ogre::TextureGpu *mDynamicCubemap = 0;
	protected:
		Ogre::CompositorWorkspace *mDynamicCubemapWorkspace = 0;

		IblQuality mIblQuality = IblLow;  // par in ctor
	public:		
		Ogre::CompositorWorkspace *setupCompositor();


		//  terrain  ----
	public:		
		void CreateTerrain(), DestroyTerrain();
	protected:
		Ogre::String mtrName;
		Ogre::SceneNode *nodeTerrain = 0;


		//  util
		template <typename T, size_t MaxNumTextures>
		void unloadTexturesFromUnusedMaterials( Ogre::HlmsDatablock *datablock,
												std::set<Ogre::TextureGpu *> &usedTex,
												std::set<Ogre::TextureGpu *> &unusedTex );
    	void unloadTexturesFromUnusedMaterials();
	    void unloadUnusedTextures();
	public:
	    void minimizeMemory();
    	// void setTightMemoryBudget();
	    // void setRelaxedMemoryBudget();
	};
}
