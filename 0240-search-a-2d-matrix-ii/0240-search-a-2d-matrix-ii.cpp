class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ri = matrix.size();
        int ci = matrix[0].size();

        int row = matrix.size() - 1;
        int col = 0;

        while ( row>=0 && col<ci ){
            if (target == matrix[row][col]) return true;
            else if (target > matrix[row][col]) col+=1;
            else row-=1;
        }
        return false;
    }
};