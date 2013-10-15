Requirements:
--------------
• GCC 4.4.x or later. This can be installed with:
     sudo apt-get install build-essential

• CMake 2.6 or higher. Installing instructions:
     http://www.cmake.org/cmake/help/install.html
  
• GTK+2.x or higher, including headers (libgtk2.0-dev);

• ffmpeg or libav development packages: libavcodec-dev, libavformat-dev, libswscale-dev;

• [optional] libdc1394 2.x;

• [optional] libjpeg-dev, libpng-dev, libtiff-dev, libjasper-dev.


Usage
-----
- $ mkdir build
- $ cd build
- $ cmake ..
- $ make
- $ ./snooker video.mp4

It will create snooker executable
