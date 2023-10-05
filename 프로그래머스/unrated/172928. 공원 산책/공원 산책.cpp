#include <string>
#include <vector>
#include <iostream>

using namespace std;

char board[50][50];

int width;
int height;

int tempY;
int tempX;

int puppyY;
int puppyX;

void input(vector<string> park) {
    width = park[0].size();
    height = park.size();
    
    for (int i = 0; i < park.size(); i++) {
        string oneLine = park[i];
        for (int j = 0; j < park[i].size(); j++) {
            if (oneLine[j] == 'S') {
                tempY = i;
                tempX = j;
                puppyY = i;
                puppyX = j;
            }
            board[i][j] = oneLine[j];
        }
    }
}

bool isValidCommand(string command) {
    // 명령을 실행해본다. 명령 실행 성공 여부 리턴
    char dir = command[0];
    int degree = command[2] - '0';
    
    if (dir == 'E') {
        for (int i = 1; i <= degree; i++) {
            tempX++;
            if (tempX < 0 || tempX >= width || board[tempY][tempX] == 'X') {
                tempX = puppyX;
                return false;
            }
        }
    } else if (dir == 'W') {
        for (int i = 1; i <= degree; i++) {
            tempX--;
            if (tempX < 0 || tempX >= width || board[tempY][tempX] == 'X') {
                tempX = puppyX;
                return false;
            }
        }
    } else if (dir == 'S') {
        for (int i = 1; i <= degree; i++) {
            tempY++;
            if (tempY < 0 || tempY >= height || board[tempY][tempX] == 'X') {
                tempY = puppyY;
                return false;
            }
        }
    } else {
        for (int i = 1; i <= degree; i++) {
            tempY--;
            if (tempY < 0 || tempY >= height || board[tempY][tempX] == 'X') {
                tempY = puppyY;
                return false;
            }
        }
    }
    
    return true;
}

void move(string command) {
    // 성공이므로 puppyY, puppyX <- tempY, tempX 넣기
    puppyY = tempY;
    puppyX = tempX;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    input(park);
    
    for (int command = 0; command < routes.size(); command++) {
        if (isValidCommand(routes[command])) {
            move(routes[command]);
        }
    }
    
    vector<int> answer(2);
    
    answer[0] = puppyY;
    answer[1] = puppyX;
    
    return answer;
}

int main(void) {
    vector<string> park = {"SOO","OOO", "OOO"};
    vector<string> routes = {"E 2","S 2","W 1"};

    vector<int> answer = solution(park, routes);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0; 
}