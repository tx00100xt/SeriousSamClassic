#!/bin/bash

# clone repo
# git clone https://github.com/tx00100xt/SeriousSamClassic.git
# cd SeriousSamClassic

cd SamTFE
mv Scripts/GLSettings Scripts/GLSettings_new
wget https://archive.org/download/SeriousSamDemo/SeriousSamDemo.exe
wget https://archive.org/download/SeriousSamPatches/serioussampatch105_usa.exe
7z x SeriousSamDemo.exe
7z x -y serioussampatch105_usa.exe
rm -fr Scripts/GLSettings
mv Scripts/GLSettings_new Scripts/GLSettings
cp -vr Disk1/* .
sed -i 's/01_Hatshepsut.wld/KarnakDemo.wld/g' Sources/SeriousSam/SeriousSam.cpp
sed -i 's/sam_menulogo256a.tex/sam_menulogo256a_demo.tex/g' Sources/SeriousSam/Menu.cpp
sed -i 's/sam_menulogo256b.tex/sam_menulogo256b_demo.tex/g' Sources/SeriousSam/Menu.cpp
# Remove useless Windows files
rm -f {*.exe,*.ex_,*.bmp,*.inx,*.hdr,*.bin,*.cab,*.ini,*.log}
rm -fr Bin
rm -fr Disk1 
rm -fr Tools.Win32
mkdir Bin
cd Sources
./build-linux64.sh -DTFE=TRUE

cd ..
cd ..
cd SamTSE
mv Scripts/GLSettings Scripts/GLSettings_new
wget https://archive.org/download/serioussamsedemo/SeriousSamSEDemo.exe
wget https://archive.org/download/SeriousSamPatches/secondencounterpatch107_usa.exe
7z x SeriousSamSEDemo.exe
7z x -y secondencounterpatch107_usa.exe
rm -fr Scripts/GLSettings
mv Scripts/GLSettings_new Scripts/GLSettings
cp -vr Disk1/* .
sed -i 's/1_0_InTheLastEpisode.wld/Demo\\\\Palenque_Demo.wld/g' Scripts/Game_startup.ini
sed -i 's/1_0_InTheLastEpisode.wld/Demo\\\\Palenque_Demo.wld/g' Sources/SeriousSam/SeriousSam.cpp
sed -i 's/sam_menulogo256a.tex/sam_menulogo256a_demo.tex/g' Sources/SeriousSam/Menu.cpp
sed -i 's/sam_menulogo256b.tex/sam_menulogo256b_demo.tex/g' Sources/SeriousSam/Menu.cpp
# Remove useless Windows files
rm -f {*.exe,*.ex_,*.bmp,*.inx,*.hdr,*.bin,*.cab,*.ini,*.log}
rm -fr Bin
rm -fr Disk1 
rm -fr Tools.Win32
mkdir Bin
cd Sources
./build-linux64.sh
