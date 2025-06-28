class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 ) return n;
        int prev2 = 2;
        int prev1 = 1;

        int cur;
        for(int i = 3 ; i <= n ; i++){
            cur = prev1 + prev2;
            prev1 = prev2;
            prev2 = cur;
        }
        return cur;
    }
};