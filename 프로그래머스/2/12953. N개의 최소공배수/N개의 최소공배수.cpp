#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(true) {
        int remain = a % b;
        
        if (remain == 0 ) return b;
        
        a = b;
        b = remain;
    }
}

int solution(vector<int> arr) {
    int answer = 0;
    
    int temp = arr[0] * arr[1] / gcd(arr[0], arr[1]);
    
    for (int i = 2; i < arr.size(); i++) {
        temp = temp * arr[i] / gcd(temp, arr[i]);
    }
    
    return temp;
}