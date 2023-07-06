#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> split(string input, string delimeter) {
    vector<int> tokens;
    long long pos = 0;
    string token = "";
    
    while((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        int number = atoi(token.c_str());
        tokens.push_back(number);
        input.erase(0, pos + delimeter.length());
    }
    
    tokens.push_back(stoi(input));
    return tokens;
}
    

string solution(string s) {
    vector<int> numbers = split(s, " ");
    
    sort(numbers.begin(), numbers.end());
    
    string answer = "";
    
    answer += to_string(numbers.front());
    answer += " ";
    answer += to_string(numbers.back());
    
    return answer;
}