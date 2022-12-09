#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

int main(int argc, const char* argv[])
{
    system("mkdir motion/");
    system("rm motion/*");
    
    
    VideoCapture cap1(atoi(argv[1]));
    VideoCapture cap2(atoi(argv[2]));
    if(!cap1.isOpened()) return -1;
    if(!cap2.isOpened()) return -1;

    cap1.set(CAP_PROP_FRAME_WIDTH,800);
    cap1.set(CAP_PROP_FRAME_HEIGHT,600);
    cap2.set(CAP_PROP_FRAME_WIDTH,640);
    cap2.set(CAP_PROP_FRAME_HEIGHT,480);
    fps = cap1.set(CAP_PROP_FPS, 30);
    namedWindow("Cam1",WINDOW_KEEPRATIO);
    namedWindow("Cam2",WINDOW_KEEPRATIO);

    VideoWriter videoW1("output1.avi",VideoWriter::fourcc('M','J','P','G'),fps, Size(800,600));
    VideoWriter videoW2("output2.avi",VideoWriter::fourcc('M','J','P','G'),fps, Size(640,480));

    Mat frameC1, frameC2;
    for(;;)
    {
        //capturing original camera signal
        cap1 >> frameC1;
        cap2 >> frameC2;
        
        imshow("Cam1", frameC1);
        imshow("Cam2", frameC2);

        videoW1.write(frameC1);
        videoW2.write(frameC2);

        if(waitKey(1) >= 0) break;
    }

    cap1.release();
    videoW1.release();
    cap2.release();
    videoW2.release();
    
    return 0;
}

