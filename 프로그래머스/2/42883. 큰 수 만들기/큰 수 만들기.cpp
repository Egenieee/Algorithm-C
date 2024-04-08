#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int maxIdx = -1;
    
    for (int i = 0; i < number.size() - k; i++) {
        char maxNum = '0';
        for (int j = maxIdx + 1; j <= i + k; j++) {
            if (number[j]  > maxNum) {
                maxNum = number[j];
                maxIdx = j;
            }
        }    
        
        answer += maxNum;
    }
    
    return answer;
}