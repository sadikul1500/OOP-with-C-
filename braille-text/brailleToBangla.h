#ifndef brailleToBangla_H
#define brailleToBangla_H
#include<iostream>
#include<fstream>
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

        bool isConsonant(string consonant)
        {
            unordered_map<string, string> allVowel = bangla.getVowelDictionary();
            /*
            for (pair<string, string> element : allVowel)
            {
                cout<<8909000<<endl;
                //oFile<<consonant<<" "<<element.second<<endl;
                //if(consonant == element.second)
                //{
                    //cout<<"dd "<<letters[i]<<endl;
                  //  return false; //element.second;
                //}
            }
            */



            //ofstream oFile("consonant.txt", ios::app);
            //cout<<"ookkk"<<endl;
            for (pair<string, string> element : allVowel)
            {
                //cout<<8909000<<endl;
                //oFile<<consonant<<" "<<element.second<<endl;
                if(consonant == element.second)
                {
                    //cout<<"dd "<<letters[i]<<endl;
                    return false; //element.second;
                }
            }
            return true;
            /*
            ofstream oFile("consonant.txt", ios::app);
            if (bangla.getVol_spe().find(consonant) != bangla.getVol_spe().end()
                 || bangla.getVolume().find(consonant) != bangla.getVolume().end()
                 || bangla.getSymbolToKar().find(consonant) != bangla.getSymbolToKar().end())
            {
                oFile<<"false "<<consonant<<endl;
                return false;
            }
            */
            /*
            for (pair<string, string> element : bangla.getConsonant())
            {
                if(consonant == element.second)
                {
                    return true;
                }
            }
            */
            //oFile<<"true "<<consonant<<endl;
            //return true;
        }

        string getBrailleToText(vector<string> text) //overriden
        {
            vector<string> outText = textProcess(text); //banglaTextProcess class
            int i = 0;
            string out = ""; //new
            ofstream oFile("tests.txt", ios::app);
            //int length = srtlen(outText);

            while(i < outText.size())
            {
                oFile<<outText[i]<<"\n"; //test_hudai
                if(bangla.getVol_spe().find(outText[i]) != bangla.getVol_spe().end() && i>0 && outText[i-1] == bangla.getVolume()["100000"])
                {
                    //outText = outText.substr(0, i-1) + outText.substr(i, outText.size()-i+1);
                    outText.erase(outText.begin()+ i-1);
                    i -= 1;
                }
                else if(bangla.getSymbolToKar().find(outText[i]) != bangla.getSymbolToKar().end() && i>0 &&
                        isConsonant(outText[i-1]))
                {
                    //outText = outText.substr(0, i) + bangla.getSymbolToKar()[outText[i]] + outText.substr(i+1, outText.size()-i);
                    outText[i] = bangla.getSymbolToKar()[outText[i]];
                    //cout<<"yes"<<endl;
                }
                //if(bangla.getSymbolToKar().find(outText[i]) != bangla.getSymbolToKar().end()) cout<<"paise"<<endl;
                i += 1;
            }

            return returnText(outText);
        }

        string postProcess(string text)
        {
            return text;
        }


};

#endif // brailleToEnglish_H


