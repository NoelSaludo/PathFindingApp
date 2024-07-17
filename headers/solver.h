#include <vector>
#include <algorithm>

#ifndef SOLVER_H_
#define SOLVER_H_
struct dnp{
    std::vector<int> previousList;
};

std::vector<int> Solve(dnp data, int end);
#endif