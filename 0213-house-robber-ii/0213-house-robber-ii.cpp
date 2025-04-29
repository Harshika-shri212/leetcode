class Solution {
public:

    int solve(vector<int>&v , int n , vector<int>&dp){
        
        if (n >= v.size()) return 0;

        if(dp[n] != -1) return dp[n];
        int pick = v[n] + solve(v,n+2,dp);
        int not_pick = solve(v,n+1,dp);

        return dp[n] = max(pick , not_pick);
    }

    int rob(vector<int>& nums) {
        
        int n =  nums.size();
        if (n == 1) return nums[0]; 

        vector<int>sub1(nums.begin() , nums.begin() + n - 1);
        vector<int> dp1(sub1.size(), -1);

        vector<int>sub2(nums.begin()+1 , nums.end());
        vector<int> dp2(sub2.size(), -1);


        int a1 = solve(sub1 , 0 , dp1);
        int a2 = solve(sub2 , 0 , dp2);

        return max(a1,a2);
    }
};