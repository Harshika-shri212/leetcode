class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> res = {0,0};
        int row = grid.size();
        int col = grid[0].size();

        vector<int> freq(row*row + 1 , 0);

        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col ; j++){
                int num = grid[i][j];
                freq[num] += 1;
            }
        }

        for(int i = 1 ; i < freq.size() ; i++){
            if(freq[i] == 0) res[1] = i;
            else if(freq[i] == 2) res[0] = i;
        }

        return res;
    }
};