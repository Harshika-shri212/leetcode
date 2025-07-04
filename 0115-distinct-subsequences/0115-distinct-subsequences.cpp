class Solution {
public:

    int fn(string& s , string& t , int n1 , int n2 , vector<vector<int>>&dp , int i , int j){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int tot;
        if(s[i] == t[j]){
            tot = fn(s,t,n1,n2,dp,i-1,j-1) + fn(s,t,n1,n2,dp,i-1,j);
        }
        else{
            tot = fn(s,t,n1,n2,dp,i-1,j);
        }
        return dp[i][j] = tot;
    }

    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<int>>dp(n1 , vector<int>(n2 , -1));

        return fn(s , t , n1 , n2 , dp , n1 - 1 , n2 - 1);
    }
};