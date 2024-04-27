class Solution {
    
    private int getGcd(int a, int b) {
        if (b == 0) return a;
        return getGcd(b, a % b);
    }
    
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        
        int one = getGcd(n, m);
        int two = n * m / one; 
        
        answer[0] = one;
        answer[1] = two;
        
        return answer;
    }
}