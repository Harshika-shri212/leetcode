class Solution {
public:


    int solve(vector<int>&dp , int n){
        
        if(dp[n] != -1) return dp[n];
        else return dp[n] = solve(dp,n-1) + solve(dp,n-2);
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+1 , -1);
        if(n==1) return 1;
        if(n==2) return 2;
        dp[1] = 1;
        dp[2] = 2;
        return solve(dp,n);
         
    }
};