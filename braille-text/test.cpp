////#include<iostream>
////#include "commonSymbols.h"
////
////using namespace std;
////
////int main()
////{
////    CommonSymbols cs;
////    cout<<cs.getPunctuation()["000001011011"]<<endl;
////}
//#include<iostream>
//#include<iterator>
//
//using namespace std;
//
//void print(string* arr)
//{
//    for (int i = 0; i < 4; i++)
//      cout << arr[i] << endl;
//}
//
//int main() {
//   string animals[] = {"Elephant", "Lion", "Deer", "Tiger", "Monkey"}; //The
//   //string type array
//   cout<<sizeof(animals) / sizeof(*animals)<<endl;
//   print(animals);
//
//}


// CPP code to check if a key is present
// in an unordered_map
#include <bits/stdc++.h>
#include<boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

// Function to check if the key is present or not
string check_key(unordered_map<string, string> m, string key)
{
	// Key is not present
	if (m.find(key) != m.end())
		return "Present";

	return "Not Present";
}

// Driver
int main()
{
    path p("F:/braille");
    for (auto i = directory_iterator(p); i != directory_iterator(); i++)
    {
        if (!is_directory(i->path())) //we eliminate directories
        {
            cout << i->path().filename().string() << endl;
        }
        else
            continue;
    }
}


#include <boost/filesystem.hpp>
using namespace std;
//using namespace boost::filesystem;

int main()
{
    path p("D:/AnyFolder");
    for (auto i = directory_iterator(p); i != directory_iterator(); i++)
    {
        if (!is_directory(i->path())) //we eliminate directories
        {
            cout << i->path().filename().string() << endl;
        }
        else
            continue;
    }
}

