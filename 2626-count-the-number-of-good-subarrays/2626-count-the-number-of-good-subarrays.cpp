class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        long long c = 0;
        int i = 0;
        int j = 0;
        map<int,int>mp;

        int n = nums.size();

        while(j < n){
            c += mp[nums[j]];
            mp[nums[j]] += 1;
            while(c >= k){
                res += n - j;
                mp[nums[i]] -= 1;
                c -= mp[nums[i]];
                i += 1;
            }
            j += 1;
        }
        return res;
    }
};