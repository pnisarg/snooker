#include<iostream>
#include "ballDetect.h"
using namespace std;
using namespace cv;
int main(int argc, char **argv){
    ballDetect detect;
    detect.initDetect(argv[1]);
    return 0;
}

