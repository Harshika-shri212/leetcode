class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = -1;
        int diff = INT_MAX;
        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() - 2 ; i++){
            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r){
                int tot = nums[i] + nums[l] + nums[r];
                int dif = abs(tot - target);
                if(dif < diff){
                    diff = dif;
                    closest = tot;
                }
                if(tot > target){
                    r -= 1;
                }
                else l += 1;
            }
        }
        return closest;
    }
};