class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[0];

        vector<int> a;
        a = nums;

        s = a[s];
        f = a[a[f]];

        while(s != f){
            s = a[s];
            f = a[a[f]];
        }

        f = a[0];

        while(s != f){
            s = a[s];
            f = a[f];
        }

        return s;

    }
};