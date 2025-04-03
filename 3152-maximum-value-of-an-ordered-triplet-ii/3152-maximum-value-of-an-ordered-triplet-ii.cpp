class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long>pref(n , 0);
        vector<long long>suff(n , 0);

        long long m = nums[0];
        for(int i = 1 ; i < n; i++){
            pref[i] = m;
            if(nums[i] > m) m = nums[i];
        }

        long long ma = nums.back();
        for(int i = n - 2 ; i >= 0 ; i--){
            suff[i] = ma;
            if(nums[i] > ma) ma = nums[i];
        }

        long long res = 0;
        for(int i = 1 ; i < n ; i++){
            long long tot = (pref[i] - nums[i]) * suff[i];
            if(tot > res) res = tot;
        }

        return res;
    }
};