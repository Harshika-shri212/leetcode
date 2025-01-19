
class Solution {
public:

    void solve(int start, vector<vector<int>> & res, vector<int> & curr, vector<int> & candidates , int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target<0) return;
        for(int i=start; i<candidates.size(); i++){
            if (i>start && candidates[i]==candidates[i-1] ) continue;
            curr.push_back(candidates[i]);
            solve(i+1, res , curr , candidates, target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<vector<int>> res;
     vector<int> curr;
     sort(candidates.begin() , candidates.end());
     solve(0,res, curr, candidates, target);
     return res;
    }
};