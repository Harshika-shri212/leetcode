class Solution {
public:

    int fn(int i1 , int i2 , string& text1 , string& text2 ,  vector<vector<int>>& dp){
        if(i1 < 0 || i2 <0) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(text1[i1] == text2[i2]){
            return dp[i1][i2] = 1 + fn(i1 - 1 , i2 - 1 , text1 , text2 , dp);
        }

        else{
            return dp[i1][i2] = max(fn(i1 - 1 , i2 , text1 , text2 , dp) , fn(i1 , i2 - 1 , text1 , text2 , dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i1 = text1.size();
        int i2 = text2.size();
        vector<vector<int>>dp(i1 , vector<int>(i2 , -1));
        return fn(i1 - 1 , i2 - 1 , text1 , text2 , dp);
    }
};