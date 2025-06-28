class Solution {
public:

    int fn(vector<int>& nums , vector<int>& dp , int ind){
        if(ind == 0) return nums[0];
        if(ind == 1) return nums[1];

        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MIN;
        for(int i = ind-2 ; i >= 0 ; i--){
            int num = fn(nums , dp , i) + nums[ind];
            ans = max(num , ans);
        }
        return dp[ind] = ans;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , -1);
        int a = fn(nums , dp , n-1);
        int b = INT_MIN;
        if(n-2 >= 0) b = fn(nums , dp , n-2);
        return max(a,b);
    }
};