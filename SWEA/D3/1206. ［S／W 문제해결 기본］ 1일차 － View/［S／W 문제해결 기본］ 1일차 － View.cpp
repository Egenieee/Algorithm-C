#include <iostream>
#include <algorithm>

using namespace std;

int buildings[1001];
int inputN;
int answer;

void init() {
    for (int i = 0; i < inputN; i++) {
        buildings[i] = 0;
    }
    answer = 0;
}

void calc() {
    for (int i = 2; i < inputN; i++) {
        int center = buildings[i];

        int minValue = 300;

        minValue = min(minValue, center - buildings[i - 2]);
        minValue = min(minValue, center - buildings[i - 1]);
        minValue = min(minValue, center - buildings[i + 1]);
        minValue = min(minValue, center - buildings[i + 2]);

        if (minValue < 0) continue;
        else answer += minValue;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        cin >> inputN;

        init();

        for (int i= 0; i < inputN; i++) {
            cin >> buildings[i];
        }

        calc();

        cout << "#" << test_case << " " << answer << "\n";

	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}