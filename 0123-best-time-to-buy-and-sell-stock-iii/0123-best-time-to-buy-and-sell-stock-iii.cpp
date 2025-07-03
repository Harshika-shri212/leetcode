class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (n+1 , vector<vector<int>>(2 , vector<int>(3 , 0)));
        
        for(int i = 0 ; i <= n ; i++){
            dp[i][0][0] = 0;
            dp[i][1][0] = 0;
        }

        for(int buy = 0 ; buy <= 1 ; buy++){
            for(int cap = 0 ; cap <= 2 ; cap++){
                dp[n][buy][cap] = 0;
            }
        }

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int cap = 1 ; cap<= 2 ; cap++){
                    int pr;
                    if(buy == 1){
                        int b1 = -prices[i] + dp[i + 1][0][cap];
                        int b2 = dp[i+1][1][cap];
                        pr = max(b1 , b2);
                    }
                    else{
                        int s1 = prices[i] + dp[i + 1][1][cap-1];
                        int s2 = dp[i+1][0][cap];
                        pr = max(s1 , s2);
                    }
                    dp[i][buy][cap] = pr;
                }
            }
        }
        return dp[0][1][2];
    }
};