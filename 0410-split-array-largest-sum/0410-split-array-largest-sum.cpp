class Solution {
public:

    int func(vector<int>&nums , int m){
        int sub = 1;
        int ele = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(ele + nums[i] <= m){
                ele += nums[i];
            }
            else{
                sub += 1;
                ele = nums[i];
            }
        }
        return sub;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());;
        int high = accumulate(nums.begin() , nums.end() , 0);

        
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int split = func(nums , mid);
            if(split <= k){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};