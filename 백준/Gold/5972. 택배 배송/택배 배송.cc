#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int inputN, inputM;

vector<pair<int, int>> adj[50001];
int dist[50001];

struct compare {
    bool operator()(pair<int, int> one, pair<int, int> two) {
        return one.second > two.second;
    }
};

void init() {
    for (int i = 0; i <= inputN; i++) {
        dist[i] = INT32_MAX;
    }
}

int main() {
    cin >> inputN >> inputM;

    for(int i = 0; i < inputM; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }
    
    init();

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> myQ;
    dist[1] = 0;
    myQ.push({1, 0});

    while(!myQ.empty()) {
        int curNode = myQ.top().first;
        myQ.pop();

        for (int next = 0; next < adj[curNode].size(); next++) {
            int nextNode = adj[curNode][next].first;
            int nextCost = adj[curNode][next].second;

            if (dist[nextNode] > dist[curNode] + nextCost) {
                dist[nextNode] = dist[curNode] + nextCost;
                myQ.push({nextNode, dist[nextNode]});
            }
        }
    }
    
    cout << dist[inputN];

    return 0;
}