#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

string line;
bool minusFlag = false;

vector<string> split(string line) {
    vector<string> tokens;
    string token;
    long long pos = 0;
    
    while((pos = line.find("-")) != string::npos) {
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
        tokens.push_back(token);
    }

    tokens.push_back(line);

    return tokens;
}

int splitPlus(string input) {
    string token;
    int sum = 0;
    long long pos = 0;

    while((pos = input.find("+")) != string::npos) {
        token = input.substr(0, pos);
        input.erase(0, pos + 1);
        sum += stoi(token);
    }

    sum += stoi(input);

    return sum;
}

int main() {
    cin >> line;

    vector<string> numbers = split(line);

    vector<int> newNumbers;
    int curNum = 0;

    for (string each : numbers) {
        int sum = 0;

        if (each.find("+") != string::npos) {
            sum += splitPlus(each);
        } else {
            sum += stoi(each);
        }

        newNumbers.push_back(sum);
    }

    int answer = 0;

    for(int i = 0; i < newNumbers.size(); i++) {
        if (i == 0) {
            answer += newNumbers[i];
        } else {
            answer -= newNumbers[i];
        }
    }

    cout << answer;

    return 0;
}