class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n , 1);

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    int val = 1 + arr[j];
                    arr[i] = max(val , arr[i]);
                }
            }
        }

        int ans = *max_element(arr.begin() , arr.end());

        return ans;
    }
};