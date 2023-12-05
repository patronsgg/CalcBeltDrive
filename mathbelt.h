#ifndef MATHBELT_H
#define MATHBELT_H

#include <map>
#include <numeric>

class mathbelt
{
public:
    /*std::map<double, std::map<double, int>> modules = { {1, {{1000, 13}, {1500, 14}, {3000, 15}}},
                                                     {1.5,{{1000, 10}, {1500, 11}, {3000, 12}}},
                                                     {2, {{1000, 10}, {1500, 11}, {3000, 12}}},
                                                     {3, {{1000, 12}, {1500, 14}, {3000, 16}}},
                                                     {4, {{1000, 16}, {1500, 18}, {3000, 20}}},
                                                     {5, {{1000, 16}, {1500, 18}, {3000, 20}}},
                                                     {7, {{1000, 22}, {1500, 24}, {3000, 26}}}};*/
    mathbelt();
    static double returnM(double m);
    static int returnN(int n);
    static double returnStep(double m);
    static double floorL(double l);
    static double floorB(double x);
    static double returnF_0(double x);
    static double returnQ(double x);
    static double returnb(double x);
    static double returnF_y(double x);
    static double returnT(double m);
    static double returnLymbda(double m);
    static int returnZ(double m, double n);
};

#endif // MATHBELT_H
