#ifndef UIPROTO_H
#define UIPROTO_H
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <math.h>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/contrib/contrib.hpp>

#include <QMainWindow>
#include<QFileDialog>
#include<QtCore>
using namespace cv;
namespace Ui {
class UiProto;
}

class UiProto : public QMainWindow
{
    Q_OBJECT

public:
    explicit UiProto(QWidget *parent = 0);
    ~UiProto();
    cv::Mat orginalL;
    cv::Mat orginalR;
    cv::Mat matGrayscaleL;
    cv::Mat matGrayscaleR;
    cv::Mat matDeapth;
    cv::Mat g1, g2, g3, g4;
    cv::Mat disp, disp8,disp3, disp2, disp16;

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_SadSlider_valueChanged(int value);

    void on_NrOfDispSlider_valueChanged(int value);

    void on_PrefilterCapSlider_valueChanged(int value);

    void on_UniquenessRatoSlider_valueChanged(int value);

    void on_speclewindowSlider_valueChanged(int value);

    void on_specRangeSlider_valueChanged(int value);

    void on_disp12MaxDifSlider_valueChanged(int value);

    void on_FullDPCheckbox_toggled(bool checked);

    void on_P1Slider_sliderPressed();

    void on_P1Slider_valueChanged(int value);

    void on_P2Slider_valueChanged(int value);

    void on_btnChessboard_clicked();

    void on_minDisparitySlider_valueChanged(int value);

    void on_btnHistogram_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::UiProto *ui;
    int SADWindowSize;
    //int SW = SADWindowSize;
    int numberOfDisparities;
    int preFilterCap;
    int minDisparity;
    int uniquenessRatio;
    int speckleWindowSize;
    int speckleRange;
    int disp12MaxDiff;
    bool fullDP;
    //sgbm.P1 = 600;
    //sgbm.P2 = 2400;
    int P1;
    //P1 = 8*cn*SW*SW;
    int P2;
    //P2 = 32*cn*SW*SW;
     QImage UiProto::matToQImage(cv::Mat mat);
};

#endif // UIPROTO_H
