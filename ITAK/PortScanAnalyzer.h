//
// Created by Jake on 4/22/2017.
//

#ifndef ITAK_PORTSCANANALYZER_H
#define ITAK_PORTSCANANALYZER_H

#include "Analyzer.h"

class PortScanAnalyzer : public Analyzer
{
public:
    PortScanAnalyzer();

    ResultSet run(std::ifstream& fin);
private:

};


#endif //ITAK_PORTSCANANALYZER_H
