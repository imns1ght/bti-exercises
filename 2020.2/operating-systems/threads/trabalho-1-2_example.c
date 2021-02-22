#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define PI acos(-1)

double f2(double x) {
    return sin(2 * x) + cos(5 * x);
    // return 5;
}

double f(double x) {
    return 5;
}

int main(int argc, char* argv[]) {
    double a = 0;
    double b = 2 * PI;
    // double b = 10;
    double n = 200;  // numero de trapezios
    double h = (b - a) / n;
    double area_total = (f2(a) + f2(b)) / 2;

    for (double i = 1; i < n; i++) {
        double x_i = (a + i) * h;
        area_total += f2(x_i);
    }
    area_total = h * area_total;

    printf("area_total %e \n", area_total);

    return 0;
}