#ifndef brailleToEnglish_H
#define brailleToEnglish_H
#include<iostream>
#include<unordered_map>
#include "bangla.h"
#include "banglaTextProcess.h"

using namespace std;

class BrailleToBangla: public BanglaTextProcess
{
    private:
        Bangla bangla;

    public:
        BrailleToBangla()
        {
            cout<<"braille to bangla"<<endl;
        }

        string* getBrailleToText(string *text)
        {
            string[] outText = textProcess(text);
            //int length = srtlen(outText);

            while(i < srtlen(outText))
            {
                if(bangla.getVol_spe().find(outText[i]) != bangla.getVol_spe().end() && i>0 && outText[i-1] == "100000")
                {
                    outText = outText.substr(0, i-1) + outText.substr(i, srtlen(outText)-i+1);
                }
                else if(bangla.getSymbolToKar().find(outText[i]) != bangla.getSymbolToKar().end() && i>0 &&
                        bangla.getConsonant().find(outText[i-1]) != bangla.getConsonant().end())
                {
                    outText = outText.substr(0, i) + bangla.getSymbolToKar()[outText[i]] + outText.substr(i+1, srtlen(outText)-i);
                }
                i += 1;
            }

            return outText;
        }


};

#endif // brailleToEnglish_H


