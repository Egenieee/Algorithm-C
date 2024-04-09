#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int inputN, inputM;
int visited[201];
vector<int> adj[201];
vector<int> paths;

void init() {
    for (int i = 0; i < 201; i++) {
        visited[i] = 0;
    }
}

bool canTravel(int from, int to) {
    init();
    queue<int> myQ;
    visited[from] = 1;
    myQ.push(from);

    while (!myQ.empty()) {
        int curNode = myQ.front();
        myQ.pop();

        if (curNode == to) return true;

        for (int next = 0; next < adj[curNode].size(); next++) {
            int nextNode = adj[curNode][next];

            if (visited[nextNode]) continue;

            visited[nextNode] = 1;
            myQ.push(nextNode);
        }
    }

    return false;
}

int main() {
    cin >> inputN >> inputM;

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputN; j++) {
            int num;
            cin >> num;

            if (num == 0) continue;

            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    for (int i = 0; i < inputM; i++) {
        int num;
        cin >> num;
        paths.push_back(num - 1);
    }

    for (int i = 0; i < inputM - 1; i++) {
        int from = paths[i];
        int to = paths[i + 1];
        if (!canTravel(from, to)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
 }