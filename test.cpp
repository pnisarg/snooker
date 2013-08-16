
/**
 *@author: Nisarg Patel
 *Date: 16/08/2013
 */
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat src,src_gray,processed,blue,pink,white,red,brown,black,yellow,temp;
    src = imread(argv[1]);
    pyrUp(src, src);
    cvtColor(src, src_gray, CV_BGR2HSV);
    blur(src_gray, src_gray, Size(3,3));
    //opencv uses 0-180 for H
    //red - 0,150,150 - 10,255,255
    //white - 0,0,200 - 255,70,255
    //black - 0,0,0 - 255,255,50
    //blue - 120,0,0 - 130,255,255
    //yellow -25,150,140 - 35,255,255
    //pink - 155,0,0 - 165,255,255
    //all-inverted - 40,0,0 - 130,255,255
    
    //blue
    inRange(src_gray, Scalar(120,0,0),
            Scalar(130,255,255), processed);
    Canny(processed, blue, 100, 100*3,5);
    //pink
    inRange(src_gray, Scalar( 155,0,0),
            Scalar(165,255,255), processed);
    Canny(processed, pink, 100, 100*3,5);
    bitwise_or(pink, blue, temp);
    //white
    inRange(src_gray, Scalar(0,0,200),
            Scalar(255,50,255), processed);
    Canny(processed, white, 100, 100*3,5);
    bitwise_or(temp, white, temp);
    //red
    inRange(src_gray, Scalar(0,150,150),
            Scalar(10,255,255), processed);
    Canny(processed, red, 100, 100*3,5);
    bitwise_or(temp, red, temp);
    //black
    inRange(src_gray, Scalar(0,0,0),
            Scalar(255,255,50), processed);
    Canny(processed, black, 100, 100*3,5);
    bitwise_or(temp, black, temp);
    //yellow
    inRange(src_gray, Scalar(25,150,140),
            Scalar(35,255,255), processed);
    Canny(processed, yellow, 100, 100*3,5);
    bitwise_or(temp, yellow, temp);
    //brown
    inRange(src_gray, Scalar(10,160,140),
            Scalar(20,220,200), processed);
    Canny(processed, brown, 100, 100*3,5);
    bitwise_or(temp, brown, processed);
    vector<Vec3f> circles;
    HoughCircles(processed,circles, CV_HOUGH_GRADIENT,1,src_gray.rows/64,10,15,5,20);
    for( size_t i = 0; i < circles.size(); i++ ) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1])); int radius = cvRound(circles[i][2]);
        // circle center
        circle( src, center, 3, Scalar(150,255,150), -1, 8, 0 );
        // circle outline
        circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
        
    }
    cout << circles.size();
    namedWindow( "src", CV_WINDOW_AUTOSIZE );
    imshow( "src", src);
    namedWindow("processed ");
    imshow("processed",processed);
    
    waitKey(0);
    
    
    return 0;
}

