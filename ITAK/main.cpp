#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "DenialOfServiceAnalyzer.h"
#include "Utils/Utils.h"

int main()
{

    std::ifstream fin("SampleData.csv");
    Dictionary<std::string, Dictionary<std::string, unsigned int>> test;
//    Dictionary<std::string, std::string> test;
//    std::string elements[4];
//
//    std::string line;
//
//    if (fin.is_open())
//    {
//        while (std::getline(fin, line))
//        {
//            if (split(line, ',', elements, 4))
//            {
//                test.add(elements[0], "0");
//            }
//        }
//    }
//
//    fin.close();
//
//    test.print();

    DenialOfServiceAnalyzer dsa;

    test = dsa.input(fin);








    return 0;
}