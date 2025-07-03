class Solution {
public:

    int fn(vector<int>& prices ,vector<vector<int>>&dp , int fees , int n , int ind , int buy){
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int pr;
        if(buy){
            int b1 = -prices[ind] + fn(prices , dp , fees , n , ind + 1 , 0);
            int b2 = fn(prices , dp , fees , n , ind + 1 , 1);
            pr = max(b1 , b2);
        }
        else{
            int s1 = prices[ind] + fn(prices , dp , fees , n , ind + 1 , 1) - fees;
            int s2 = fn(prices , dp , fees , n , ind + 1 , 0);
            pr = max(s1 , s2);
        }
        return dp[ind][buy] = pr;
    }

    int maxProfit(vector<int>& prices, int fees) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2 , -1));
        return fn(prices , dp , fees , n , 0 , 1);
    }
};