class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l;
        vector<int> r;
        vector<int> s;
        vector<int> res;

        for(int i : nums){
            if(i < pivot) l.push_back(i);
            else if(i == pivot) s.push_back(i);
            else r.push_back(i);
        }

        res.insert(res.end() , l.begin() , l.end());
        res.insert(res.end() , s.begin() , s.end());
        res.insert(res.end() , r.begin() , r.end());

        return res;
    }
};