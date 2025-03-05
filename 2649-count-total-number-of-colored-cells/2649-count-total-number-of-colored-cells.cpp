class Solution {
public:
    long long coloredCells(int n) {
        long long cells = 1;
        

        long long newly = 0;

        for(int i = 1; i < n ; i++){
            newly += 4;
            cells += newly;
        }
        return cells;
    }
};
