Qt based user interface for INQNET TDC

Instructions:

1. install Ubuntu 22.04.1 (this vesion manage dual boot with windows automatically)

2. Fix the date an the time of the computer, then run sudo apt-get update

3. sudo apt-get install cmake perl ninja-build default-libmysqlclient-dev libxcb-xinerama0  libmysql++-dev libxcb-cursor0 '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev libpciaccess-dev libfontconfig1-dev   libfreetype6-dev    libx11-dev    libx11-xcb-dev    libxext-dev    libxfixes-dev    libxi-dev    libxrender-dev    libxcb1-dev    libxcb-cursor-dev    libxcb-glx0-dev    libxcb-keysyms1-dev    libxcb-image0-dev    libxcb-shm0-dev    libxcb-icccm4-dev    libxcb-sync-dev    libxcb-xfixes0-dev    libxcb-shape0-dev    libxcb-randr0-dev    libxcb-render-util0-dev    libxcb-util-dev    libxcb-xinerama0-dev    libxcb-xkb-dev    libxkbcommon-dev    libxkbcommon-x11-dev libgtk-3-dev libglib2.0-dev mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev

4. download and install qt-creator-opensource-linux-x86_64-11.0.0.run

5. donwload and unzip qt-everywhere-src-6.4.0.tar.xz

6. Follow the instructions on the qt-everywhere readme (requires some packages to install and run few commands)

7.  Open qtcreator, open the .pro file of this project, on the kit manager and search for the QT on qt-everywhere.../base/bin/qmake

8. Change the release build directory to the local /build folder of this project

9. you should be ready to go, press play (on release mode)

