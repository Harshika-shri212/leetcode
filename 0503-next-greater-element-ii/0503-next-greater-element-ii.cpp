class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> m(nums.size(),-1);
        stack<int>s;
        s.push(0);
        for(int i=0;i<2*nums.size();i++){
            while(!s.empty() && nums[i%n]>nums[s.top()]){
                m[s.top()]=nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return m;
    }
};