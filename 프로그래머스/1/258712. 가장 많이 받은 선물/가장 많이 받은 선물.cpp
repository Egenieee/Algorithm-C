#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Member {
    int in;
    int out;
    int score = 0;
    int receive;
    string name;
};

int inputN;
int board[51][51];
unordered_map<string, int> friendsMap;

Member members[51];

vector<string> split(string input, string delimeter) {
    string token;
    long long pos = 0;
    vector<string> tokens;
    
    while((pos = input.find(delimeter)) != string::npos) {
        string token = input.substr(0, pos);
        tokens.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    
    tokens.push_back(input);
    
    return tokens;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    inputN = friends.size();
    
    int cnt = 0;
    
    for (string one : friends) {
        friendsMap[one] = cnt;
        cnt++;
    }
    
    for (string gift : gifts) {
        vector<string> each = split(gift, " ");
        
        string from = each[0];
        string to = each[1];
        int fromIdx = friendsMap[from];
        int toIdx = friendsMap[to];
        
        board[fromIdx][toIdx]++;
        members[fromIdx].out++;
        members[toIdx].in++;
        members[fromIdx].name = from;
        members[toIdx].name = to;
    }
    
    // 선물 지수 구하기
    for (int i = 0; i < inputN; i++) {
        members[i].score = members[i].out - members[i].in;
    }
    
    for (int from = 0; from < inputN; from++) {
        for (int to = 0; to < inputN; to++) {
            if (from == to || board[from][to] == -1 || board[to][from] == -1) continue;
            
            //cout << "from : " << members[from].name << " to : " << members[to].name << "\n";
            
            if(board[from][to] > board[to][from]) {
                members[from].receive++;
                //cout << members[from].name << "이 선물 받습니다.\n";
            } else if (board[from][to] < board[to][from]) {
                members[to].receive++;
                //cout << members[to].name << "이 선물 받습니다.\n";
            } else if (board[from][to] == board[to][from]) {
                // 주고 받은 선물 개수가 같은 경우, 선물 지수를 비교한다.
                //cout << "주고 받은 선물 개수가 같아서 선물 지수 비교합니다.\n";
                if (members[from].score < members[to].score) {
                    members[to].receive++;
                    //cout << members[to].name << "번이 선물 받습니다.\n";
                } else if (members[from].score > members[to].score) {
                    members[from].receive++;
                    //cout << members[from].name << "번이 선물 받습니다.\n";
                }
            }
            
            board[from][to] = -1;
            board[to][from] = -1;
            cout << "\n";
        }
    }
    
    int maxCnt = -1;
    
    for (int i = 0; i < inputN; i++) {
        maxCnt = max(members[i].receive, maxCnt);
    }
    
    return maxCnt;
}