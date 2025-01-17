class Solution {
public:

    void solve(int start,vector<int>& curr, vector<int> &res, int t,vector<int> &nums){
        if(t==0 && curr.size()==2){
            res=curr;
            return;
        }

        if(curr.size()>=2)  return;

        for(int i=start;i<nums.size();i++){
            curr.push_back(i);
            solve(i+1,curr,res,t-nums[i],nums);
            curr.pop_back();
        }
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<int> res;
        solve(0,curr,res,target,nums);
        return res;
    }
};