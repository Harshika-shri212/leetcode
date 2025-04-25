class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int>mp;
        for(int i : nums){
            mp[i] += 1;
        }
        int dis = mp.size();

        int c = 0;
        int n = nums.size();
        int left = 0;

         map<int , int >m;

        for(int i = 0 ; i < n; i++){
            m[nums[i]] += 1;
            while(m.size() == dis){
                c += n-i;
                m[nums[left]] -= 1;
                if(m[nums[left]] == 0) m.erase(nums[left]);
                left += 1;
            }
        }
        return c;
    }
};