#ifndef double_map_H
#define double_map_H
#include<iostream>
#include<unordered_map>
#include "commonSymbols.h"

using namespace std;

class DoubleMap
{
    private:
        CommonSymbols commonSymbols;
        string* letters;
        int position, bracket_count;

    public:
        DoubleMap(string* letters, int position, int bracket_count)
        {
            this.letters = letters;
            this.position = position;
            this.bracket_count = bracket_count;
            cout<<"double map"<<endl;
        }

        string getCharFromDoubleMap()
        {
            string char = letters[position];
            int length = sizeof(letters) / sizeof(*letters);

            if(char == "011001")
            {
                (position + 1 == length) ? return "?" :  return "\“";
            }

             else if(char == "001011")
             {
                if (position + 1 == length ||
                    commonSymbol.getPunctuation().find(letters[position]) != commonSymbol.getPunctuation().end())
                    {
                        return "\"";
                    }
                return "্";
             }

             else if(char == "011011")
             {
                if (bracket_count == 1)
                {
                    bracket_count = 0;
                    return ")";
                }
                bracket_count += 1;
                return "(" ;
             }

             else if(char == "010000")
             {
                 (position + 1 == length || length > 3) ? returnn "," : ".";
             }



        }

        int getBracket_count()
        {
            return bracket_count;
        }
};
#endif // double_map_Hs
