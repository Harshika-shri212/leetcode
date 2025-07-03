class Solution {
public:


    int maxProfit(vector<int>& prices, int fees) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2 , 0));
        
        for(int ind = n - 1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1; buy++){
                int pr;
                if(buy){
                    int b1 = -prices[ind] + dp[ind + 1][0];
                    int b2 = dp[ind + 1][1];
                    pr = max(b1 , b2);
                }
                else{
                    int s1 = prices[ind] + dp[ind + 1][1] - fees;
                    int s2 = dp[ind + 1][0];
                    pr = max(s1 , s2); 
                }
                dp[ind][buy] = pr;
            }
        }
        return dp[0][1];
    }
};