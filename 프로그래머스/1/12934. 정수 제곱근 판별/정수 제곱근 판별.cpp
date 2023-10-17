#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(long long n) {
    if ((sqrt(n) - (int)(sqrt(n)) == 0)) {
        return pow(sqrt(n) + 1, 2);
    } 
    
    return -1;
}