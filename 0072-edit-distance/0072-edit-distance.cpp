class Solution {
public:

    int fn(string word1, string word2 , vector<vector<int>>&dp , int i , int j){
        if(i < 0){
            return j + 1;
        }
        if(j < 0){
            return i + 1;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int ans;

        if(word1[i] == word2[j]) ans = fn(word1 , word2 , dp , i-1 , j-1);

        else{
            int a1 = 1 + fn(word1 , word2 , dp , i , j-1);   //insert
            int a2 = 1 + fn(word1 , word2 , dp , i - 1 , j); //delete
            int a3 = 1 + fn(word1 , word2 , dp , i-1 , j-1); //replace

            ans = min({a1 , a2 , a3});
        }
        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>dp(m , vector<int>(n , -1));

        return fn(word1 , word2 , dp , m-1 , n-1);
    }
};