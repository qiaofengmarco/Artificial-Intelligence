#ifndef MY_HEADERS_HPP
#define MY_HEADERS_HPP

#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <ctime>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <iterator>
#include <functional>
#include <map>
#include <hash_map>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

int reverse_act(int act)
{
    if (act == UP)
        return DOWN;
    else if (act == DOWN)
        return UP;
    else if (act == RIGHT)
        return LEFT;
    return RIGHT;
}

#endif