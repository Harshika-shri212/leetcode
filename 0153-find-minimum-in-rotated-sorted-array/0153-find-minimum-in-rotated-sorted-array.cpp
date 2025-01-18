class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size()-1;
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] > nums[n]){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return nums[low];
    }
};