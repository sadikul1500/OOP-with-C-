#ifndef brailleToBangla_H
#define brailleToBangla_H
#include<iostream>
#include<unordered_map>
#include "bangla.h"
#include "banglaTextProcess.h"

using namespace std;

class BrailleToBangla: public BanglaTextProcess, public BrailleToText
{
    private:
        Bangla bangla;

    public:
        BrailleToBangla()
        {
            cout<<"braille to bangla"<<endl;
        }

        string getBrailleToText(vector<string> text)
        {
            string outText = textProcess(text); //banglaTextProcess class
            int i = 0;
            //int length = srtlen(outText);

            while(i < outText.size())
            {
                if(bangla.getVol_spe().find(outText[i]) != bangla.getVol_spe().end() && i>0 && outText[i-1] == "100000")
                {
                    outText = outText.substr(0, i-1) + outText.substr(i, outText.size()-i+1);
                }
                else if(bangla.getSymbolToKar().find(outText[i]) != bangla.getSymbolToKar().end() && i>0 &&
                        bangla.getConsonant().find(outText[i-1]) != bangla.getConsonant().end())
                {
                    outText = outText.substr(0, i) + bangla.getSymbolToKar()[outText[i]] + outText.substr(i+1, outText.size()-i);
                }
                i += 1;
            }

            return outText;
        }


};

#endif // brailleToBangla_H


