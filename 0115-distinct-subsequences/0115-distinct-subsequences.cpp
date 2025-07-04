class Solution {
public:

    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<double>>dp(n1 + 1 , vector<double>(n2 + 1 , 0));

        for(int i = 0 ; i <= n1 ; i++){
            dp[i][0] = 1;
        }

        for(int j = 1 ; j <= n2 ; j++){
            dp[0][j] = 0;
        }

        for(int i = 1 ; i <= n1  ; i++){
            for(int j = 1 ; j <= n2  ; j++){
                double tot;
                if(s[i-1] == t[j-1]){
                    tot = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    tot = dp[i-1][j];
                }
                dp[i][j] = tot;
            }
        }
        return (int)dp[n1][n2];
    }
};