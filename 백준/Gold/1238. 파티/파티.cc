#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int inputN, inputM, inputX;

vector<pair<int, int>> adj[1001];
vector<pair<int, int>> adjReverse[1001];

int dist[1001];
int distReverse[1001];

void dijkstra(int start) {
    for (int i = 0; i < 1001; i++) {
        dist[i] = 987654321;
    }

    priority_queue<pair<int, int>> myQ;
    dist[start] = 0;
    myQ.push({start, 0});

    while(!myQ.empty()) {
        int curNode = myQ.top().first;
        int curDist = myQ.top().second;
        myQ.pop();

        for (int next = 0; next < adj[curNode].size(); next++) {
            int nextNode = adj[curNode][next].first;
            int nextDist = adj[curNode][next].second;

            if (dist[nextNode] > dist[curNode] + nextDist) {
                dist[nextNode] = dist[curNode] + nextDist;
                myQ.push({nextNode, dist[nextNode]});
            }
        }
    }
}

void dijkstraReverse(int start) {
    for (int i = 0; i < 1001; i++) {
        distReverse[i] = 987654321;
    }

    priority_queue<pair<int, int>> myQ;
    distReverse[start] = 0;
    myQ.push({start, 0});

    while(!myQ.empty()) {
        int curNode = myQ.top().first;
        int curDist = myQ.top().second;
        myQ.pop();

        for (int next = 0; next < adjReverse[curNode].size(); next++) {
            int nextNode = adjReverse[curNode][next].first;
            int nextDist = adjReverse[curNode][next].second;

            if (distReverse[nextNode] > distReverse[curNode] + nextDist) {
                distReverse[nextNode] = distReverse[curNode] + nextDist;
                myQ.push({nextNode, distReverse[nextNode]});
            }
        }
    }
}

int main() {
    cin >> inputN >> inputM >> inputX;

    for (int i = 0; i < inputM; i++) {
        int from, to, cost;

        cin >> from >> to >> cost;

        adj[from].push_back({to, cost});
        adjReverse[to].push_back({from, cost});
    }

    dijkstra(inputX);
    dijkstraReverse(inputX);

    int maxValue = -1;

    for (int i = 1; i <= inputN; i++) {
        int toX = distReverse[i]; // X마을로 가는 최단 거리
        int fromX = dist[i]; // X마을에서 각자 마을로 가는 최단 거리

        maxValue = max(maxValue, toX + fromX);
    }

    cout << maxValue;

    return 0;
}