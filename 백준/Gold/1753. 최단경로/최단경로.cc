#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999

using namespace std;

vector<pair<int, int>> adj[20002];

int startNode;
int V;
int E;

vector<int> getMinDist() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    vector<int> dist(V + 1, INF);

    // 시작 번호 -> 모든 정점의 최단 경로 구하기

    dist[startNode] = 0;
    queue.push({0, startNode});

    while(!queue.empty()) {
        int from = queue.top().second;
        int cost = queue.top().first;
        queue.pop();

        if (dist[from] < cost) {
            continue;
        }

        for (int i = 0; i < adj[from].size(); i++) {
            int to = adj[from][i].first;
            int newCost = adj[from][i].second + cost;

            if (newCost < dist[to]) {
                dist[to] = newCost;
                queue.push({newCost, to});
            }
        }
    }

    return dist;
}

int main(void) {
    cin >> V >> E;
    cin >> startNode;

    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        adj[from].push_back({to, cost});
    }

    vector<int> dist = getMinDist();

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF\n"; 
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}