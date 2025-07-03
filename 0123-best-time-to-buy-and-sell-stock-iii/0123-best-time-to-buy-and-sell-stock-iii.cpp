class Solution {
public:

    int fn(vector<int>& prices , vector<vector<vector<int>>>& dp , int ind , int buy , int cap){
        int n = prices.size();
        if(cap == 0 || ind == n) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int pr;
        if(buy){
            pr =  max( (-prices[ind] + fn(prices , dp , ind + 1 , 0 , cap)) , 
                        (fn(prices , dp , ind + 1 , 1 , cap)) );
        }
        else{
            int s1 = prices[ind] + fn(prices , dp , ind + 1 , 1 , cap - 1);
            int s2 = fn(prices , dp , ind + 1 , 0 , cap);
            pr = max(s1 , s2);
        }
        return dp[ind][buy][cap] = pr;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        return fn(prices , dp , 0 , 1 , 2);
    }
};