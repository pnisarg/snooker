#ifndef __BALLDETECT_H_INCLUDED__
#define __BALLDETECT_H_INCLUDED__
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<string>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

class ballDetect{
public:
    //max number of objects to be detected in frame
    const int MAX_NUM_OBJECTS;
    //minimum and maximum object area
    const int MIN_OBJECT_AREA;
    const int MAX_OBJECT_AREA;
    //FRAME_HEIGHT*FRAME_WIDTH/1.5;
    //default capture width and height
    const int FRAME_WIDTH;
    const int FRAME_HEIGHT;

    ballDetect();
    string intToString(int number);
    void drawObject(int x, int y,Mat &frame,int ballIndex,int redIndex);
    void morphOps(Mat &processed);
    void trackFilteredObject(int &, int &, Mat , Mat &,int);
};

#endif
