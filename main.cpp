#include <iostream>
#include <vector>
#include <string>

#include "Modules/Compute.h"


using namespace std;


int main() {
    // The problem initialising
    ifstream problemFile("../Problems/SP-45.json");
    Problem problem(problemFile);

    vector<body> bodies = problem.bodies;
    double t = problem.TIME_START;

    system("chcp 65001"); // Fuck Windows

    dataOut DataOut(bodies, problem.DATA_OUT_TIME_STEP, problem.METHOD);
    DataOut.forceOut(bodies, t);


    if (problem.METHOD == "Eul") {
        comp(ByEuler, bodies, t, problem.TIME_END, problem, DataOut);
    } else if (problem.METHOD == "PC") {
        comp(ByPredictorCorrector, bodies, t, problem.TIME_END, problem, DataOut);
    } else if (problem.METHOD == "LF") {
        compByLF(bodies, t, problem.TIME_END, problem, DataOut);
    } else if (problem.METHOD == "RK4") {
        comp(ByRK4, bodies, t, problem.TIME_END, problem, DataOut);
    }


    DataOut.close();
    return 0;
}
