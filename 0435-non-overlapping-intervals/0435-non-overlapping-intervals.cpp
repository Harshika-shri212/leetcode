class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int c = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int end = intervals[0][1];

        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] < end) {
                c += 1;
            }
            else{
                end = intervals[i][1];
            }
        }

        return c;
    }
};