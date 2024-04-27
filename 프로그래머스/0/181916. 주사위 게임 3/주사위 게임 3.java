import java.util.*;

class Solution {
    int[] dat = new int[7];
    
    private boolean allOne() {
        for (int i = 1; i < dat.length; i++) {
            if (dat[i] > 1) return false;
        }
        return true;
    }
    
    private int getMin() {
        int min = Integer.MAX_VALUE;
        
        for (int i = 1; i < dat.length; i++) {
            if (min > i && dat[i] > 0) {
                min = i;
            }
        }
        
        return min;
    }
    
    public int solution(int a, int b, int c, int d) {
        int answer = 0;
        
        dat[a]++;
        dat[b]++;
        dat[c]++;
        dat[d]++;
        
        if (allOne()) {
            return getMin();
        }
        
        for (int i = 1; i < dat.length; i++) {
            if (dat[i] == 4) {
                return 1111 * i;
            } 
        }
        
        for (int i = 1; i < dat.length; i++) {
            if (dat[i] == 3) {
                for (int j = 1; j < dat.length; j++) {
                    if (dat[j] == 1) {
                        return (int) Math.pow(10 * i + j, 2);
                    }
                }
            } 
        }
            
        for (int i = 1; i < dat.length; i++) {
            if (dat[i] == 2) {
                for (int j = i + 1; j < dat.length; j++) {
                    if (dat[j] == 2) {
                        return (i + j) * Math.abs(i - j);
                    }
                }
            }
        } 
        
        for (int i = 1; i < dat.length; i++) {
            if (dat[i] == 2) {
                for (int j = 1; j < dat.length; j++) {
                    if (dat[j] == 1) {
                        for (int k = j + 1; k < dat.length; k++) {
                            if (dat[k] == 1) {
                                return j * k;
                            }
                        }
                    }
                }
            }
        } 
        
        return answer;
    }

}