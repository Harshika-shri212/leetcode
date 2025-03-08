class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = INT_MIN;
        int c = 0;
        for(int i : nums){
            if(i != 1){
                m = max(m , c);
                c = 0;
            }
            else c += 1;
        }   
        return max(m,c);
    }
};