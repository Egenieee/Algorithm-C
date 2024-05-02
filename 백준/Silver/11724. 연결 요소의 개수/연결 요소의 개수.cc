#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> graph[1001];
int visited[1001];
int n, m;

void bfs(int node) {
	queue<int> q;
	q.push(node);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (visited[next] == 1) continue;

			visited[next] = 1;
			q.push({ next });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) continue;
		cnt++;
		bfs(i);
	}

	cout << cnt;
}