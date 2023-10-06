#include <iostream>

using namespace std;

int inputN;
int inputM;

int arr[9];
int visited[9];

void print() {
    for (int i = 0; i < inputM; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void permutate(int depth) {
    if (depth == inputM) {
        print();
        return;
    }

    for (int i = 1; i <= inputN; i++) {
        arr[depth] = i;
        permutate(depth + 1);
    }
}

int main(void) {
    cin >> inputN >> inputM;

    permutate(0);

    return 0;
}