//#include <QCoreApplication>
#include<iostream>
#include<string>
#include<vector>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/core/ocl.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/photo.hpp>
//#include<experimental/filesystem>

using namespace std;
using namespace cv;
using namespace cv::ocl;
//namespace fs = experimental::filesystem;

int main() //int argc, char *argv[]
{


    vector<cv::String> fn;
    glob("F:\\braille-text\\saadi\\*.png", fn, false);
    string outt = "F:\\braille-text\\saadi_out_3_crop\\";

    Mat image, gray, blur, blackWhite, erosion, dilation;
    //vector<Mat> images;
    size_t count = fn.size(); //number of png files in images folder
    for (size_t i=0; i<count; i++){
        cout<<fn[i]<<endl;
        image = imread(fn[i], IMREAD_COLOR);
        Rect crop_region(25, 100, image.cols-30, image.rows-130);
        image = image(crop_region);

        cvtColor(image, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, blur, Size(7, 7), 0, 0);
        //threshold(blur, blackWhite, 0, 255, 20);
        adaptiveThreshold(blur, blackWhite, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 5);


        /*
        double maxVal, minVal;
        Mat output;
        int top, bottom, left , right;
        int borderType = BORDER_CONSTANT;
        Scalar value;
        top = (int) (9); bottom = (int) (9);
        left = (int) (9); right = (int) (9);
        output = blur;
        Mat out = blur;
        value = 0;
        copyMakeBorder(blur,output,top,bottom,left,right,borderType,value);

         for(int y = 9; y < blur.rows; y++) {

            for(int x = 9; x < blur.cols; x ++) {

                    Mat ROI = blur(cv::Rect(cv::Point(x-4,y-4),cv::Size(9,9)));
                    minMaxLoc(ROI,&minVal,&maxVal);

            if(blur.at<uchar>(cv::Point(x-4,y-4)) >= 0.6*maxVal){

            out.at<uchar>(cv::Point(x-4,y-4)) = 255;
        }else{
            out.at<uchar>(cv::Point(x-4,y-4));

            }
        }
    }
    */

        //cout<<"local"<<endl;

        //imshow( "local otsu ", out);




        erode(blackWhite, erosion, getStructuringElement(MORPH_RECT, Size(5, 5)));
        dilate(erosion, dilation, getStructuringElement(MORPH_RECT, Size(5, 5)));
        //images.push_back(imread(fn[i]));
        imwrite((outt+to_string(i)+".png"), dilation);
        imshow( "black white image ", dilation); //optional
        cout<<"end"<<endl;
    }
    waitKey(0);
    destroyAllWindows();
}







/*
    std::string path = "F:\\image\\result1\\binDataFiles";    //"/path/to/directory";
        for (const auto & entry : fs::directory_iterator(path))
            std::cout << entry.path() << std::endl;

    */
    /*
    //QCoreApplication a(argc, argv);
    Mat image;
    char key;
    cout<<"ok man\n";

    image = imread("G:\\f drive\\1IIT\\5th semester\\SPL2\\Bengali-Braille-to-Text-Translator-master\\braille-data\\data_01.jpg", IMREAD_COLOR);
    imshow("opencv and qt", image);

    while(1)
    {
        key = waitKey();

        if (key == 'q')
        {
            destroyAllWindows();
            break;
        }
    }
    return 0; //a.exec();
    */
    /*
    vector<cv::String> fn;
    glob("G:\\image\\*.jpg", fn, false);
    string out = "G:\\image\\";

    Mat image, gray, blur, blackWhite, edge, oil, sharp, dnoise, water_color, erosion, dilation;
    //vector<Mat> images;
    size_t count = fn.size(); //number of png files in images folder
    for (size_t i=0; i<count; i++){
        //cout<<fn[i]<<endl;
        image = imread(fn[i], IMREAD_COLOR);

        stylization(image, water_color, 60, 0.45f);
        //pencilSketch(image, water_color, 60, 0.07, 0.02);
        imwrite((out+to_string(i)+"_water.png"), water_color);
        //cvtColor(image, gray, COLOR_BGR2GRAY);
        //imwrite((out+to_string(i)+"_gray.png"), gray);
        //fastNlMeansDenoisingColored(image, dnoise,30.0,30.0,7,21);
        //imwrite((out+to_string(i)+"_dnoise.png"), dnoise);
        //xphoto::oilPainting(image, oil, 10, 1, COLOR_BGR2Lab);

        //GaussianBlur(image, blur, Size(7, 7), 0, 0);
        //imwrite((out+to_string(i)+"_blur.png"), blur);
        //Laplacian(image, sharp, -1); //sharpening
        //imwrite((out+to_string(i)+"_sharp.png"), sharp);
        //Canny(blur, edge, 50, 100, 3);
        //imwrite((out+to_string(i)+"_canny.png"), edge);

        //threshold(blur, blackWhite, 0, 255, THRESH_BINARY | THRESH_OTSU);
        //images.push_back(imread(fn[i]));
        //imwrite((out+to_string(i)+".png"), blackWhite);
        //imshow( "black white image ", blackWhite); //optional
    }
    */
