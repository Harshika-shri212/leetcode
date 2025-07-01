class Solution {
public:

    int fn(vector<int>& prices , vector<vector<int>>& dp , int ind , int buy){
        if(ind == prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit;

        if(buy){
            int p1 = -prices[ind] + fn(prices , dp , ind + 1 , 0);
            int p2 = fn(prices , dp , ind + 1 , 1);
            profit = max(p1 , p2);
        }

        else{
            int s1 = prices[ind] + fn(prices , dp , ind + 1 , 1);
            int s2 = fn(prices , dp , ind + 1 , 0);
            profit = max(s1 , s2);
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1 , vector<int>(2 , -1));
        return fn(prices , dp , 0 , 1);
    }
};