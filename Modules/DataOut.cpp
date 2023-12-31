#include "DataOut.h"


dataOut::dataOut(const std::vector<body>& bodies, const double& step, const std::string& method) {
    _n = bodies.size();
    _step = step;
    _tPrevious = 0;
    for(size_t i = 0; i < _n; i++) {
        _dataFiles.resize(_n + 1);
        _dataFiles[i].open("Data_output/" + bodies[i].name + "_" + method + ".txt");
    }
    _dataFiles[_n].open("Data_output/total_energy_" + method + ".txt");
}

void dataOut::forceOut(const std::vector<body>& bodies, const double& t) {
    for (size_t i = 0; i < _n; i++) {
        Writer(_dataFiles[i], t, bodies[i].coordinates);
    }
    Writer(_dataFiles[_n], t, std::vector{getTotalEnergy(bodies)});

    _tPrevious = t;
}

void dataOut::Out(const std::vector<body>& bodies, const double& t) {
    if (t - _tPrevious >= _step) {
        forceOut(bodies, t);
    }
}

void dataOut::Writer(std::ofstream& out, const double& t, const std::vector<double>& data) {
    out << t << " ";
    for (const auto i : data) {
        out << i << " ";
    }
    out << std::endl;
}

void dataOut::close() {
    for (auto & _dataFile : _dataFiles) {
        _dataFile.close();
    }
}