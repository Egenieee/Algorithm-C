#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

int numbers[12];
int operators[4];

int inputN;

long long maxResult;
long long minResult;

void permutate(int count, long long result , int add, int sub, int mul, int div) {
    // 모든 연산자 뽑혔으면 결과 계산하기
    if (count == inputN) {
        maxResult = max(result, maxResult);
        minResult = min(result, minResult);

        return;
    }

    // 덧셈 가능
    if (add > 0) {
        //cout << count << "번 째 연산자 뽑음. +\n";
        permutate(count + 1, result + numbers[count], add - 1, sub, mul, div);
    } 

    // 뺄셈 가능
    if (sub > 0) { 
        //cout << count << "번 째 연산자 뽑음. -\n";
        permutate(count + 1, result - numbers[count], add, sub - 1, mul, div);
    } 

    // 곱셈 가능
    if (mul > 0) {
        //cout << count << "번 째 연산자 뽑음. *\n";
        permutate(count + 1, result * numbers[count], add, sub, mul - 1, div);
    } 

    // 나눗셈 가능
    if (div > 0) {
        //cout << count << "번 째 연산자 뽑음. /\n";
        permutate(count + 1, result / numbers[count], add, sub, mul, div - 1);
    }
}

int main(void) {
    cin >> inputN;

    for (int i = 0; i < inputN; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    maxResult = INT32_MIN;
    minResult = INT32_MAX;

    permutate(1, (long long) numbers[0], operators[ADD], operators[SUB], operators[MUL], operators[DIV]);

    cout << maxResult << "\n";
    cout << minResult << "\n";

    return 0;
}