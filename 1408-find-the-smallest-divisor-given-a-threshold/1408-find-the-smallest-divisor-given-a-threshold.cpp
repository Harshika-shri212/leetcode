class Solution {
public:

    int solve(int mid , vector<int>& nums){
        int tot = 0;
        for(int i : nums){
            int rem = ceil(double(i)/mid);
            tot += rem;
        }
        return tot;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = 0;
        int l = 1;
        int h = *max_element(nums.begin() , nums.end());
        while(l <= h){
            int mid = l + (h - l)/2;
            int res = solve(mid , nums);
            if(res <= threshold){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};