class Solution {
public:

    int is_possible(int mid ,vector<int>& bloomDay , int m , int k){
        vector<int>bloomed(bloomDay.size() , 0);
        for(int i = 0 ; i < bloomDay.size() ; i++){
            if(bloomDay[i] <= mid) bloomed[i] = 1;
        }
        int c = 0;
        int bouq = 0;
        for(int i : bloomed){
            if (i == 1) c += 1;
            else{
                bouq += c / k;
                c = 0;
            }
        }
        bouq += c / k;
        if(bouq >= m) return 1;
        else return 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int l = 1;
        int h = *max_element(bloomDay.begin() , bloomDay.end());
        while(l <= h){
            int mid = l + (h - l)/2;
            int f = is_possible(mid , bloomDay , m, k);
            if(f == 0){
                l = mid + 1;
            }
            else{
                ans = mid;
                h = mid - 1;
            }
        }
        return ans;
    }
};