#include <string>
#include <vector>

using namespace std;

int parent[201];
int inputN;

void init() {
    for (int i = 0; i < 201; i++) {
        parent[i] = i;
    }
}

int find(int target) {
    if (parent[target] == target) {
        return target;
    }
    
    int result = find(parent[target]);
    parent[target] = result;
    return result;
}

void setUnion(int one, int two) {
    int oneBoss = find(one);
    int twoBoss = find(two);
    
    if (oneBoss == twoBoss) {
        return;
    }
    
    parent[twoBoss] = oneBoss;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = n;
    
    inputN = n;
    init();
    
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputN; j++) {
            if (computers[i][j] == 1) {
                if(find(i) == find(j)) continue;
                
                setUnion(i, j);
                answer--;
            }
        }
    }
    
    return answer;
}