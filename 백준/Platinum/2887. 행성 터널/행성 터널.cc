#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputN;
int parents[100001];

struct info {
    int one;
    int two;
    int dist;
};

bool compare(info one, info two) {
    return one.dist < two.dist;
}

vector<pair<int, int>> Xs;
vector<pair<int, int>> Ys;
vector<pair<int, int>> Zs;

vector<info> infos;

int find(int target) {
    if (parents[target] == target) return target;

    int ret = find(parents[target]);
    parents[target] = ret;

    return ret;
}

void setUnion(int one, int two) {
    int bossOne = find(one);
    int bossTwo = find(two);

    if (bossOne == bossTwo) return;

    parents[bossTwo] = bossOne;
}

int main() {
    cin >> inputN;

    for (int i = 0; i < inputN; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < inputN; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        // x, y, z 값과 순서 저장
        Xs.push_back({x, i});
        Ys.push_back({y, i});
        Zs.push_back({z, i});
    }

    // x, y, z 값 정렬
    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());
    sort(Zs.begin(), Zs.end());

    // 정렬한 값 토대로 두 행성 간의 거리 구해서 info에 저장하기
    for (int i = 0; i < inputN - 1; i++) {
        int xDiff = abs(Xs[i].first - Xs[i + 1].first);
        int yDiff = abs(Ys[i].first - Ys[i + 1].first);
        int zDiff = abs(Zs[i].first - Zs[i + 1].first);

        infos.push_back({Xs[i].second, Xs[i + 1].second, xDiff});
        infos.push_back({Ys[i].second, Ys[i + 1].second, yDiff});
        infos.push_back({Zs[i].second, Zs[i + 1].second, zDiff});
    }

    sort(infos.begin(), infos.end(), compare);

    int selectedCnt = 0;
    int targetCnt = inputN - 1;
    int price = 0;

    for (int i = 0; i < infos.size(); i++) {
        int a = infos[i].one;
        int b = infos[i].two;

        if (find(a) == find(b)) continue;

        selectedCnt++;
        price += infos[i].dist;
        setUnion(a, b);

        if (selectedCnt == targetCnt) break;
    }

    cout << price;

    return 0;
}