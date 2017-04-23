//
// Created by Jake on 4/22/2017.
//

#include "DenialOfServiceAnalyzer.h"
#include "Utils/Utils.h"

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer()
{
    // empty
}

Dictionary<std::string, Dictionary<std::string, unsigned int>> DenialOfServiceAnalyzer::input(std::ifstream& fin)
{
    Dictionary<std::string, Dictionary<std::string, unsigned int>> result;
    Dictionary<std::string, unsigned int> inner;
    std::string line;
    std::string elements[4];

    if (fin.is_open())
    {
        while (std::getline(fin, line))
        {
            if (split(line, ',', elements, 4))
            {
                inner.add(elements[0], 0);
                result.add(elements[1], inner);
            }
        }
    }
    fin.close();

    return result;

}
