class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;

        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] == target){
                first = mid;
                r = mid - 1;
            }
            else r = mid - 1;
        }

        int ll = 0;
        int rr = nums.size() - 1;

        while(ll <= rr){
            int mid = ll + (rr - ll)/2;
            if(nums[mid] < target) ll = mid + 1;
            else if(nums[mid] == target){
                last = mid;
                ll = mid + 1;
            }
            else rr = mid - 1;
        }

        return {first , last};
    }
};