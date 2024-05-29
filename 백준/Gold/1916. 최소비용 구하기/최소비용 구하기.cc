#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int inputN, inputM;
int startNode, endNode;

vector<pair<int, int>> adj[1001];
int dist[1001];

struct compare {
	bool operator()(pair<int, int> one, pair<int, int> two) {
		return one.second > two.second;
	}
};

void init() {
	for (int i = 0; i < 1001; i++) {
		dist[i] = INT32_MAX;
	}
}

int main() {
	cin >> inputN >> inputM;

	for (int i = 0; i < inputM; i++) {
		int from, to, cost;

		cin >> from >> to >> cost;

		adj[from].push_back({ to, cost });
	}

	cin >> startNode >> endNode;

	init();

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> myQ;
	myQ.push({ startNode, 0 });
	dist[startNode] = 0;

	while (!myQ.empty()) {
		int curNode = myQ.top().first;
		int curCost = myQ.top().second;
		myQ.pop();

		if (dist[curNode] < curCost) continue;

		for (int next = 0; next < adj[curNode].size(); next++) {
			int nextNode = adj[curNode][next].first;
			int nextCost = adj[curNode][next].second;

			if (dist[nextNode] > dist[curNode] + nextCost) {
				dist[nextNode] = dist[curNode] + nextCost;
				myQ.push({ nextNode, dist[nextNode] });
			}
		}
	}

	cout << dist[endNode];

	return 0;
}