#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int inputN;
int inputM;
int inputV;

vector<int> adj[10001];
int visitedDFS[10001];
int visitedBFS[10001];

void dfs(int cur) {
    cout << cur << " ";

    if (cur == inputV) {
        visitedDFS[cur] = 1;
    }

    sort(adj[cur].begin(), adj[cur].end());

    for (int next = 0; next < adj[cur].size(); next++) {
        int nextNode = adj[cur][next];

        if (visitedDFS[nextNode]) continue;
        visitedDFS[nextNode] = 1;
        dfs(nextNode);
        //visitedDFS[nextNode] = 0;
    }
}

void bfs() {
    queue<int> myQ;
    visitedBFS[inputV] = 1;
    myQ.push(inputV);

    while(!myQ.empty()) {
        int cur = myQ.front();
        myQ.pop();

        cout << cur << " ";

        sort(adj[cur].begin(), adj[cur].end());

        for (int next = 0; next < adj[cur].size(); next++) {
            int nextNode = adj[cur][next];

            if (visitedBFS[nextNode]) continue;

            myQ.push(nextNode);
            visitedBFS[nextNode] = 1;
        }
    }
}

int main() {

    cin >> inputN >> inputM >> inputV;

    for (int i = 0; i < inputM; i++) {
        int from, to;

        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    // dfs
    dfs(inputV);

    cout << "\n";

    // bfs
    bfs();
}