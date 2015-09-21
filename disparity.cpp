#include "disparity.h"

Disparity::Disparity()
{

}

Disparity::Disparity(string l, string r)
{
    img_left = imread(l);
    img_right = imread(r);
    cvtColor(img_left, g_left, CV_BGR2GRAY);
    cvtColor(img_right, g_right, CV_BGR2GRAY);



}

Mat Disparity::semiGlobalBlockMatching()
{
    StereoSGBM sgbm;
    sgbm.SADWindowSize = 9;
    sgbm.numberOfDisparities = 128;
    sgbm.preFilterCap = 63;
    sgbm.minDisparity = -64;
    sgbm.uniquenessRatio = 1;
    sgbm.speckleWindowSize = 100;
    sgbm.speckleRange = 16;
    sgbm.disp12MaxDiff = 2;
    sgbm.fullDP = false;
    sgbm.P1 = 1200;
    sgbm.P2 = 2400;

    sgbm(g_left, g_right, disp);
    normalize(disp, disp8, 0, 255, CV_MINMAX, CV_8U);
    return disp8;

}


