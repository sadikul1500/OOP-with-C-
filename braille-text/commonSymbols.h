#ifndef commonSymbols_H
#define commonSymbols_H
#include <unordered_map>
#include<iostream>


using namespace std;

class CommonSymbols
{
    private:
        unordered_map<string, string>
        punctuation = {
        {"001001", "-"}, {"010011", "|"}, {"000001011001", "\‘"}, {"001011001000", "\’"},
        {"000001011011", "["}, {"011000", ";"}, {"011010", "!"}, {"000011011011", "="},
        {"001010001010", "*"}, {"011011001000", "]"}, {"010010", ","}, {"001011", "\""},
        {"011001", "\“"}, {"011011", "("}, {"010000", ","}, {"001100", "/"}, {"000010", "$"}
        };

        unordered_map<string, string>
        Operator = {
        {"001001", "-"}, {"000011011011", "="}, {"001010001010", "*"}, {"001110", ">"}, {"110001", "<"},
        {"010000", "."}, {"001100", "/"}, {"011011", "("}, {"001101", "+"}, {"100101", "%"}, {"000110", "^"},
        };

        unordered_map<string, string>
        hosonto = {
        {"011001", "?"}, {"011011", ")"}, {"001011", "্"}
        };

        unordered_map<string, string>
        dot = {
        {"010000", "."}
        };

        unordered_map<string, string>
        twelveDots = {
        {"000011011011", "="}, {"001010001010", "*"}, {"000001011011", "["}, {"000001011001", "\‘"}, {"001011001000", "\’"},
        {"011011001000", "]"}, {"000010111010", "ঋ"}, {"010000011110", "ৎ"}
        };

        unordered_map<string, string>
        double_mapping = {
        {"011001", "?"}, {"001011", "\""}, {"011011", "("}, {"010000", ","}
        };


    public:
        CommonSymbols()
        {
            cout<<"common symbols"<<endl;
        }

        unordered_map<string, string> getHosonto()
        {
            return hosonto;
        }

        unordered_map<string, string> getOperator()
        {
            return Operator;
        }

        unordered_map<string, string> getTwelveDots()
        {
            return twelveDots;
        }

        unordered_map<string, string> getDouble_mapping()
        {
            return double_mapping;
        }

        unordered_map<string, string> getPunctuation()
        {
            return punctuation;
        }

        unordered_map<string, string> getDot()
        {
            return dot;
        }
        //void print();
    //cout<<dict[7]<<endl;

};
#endif // commonSymbols_H

//int main()
//{
//    CommonSymbols dd;
//    cout<<dd.getTwelveDots()["011011001000"]<<endl;
//}
