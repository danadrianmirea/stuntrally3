#include "pch.h"
#include "Def_Str.h"
#include "settings.h"
#include "CApp.h"
#include "CGui.h"

#include <filesystem>
#include <Ogre.h>
#include <MyGUI_TextBox.h>
#ifndef _WIN32
#include <dirent.h>
#endif
using namespace Ogre;
namespace fs = std::filesystem;


///  Get Materials
//-----------------------------------------------------------------------------------------------------------
void CGui::GetMaterials(String filename, bool clear, String type)
{
	if (clear)
		vsMaterials.clear();
	
	DataStreamPtr stream = ResourceGroupManager::getSingleton().openResource(filename);
	if (stream)
	{	try
		{	while(!stream->eof())
			{
				std::string line = stream->getLine();
				StringUtil::trim(line);
 
				if (StringUtil::startsWith(line, type/*"material"*/))
				{
					//LogO(line);
					Ogre::vector<String>::type vec = StringUtil::split(line," \t:");
					bool skipFirst = true;
					for (auto it = vec.begin(); it < vec.end(); ++it)
					{
						if (skipFirst)
						{	skipFirst = false;
							continue;
						}
						std::string match = (*it);
						StringUtil::trim(match);
						if (!match.empty())
						{
							//LogO(match);
							vsMaterials.push_back(match);						
							break;
						}
					}
			}	}
		}catch (Exception &e)
		{
			LogO("!GetMaterials Exception! " + e.getFullDescription());
	}	}
	stream->close();
}

void CGui::GetMaterialsMat(String filename, bool clear, String type)
{
	if (clear)
		vsMaterials.clear();
	
	std::ifstream stream(filename.c_str(), std::ifstream::in);
	if (!stream.fail())
	{	try
		{	while(!stream.eof())
			{
				char ch[256+2];
				stream.getline(ch,256);
				std::string line = ch;
				StringUtil::trim(line);
 
				if (StringUtil::startsWith(line, type/*"material"*/))
				{
					//LogO(line);
					auto vec = StringUtil::split(line," \t:");
					bool skipFirst = true;
					for (auto it : vec)
					{
						std::string match = it;
						StringUtil::trim(match);
						if (!match.empty())
						{
							if (skipFirst)
							{	skipFirst = false;  continue;	}

							//LogO(match);
							vsMaterials.push_back(match);						
							break;
						}
					}
			}	}
		}catch (Exception &e)
		{
			LogO("GetMaterialsMat Exception! " + e.getFullDescription());
	}	}
	else
		LogO("GetMat, can't open: " + filename);
	stream.close();
}


///  system file, dir
//-----------------------------------------------------------------------------------------------------------
bool CGui::Rename(String from, String to)
{
	try
	{	if (fs::exists(from.c_str()))
			fs::rename(from.c_str(), to.c_str());
	}
	catch (const fs::filesystem_error & ex)
	{
		String s = "Error: Renaming file " + from + " to " + to + " failed ! \n" + ex.what();
		strFSerrors += "\n" + s;
		LogO(s);
		return false;
	}
	return true;
}

bool CGui::Delete(String file)
{
	try
	{	fs::remove(file.c_str());
	}
	catch (const fs::filesystem_error & ex)
	{
		String s = "Error: Deleting file " + file + " failed ! \n" + ex.what();
		strFSerrors += "\n" + s;
		LogO(s);
		return false;
	}
	return true;
}

bool CGui::DeleteDir(String dir)
{
	try
	{	fs::remove_all(dir.c_str());
	}
	catch (const fs::filesystem_error & ex)
	{
		String s = "Error: Deleting directory " + dir + " failed ! \n" + ex.what();
		strFSerrors += "\n" + s;
		LogO(s);
		return false;
	}
	return true;
}

bool CGui::CreateDir(String dir)
{
	try
	{	fs::create_directory(dir.c_str());
	}
	catch (const fs::filesystem_error & ex)
	{
		String s = "Error: Creating directory " + dir + " failed ! \n" + ex.what();
		strFSerrors += "\n" + s;
		LogO(s);
		return false;
	}
	return true;
}

bool CGui::Copy(String file, String to)
{
	try
	{	if (fs::exists(to.c_str()))
			fs::remove(to.c_str());

		if (fs::exists(file.c_str()))
			fs::copy_file(file.c_str(), to.c_str());
	}
	catch (const fs::filesystem_error & ex)
	{
		String s = "Error: Copying file " + file + " to " + to + " failed ! \n" + ex.what();
		strFSerrors += "\n" + s;
		LogO(s);
		return false;
	}
	return true;
}


void App::UpdWndTitle()
{
	String s = String("SR Editor  track: ") + pSet->gui.track;
	if (pSet->gui.track_user)  s += "  *user*";

	//; SDL_SetWindowTitle(mSDLWindow, s.c_str());
}


//  key,mb info  ==================
void App::UpdKeyBar(Real dt)
{
	/*
	// TODO: This is definitely not bullet-proof.
	const int Kmax = SDL_SCANCODE_SLEEP;  // last key
	static float tkey[Kmax+1] = {0.f,};  // key delay time
	int i;
	static bool first=true;
	if (first)
	{	first=false;
		for (i=Kmax; i > 0; --i)  tkey[i] = 0.f;
	}
	String ss = "   ";
	//  pressed
	for (i=Kmax; i > 0; --i)
		if (mInputWrapper->isKeyDown(SDL_Scancode(i)))
			tkey[i] = 0.2f;  // min time to display

	//  modif
	const static int
		lc = SDL_SCANCODE_LCTRL,  rc = SDL_SCANCODE_RCTRL,
		la = SDL_SCANCODE_LALT,   ra = SDL_SCANCODE_RALT,
		ls = SDL_SCANCODE_LSHIFT, rs = SDL_SCANCODE_RSHIFT;

	if (tkey[lc] > 0.f || tkey[rc] > 0.f)	ss += "#D0F0D0Ctrl  ";
	if (tkey[la] > 0.f || tkey[ra] > 0.f)	ss += "#D0F0D0Alt  ";
	if (tkey[ls] > 0.f || tkey[rs] > 0.f)	ss += "#D0F0D0Shift  ";

	//  mouse buttons
	if (mbLeft)  ss += "#C0FFFFLMB  ";
	if (mbRight)  ss += "#C0FFFFRMB  ";
	if (mbMiddle)  ss += "#C0FFFFMMB  ";

	//  all
	for (i=Kmax; i > 0; --i)
	{
		if (tkey[i] > 0.f)
		{	tkey[i] -= dt;  //dec time
			if (i!=lc && i!=la && i!=ls && i!=rc && i!=ra && i!=rs)
			{
				String s = String(SDL_GetKeyName(SDL_GetKeyFromScancode(static_cast<SDL_Scancode>(i))));
				s = StringUtil::replaceAll(s, "Keypad", "#FFFFC0Num ");
				ss += "#FFFFFF" + s + "  ";
			}
	}	}
	
	//  mouse wheel
	static int mzd = 0;
	if (mz > 0)  mzd = 30;
	if (mz < 0)  mzd = -30;
	if (mzd > 0)  {  ss += "#D0D8FFWheel up";  --mzd;  }
	if (mzd < 0)  {  ss += "#D0D8FFWheel down";  ++mzd;  }
	txInput->setCaption(ss);
	*/
}
