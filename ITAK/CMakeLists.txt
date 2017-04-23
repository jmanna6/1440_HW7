cmake_minimum_required(VERSION 3.7)
project(ITAK)

set(CMAKE_CXX_STANDARD 11)

set(UTILS_FILES
        Utils/Utils.cpp
        Utils/Utils.h
        Utils/Dictionary.h
        Utils/KeyValue.h
        )

set(SOURCE_FILES
        Analyzer.cpp
        Analyzer.h
        Configuration.cpp
        Configuration.h
        DenialOfServiceAnalyzer.cpp
        DenialOfServiceAnalyzer.h
        PortScanAnalyzer.cpp
        PortScanAnalyzer.h
        ResultSet.cpp
        ResultSet.h
        )

add_executable(ITAK main.cpp ${SOURCE_FILES} ${UTILS_FILES})

set(TESTING_FILES

        )
add_executable(testing Testing/testingMain.cpp ${SOURCE_FILES} ${TESTING_FILES} ${UTILS_FILES})