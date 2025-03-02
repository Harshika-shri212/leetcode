class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> m;

        for(auto nums : nums1){
            m[nums[0]] = nums[1];
        }
        for(auto nums : nums2){
            m[nums[0]] += nums[1];
        }
        vector<vector<int>> res;
        for(auto it : m){
            res.push_back({it.first , it.second});
        }
        return res;
    }
};