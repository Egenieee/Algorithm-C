#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count;

void getTargetNum(vector<int> &numbers, int target, int sum, int index) {
    // 다 선택했을 경우
    // cout << "현재 index : " << index << "\n";
    // cout << "현재 sum : " << sum << "\n";
    // cout << "\n";
    
    if (index == numbers.size()) {
        if (sum == target) {
            count++;
            //cout << "현재 sum : " << sum << "\n";
        }
        return;
    }
    
    getTargetNum(numbers, target, sum + numbers[index], index + 1);
    getTargetNum(numbers, target, sum - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    count = 0;
    getTargetNum(numbers, target, 0, 0);
    
    return count;
}