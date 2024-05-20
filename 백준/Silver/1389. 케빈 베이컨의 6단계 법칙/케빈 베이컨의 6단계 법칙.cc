#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int inputN;
int inputM;
int minKevin;
int answer;

vector<int> adj[101];
int dist[101];

void init() {
    for (int i = 0; i < 101; i++) {
        dist[i] = -1;
    }
}

void dijkstra(int startNode) {
    queue<int> myQ;

    init();
    myQ.push(startNode);
    dist[startNode] = 0;

    while(!myQ.empty()) {
        int curNode = myQ.front();
        myQ.pop();

        for (int next = 0; next < adj[curNode].size(); next++) {
            int nextNode = adj[curNode][next];

            if (dist[nextNode] >= 0) continue;

            myQ.push(nextNode);
            dist[nextNode] = dist[curNode] + 1;
        }
    }

    int sum = 0;

    for (int i = 1; i <= inputN; i++) {
        sum += dist[i];
    }

    if (sum < minKevin) {
        minKevin = sum;
        answer = startNode;
    }
}

int main() {
    cin >> inputN >> inputM;

    minKevin = 999999;

    for (int i = 0; i < inputM; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    // 1번부터 N번까지 다익스트라 돌려서 합 구하기
    for (int i = 1; i <= inputN; i++) {
        dijkstra(i);
    }

    cout << answer;

    return 0;
}