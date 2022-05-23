## Serious Sam Classic

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

There are still many asserts in the engine. Most of them are irrelevant and should be removed, but while it's not done, the asserts will effectively kill the engine when triggered in the Debug build. Use Release or RelWithDebInfo build if you intend to play (automatically set as RelWithDebInfo in the build scripts).

### Linux

#### Setting up the repository

Type this in your terminal:

```
git clone https://gitflic.ru/project/tx00100xt/serioussamclassic.git SeriousSamClassic
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

### FreeBSD

#### Setting up the repository

Type this in your terminal:

```
git clone https://gitflic.ru/project/tx00100xt/serioussamclassic.git SeriousSamClassic
```

#### Copy official game data (optional)

If you have access to a copy of the game (either by CD or through Steam),
you can copy the *.gro files from the game directory to the repository.
(SeriousSamClassic/SamTFE is the directory of the game Serious Sam Classic The First Encounter, SeriousSamClassic/SamTSE is the directory of the game Serious Sam Classic The Second Encounter)

#### Building (only for SS:TFE)

Type this in your terminal:

```
cd SeriousSamClassic/SamTFE/Sources
cp -vfr Entities/PlayerWeapons_old.es Entities/PlayerWeapons.e
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
cp -vfr Entities/PlayerWeapons_old.es Entities/PlayerWeapons.e
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
1. Build game from source code or [Download latest release](https://github.com/tx00100xt/SeriousSamClassic/releases) and copy the latest files from the game directory to SamTFE/Bin
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
cp -vfr Entities/PlayerWeaponsHD.es Entities/PlayerWeapons.e
mkdir cmake-build
cd cmake-build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DTFE=TRUE ..
make -j4
cp -v SeriousSam DedicatedServer MakeFONT ecc ../../Bin
cp -v Debug/*.so ../../Bin
```

Download [XplusTFE] and unpack to  SeriousSamClassic/SamTFE/Mods directory.
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
cp -vfr Entities/PlayerWeapons_old.es Entities/PlayerWeapons.e
mkdir cmake-build
cd cmake-build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
make -j4
cp -v SeriousSam DedicatedServer MakeFONT ecc ../../Bin
cp -v Debug/*.so ../../Bin
```

Download [XplusTSE] and unpack to  SeriousSamClassic/SamTSE/Mods directory.
To start the modification, use the game menu - item Modification.

License
-------

* Serious Engine is licensed under the GNU GPL v2 (see LICENSE file).
* amp11lib is licensed under the GNU GPL v2 (see amp11lib/COPYING file).

Some of the code included with the engine sources is not licensed under the GNU GPL v2:

* zlib (located in `Sources/Engine/zlib`) by Jean-loup Gailly and Mark Adler
* LightWave SDK (located in `Sources/LWSkaExporter/SDK`) by NewTek Inc.
* libogg/libvorbis (located in `Sources/libogg` and `Sources/libvorbis`) by Xiph.Org Foundation

[XplusTFE]: https://drive.google.com/file/d/1MPmibfMCGTWFBSGeFWG3uae0zZzJpiKy/view?usp=sharing "Serious Sam Classic XPLUS Mod"
[XplusTSE]: https://drive.google.com/file/d/1W_UIeVl7y3ZBroM39FmKdngNZuXC7DKv/view?usp=sharing "Serious Sam Classic XPLUS Mod"
