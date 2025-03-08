class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>l;
        int dup = 0;
        for(auto it = nums.begin() ; it != nums.end();){
            if(find(l.begin() , l.end() , *it) == l.end()){
                l.push_back(*it);
                dup += 1;
                ++it;
            }
            else it = nums.erase(it);
        }
        return dup;
    }
};