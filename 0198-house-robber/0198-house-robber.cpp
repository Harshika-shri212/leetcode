class Solution {
public:

    int solve(vector<int> &nums , vector<int> &dp ,int &len , int n){
        if(n >= len) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = nums[n] + solve(nums,dp,len,n+2);
        int not_pick = solve(nums,dp,len,n+1);
        return dp[n] = max(pick , not_pick);
    }

    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int>dp(len , -1);
        return solve(nums , dp , len , 0);
    }
};