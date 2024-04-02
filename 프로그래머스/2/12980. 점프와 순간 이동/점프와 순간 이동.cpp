#include <iostream>
using namespace std;

int solution(int n)
{
    int remain;
    int cnt = 0;
    
    while(n != 0) {
        remain = n % 2;
        n /= 2;
        
        if (remain == 1) {
            cnt++;
        }
    }
    
    return cnt;
}