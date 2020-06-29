#include<iostream>
#include<fstream>
//#include<filesystem>
#include "brailleToText.h"
#include "brailleToEnglish.h"
#include "brailleToBangla.h"
//#include "splitText.h"
//#include "fileManager.h"
//#include "postTextProcess.h"

using namespace std;

int main()
{
    BrailleToText *brailleToText;
    BrailleToEnglish brailleToEnglish;
    BrailleToBangla brailleToBangla;

    string language;
    cout<<"select language\n1.Bangla\n2.English"<<endl;
    getline(cin, language);

    if(language == "english" || language == "2")
    {
        brailleToText = &brailleToEnglish;
    }
    else
    {
        brailleToText = &brailleToBangla;
    }

    string inputFile = "download3.txt";
    string outText = brailleToText->getText(inputFile, brailleToText);
    ofstream oFile("out_"+inputFile); //"outDataBangla.txt"
    oFile<<outText;

}
