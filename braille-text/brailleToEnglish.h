#ifndef brailleToEnglish_H
#define brailleToEnglish_H
#include<iostream>
#include<unordered_map>
#include "english.h"
#include "double_map.h"

using namespace std;

class BrailleToEnglish: public BrailleToText
{
    private:
        English english;
        string numeral_sign = "001111";
        string capital_sign = "000001";

    public:
        BrailleToEnglish()
        {
            cout<<"braille to text"<<endl;
        }

        string upper(string lower)
        {
            int length = lower.size();
            for(int i=0; i<length; i++)
                lower[i] = lower[i] - 32;
            return lower;
        }

        string getText(unordered_map<string, string> dd, vector<string> letters, int i, bool *capital)
        {
            int flag = 0;

            for (pair<string, string> element : dd)
            {
                if(letters[i] == element.first)
                {
                    flag = 0;
                    if(*capital)
                    {
                        *capital = false;
                        return upper(element.second);
                    }
                    return element.second;
                }
            }
            if(!flag) return letters[i];

        }

        string numberProcess(vector<string> letters, int *bracket_count, int *i, int* length)
        {
            if(english.getOperator().find(letters[*i]) != english.getOperator().end())
            {
                 if(letters[*i] == "011011" and *bracket_count == 0)
                 {
                     *bracket_count += 1;
                     return "(";
                 }

                 else if(letters[*i] == "011011" and *bracket_count == 1)
                 {
                     *bracket_count = 0;
                     return ")";
                 }

                 else
                 {
                     return english.getOperator()[letters[*i]];
                 }
            }

            else if(english.getEnglishNumbers().find(letters[*i]) != english.getEnglishNumbers().end())
            {
                return english.getEnglishNumbers()[letters[*i]];
            }

            else if((english.getOperator().find(letters[*i]) == english.getOperator().end() ||
                    english.getEnglishNumbers().find(letters[*i]) == english.getEnglishNumbers().end()) && *i+1 < *length)
            {
                if(letters[*i] == "001010" && letters[*i+1] == "001010")
                {
                    *i++;
                    return english.getOperator()[letters[*i-1] + letters[*i+1-1]];
                }

                else if(letters[*i] == "000011" && letters[*i+1] == "011011")
                {
                    *i++;
                    return english.getOperator()[letters[*i-1] + letters[*i+1-1]];
                }

                else if(letters[*i] == "000001" && letters[*i+1] == "011011")
                {
                    *i++;
                    return "[";
                }

                else if(letters[*i] == "011011" && letters[*i+1] == "000001")
                {
                    *i++;
                    return "]";
                }

                else
                {
                    return "";
                }
            }

            else return "";
        }

        string postProcess(string text)
        {
            if(text.find("000001000001") != string::npos)
            {
                text.replace(text.find("000001000001"), 12, "");
                int length = text.size();
                cout<<text<<endl;
                for(int i=0; i<length-1; i++)
                {
                    text[i] = text[i] - 32;
                }
            }
            return text;
        }


        string getBrailleToText(vector<string> letters)
        {
            int length = letters.size();//sizeof(letters) / sizeof(*letters);
            bool capital = false, num = false;
            int i = 0;
            string text = "";
            int bracket_count = 0;
            unordered_map<string, string> dd = english.getEnglishDictionary();

            while(i < length)
            {
                if(num)
                {
                    text += numberProcess(letters, &bracket_count, &i, &length);
                }

                else
                {
                    if(letters[i] == numeral_sign) //i == 0 &&
                    {
                        num = true;
                    }
                    //else if(letters[i] == numeral_sign && english.getPunctuation().find(letters[i-1]) !=english.getPunctuation().end())
                    //{
                      //  num = true;
                    //}
                    else
                    {
                        if(i+1 < length && english.getTwelveDots().find(letters[i] + letters[i+1]) != english.getTwelveDots().end())
                        {
                            text += english.getTwelveDots()[letters[i] + letters[i + 1]];
                            i += 1;
                        }
                        else if(english.getDouble_mapping().find(letters[i]) != english.getDouble_mapping().end())
                        {
                            DoubleMap doubleMap(letters, i, bracket_count);
                            text += doubleMap.getCharFromDoubleMap();
                            bracket_count = doubleMap.getBracket_count();
                            //i += 1;
                        }
                        else if(letters[i] == capital_sign && i+1 <length && letters[i+1] == capital_sign)
                        {
                            text += capital_sign + capital_sign;
                            i += 1;
                        }
                        else if (letters[i] == capital_sign)
                        {
                            capital = true;
                        }
                        else
                        {
                            text += getText(dd, letters, i, &capital);

                        }
                        num = false;
                    }
                }
                i += 1;
            }
            text += " ";
            return text;
        }

};

#endif // brailleToEnglish_H

