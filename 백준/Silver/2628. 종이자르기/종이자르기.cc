#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputM, inputN;
int inputK;

int main() {
    cin >> inputM >> inputN >> inputK;

    vector<int> heights;
    vector<int> widths;

    for (int i = 0; i < inputK; i++) {
        int type, idx;
        cin >> type >> idx;

        if (type == 0) {
            heights.push_back(idx);
        }
        else {
            widths.push_back(idx);
        }
    }

    heights.push_back(0);
    heights.push_back(inputN);
    widths.push_back(0);
    widths.push_back(inputM);

    sort(heights.begin(), heights.end());
    sort(widths.begin(), widths.end());

    // 각 구간구하기
    int maxHeight = -1; 
    int maxWidth = -1;

    for (int i = 0; i < heights.size() - 1; i++) {
        if (heights[i + 1] - heights[i] > maxHeight) {
            maxHeight = heights[i + 1] - heights[i];
        }
    }

    for (int i = 0; i < widths.size() - 1; i++) {
        if (widths[i + 1] - widths[i] > maxWidth) {
            maxWidth = widths[i + 1] - widths[i];
        }
    }

    cout << maxHeight * maxWidth;

    return 0;
}