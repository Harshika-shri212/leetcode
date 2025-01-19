class Solution {
public:
    int solve(vector<int> &dp , int n){
        if(n==1 || n==2) return n;
        else if(dp[n-1] != -1) return dp[n-1];
        else return dp[n-1] = solve(dp , n-1) + solve(dp , n-2);
    }
    int climbStairs(int n) {
        vector<int> dp(n , -1);
        int ways = solve(dp , n);
        return ways;
    }
};