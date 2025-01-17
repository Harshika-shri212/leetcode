class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0] , max_profit=0 , curr=0;
        for(int i=1;i<prices.size();i++){
            if (prices[i]<min_buy) min_buy=prices[i];
            else{
                curr=prices[i]-min_buy;
                max_profit=fmax(max_profit , curr);
            }
        }
        return max_profit;
    }
};