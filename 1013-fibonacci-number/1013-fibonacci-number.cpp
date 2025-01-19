class Solution {
public:

    int solve(vector<int> & dp , int n){
        if( n==0 || n==1 ) return n;
        else if (dp[n] != -1) return dp[n];
        else return dp[n] = solve(dp , n - 1) + solve(dp , n - 2);
    }
    int fib(int n) {
        vector<int> dp(n+1 , -1);
        int res = solve(dp , n);
        return res;
    }
};