#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[101];

struct Line {
    int start;
    int end;
    int cost;
};

bool compare(Line one, Line two) {
    return one.cost < two.cost;
}

vector<Line> lines;

void init() {
    for (int i = 0; i < 101; i++) {
        parent[i] = i;
    }
}

int find(int target) {
    if (parent[target] == target) return target;
    
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

int solution(int n, vector<vector<int>> costs) {
    
    for (vector<int> eachCost : costs) {
        int startNode = eachCost[0];
        int endNode = eachCost[1];
        int cost = eachCost[2];
        
        lines.push_back({startNode, endNode, cost});
    }
    
    sort(lines.begin(), lines.end(), compare);
    init();
    
    int targetCnt = n - 1;
    int curCnt = 0;
    int totalCost = 0;
    
    for (Line line : lines) {
        if (find(line.start) == find(line.end)) continue;
        
        curCnt++;
        totalCost += line.cost;
        setUnion(line.start, line.end);
        
        if (curCnt == targetCnt) break;
    }
    
    return totalCost;
}