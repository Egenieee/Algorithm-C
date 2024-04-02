#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<int> adj[101];

int breakWire(int one, int two) {
    int visitedOne[101] = {0};
    int visitedTwo[101] = {0};
    
    int cntOne = 1;
    int cntTwo = 1;
    
    queue<int> myQ;
    visitedOne[one] = 1;
    myQ.push(one);
    
    while(!myQ.empty()) {
        int curNode = myQ.front();
        myQ.pop();
        
        for (int next = 0; next < adj[curNode].size(); next++) {
            int nextNode = adj[curNode][next];
            
            // 이미 방문한 곳이라면 pass
            if (visitedOne[nextNode] || nextNode == two) continue;
            
            cntOne++;
            visitedOne[nextNode] = 1;
            myQ.push(nextNode);
        } 
    }
    
    visitedTwo[two] = 1;
    myQ.push(two);
    
    while(!myQ.empty()) {
        int curNode = myQ.front();
        myQ.pop();
        
        for (int next = 0; next < adj[curNode].size(); next++) {
            int nextNode = adj[curNode][next];
            
            // 이미 방문한 곳이라면 pass
            if (visitedTwo[nextNode] || nextNode == one) continue;
            
            cntTwo++;
            visitedTwo[nextNode] = 1;
            myQ.push(nextNode);
        }
    }
    
    return abs(cntOne - cntTwo);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999;
    
    // create network 
    for (vector<int> wire : wires) {
        int from = wire[0];
        int to = wire[1];
        
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    // 연결 하나씩 끊고, 만들 수 있는 네트워크 개수 구하기
    for (vector<int> wire : wires) {
        int result = breakWire(wire[0], wire[1]);
        
        if (result != -1) {
            answer = min(answer, result);
        }
    }
    
    return answer;
}