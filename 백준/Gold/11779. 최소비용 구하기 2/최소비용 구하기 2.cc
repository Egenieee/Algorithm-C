#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int inputN, inputM;
int startNode, endNode;

// 도착, 비용
vector<pair<int, long long>> adj[1001];

int dist[1001];
int parents[1001];

struct compare {
    bool operator()(pair<int, int> one, pair<int, int> two) {
        return one.second > two.second;
    }
};

void init() {
    for (int i = 0; i < 1001; i++) {
        dist[i] = INT32_MAX;
        parents[i] = -1;
    }
}

int main() {
    cin >> inputN >> inputM;

    for (int i = 0; i < inputM; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        adj[from].push_back({to, cost});
    }

    cin >> startNode >> endNode;

    init();

    priority_queue<pair<int, long long>, vector<pair<int, long long>>, compare> myQ;
    dist[startNode] = 0;
    parents[startNode] = 0;
    myQ.push({startNode, 0});

    while(!myQ.empty()) {
        int curNode = myQ.top().first;
        long long curCost = myQ.top().second;
        myQ.pop();

        if (dist[curNode] < curCost) continue;

        for (int next = 0; next < adj[curNode].size(); next++) {
            int nextNode = adj[curNode][next].first;
            long long nextCost = adj[curNode][next].second;

            if (dist[nextNode] > dist[curNode] + nextCost) {
                dist[nextNode] = dist[curNode] + nextCost;
                parents[nextNode] = curNode;
                myQ.push({nextNode, dist[nextNode]});
            }
        }
    }

    // 경로 찾기
    vector<int> paths;
    int curNode = endNode;
    paths.push_back(curNode);

    while(true) {
        curNode = parents[curNode];
        paths.push_back(curNode);

        if (curNode == startNode) break;
    }

    reverse(paths.begin(), paths.end());

    cout << dist[endNode] << "\n";
    cout << paths.size() << "\n";
    
    for (int node : paths) {
        cout << node << " ";
    }
    
    return 0;
}