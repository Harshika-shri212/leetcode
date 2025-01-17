class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            auto it = find(curr.begin(), curr.end(), nums[i]);
            if (it != curr.end()) {
                int foundIndex = distance(curr.begin(), it);
                res.push_back(foundIndex);
                res.push_back(i);
                break;
            } else {
                curr.push_back(target - nums[i]);
            }
        }
        return res;
    }
};
