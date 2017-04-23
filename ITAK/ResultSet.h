//
// Created by Jake on 4/22/2017.
//

#ifndef ITAK_RESULTSET_H
#define ITAK_RESULTSET_H

#include <string>
#include <vector>

#include "Utils/Dictionary.h"

class ResultSet
{
public:
    // ResultSet(AnalyzerType at);

    std::vector<std::string> findLikelyAttackers();
    std::vector<std::string> findPossibleAttackers();
    std::vector<std::string> findAttackPeriod();
    std::vector<std::string> findTimeframe();
    std::vector<std::string> findPortCount();

    void print(std::ostream& out);

private:
    Dictionary<std::string, std::vector<std::string>> m_Results;

    enum AnalyzerType {DenialOfService, PortScan};
};


#endif //ITAK_RESULTSET_H
