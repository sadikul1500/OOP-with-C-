#ifndef BanglaTextProcess_H
#define BanglaTextProcess_H
#include<iostream>
#include<unordered_map>
#include "doubleMap.h"
#include "bangla.h"

using namespace std;

class BanglaTextProcess
{
    private:
        Bangla bangla;
        string numeral_sign = "001111";

    public:
        BanglaTextProcess()
        {
            cout<<"Bangla text process"<<endl;
        }


        string getText(unordered_map<string, string> dd, string letters, int i)
        {
            for (pair<string, string> element : dd)
            {
                if(letters[i] == element.first)
                {
                    return element.second;
                }
            }
        }


        string checkJointLetter(unordered_map<string, string> dd, string letters, int *i, int length)
        {
            if(letters[*i] == "000100" && *i+2 < length)
            {
                *i += 2;
                return dd[letters[*i+1]] + bangla.getHosonto() + dd[letters[*i+2]];
            }

            else if(letters[*i] == "000101" && *i+4 < length)
            {
                string joint = dd[letters[*i+1]] + dd[letters[*i+2]] + dd[letters[*i+3]] + dd[letters[*i+4]];
                if(bangla.getFourLetters().find(joint) != bangla.getFourLetters().end())
                {
                    for (pair<string, string> element : bangla.getFourLetters())
                    {
                        if(joint == element.first)
                        {
                            i += 4;
                            return dd[letters[*i+1]] + bangla.getHosonto() + dd[letters[*i+2]] +
                            bangla.getHosonto() + dd[letters[*i+3]] + bangla.getHosonto() + dd[letters[*i+4]];

                        }
                    }
                }
            }

            else if(letters[*i] == "000101" && *i+3 < length)
            {
                *i += 3;
                return dd[letters[*i + 1]] + bangla.getHosonto() + dd[letters[*i + 2]] + bangla.getHosonto() +
                       dd[letters[*i + 3]];

            }

            return "";

        }


        string numberProcess(string* letters, int *bracket_count, int *i, int* length)
        {
            if(bangla.getOperator().find(letters[*i]) != bangla.getOperator().end())
            {
                 if(letters[*i] == "011011" and *bracket_count == 0)
                 {
                     *bracket_count += 1;
                     return "(";
                 }

                 else if(letters[*i] == '011011' and *bracket_count == 1)
                 {
                     *bracket_count = 0;
                     return ")";
                 }

                 else
                 {
                     return bangla.getOperator()[letters[*i]];
                 }
            }

            else if(bangla.getNumbers().find[letters[*i] != bangla.getNumbers().end())
            {
                return bangla.getNumber([letters[*i]);
            }

            else if((bangla.getOperator().find([letters[*i]) == bangla.getOperator().end() ||
                    bangla.getNumbers().find([letters[*i]) == bangla.getNumbers().end()) && *i+1 < *length)
            {
                if(letters[*i] == "001010" && letters[i+1] == "001010")
                {
                    *i++;
                    return bangla.getOperator()[letters[*i] + letters[*i+1]];
                }

                else if(letters[*i] == "000011" && letters[i+1] == "011011")
                {
                    *i++;
                    return bangla.getOperator()[letters[*i] + letters[*i+1]];
                }

                else if(letters[*i] == "000001" && letters[i+1] == "011011")
                {
                    *i++;
                    return "[";
                }

                else if(letters[*i] == "011011" && letters[i+1] == "000001")
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


        string textProcess(string* letters)
        {
            int length = sizeof(letters) / sizeof(*letters);
            bool num = false;
            int i = 0, bracket_count = 0;
            string text = "";
            unordered_map<string, string> hos = bangla.getHosonto();
            unordered_map<string, string> dd = bangla.getBanglaDictionary();

            while(i < length)
            {
                if(num)
                {
                    text += numberProcess(letters, &bracket_count, &i, &length);
                }

                else
                {
                    if(i == 0 && letters[i] == numeral_sign)
                    {
                        cout<<"numeral sign found in bangla"<<endl;
                        num = true;
                    }

                    else if(letters[i] == numeral_sign && bangla.getPunctuation().find(letters[i-1]) != bangla.getPunctuation().end()
                            || bangla.getDot().find(letters[i]) != bangla.getDot().end())
                    {
                        cout<<"numeral sign found"<<endl;
                        num = true;
                    }

                    else
                    {
                        if(i + 1 < length && bangla.getTwelveDots().find(letters[i] + letters[i + 1]) != != bangla.getTwelveDots().end())
                        {
                            text += bangla.getTwelveDots().[letters[i] + letters[i + 1]];
                        }

                        else if(bangla.getDouble_mapping().find(letters[i]) != bangla.getDouble_mapping().end())
                        {
                            DoubleMap doubleMap(letters, i, bracket_count);
                            text += doubleMap.getCharFromDoubleMap();
                            bracket_count = doubleMap.getBracket_count();
                            i += 1;
                        }

                        string txt = checkJointLetter(dd, letters, &i, length);
                        text += txt;

                        if(!txt)
                        {
                            text += getText(dd, letters, i);
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
#endif // BanglaTextProcess
