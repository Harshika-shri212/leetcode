class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int c = 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        while(pq.size()>=2 && pq.top()<k){
            long long x = pq.top();
            pq.pop();

            long long y = pq.top();
            pq.pop();

            pq.push(min(x, y) * 2 + max(x, y));

            c+=1;

        }

        return c;
    }
};