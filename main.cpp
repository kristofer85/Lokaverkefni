#include "uiproto.h"
#include <QApplication>

#include "disparity.h"
#include "reprojectimageto3d.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UiProto w;
    w.show();

    return a.exec();

    /*
    Mat depth;
    Disparity disparity("C:/!!Haust2015/Lokaverkefni/myndir/Left_stytta.png","C:/!!Haust2015/Lokaverkefni/myndir/right_stytta.png");
    depth = disparity.semiGlobalBlockMatching();
    ReprojectImageTo3d reprojectImageTo3d;
    FileStorage fs("C:/Q.xml", FileStorage::READ);

    if (!fs.isOpened())
    {
        cerr << "ERROR: Could not read Q.xml" << endl;
        return 1;
    }

    Mat Q;

    fs["Q"] >> Q;
    Q.convertTo(Q, CV_32F);
    fs.release();

    // If size of Q is not 4x4 exit
    if (Q.cols != 4 || Q.rows != 4)
    {
        cerr << "ERROR: Q is not 4x4)" << endl;
        return 1;
    }

    // Loading disparity image

    if (depth.empty())
    {
        cerr << "ERROR: Could not read disparity-image.pgm" << endl;
        return 1;
    }

    // Conversion of the disparity map to 32F before reprojecting to 3D
    // NOTE: also take care to do not scale twice the disparity
    depth.convertTo(depth, CV_32F, 1.0 / 16.0);

    // Reproject image to 3D by OpenCV
    Mat image3DOCV;
    reprojectImageTo3D(depth, image3DOCV, Q, false, CV_32F);

    // Reproject image to 3D by our own method
    Mat image3D;
    reprojectImageTo3d.reproject(depth, Q, image3D);

    reprojectImageTo3d.save(image3D, "c:/custom.xyz");
    reprojectImageTo3d.save(image3D, "c:/opencv.xyz");
    return 0;
    */
}
