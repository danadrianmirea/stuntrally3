#include "pathmanager.h"
#include "pch.h"
#include "CScene.h"
#include "data/CData.h"
#include "data/SceneXml.h"
// #include "WaterRTT.h"
#include "Road.h"
// #include "PaceNotes.h"


CScene::CScene(App* app1)
	:app(app1)
	// ,sun(0), pr(0),pr2(0)
	// ,grass(0), trees(0)
	// ,road(0), pace(0), trail(0)
{
	data = new CData();
	sc = new Scene();
	// mWaterRTT = new WaterRTT();
}

CScene::~CScene()
{
	//?DestroyRoad();
	// delete pace;

	// OGRE_DELETE mTerrainGroup;

	delete sc;
	delete data;
}

void CScene::DestroyRoads()
{
	for (auto r : roads)
		r->Destroy();
	roads.clear();
	rdCur = 0;
	road = 0;
}
/*
void CScene::DestroyPace()
{
	if (pace)
	{	pace->Destroy();
		delete pace;  pace = 0;
	}
}*/
void CScene::DestroyTrail()
{
	if (trail)
	{	trail->Destroy();
		delete trail;  trail = 0;
	}
}

void CScene::destroyScene()
{
	// mWaterRTT->destroy();

	// DestroyRoads();  DestroyPace();  DestroyTrail();
	// DestroyTrees();
	// DestroyWeather();
}
