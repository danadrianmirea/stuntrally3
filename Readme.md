![](/data/hud/stuntrally-logo.jpg)

[![Translation status](https://hosted.weblate.org/widget/stunt-rally-3/stunt-rally-3/svg-badge.svg)](https://hosted.weblate.org/engage/stunt-rally-3/)
![Last commit date](https://flat.badgen.net/github/last-commit/stuntrally/stuntrally3)
![Commits count](https://flat.badgen.net/github/commits/stuntrally/stuntrally3)
![License](https://flat.badgen.net/github/license/stuntrally/stuntrally3)

## Links

[Stunt Rally Homepage](https://stuntrally.tuxfamily.org/) - Download links, track & vehicle browsers etc.  
[Sources](https://github.com/stuntrally/stuntrally3/) - also for bugs & Issues, pull requests, etc.  
[Forums](https://forum.freegamedev.net/viewforum.php?f=77) - Discussions, tracks, Issues, etc.  
[Documentation](https://github.com/stuntrally/stuntrally3/blob/main/docs/_menu.md) - is now inside docs/  
Old [Screenshots](https://stuntrally.tuxfamily.org/gallery) - Galleries from 2.x versions and development  
[Videos](https://www.youtube.com/user/TheCrystalHammer) - from game and (old) editor  
[Donations](https://cryham.tuxfamily.org/donate/) - financial support

------------------------------------------------------------------------------

## Description

3D racing game with own Track Editor.

Stunt Rally 3 features 226 tracks in 40 sceneries and 25 vehicles.  
Game modes include:
* Single Race (with your Ghost drive, track car guide), Replays,
* Challenges, Championships, Tutorials, (series of tracks)
* Multiplayer (info [here](docs/multiplayer.md), no official server) and Split Screen, up to 6 players.  

The Track Editor allows creating and modifying tracks.  
Both run on GNU/Linux and Windows.  

**Full features** [list here](docs/Features.md).  

The game has a **rally** style of driving and sliding, mostly on gravel,  
with possible **stunt** elements (jumps, loops, pipes) and generated roads from 3D spline.  
It also features few Sci-Fi vehicles and planets.

This is continuation of old [Stunt Rally](https://github.com/stuntrally/stuntrally) 2.x.  
Using [Ogre-Next](https://github.com/OGRECave/ogre-next) for graphics and [VDrift](https://github.com/VDrift/vdrift) for simulation.

**Documentation** is now inside [docs/](docs/_menu.md) dir. It's partly WIP.

**Changes** and new features in [changelog](docs/Changelog.md).  
Details in [Roadmap](docs/Roadmap.md) with few missing features, known issues, and todo.  
Progress posts in [SR forum topic](https://forum.freegamedev.net/viewtopic.php?f=81&t=18515). Dev questions and answers in Ogre-Next [topic](https://forums.ogre3d.org/viewtopic.php?t=96576).

------------------------------------------------------------------------------

## Quick Start

[Hardware requirements](docs/Running.md#hardware-requirements).

### Game

Esc or Tab - shows/hides GUI.

Quick setup help is on the Welcome screen, shown at game start, or by Ctrl-F1.  
- Use Ogre config dialog before start to adjust Screen resolution, etc (start with `cfg` argument will show it).  
  Only OpenGL 3+ Rendering Subsystem is supported now
- Open Options to pick graphics preset according to your GPU and *do* restart.  
- Open Options tab Input, to see or reassign keys, or configure a game controller, info [here](docs/Running.md#input).  

Game related Hints are available in menu: How to drive, with few driving lessons.  
Have fun 😀

#### Troubleshooting

If you have problems at start, check page [Running](docs/Running.md).  
All settings and logs are saved to user folder, see [Paths](docs/Paths.md). It is also shown on first Help page.

------------------------------------------------------------------------------

### Editor

F1 (or tilde) - shows/hides GUI,  
Tab - switches between Camera and Edit modes.  
Press Ctrl-F1 to read what can be edited and how.  

There is no undo, so use F5 to reload last track state, and F4 to save it often.  
After each save, track can be tested in game.

[Tutorial](docs/editor.md) page has more info with _Old videos (to be replaced)_.  


------------------------------------------------------------------------------

## Building

How to compile project from sources:  
- On **Linux**  is described in [Building](docs/Building.md).  
  Requires building Ogre-Next and MyGui fork from sources first.  
- On **Windows** in [BuildingVS](docs/BuildingVS.md), building all dependecies from sources first.

------------------------------------------------------------------------------

## Feedback

Before reporting bugs or issues, be sure to [Read before posting](https://forum.freegamedev.net/viewtopic.php?f=78&t=3814) topic first

Then create a [new issue on github](https://github.com/stuntrally/stuntrally3/issues/new) (if not present already)  
or a topic on Forum [SR Bugs & Help](https://forum.freegamedev.net/viewforum.php?f=78).

## Contributing

Help and contributing is welcome.  
If you'd like to contribute, please check [Contributing](docs/Contributing.md).  
You can help with:  
- [translating](docs/Localization.md) - done on Weblate
- testing, packaging, adding or improving content, fixing, developing code etc.  
  done with PRs on github

## Developing

General info with some details for SR3, its sources and using Ogre-Next is in [Developing](docs/Developing.md).  
Sources have emojis, [this file](/src/emojis.txt) has all, with quick components guide etc.

------------------------------------------------------------------------------

## License

    Stunt Rally 3 - 3D racing game, with own Track Editor
                    based on Ogre-Next rendering and VDrift simulation
    Copyright (C) 2010-2023  Crystal Hammer and contributors


    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see https://www.gnu.org/licenses/

------------------------------------------------------------------------------

    The license GNU GPL 3.0 applies to code written by us,
    which is in src/ dir, subdirs:
	- common, editor, game, network, road, transl
	and modified, subdirs:
	- Terra, sound, vdrift

    Libraries used have their own licenses, included in:
	- btOgre2, oics (modified to tinyxml2)
    - OgreCommon (modified slightly)
    - in src/vdrift/: half.hpp, quickprof.h, Buoyancy.h, unittest.h
    
	For Media (art, data) licenses, see various _*.txt files in data/ subdirs.

------------------------------------------------------------------------------
