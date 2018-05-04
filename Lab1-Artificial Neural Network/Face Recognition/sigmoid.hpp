#ifndef MY_SIGMOID_HPP
#define MY_SIGMOID_HPP

#include "pack.h"

double __sigmoid(double x) {
    double t = exp(x);
    return t / (1.0 + t);
}

double __delta_sigmoid(double x) {
    double t = __sigmoid(x);
    return t * (1.0 - t);
}

#endif