#include "uiproto.h"
#include "ui_uiproto.h"


class SterioMats
{
   public:
    Mat left;
    Mat right;
    vector<Point2f> ptvecL;
    vector<Point2f> ptvecR;
    SterioMats()
    {

    }

    SterioMats(String L, String R)
    {
        left = imread(L);
        //imshow("left",left);
        right = imread(R);
        //imshow("right",right);
    }
    SterioMats(Mat L, Mat R)
    {
        left = L;
        right = R;
    }
    void Corners(Size boardSize)
    {
        //namedWindow( "image left", WINDOW_AUTOSIZE );
        //namedWindow( "image right", WINDOW_AUTOSIZE );
        bool foundL = findChessboardCorners( left, boardSize, ptvecL, CV_CALIB_CB_ADAPTIVE_THRESH );
        bool foundR = findChessboardCorners( right, boardSize, ptvecR, CV_CALIB_CB_ADAPTIVE_THRESH );
        /*
        std::cout << "foundL = " << foundL << " foundR = " << foundR << std::endl;
        std::cout << " L " << ptvecL.size() << " R " << ptvecR.size() << std::endl;
        if(!foundL)
        {
            std::cout << "FoundL not true" << std::endl;
            rotate(left, -90, left);
            ptvecL.clear();
            bool foundL = findChessboardCorners( left, boardSize, ptvecL, CV_CALIB_CB_ADAPTIVE_THRESH );
            std::cout << "foundL = " << foundL << " L " << ptvecL.size() << std::endl;
        }
        else
        {
            std::cout << "foundL = " << foundL << " L " << ptvecL.size() << std::endl;
        }
        if(!foundR)
        {
            std::cout << "FoundR not true" << std::endl;
            flip(right,right,1);
            ptvecR.clear();
            foundR = findChessboardCorners( left, boardSize, ptvecL, CV_CALIB_CB_ADAPTIVE_THRESH );
            std::cout << "foundR = " << foundL << " R " << ptvecR.size() << std::endl;
        }
        else
        {
            std::cout << "foundR = " << foundR << " R " << ptvecR.size() << std::endl;
        }
        */
        drawChessboardCorners( left, boardSize,ptvecL, foundL );
        drawChessboardCorners( right, boardSize,ptvecR, foundR );
        //imshow("image left ",left);
        //imshow("image right ",right);

    }
};

UiProto::UiProto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UiProto)
{
    ui->setupUi(this);
}

UiProto::~UiProto()
{
    delete ui;
}

QImage UiProto::matToQImage(cv::Mat mat) {
    if(mat.channels() == 1) {                   // if grayscale image
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // declare and return a QImage
    } else if(mat.channels() == 3) {            // if 3 channel color image
        cv::cvtColor(mat, mat, CV_BGR2RGB);     // invert BGR to RGB
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // declare and return a QImage
    } else {
        qDebug() << "in openCVMatToQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();        // return a blank QImage if the above did not work
}

void UiProto::on_pushButton_8_clicked()
{
    QString strFileName = QFileDialog::getOpenFileName();       // bring up open file dialog

    /*
    if(strFileName == "") {                                     // if file was not chosen
        ui->lblChosenFile->setText("file not chosen");          // update label
        return;                                                 // and exit function
    }
    */

    orginalL = cv::imread(strFileName.toStdString());        // open image
    cv::pyrDown(orginalL,orginalL,Size( orginalL.cols/2, orginalL.rows/2 ));
    cv::cvtColor(orginalL, matGrayscaleL, CV_BGR2GRAY);
     QImage QorginalL = matToQImage(orginalL);         // convert original and Canny images to QImage
     ui->picL->setPixmap(QPixmap::fromImage(QorginalL));   // show original and Canny images on labels


}

void UiProto::on_pushButton_10_clicked()
{
    QString strFileName = QFileDialog::getOpenFileName();       // bring up open file dialog


    /*
    if(strFileName == "") {                                     // if file was not chosen
        ui->lblChosenFile->setText("file not chosen");          // update label
        return;                                                 // and exit function
    }
    */

    orginalR = cv::imread(strFileName.toStdString());        // open image
    cv::pyrDown(orginalR,orginalR,Size( orginalR.cols/2, orginalR.rows/2 ));
     cv::cvtColor(orginalR, matGrayscaleR, CV_BGR2GRAY);
     QImage QorginalR = matToQImage(orginalR);         // convert original and Canny images to QImage
     ui->picR->setPixmap(QPixmap::fromImage(QorginalR));   // show original and Canny images on labels
}

void UiProto::on_SadSlider_valueChanged(int value)
{
    if(!(value%2 == 0))
    {
        SADWindowSize = value;
        ui->SADwindowValue->setText(QString::number(value));
    }
}

void UiProto::on_NrOfDispSlider_valueChanged(int value)
{
    if((value-minDisparity)%16 == 0)
    {
        numberOfDisparities = value;
        ui->NrOfDispValue->setText(QString::number(value));
    }
}


void UiProto::on_PrefilterCapSlider_valueChanged(int value)
{
    preFilterCap = value;
    ui->prefilterCapValue->setText(QString::number(value));
}

void UiProto::on_UniquenessRatoSlider_valueChanged(int value)
{
    uniquenessRatio = value;
    ui->UniquenessRatoValue->setText(QString::number(value));
}

void UiProto::on_speclewindowSlider_valueChanged(int value)
{
    speckleWindowSize = value;
    ui->speclewindowValue->setText(QString::number(value));
}



void UiProto::on_specRangeSlider_valueChanged(int value)
{
    speckleRange = value;
    ui->specRangeValue->setText(QString::number(value));
}

void UiProto::on_disp12MaxDifSlider_valueChanged(int value)
{
    disp12MaxDiff = value;
    ui->disp12MaxDifValue->setText(QString::number(value));
}

void UiProto::on_FullDPCheckbox_toggled(bool checked)
{
    fullDP = checked;
}

void UiProto::on_P1Slider_valueChanged(int value)
{
    P1 = value;
    ui->P1Value->setText(QString::number(value));
}



void UiProto::on_P2Slider_valueChanged(int value)
{
    P2 = value;
    ui->P2Value->setText(QString::number(value));
}

void UiProto::on_P1Slider_sliderPressed()
{

}

void UiProto::on_btnChessboard_clicked()
{
    SterioMats Smats(orginalL,orginalR);
    Size boardSize(6,9);
    Smats.Corners(boardSize);
    QImage QorginalL = matToQImage(Smats.left);         // convert original and Canny images to QImage
    ui->picL->setPixmap(QPixmap::fromImage(QorginalL));   // show original and Canny images on labels
    QImage QorginalR = matToQImage(Smats.right);         // convert original and Canny images to QImage
    ui->picR->setPixmap(QPixmap::fromImage(QorginalR));   // show original and Canny images on labels

}

void UiProto::on_minDisparitySlider_valueChanged(int value)
{
            minDisparity = value;
            ui->minDisparityValue->setText(QString::number(value));
}

void UiProto::on_btnHistogram_clicked()
{

    equalizeHist( matGrayscaleL,  matGrayscaleL );
    equalizeHist( matGrayscaleR,  matGrayscaleR );
    QImage QorginalR = matToQImage(matGrayscaleR);         // convert original and Canny images to QImage
    ui->picR->setPixmap(QPixmap::fromImage(QorginalR));   // show original and Canny images on labels
    QImage QorginalL = matToQImage(matGrayscaleL);         // convert original and Canny images to QImage
    ui->picL->setPixmap(QPixmap::fromImage(QorginalL));   // show original and Canny images on labels
    /*
    QImage QorginalR = matToQImage(matGrayscaleR);         // convert original and Canny images to QImage
    ui->picR->setPixmap(QPixmap::fromImage(QorginalR));   // show original and Canny images on labels
    QImage QorginalL = matToQImage(matGrayscaleL);         // convert original and Canny images to QImage
    ui->picL->setPixmap(QPixmap::fromImage(QorginalL));   // show original and Canny images on labels
    */
}

void UiProto::on_pushButton_4_clicked()
{

}

void UiProto::on_btnSterio_clicked()
{
    int SW = 3;
    StereoSGBM sgbm;
    /*
    sgbm(g3, g4, disp2);
    normalize(disp2, disp8, 0, 255, CV_MINMAX, CV_8U);
    imshow("disp", disp2);
    */

    cv::waitKey(0);
    int cn = orginalL.channels();
    sgbm.SADWindowSize = SW;
    sgbm.numberOfDisparities = orginalL.size().width/8;
    sgbm.preFilterCap = 63;
    sgbm.minDisparity = 0;
    sgbm.uniquenessRatio = 2;
    sgbm.speckleWindowSize = 150;
    sgbm.speckleRange = 2;
    sgbm.disp12MaxDiff = 2;
    sgbm.fullDP = true;
    //sgbm.P1 = 600;
    //sgbm.P2 = 2400;
    sgbm.P1 = 8*cn*SW*SW;
    sgbm.P2 = 32*cn*SW*SW;

    sgbm(matGrayscaleL, matGrayscaleR, disp);
    normalize(disp2, disp8, 0, 255, CV_MINMAX, CV_8U);
}
