class Solution {
public:

    void solve(int start, vector<vector<int>> & res, vector<int> & curr, vector<int> & candidates , int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target<0) return;
        for(int i=start; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            solve(i, res , curr , candidates, target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>> res;
     vector<int> curr;
     solve(0,res, curr, candidates, target);
     return res;
    }
};