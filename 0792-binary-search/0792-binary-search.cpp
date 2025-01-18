class Solution {
public:
    int search(vector<int>& nums, int target, int low = 0, int high = INT_MIN) {
        if (high == INT_MIN) high = nums.size() - 1;
        if (low > high) return -1;

        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return search(nums, target, low, mid - 1);
        else return search(nums, target, mid + 1, high);
    }
};
