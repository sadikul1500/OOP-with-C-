//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    cout << "Hello world!" << endl;
//    return 0;
//}
#include<iostream>
#include "commonSymbols.h"

using namespace std;

int main()
{
    CommonSymbols cs;
    cout<<cs.getPunctuation()["000001011011"]<<endl;
}
