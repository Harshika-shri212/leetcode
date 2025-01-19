class Solution {
public:
    int solve(int i, vector<int> &dp,  vector<int> & cost){
        if(i>=cost.size()) return 0;
        else if(dp[i] != -1) return dp[i];
        else return dp[i] = cost[i] + fmin( solve(i+1,dp,cost) , solve(i+2,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size() , -1);
        
        return fmin( solve(0,dp,cost) , solve(1,dp,cost));
    }
};