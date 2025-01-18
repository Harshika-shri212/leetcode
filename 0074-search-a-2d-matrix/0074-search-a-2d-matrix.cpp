class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row * col -1;

        int low = 0 , high = n;

        while(low<=high){
            int mid = (low+high)/2;

            int ri = mid / col;
            int ci = mid % col;

            if (target == matrix[ri][ci]) return true;
            else if (matrix[ri][ci] > target){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return false;
    }
};