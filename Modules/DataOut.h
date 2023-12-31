#pragma once
#ifndef DATAOUT_H
#define DATAOUT_H

#include <vector>
#include <fstream>

#include "Body.h"


class dataOut {
private:
    std::vector<std::ofstream> _dataFiles;
    double _step;
    size_t _n;
    double _tPrevious;
    static void Writer(std::ofstream& out, const double& t, const std::vector<double>& data);
public:
    dataOut(const std::vector<body>& bodies, const double& step, const std::string& method);
    void forceOut(const std::vector<body>& bodies, const double& t);
    void Out(const std::vector<body>& bodies, const double& t);
    void close();
};

#endif //DATAOUT_H
