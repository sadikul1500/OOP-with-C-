//#include <QCoreApplication>
#include<iostream>
#include<string>
#include<vector>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
//#include<experimental/filesystem>

using namespace std;
using namespace cv;
//namespace fs = experimental::filesystem;

int main() //int argc, char *argv[]
{
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

    vector<cv::String> fn;
    glob("G:\\f drive\\1IIT\\5th semester\\SPL2\\Bengali-Braille-to-Text-Translator-master\\braille-data\\*.jpg", fn, false);
    string out = "F:\\braille-text\\image_out\\";

    Mat image, gray, blur, blackWhite;
    //vector<Mat> images;
    size_t count = fn.size(); //number of png files in images folder
    for (size_t i=0; i<count; i++){
        //cout<<fn[i]<<endl;
        image = imread(fn[i], IMREAD_COLOR);
        cvtColor(image, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, blur, Size(7, 7), 0, 0);
        threshold(blur, blackWhite, 0, 255, THRESH_BINARY | THRESH_OTSU);
        //images.push_back(imread(fn[i]));
        imwrite((out+to_string(i)+".png"), blackWhite);
        imshow( "black white image ", blackWhite); //optional
    }
    waitKey(0);
    destroyAllWindows();
}
