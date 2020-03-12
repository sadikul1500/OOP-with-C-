#include<iostream>
#include<fstream>
#include<filesystem>
#include "brailleToText.h"
#include "brailleToEnglish.h"
#include "brailleToBangla.h"
//#include "fileManager.h"
#include "postTextProcess.h"

using namespace std;

int main()
{

    string path = "/path/to/brailleDoc";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;

}
