//
// Created by Jake on 4/22/2017.
//

#ifndef ITAK_DENIALOFSERVICEANALYZER_H
#define ITAK_DENIALOFSERVICEANALYZER_H

#include "Analyzer.h"

class DenialOfServiceAnalyzer : public Analyzer
{
public:
    DenialOfServiceAnalyzer();

    ResultSet run(std::ifstream& fin);
    Dictionary<std::string, Dictionary<std::string, unsigned int>> input(std::ifstream& fin);

private:

};


#endif //ITAK_DENIALOFSERVICEANALYZER_H
