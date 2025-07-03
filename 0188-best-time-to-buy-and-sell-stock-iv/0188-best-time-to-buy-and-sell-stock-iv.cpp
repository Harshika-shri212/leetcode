class Solution {
public:


    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n + 1 , vector<int>(2 * k + 1  , 0));
        
        for(int ind = n - 1 ; ind >= 0 ; ind--){
            for(int transac = 2*k - 1 ; transac >= 0 ; transac--){
                int pr;
                if(transac % 2 == 0){
                    int b1 = -prices[ind] + dp[ind + 1][transac+1];
                    int b2 = dp[ind + 1][transac];
                    pr = max(b1 , b2);
                }
                else{
                    int s1 = prices[ind] + dp[ind + 1][transac + 1];
                    int s2 = dp[ind + 1][transac];
                    pr = max(s1 , s2);
                }
                dp[ind][transac] = pr;
            }
        }
        return dp[0][0];
    }
};