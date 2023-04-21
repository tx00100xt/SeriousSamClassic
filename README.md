## Serious Sam Classic
![Build status](https://github.com/tx00100xt/SeriousSamClassic/actions/workflows/cibuild.yml/badge.svg)
[![License: GPL v2](https://img.shields.io/badge/License-GPL_v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/tx00100xt/SeriousSamClassic)

This is the source code for Serious Engine v.1.10, including the following projects:

* `DedicatedServer`
* `Ecc` The *Entity Class Compiler*, a custom build tool used to compile *.es files
* `Engine` Serious Engine 1.10
* `EngineGUI` Common GUI things for game tools
* `EntitiesMP` All the entity logic
* `GameGUIMP` Common GUI things for game tools
* `GameMP` All the game logic
* `Modeler` Serious Modeler
* `RCon` Used to connect to servers using an admin password
* `SeriousSam` The main game executable
* `SeriousSkaStudio` Serious Ska Studio
* `WorldEditor` Serious Editor
* `DecodeReport` Used to decode crash *.rpt files
* `Depend` Used to build a list of dependency files based on a list of root files
* `LWSkaExporter` Exporter for use in LightWave
* `MakeFONT` Used for generating *.fnt files
* `Shaders` Compiled shaders
* `GameAgent` The serverlist masterserver written in Python
* `libogg`, `libvorbis` Third party libraries used for playing OGG-encoded ingame music (see http://www.vorbis.com/ for more information)

Building
--------
More detailed information about building the game for different operating systems and different platforms can be found on the [SeriousSamClassic wiki.](https://github.com/tx00100xt/SeriousSamClassic/wiki)

There are still many asserts in the engine. Most of them are irrelevant and should be removed, but while it's not done, the asserts will effectively kill the engine when triggered in the Debug build. Use Release or RelWithDebInfo build if you intend to play (automatically set as RelWithDebInfo in the build scripts).

### Linux

#### Setting up the repository

Type this in your terminal:

```
git clone https://github.com/tx00100xt/SeriousSamClassic.git SeriousSamClassic
```

#### Copy official game data (optional)

If you have access to a copy of the game (either by CD or through Steam),
you can copy the *.gro files from the game directory to the repository.
(SeriousSamClassic/SamTFE is the directory of the game Serious Sam Classic The First Encounter, SeriousSamClassic/SamTSE is the directory of the game Serious Sam Classic The Second Encounter)

#### Building (only for SS:TFE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTFE/Sources
./build-linux64.sh -DTFE=TRUE	# use build-linux32.sh for 32-bits
```

#### Building (only for SS:TSE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTSE/Sources
./build-linux64.sh        	# use build-linux32.sh for 32-bits
```

### Gentoo

To build a game for gentoo, use a https://github.com/tx00100xt/serioussam-overlay containing ready-made ebuilds for building the game and add-ons.

### Arch Linux

To build a game under Arch Linux you can use the package from AUR: https://aur.archlinux.org/packages/serioussam

### Raspberry Pi

The build for raspberry pi is similar to the build for Linux, you just need to add an additional build key.

```
cd SeriousSamClassic/SamTFE/Sources
./build-linux64.sh -DTFE=TRUE -DRPI4=TRUE	# use build-linux32.sh for 32-bits
```
for Serious Sam Classic The First Encounter, or for Serious Sam Classic The Second Encounter:
```
cd SeriousSamClassic/SamTSE/Sources
./build-linux64.sh -DRPI4=TRUE           	# use build-linux32.sh for 32-bits
```

### FreeBSD

#### Setting up the repository

Type this in your terminal:

```
git clone https://github.com/tx00100xt/SeriousSamClassic.git SeriousSamClassic
```

#### Copy official game data (optional)

If you have access to a copy of the game (either by CD or through Steam),
you can copy the *.gro files from the game directory to the repository.
(SeriousSamClassic/SamTFE is the directory of the game Serious Sam Classic The First Encounter, SeriousSamClassic/SamTSE is the directory of the game Serious Sam Classic The Second Encounter)

#### Building (only for SS:TFE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTFE/Sources
cp -vfr Entities/PlayerWeapons_old.es Entities/PlayerWeapons.es
mkdir cmake-build
cd cmake-build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DTFE=TRUE ..
make -j4
cp -v SeriousSam DedicatedServer MakeFONT ecc ../../Bin
cp -v Debug/*.so ../../Bin
```

#### Building (only for SS:TSE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTSE/Sources
cp -vfr EntitiesMP/PlayerWeapons_old.es EntitiesMP/PlayerWeapons.es
mkdir cmake-build
cd cmake-build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
make -j4
cp -v SeriousSam DedicatedServer MakeFONT ecc ../../Bin
cp -v Debug/*.so ../../Bin
```

Note that the CD version of SS:TSE used MP3 for music. You will need to build / get `libamp11lib.so` and copy it inside `Bin` with the other libs to have music. Steam version uses ogg and doesn't need this library.

Running
-------

This version of the engine comes with a set of resources (`\SE1_10b.GRO`) that allow you to freely use the engine without any additional resources required. You can buy the original games on Steam, as a part of a bundle with Serious Sam Revolution ( http://store.steampowered.com/app/227780 )

## Serious Sam Classic The First Encounter

### Running the game

1. Locate the game directory for "Serious Sam Classic The First Encounter" ([steam](https://store.steampowered.com/app/41050/Serious_Sam_Classic_The_First_Encounter/))
1. Build game from source code or [Download latest release](https://github.com/tx00100xt/SeriousSamClassic/releases) and copy the latest files from the game directory to SamTFE/Bin
1. Copy all *.gro files, Help folder and Levels folder from the game directory to SamTFE directory.
   At the current time the files are:
   * Help (folder)
   * Levels (folder)
   * 1_00_ExtraTools.gro
   * 1_00_music.gro
   * 1_00c.gro
   * 1_00c_Logo.gro
   * 1_00c_scripts.gro
   * 1_04_patch.gro
1. Start the game
   * ./run_game.sh or ./run_game_hud.sh (for start game with MangoHUD)

## Serious Sam Classic The Second Encounter

### Running the game

1. Locate the game directory for "Serious Sam Classic The Second Encounter" ([steam](https://store.steampowered.com/app/41060/Serious_Sam_Classic_The_Second_Encounter/))
1. Build game from source code or [Download latest release](https://github.com/tx00100xt/SeriousSamClassic/releases) and copy the latest files from the game directory to SamTSE/Bin
1. Copy all *.gro files and Help folder from the game directory to SamTSE directory.
   At the current time the files are:
   * Help (folder)
   * SE1_00.gro
   * SE1_00_Extra.gro
   * SE1_00_ExtraTools.gro
   * SE1_00_Levels.gro
   * SE1_00_Logo.gro
   * SE1_00_Music.gro
   * 1_04_patch.gro
   * 1_07_tools.gro
1. Start the game
   * ./run_game.sh or ./run_game_hud.sh (for start game with MangoHUD)

## Install the game in system (/usr/bin;/usr/lib/;/usr/share)

1. Edit the build script by adding a parameter to the cmake command:
```
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr 
```
2. Build game from source code with script.
3. Install the game: 
```
cd cmake-build
sudo make install
```
4.   Put game data in (Recommended):
```
/usr/share/serioussam/ - for TFE
/usr/share/serioussamse/ - for TSE
```
or
```
~/.local/share/Serious-Engine/serioussam/ - for TFE
~/.local/share/Serious-Engine/serioussamse/ - for TSE
```
4. Type in console:
```
serioussam       	# for run Serious Sam Classic The First Encounter
```
  or
```
serioussamse       	# for run Serious Sam Classic The Second Encounter
```
Note: If the game does not find the data on the recommended paths, then it will independently perform a search.

## Serious Sam Classic XPLUS

What is XPLUS?
XPLUS is a global modification that changes effects, models, weapons, textures to high definition. XPLUS was created by fans of the game Serious Sam and is distributed for free.
Remark: -JD- and VITEK is author this mod for windows.

![XPLUS Oasis](https://raw.githubusercontent.com/tx00100xt/SeriousSamClassic/main/Images/samxplus_1.png)

![XPLUS Dunes](https://raw.githubusercontent.com/tx00100xt/SeriousSamClassic/main/Images/samxplus_2.png)

![XPLUS Sacred Yards](https://raw.githubusercontent.com/tx00100xt/SeriousSamClassic/main/Images/samxplus_3.png)

### Linux

#### Building XPLUS (only for SS:TFE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTFE/Sources
./build-linux64xplus.sh -DTFE=TRUE	# use build-linux32xplus.sh for 32-bits
```

### FreeBSD

#### Building XPLUS (only for SS:TFE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTFE/Sources
cp -vfr Entities/PlayerWeaponsHD.es Entities/PlayerWeapons.es
mkdir cmake-build
cd cmake-build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DTFE=TRUE ..
make -j4
cp -v Debug/*.so ../../Mods/XPLUS/Bin
```
Download:
[Xplus TFE from Google Drive] or [Xplus TFE from pCloud], and unpack to  SeriousSamClassic/SamTFE/Mods directory.
To start the modification, use the game menu - item Modification.

### Linux

#### Building XPLUS (only for SS:TSE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTSE/Sources
./build-linux64xplus.sh        	    # use build-linux32xplus.sh for 32-bits
```

### FreeBSD

#### Building XPLUS (only for SS:TSE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTSE/Sources
cp -vfr EntitiesMP/PlayerWeaponsHD.es EntitiesMP/PlayerWeapons.es
mkdir cmake-build
cd cmake-build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
make -j4
cp -v Debug/*.so ../../Mods/XPLUS/Bin
```
Download:
[Xplus TSE from Google Drive] or [Xplus TSE from pCloud],, and unpack to  SeriousSamClassic/SamTSE/Mods directory.
To start the modification, use the game menu - item Modification.

Building demo version of the game
---------------------------------

To build the demo version of the game, official demo files for Windows and official patches for the game from Croteam are used. 
These files are automatically downloaded and unpacked in demo build scripts.

Type this in your terminal:

```
git clone https://github.com/tx00100xt/SeriousSamClassic.git SeriousSamClassic
cd SeriousSamClassic
./build-linux64demo.sh        	    # use build-linux32demo.sh for 32-bits
```

Windows
-------
* This project can be compiled starting from Windows 7 and higher.

1. Download and Install [Visual Studio 2015 Community Edition] or higher.
2. Download and Install [Windows 10 SDK 10.0.14393.795] or other.
3. Open the solution in the Sources folder, select Release x64 or Release Win32 and compile it.

Supported Architectures
----------------------
* `x86`
* `aarch64`
* `e2k` (elbrus)

Supported OS
-----------
* `Linux`
* `FreeBSD`
* `Windows`
* `Raspberry PI OS`

### Build status
|CI|Platform|Compiler|Configurations|Platforms|Status|
|---|---|---|---|---|---|
|GitHub Actions|Windows, Ubuntu, FreeBSD, Alpine, Raspberry PI OS Lite|MSVC, GCC, Clang|Release|x86, x64, armv7l, aarch64|![GitHub Actions Build Status](https://github.com/tx00100xt/SeriousSamClassic/actions/workflows/cibuild.yml/badge.svg)

You can download a the automatically build based on the latest commit.  
To do this, go to the [Actions tab], select the top workflows, and then Artifacts.

License
-------

* Serious Engine is licensed under the GNU GPL v2 (see LICENSE file).
* amp11lib is licensed under the GNU GPL v2 (see amp11lib/COPYING file).

Some of the code included with the engine sources is not licensed under the GNU GPL v2:

* zlib (located in `Sources/Engine/zlib`) by Jean-loup Gailly and Mark Adler
* LightWave SDK (located in `Sources/LWSkaExporter/SDK`) by NewTek Inc.
* libogg/libvorbis (located in `Sources/libogg` and `Sources/libvorbis`) by Xiph.Org Foundation

[Xplus TFE from Google Drive]: https://drive.google.com/file/d/1MPmibfMCGTWFBSGeFWG3uae0zZzJpiKy/view?usp=sharing "Serious Sam Classic XPLUS Mod"
[Xplus TSE from Google Drive]: https://drive.google.com/file/d/1W_UIeVl7y3ZBroM39FmKdngNZuXC7DKv/view?usp=sharing "Serious Sam Classic XPLUS Mod"
[Xplus TFE from pCloud]: https://e1.pcloud.link/publink/show?code=XZ02gRZ4nhrRGPSfV4aEL4IF8GYySafWVJX "Serious Sam Classic XPLUS Mod"
[Xplus TSE from pCloud]: https://e1.pcloud.link/publink/show?code=XZy2gRZ3D7n8fu83SkhIdB1xRaK7y9pKiry "Serious Sam Classic XPLUS Mod"
[Visual Studio 2015 Community Edition]: https://go.microsoft.com/fwlink/?LinkId=615448&clcid=0x409 "Visual Studio 2015 Community Edition"
[Windows 10 SDK 10.0.14393.795]: https://go.microsoft.com/fwlink/p/?LinkId=838916 "Windows 10 SDK 10.0.14393.795"
[Actions tab]: https://github.com/tx00100xt//SeriousSamClassic/actions "Download Artifacts"
