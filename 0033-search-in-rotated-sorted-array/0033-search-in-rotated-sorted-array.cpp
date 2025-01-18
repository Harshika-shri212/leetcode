class Solution {
public:
    int search(vector<int>& nums, int target) {
        int partition = findmin(nums , 0 , nums.size()-1 );
        int ind = bs(nums , partition , nums.size()-1, target);
        if (ind == -1) {
            int ind2 = bs(nums , 0 , partition-1, target );
            return ind2;
        }
        else return ind;
        
    }

    int findmin(vector<int>& nums , int low , int high){
        while (low<= high){
            int mid = (low + high) / 2;
            if (nums[mid] > nums[nums.size()-1]) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }

    int bs(vector<int>& nums, int low, int high , int target){
        while(low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};