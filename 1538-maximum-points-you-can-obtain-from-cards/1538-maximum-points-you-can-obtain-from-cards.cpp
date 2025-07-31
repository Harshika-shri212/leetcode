class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = 0;
        int ans = 0;
        for(int i = 0 ; i < k ; i++){
            score += cardPoints[i];
        }

        int n = cardPoints.size();
        int r = n - 1;
        ans = score;

        for(int i = k - 1 ; i >= 0 ; i--
        ){
            score -= cardPoints[i];
            score += cardPoints[r];
            
            r -= 1;
            ans = max(ans , score);
        }

        return ans;
    }
};