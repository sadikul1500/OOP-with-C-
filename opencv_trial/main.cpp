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
    glob("F:\\braille-text\\scan_copy\\*.jpeg", fn, false);
    string outt = "F:\\braille-text\\scan_copy_simple\\";

    //int ret
    Mat image, gray, hist, blur, median, blackWhite, erosion, dilation;
    //vector<Mat> images;
    size_t count = fn.size(); //number of png files in images folder
    for (size_t i=0; i<count; i++){
        cout<<fn[i]<<endl;
        image = imread(fn[i], IMREAD_COLOR);
        Rect crop_region(25, 100, image.cols-30, image.rows-130);
        image = image(crop_region);

        cvtColor(image, gray, COLOR_BGR2GRAY);
        //equalizeHist(gray, hist); not works
        GaussianBlur(gray, blur, Size(5, 5), 0, 0);
        medianBlur(blur, median, 5);
        //threshold(blur, blackWhite, 0, 255, THRESH_BINARY + THRESH_OTSU);
        adaptiveThreshold(median, blackWhite, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 13, 6);
        //threshold( blur, blackWhite, 230, 255, THRESH_BINARY );



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





