#pragma once
// -- NOT to be included in headers?  --

#include <iomanip>
#include <OgreVector3.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>
#include <OgreString.h>
#include <MyGUI_LanguageManager.h>

//  Log in ogre.log
#define LogO(s)  Ogre::LogManager::getSingleton().logMessage(s)

//  to string
// #define toStr(v)   Ogre::StringConverter::toString(v)  // cant
inline Ogre::String toStr(const int    a)        {  return Ogre::StringConverter::toString(a);  }
inline Ogre::String toStr(const unsigned int a)  {  return Ogre::StringConverter::toString(a);  }
inline Ogre::String toStr(const float  a)        {  return Ogre::StringConverter::toString(a);  }
inline Ogre::String toStr(const size_t a)        {  return Ogre::StringConverter::toString(a);  }
inline Ogre::String toStr(const Ogre::Vector2 a) {  return Ogre::StringConverter::toString(a);  }
inline Ogre::String toStr(const Ogre::Vector3 a) {  return Ogre::StringConverter::toString(a);  }
inline Ogre::String toStr(const Ogre::Vector4 a) {  return Ogre::StringConverter::toString(a);  }
#define toStrC(v)  toStr(v).c_str()

//  translation
#define TR(s)  MyGUI::LanguageManager::getInstance().replaceTags(s)


//  format int,float to string
static Ogre::String iToStr(const int v, const char width=0)
{
	std::ostringstream s;
	if (width != 0)  s.width(width);  //s.fill(fill);
	s << std::fixed << v;
	return s.str();
}
static Ogre::String fToStr(const float v, const char precision=2, const char width=4, const char fill=' ')
{
	std::ostringstream s;
	if (width != 0)  s.width(width);  s.fill(fill);
	s << std::fixed << std::setprecision(precision) << v;
	return s.str();
}

//  string to var
#define s2r(s)   Ogre::StringConverter::parseReal(s)
#define s2i(s)   Ogre::StringConverter::parseInt(s)
#define s2c(s)   Ogre::StringConverter::parseColourValue(s)

#define s2v2(s)  Ogre::StringConverter::parseVector2(s)
#define s2v(s)   Ogre::StringConverter::parseVector3(s)
#define s2v4(s)  Ogre::StringConverter::parseVector4(s)

#define b2s(b)   (b) ? "true" : "false"

/*
const int ciShadowSizesNum = 5;
const int ciShadowSizesA[ciShadowSizesNum] = {256,512,1024,2048,4096};
*/
static Ogre::String StrTime(float time)  // format time string
{
	int min = (int) time / 60;
	float secs = time - min*60;
	if (time != 0.f)
	{	Ogre::String ss = toStr(min)+":"+fToStr(secs,2,5,'0');
		return ss;
	}else
		return "-:--.--";
}
static Ogre::String StrTime2(float time)  // short
{
	int min = (int) time / 60;
	float secs = floor(time - min*60);
	if (time != 0.f)
	{	Ogre::String ss = toStr(min)+":"+fToStr(secs,0,2,'0');
		return ss;
	}else
		return "-:--";
}

static float s2time(Ogre::String s)  // parse m:ss or sec
{
	if (s.find(':') != s.npos)
	{
		Ogre::StringVector ms = Ogre::StringUtil::split(s, ":");
		float m = s2r(ms[0]), s = s2r(ms[1]);
		return m * 60.f + s;
	}
	return s2r(s);
}
