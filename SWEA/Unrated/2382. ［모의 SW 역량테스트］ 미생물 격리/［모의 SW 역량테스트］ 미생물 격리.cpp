#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct Group {
	int row, col, cnt, dir;
};

struct MAP {
	int groupNum; // 현재 셀 차지한 군집 번호
	int cnt;      // 현재 셀에 모인 미생물 합
};

int n, m, k;
vector<Group> group;
vector<int> alive;  // 현재 살아있는 군집 목록

int dy[] = { 0, -1, 1, 0, 0 };
int dx[] = { 0, 0, 0, -1, 1 };

void input() {
	cin >> n >> m >> k;
	group.push_back({ 0, 0, 0, 0 });
	for (int i = 1; i <= k; i++) {
		int row, col, cnt, dir;
		cin >> row >> col >> cnt >> dir;
		group.push_back({ row, col, cnt, dir });
		alive.push_back(i);
	}
}

void simul() {
	for (int time = 0; time < m; time++) {
		MAP map[101][101] = { 0, };

		for (int i = 0; i < alive.size(); i++) {
			int nowGroupNum = alive[i];
			Group nowGroup = group[nowGroupNum];
			nowGroup.row += dy[nowGroup.dir];
			nowGroup.col += dx[nowGroup.dir];

			// 맵 가장자리
			if (nowGroup.row <= 0 || nowGroup.row >= n - 1 ||
				nowGroup.col <= 0 || nowGroup.col >= n - 1) {
				nowGroup.cnt /= 2;
				nowGroup.dir += 1;
				if (nowGroup.dir % 2 == 1)
					nowGroup.dir -= 2;
			}

			// 한 셀에 여러 군집이 모이는 경우
			// 합치기
			// 현재 셀에서 가장 많았던 군집
			int maxGroupNum = map[nowGroup.row][nowGroup.col].groupNum;
			Group maxGroup = group[maxGroupNum];

			// 현재 셀보다 내가 더 큰 경우 -> 현재 셀 삭제
			if (maxGroup.cnt < nowGroup.cnt) {
				map[nowGroup.row][nowGroup.col] = { nowGroupNum, map[nowGroup.row][nowGroup.col].cnt + nowGroup.cnt };
				group[maxGroupNum].cnt = 0;
			}
			else {
				map[nowGroup.row][nowGroup.col] = { maxGroupNum, map[nowGroup.row][nowGroup.col].cnt + nowGroup.cnt };
				nowGroup.cnt = 0;
			}
			group[nowGroupNum] = nowGroup;
		}

		// 다음 턴 준비
		vector<int> next_alive;
		for (int i = 0; i < alive.size(); i++) {
			int nowGroupNum = alive[i];
			Group nowGroup = group[nowGroupNum];
			if (nowGroup.cnt == 0) continue;  // 미생물이 없으면 무시

			group[nowGroupNum].cnt = map[nowGroup.row][nowGroup.col].cnt;
			next_alive.push_back(nowGroupNum);
		}
		alive = next_alive;
	}
}

int solve() {
	simul();

	// 시뮬레이션 후 남아있는 군집의 미생물 총 합 
	int ret = 0;
	for (int i = 0; i < alive.size(); i++) {
		ret += group[alive[i]].cnt;
	}
	return ret;
}

int main() {
	// freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		group.clear();
		alive.clear();

		input();
		int ans = solve();

		cout << "#" << tc << " " << ans << "\n";
	}
}