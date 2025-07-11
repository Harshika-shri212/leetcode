class Solution {
public:

    int fn(vector<int>& nums , vector<vector<int>>& dp , int ind , int prev){
        int n = nums.size();
        if(ind >= n) return 0;

        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int not_take = fn(nums , dp , ind + 1 , prev) + 0 ; 
        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]){
            take = fn(nums , dp , ind + 1 , ind) + 1;
        }

        return dp[ind][prev+1] = max(take , not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return fn(nums , dp , 0 , -1);
    }
};