#include "mathbelt.h"

std::map<double, std::map<double, int>> modules = { {1, {{1000, 13}, {1500, 14}, {3000, 15}}},
                                                 {1.5,{{1000, 10}, {1500, 11}, {3000, 12}}},
                                                 {2, {{1000, 10}, {1500, 11}, {3000, 12}}},
                                                 {3, {{1000, 12}, {1500, 14}, {3000, 16}}},
                                                 {4, {{1000, 16}, {1500, 18}, {3000, 20}}},
                                                 {5, {{1000, 16}, {1500, 18}, {3000, 20}}},
                                                 {7, {{1000, 22}, {1500, 24}, {3000, 26}}}};

mathbelt::mathbelt()
{

}

double mathbelt::returnF_0(double x) {
    if (x == 1) {
        return 2.5;
    }
    else if (x == 1.5) {
        return 3.5;
    }
    else if (x == 2) {
        return 5.0;
    }
    else if (x == 3) {
        return 9.0;
    }
    else if (x == 4) {
        return 25.0;
    }
    else if (x == 5) {
        return 30.0;
    }
    else if (x == 7) {
        return 32.0;
    }
    else {
        return 0.0;
    }
}

double mathbelt::returnQ(double x)
{
    if (x == 1) {
        return 0.0002;
    }
    else if (x == 1.5) {
        return 0.00025;
    }
    else if (x == 2) {
        return 0.0003;
    }
    else if (x == 3) {
        return 0.0004;
    }
    else if (x == 4) {
        return 0.0006;
    }
    else if (x == 5) {
        return 0.0007;
    }
    else if (x == 7) {
        return 0.0008;
    }
    else {
        return 0.0;
    }
}

double mathbelt::returnb(double x)
{
    if (x < 8) {
        return 0.7;
    }
    else if (x >= 8 && x < 16) {
        return 0.85;
    }
    else if (x >= 16 && x < 25) {
        return 0.95;
    }
    else if (x == 25) {
        return 1;
    }
    else if (x > 25 && x <= 40) {
        return 1.1;
    }
    else if (x > 40 && x <= 65) {
        return 1.15;
    }
    else if (x > 65 && x <= 100) {
        return 1.1;
    }
    else {
        return 1.15;
    }
}

double mathbelt::returnF_y(double x)
{
    if (x == 2) {
        return 1.0;
    }
    else if (x == 3) {
        return 1.5;
    }
    else if (x == 4) {
        return 4.0;
    }
    else if (x == 5) {
        return 5.0;
    }
    else if (x == 7) {
        return 6.0;
    }
    else {
        return 0.0;
    }
}

double mathbelt::returnT(double m)
{
    if (m == 1 || m == 1.5) {
        return 0.4;
    } else if (m == 2 || m == 3) {
        return 0.6;
    }
    return 0.8;
}

double mathbelt::returnLymbda(double m)
{
    if (m == 1) {
        return 0.0007;
    } else if (m == 1.5) {
        return 0.0008;
    } else if (m == 2) {
        return 0.0009;
    } else if (m == 3) {
        return 0.0014;
    } else if (m == 4) {
        return 0.0006;
    } else if (m == 5) {
        return 0.0008;
    }
    return 0.0011;
}

int mathbelt::returnZ(double m, double n)
{
    double i = 1, j = 1000;

    if (n > 1000 && n < 1501) {
        j = 1500;
    } else if (n > 1500) {
        j = 3000;
    }

    i = mathbelt::returnM(m);

    std::map<double, int> temp = modules[i];
    return temp[j];
}

double mathbelt::returnM(double m)
{
    if (m < 1.25) {
        return 1;
    } else if (m < 1.75) {
        return 1.5;
    } else if (m < 2.5) {
        return 2;
    } else if (m < 3.5) {
        return 3;
    } else if (m < 4.5) {
        return 4;
    } else if (m < 5.5) {
        return 5;
    } else {
        return 7;
    }

}

double mathbelt::returnStep(double m)
{
    if (m == 1) {
        return 3.1;
    } else if (m == 1.5) {
        return 4.71;
    } else if (m == 2) {
        return 6.28;
    } else if (m == 3) {
        return 9.42;
    } else if (m == 4) {
        return 12.57;
    } else if (m == 5) {
        return 15.71;
    }
    return 21.99;

}

double mathbelt::floorL(double x) {
    double series[] = {45, 48, 50, 53.5, 56, 60, 63, 67, 71,
                       75, 80, 85, 90, 100, 105, 112, 115, 125,
                       130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 235};
    int n = sizeof(series) / sizeof(series[0]);
    if (x <= series[0]) {
    return series[0];
    }
    if (x >= series[n - 1]) {
    return series[n - 1];
    }
    int low = 0;
    int high = n - 1;
    int mid;
    while (low < high) {
    mid = (low + high) / 2;
    if (series[mid] == x) {
      return series[mid];
    }
    if (series[mid] < x) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
    }
    if (abs(series[low] - x) < abs(series[high] - x)) {
    return series[low];
    }
    else {
    return series[high];
    }
}

double mathbelt::floorB(double x)
{
     double values[] = {5, 8, 10, 12.5, 16, 20, 25, 32, 40, 50, 63, 80, 100, 125, 160, 200};
     double min_diff = std::abs(x - values[0]);
     int index = 0;
     for (int i = 1; i < 16; i++) {
       double diff = std::abs(x - values[i]);
       if (diff < min_diff) {
         min_diff = diff;
         index = i;
       }
     }
     return values[index];
}

