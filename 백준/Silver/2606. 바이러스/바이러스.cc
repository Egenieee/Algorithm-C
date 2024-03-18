#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int inputN, inputM;
int visited[101];
vector<int> adj[101];

int main() {
	cin >> inputN >> inputM;

	for (int i = 0; i < inputM; i++) {
		int from, to;
		cin >> from >> to;

		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	int cnt = 0;

	queue<int> myQ;


	myQ.push(1);
	visited[1] = 1;

 	while (!myQ.empty())
	{
		int current = myQ.front();
		myQ.pop();

		for (int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i];

			if (visited[next]) continue;

			visited[next] = 1;
			myQ.push(next);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}