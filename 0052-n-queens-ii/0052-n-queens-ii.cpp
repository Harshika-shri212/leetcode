class Solution {
public:

    bool canPlace(int row, int col, vector<string> & curr){
        for(int i=row-1; i>=0; i--){
            if(curr[i][col] == 'Q') return false;
        }

        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
            if(curr[i][j] == 'Q') return false;
        }

        for(int i=row-1,j=col+1; i>=0 && j<curr.size(); i--,j++){
            if(curr[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(int row, int n, int & res, vector<string> & curr){
        if(row == curr.size()){
            res+=1;
            return;
        }

        for(int col=0; col<curr.size(); col++){
            if(canPlace(row, col, curr)) {
                curr[row][col]='Q';
                solve(row+1, n, res, curr);
                curr[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {
      int res = 0;
      vector<string>curr (n ,string(n,'.'));
      solve(0, n, res, curr);
      return res;
    }
};