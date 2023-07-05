#include <string>
#include <vector>
#include <stack>

using namespace std;

// 조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.
// 조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
// 조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.

int getNumberOfOne(string number);
bool hasSameOneCount(int number, int numberOfOne);
string getBit(int number);

int solution(int n) {
    int answer = 0;
    int numberOfOne = getNumberOfOne(getBit(n));
    
    for (int i = n + 1; ; i++) {
        if (hasSameOneCount(i, numberOfOne)) {
            return i;
        }
    }
    
    return answer;
}

int getNumberOfOne(string number) {
    int count = 0;
    
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '1') {
            count ++;
        }
    }
    
    return count;
}

bool hasSameOneCount(int number, int numberOfOne) {
    string bits = getBit(number);
    
    return getNumberOfOne(bits) == numberOfOne;
}

string getBit(int number) {
    stack<string> bits;
    
    while (number != 0) {
        if (number % 2 == 0) {
            bits.push("0");
        } else {
            bits.push("1");
        }
        
        number /= 2;
    }
    
    string str;
    
    while(!bits.empty()) {
        str += bits.top();
        bits.pop();
    }
    
    return str;
}