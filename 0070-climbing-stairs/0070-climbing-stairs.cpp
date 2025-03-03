class Solution {
public:
    
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int f = 1 , s = 2;
        for(int i = 3 ; i <= n; i++){
            int t = f + s;
            f = s;
            s = t;
        }
        return s;
    }
};