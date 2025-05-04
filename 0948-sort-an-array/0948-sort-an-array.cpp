class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int , vector<int> , greater<>>pq(nums.begin() , nums.end());
        int i = 0;
        while(i < nums.size()){
            nums[i] = pq.top();
            pq.pop();
            i += 1;
        }
        return nums;
    }
};