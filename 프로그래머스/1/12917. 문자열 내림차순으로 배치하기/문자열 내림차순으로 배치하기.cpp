#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(char one, char two) {
    return one > two;   
}

string solution(string s) {
    vector<char> arr;
    
    for (int i = 0; i < s.size(); i++) {
        arr.push_back(s[i]);
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    return string(arr.begin(), arr.end());
}