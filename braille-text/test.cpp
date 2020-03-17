//////#include<iostream>
//////#include "commonSymbols.h"
//////
//////using namespace std;
//////
//////int main()
//////{
//////    CommonSymbols cs;
//////    cout<<cs.getPunctuation()["000001011011"]<<endl;
//////}
////#include<iostream>
////#include<iterator>
////
////using namespace std;
////
////void print(string* arr)
////{
////    for (int i = 0; i < 4; i++)
////      cout << arr[i] << endl;
////}
////
////int main() {
////   string animals[] = {"Elephant", "Lion", "Deer", "Tiger", "Monkey"}; //The
////   //string type array
////   cout<<sizeof(animals) / sizeof(*animals)<<endl;
////   print(animals);
////
////}
//
//
//// CPP code to check if a key is present
//// in an unordered_map
//#include <bits/stdc++.h>
////#include<boost/filesystem.hpp>
//using namespace std;
////using namespace boost::filesystem;
//
//// Function to check if the key is present or not
////string check_key(unordered_map<string, string> m, string key)
////{
////	// Key is not present
////	if (m.find(key) != m.end())
////		return "Present";
////
////	return "Not Present";
////}
//class A
//{
//public:
//    virtual void print();
//};
//
//class B
//{
//public:
//    int x =2;
//};
//
//class C: public A, public B
//{
//    public:
//    void print()
//    {
//        cout<<"overridden"<<endl;
//    }
//
//    int getX()
//    {
//        return x;
//    }
//};
//
//class D:public A
//{
//    public:
//    void print()
//    {
//        cout<<"D"<<endl;
//    }
//};
//
//vector<string> split(const string &input, const string& regx)
//{
//    regex re(regx);
//    sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
//    return {first, last};
//}
//// Driver
//int main()
//{
////    A *a;
////    C c;
////    a = &c;
////    //C(a);
////    cout<<a.getX()<<endl;
////    a->print();
//    string s = "ba n%%gl ad%%es hi%% ";
//    string p = "ytu";
//    p += "\nok";
//    cout<<p<<endl;
//    vector<string> a = split(s, " ");
//    for(int i=0; i<a.size(); i++)
//    {
//        cout<<a[i]<<endl;
//    }
//}
//
//
////#include <boost/filesystem.hpp>
////using namespace std;
////using namespace boost::filesystem;
////
////int main()
////{
////    path p("D:/AnyFolder");
////    for (auto i = directory_iterator(p); i != directory_iterator(); i++)
////    {
////        if (!is_directory(i->path())) //we eliminate directories
////        {
////            cout << i->path().filename().string() << endl;
////        }
////        else
////            continue;
////    }
////}
//
#include<iostream>
#include<unordered_map>

using namespace std;

class Map
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
        {"010000", ","}, {"001100", "/"}, {"011011", "("}, {"001101", "+"}, {"100101", "%"}, {"000110", "^"},
        };
        unordered_map<string, string> symbolToKar = {
            {"অ", ""}, {"আ", "া"},
            {"ই", "ি"}, {"ঈ", "ী"},
            {"উ", "ু"}, {"ঊ", "ূ"},
            {"এ", "ে"}, {"ঐ", "ৈ"},
            {"ও", "ো"}, {"ঔ", "ৌ"}, {"ঋ", "ৃ"}
        };
        int x = 10;

    public:
        unordered_map<string, string> getPunctuation()
        {
            return punctuation;
        }

        unordered_map<string, string> getOperator()
        {
            return Operator;
        }

        unordered_map<string, string> getSymbolToKar()
        {
            return symbolToKar;
        }

        int getX()
        {
            //(x == 10) ?
            return x ;//: return 0; //wrong
        }

};

int main()
{
    string str = "0101uytio";
    str.replace(str.find("0101"), 4, "");
    cout<<str<<endl;
    Map m;
    if(24>5 && 3>1 && 4>2 && 10<20) cout<<"hobe"<<endl;
    cout<<m.getPunctuation()["011001"]+m.getOperator()["001100"]<<endl;
    cout<<m.getOperator()["001100"]<<endl;
    //cout<<m.getX()<<endl;
    if (m.getSymbolToKar().find("এ") != m.getSymbolToKar().end() && 23>21 && 67>23) cout<<"ok"<<endl;
}
