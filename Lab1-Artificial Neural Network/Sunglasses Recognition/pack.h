/*
******************************************************************
* Southeast University Artificial Intelligence Course Project
*
* Author: Qiaofeng Marco LIU
*
* Contact Info: qiaofengmarco@outlook.com
******************************************************************
*/

#ifndef MY_PACK_H
#define MY_PACK_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <fstream>
using namespace std;

#define TARGET_HIGH 1.0
#define TARGET_LOW 0.0
#define BIGRND 0x7fffffff

int my_random(int n) {
    return rand() * n / RAND_MAX;
}

#endif