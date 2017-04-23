//
// Created by Jake on 4/22/2017.
//

#ifndef ITAK_ANALYZER_H
#define ITAK_ANALYZER_H

#include <fstream>

#include "ResultSet.h"

class Analyzer
{
public:
    ResultSet run(std::ifstream& fin);

private:

};


#endif //ITAK_ANALYZER_H
