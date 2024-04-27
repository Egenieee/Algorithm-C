import java.util.*;

class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        
        Integer[] scores = new Integer[score.length];
        
        for(int i = 0; i < score.length; i++) {
            scores[i] = score[i];
        }
        
        Arrays.sort(scores, Collections.reverseOrder());
        
        int sum = 0;
        int curCnt = 0;
        
        while(curCnt + m <= scores.length) {
            int value = scores[curCnt + m - 1] * m;
            sum += value;
            curCnt += m;
        }
             
        return sum;
    }
}