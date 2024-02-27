#/bin/sh

rm -fr build
rm -fr build-xplus

# get linuxdeploy-x86_64.AppImage
wget -nv -c https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage
chmod +x linuxdeploy-x86_64.AppImage

# get croteam gro
wget -nv -c https://raw.githubusercontent.com/tx00100xt/serioussam-mods/main/gro/SE1_10.gro

# get source code
# git clone https://github.com/tx00100xt/SeriousSamClassic.git

# apply appimage patches
# cd SeriousSamClassic
patch -p1 < appimage/patches/0001-AppImage-CMakeLists.txt.patch
patch -p1 < appimage/patches/0002-AppImage-Engine.cpp.patch
patch -p1 < appimage/patches/0003-AppImage-Engine.h.patch
patch -p1 < appimage/patches/0004-AppImage-Stream.patch
patch -p1 < appimage/patches/0005-AppImage-Menu.cpp.patch

# build game
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr ..
make -j4
make install DESTDIR=AppDir
cd ..

# build xplus
mkdir build-xplus && cd build-xplus
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr -DXPLUS=TRUE ..
make -j4
make install DESTDIR=AppDir
cd ..

# copy compiled stuff to main dir
cp -ax build/AppDir AppDir
cp -ax build-xplus/AppDir/usr/* AppDir/usr

# copy SE1_10.gro
cp -fr SE1_10.gro AppDir/usr/share/serioussam

# copy TFE metainfo and desktop files
mkdir AppDir/usr/share/metainfo
cp -fr appimage/serioussam/io.itch.tx00100xt.serioussam.desktop AppDir/usr/share/applications
cp -fr appimage/serioussam/io.itch.tx00100xt.serioussam.appdata.xml AppDir/usr/share/metainfo

# remove unused stuff
rm -fr AppDir/usr/bin/{serioussamse,serioussamse-ded,serioussamse-mkfont,serioussamse-texconv}
rm -fr AppDir/usr/bin/{serioussam-ded,serioussam-mkfont,serioussam-texconv}
rm -fr AppDir/usr/lib/{serioussamse,libEngineMP.so}
rm -fr AppDir/usr/share/applications/serioussam.desktop
rm -fr AppDir/usr/share/applications/serioussamse.desktop
rm -fr AppDir/usr/share/serioussamse

# create appimage for TFE
export LD_LIBRARY_PATH=AppDir/usr/lib
SIGN=1 ./linuxdeploy-x86_64.AppImage --executable AppDir/usr/bin/serioussam --desktop-file AppDir/usr/share/applications/io.itch.tx00100xt.serioussam.desktop --icon-file AppDir/usr/share/icons/hicolor/128x128/apps/serioussam.png --appdir AppDir --output appimage
# copr compiled stuff to main dir
mv AppDir AppDirTFE
cp -ax build/AppDir AppDir
cp -ax build-xplus/AppDir/usr/* AppDir/usr

# copy SE1_10.gro
cp -fr SE1_10.gro AppDir/usr/share/serioussamse

# copy TSE metainfo and desktop files
mkdir AppDir/usr/share/metainfo
cp -fr appimage/serioussamse/io.itch.tx00100xt.serioussamse.desktop AppDir/usr/share/applications
cp -fr appimage/serioussamse/io.itch.tx00100xt.serioussamse.appdata.xml AppDir/usr/share/metainfo

# remove unused stuff
rm -fr AppDir/usr/bin/{serioussam,serioussam-ded,serioussam-mkfont,serioussam-texconv}
rm -fr AppDir/usr/bin/{serioussamse-ded,serioussamse-mkfont,serioussamse-texconv}
rm -fr AppDir/usr/lib/{serioussam,libEngine.so}
rm -fr AppDir/usr/share/applications/serioussam.desktop
rm -fr AppDir/usr/share/applications/serioussamse.desktop
rm -fr AppDir/usr/share/serioussam

# create appimage for TSE
export LD_LIBRARY_PATH=AppDir/usr/lib
SIGN=1 ./linuxdeploy-x86_64.AppImage --executable AppDir/usr/bin/serioussamse --desktop-file AppDir/usr/share/applications/io.itch.tx00100xt.serioussamse.desktop --icon-file AppDir/usr/share/icons/hicolor/128x128/apps/serioussam.png --appdir AppDir --output appimage
# rename appimages
mv Serious_Sam_The_First_Encounter-x86_64.AppImage SeriousSamTFE-1.10.6d-x86_64.AppImage
chmod +x SeriousSamTFE-1.10.6d-x86_64.AppImage
mv Serious_Sam_The_Second_Encounter-x86_64.AppImage SeriousSamTSE-1.10.6d-x86_64.AppImage
chmod +x SeriousSamTSE-1.10.6d-x86_64.AppImage
