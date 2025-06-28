class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> prev_row_dp(n);
        vector<int> current_row_dp(n);

        for (int j = 0; j < n; ++j) {
            prev_row_dp[j] = matrix[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = prev_row_dp[j];

                int up_left = INT_MAX;
                if (j - 1 >= 0) {
                    up_left = prev_row_dp[j-1];
                }

                int up_right = INT_MAX;
                if (j + 1 < n) {
                    up_right = prev_row_dp[j+1];
                }
                
                current_row_dp[j] = matrix[i][j] + min({up, up_left, up_right});
            }
            prev_row_dp = current_row_dp; 
        }

        if (m == 1) {
            return *min_element(prev_row_dp.begin(), prev_row_dp.end());
        }

        int min_total_fall_sum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            min_total_fall_sum = min(min_total_fall_sum, prev_row_dp[j]);
        }

        return min_total_fall_sum;
    }
};