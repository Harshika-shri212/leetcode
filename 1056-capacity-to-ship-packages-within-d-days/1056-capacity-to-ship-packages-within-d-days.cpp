class Solution {
public:

    int solve(int capacity , vector<int>& weights){
        int days_taken = 1;
        int tot = 0;
        for(int i = 0 ; i < weights.size() ; i++){
            if(tot + weights[i] <= capacity) tot+=weights[i];
            else{
                days_taken += 1;
                tot = weights[i];
            }
        }
        return days_taken;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int l = *max_element(weights.begin() , weights.end());
        int h = 0;
        for(int i : weights){
            h += i;
        }
        while(l <= h){
            int mid = l + (h - l)/2;
            int days_taken = solve(mid , weights);
            if(days_taken > days){
                l = mid + 1;
            }
            else{
                ans =  mid;
                h = mid - 1;
            }
            
        }
        return ans;
    }
};