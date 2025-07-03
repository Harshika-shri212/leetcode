class Solution {
public:

    int fn(vector<int>& prices , vector<vector<int>>& dp , int ind , int k , int n , int transac){
        if(ind == n || transac == 2*k) return 0;

        if(dp[ind][transac] != -1) return dp[ind][transac];

        int pr;

        if(transac % 2 == 0){
            int b1 = -prices[ind] + fn(prices , dp , ind + 1 , k , n , transac + 1);
            int b2 = fn(prices , dp , ind + 1 , k , n , transac);
            pr = max(b1 , b2);
        }
        else{
            int s1 = prices[ind] + fn(prices , dp , ind + 1 , k , n , transac + 1);
            int s2 = fn(prices , dp , ind + 1 , k , n , transac);
            pr = max(s1 , s2);
        }
        return dp[ind][transac] = pr;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2 * k , -1));
        return fn(prices , dp , 0 , k , n , 0);
    }
};