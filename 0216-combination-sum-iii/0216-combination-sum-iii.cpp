class Solution {
public:

    void solve(int start, vector<vector<int>> & res, vector<int> & curr, int k, int target){
        if(target==0 && curr.size()==k){
            res.push_back(curr);
            return;
        }
        if(curr.size()>k) return;
        for(int i=start; i<=9; i++){
            curr.push_back(i);
            solve(i+1, res, curr, k, target-i);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(1, res, curr, k, n);
        return res;
    }
};

