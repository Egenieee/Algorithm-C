#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int x;
    int y;
    long long dist;
};

bool compare(Line one, Line two) {
    return one.dist < two.dist;
}

int inputN, inputM;
int parent[200001];

vector<Line> lines;

void init() {
    for (int i = 0; i < 200001; i++) {
        parent[i] = i;
    }
}

int find(int target) {
    if (target == parent[target]) return target;

    int ret = find(parent[target]);
    parent[target] = ret;
    return ret;
}

void setUnion(int one, int two) {
    int bossOne = find(one);
    int bossTwo = find(two);

    if (bossOne == bossTwo) return;

    parent[bossTwo] = bossOne;
}

int main() {
    while(true) {
        cin >> inputN >> inputM;

        if (inputN == 0 && inputM == 0) break;

        long long sumOfAllPrice = 0;
        lines.clear();

        for (int i = 0; i < inputM; i++) {
            int one, two;
            long long dist;

            cin >> one >> two >> dist;

            lines.push_back({one, two, dist});
            sumOfAllPrice += dist;
        }

        sort(lines.begin(), lines.end(), compare);

        int targetCnt = inputN - 1;
        int curCnt = 0;
        long long price = 0;
        init();

        for (int i = 0; i < lines.size(); i++) {
            Line curLine = lines[i];

            if (find(curLine.x) == find(curLine.y)) continue;

            price += curLine.dist;
            curCnt++;
            setUnion(curLine.x, curLine.y);

            if (curCnt == targetCnt) break;
        }

        cout << sumOfAllPrice - price << "\n";
    }
}