#ifndef DISPARITY_H
#define DISPARITY_H
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include "opencv/cv.h"
#include "opencv/cxmisc.h"
#include "opencv/highgui.h"
#include "opencv/cvaux.h"
using namespace std;
using namespace cv;

class Disparity
{
public:
    Disparity();
    Disparity(string l, string r);
    Mat semiGlobalBlockMatching();
    Mat img_left;
    Mat img_right;
    Mat g_left;
    Mat g_right;
    Mat disp;
    Mat disp8;
    string leftImage;
    string rightImage;
};

#endif // DISPARITY_H
