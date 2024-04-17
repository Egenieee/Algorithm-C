#include <string>
#include <vector>
#include <iostream>

using namespace std;

int monsterAttacks[1001];

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    for (vector<int> attack : attacks) {
        int time = attack[0];
        int amount = attack[1];
        
        monsterAttacks[time] = amount;
    }
    
    int lastAttackTime = attacks[attacks.size() - 1][0];
    int targetTime = bandage[0];
    int healingPerSec = bandage[1];
    int extraHealing = bandage[2];
    int curHealth = health;
    int attackCnt = 0;
    
    for (int i = 1; i <= lastAttackTime; i++) {
        
        //cout << "current time : " << i << "\n";
                
        // 몬스터가 공격할 경우
        if (monsterAttacks[i] > 0) {
            //cout << "monster attack!\n";
            curHealth -= monsterAttacks[i];
            attackCnt = 0;
        } 
        
        // 몬스터가 공격하지 않을 경우
        else {
            // 연속 공격 성공 시
            attackCnt++;
            curHealth += healingPerSec;
            
            if (attackCnt == targetTime) {
                //cout << "연속 공격 성공\n";
                curHealth += extraHealing;
                attackCnt = 0;
            }
        }
        
        if (curHealth > health) {
            curHealth = health;
        }
        
        if (curHealth <= 0) return -1;
        
        // cout << "curHealth : " << curHealth << "\n";
        // cout << "attackCnt : " << attackCnt << "\n";
        // cout << "\n";
    }
    
    if (curHealth <= 0) return -1;
    
    return curHealth;
}