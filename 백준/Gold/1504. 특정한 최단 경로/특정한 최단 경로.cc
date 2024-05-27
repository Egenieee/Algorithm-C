#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int inputN, inputM;
int inputU, inputV;

int dist[801];

vector<pair<int, int>> adj[801];

struct compare {
    bool operator()(pair<int, int> one, pair<int, int> two) {
        return one.second > two.second;
    }
};

void init() {
    for (int i = 0; i < 801; i++) {
        dist[i] = INT32_MAX;
    }
}

int dijkstra(int startNode, int endNode) {
    init();

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> myQ;
    myQ.push({startNode, 0});
    dist[startNode] = 0;

    while(!myQ.empty()) {
        int curNode = myQ.top().first;
        int curDist = myQ.top().second;
        myQ.pop();

        if (dist[curNode] < curDist) continue;

        for (int next = 0; next < adj[curNode].size(); next++) {
            int nextNode = adj[curNode][next].first;
            int nextDist = adj[curNode][next].second;
            
            if (dist[nextNode] > dist[curNode] + nextDist) {
                dist[nextNode] = dist[curNode] + nextDist;
                myQ.push({nextNode, dist[nextNode]});
            }
        }
    }

    return dist[endNode];
}

int main() {
    cin >> inputN >> inputM;
    
    for (int i = 0; i < inputM ; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }

    cin >> inputU >> inputV;
    int uToV = dijkstra(inputU, inputV);

    if (uToV == INT32_MAX) {
        cout << -1;
        return 0;
    }

    int one = 0;
    int two = 0;
    bool oneValid = true;
    bool twoValid = true;

    // 1 -> inputU -> inputV -> inputN
    int eachDist;

    eachDist = dijkstra(1, inputU);

    if (eachDist == INT32_MAX) {
        oneValid = false;
    }

    one += eachDist;
    one += uToV;

    eachDist = dijkstra(inputV, inputN);

    if (eachDist == INT32_MAX) {
        oneValid = false;
    }

    one += eachDist;

    // 1 -> inputV -> inputU -> inputN
    eachDist = dijkstra(1, inputV);

    if (eachDist == INT32_MAX) {
        twoValid = false;
    }

    two += eachDist;
    two += uToV;

    eachDist = dijkstra(inputU, inputN);

    if (eachDist == INT32_MAX) {
        twoValid = false;
    }

    two += eachDist;

    // 둘다 경로 없다면
    if (!oneValid && !twoValid) {
        cout << -1;
    } else {
        // 둘 중 더 작은 값이 답
        cout << min(one, two);
    }

    return 0;
}