class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>p = {0,0};

        int pp , ss;

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                if(buy == 1){
                    int p1 = -prices[i] + p[0];
                    int p2 = p[1];
                    pp = max(p1 , p2);
                }
                else{
                    int s1 = prices[i] + p[1];
                    int s2 = p[0];
                    ss = max(s1 , s2);
                }
            }
            p = {ss , pp};
        }
        return p[1];
    }
};