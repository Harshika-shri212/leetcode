class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind = findMin(nums);
        int res = bs(nums , ind , nums.size() - 1 , target);
        if(res == -1){
            res = bs(nums , 0 , ind - 1 , target);
        }
        return res;
    }

    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    int bs(vector<int>& nums , int l , int r , int &target){
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid -1;
            else l = mid + 1;
        }
        return -1;
    }
};