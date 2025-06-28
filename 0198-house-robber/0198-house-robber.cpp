class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];

        for (int ind = 2; ind < n; ++ind) {
            int maxVal = INT_MIN;
            for (int i = 0; i <= ind - 2; ++i) {
                maxVal = max(maxVal, dp[i] + nums[ind]);
            }
            dp[ind] = maxVal;
        }

        return max(dp[n - 1], dp[n - 2]);
    }
};
