class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1  ,vector<int>(2 , 0));

        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                if(buy == 1){
                    int p1 = -prices[i] + dp[i+1][0];
                    int p2 = dp[i+1][1];
                    dp[i][buy] = max(p1 , p2);
                }
                else{
                    int s1 = prices[i] + dp[i+1][1];
                    int s2 = dp[i+1][0];
                    dp[i][buy] = max(s1 , s2);
                }
            }
        }
        return dp[0][1];
    }
};