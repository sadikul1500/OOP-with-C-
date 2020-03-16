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

        string returnText(vector<string> text)
        {
            string outText = "";
            for(int i=0; i<text.size(); i++)
            {
                outText += text[i];
            }
            return outText;
        }

        string getBrailleToText(vector<string> text)
        {
            vector<string> outText = textProcess(text); //banglaTextProcess class
            int i = 0;
            //int length = srtlen(outText);

            while(i < outText.size())
            {
                if(bangla.getVol_spe().find(outText[i]) != bangla.getVol_spe().end() && i>0 && outText[i-1] == "অ")
                {
                    //outText = outText.substr(0, i-1) + outText.substr(i, outText.size()-i+1);
                    outText.erase(outText.begin()+ i-1);
                }
                else if(bangla.getSymbolToKar().find(outText[i]) != bangla.getSymbolToKar().end() && i>0 &&
                        bangla.getConsonant().find(outText[i-1]) != bangla.getConsonant().end())
                {
                    //outText = outText.substr(0, i) + bangla.getSymbolToKar()[outText[i]] + outText.substr(i+1, outText.size()-i);
                    outText[i] = bangla.getSymbolToKar()[outText[i]];
                }
                i += 1;
            }

            return returnText(outText);
        }


};

#endif // brailleToEnglish_H


