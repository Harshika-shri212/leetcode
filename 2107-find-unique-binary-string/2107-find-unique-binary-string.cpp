class Solution {
public:

    string solve(int & n , vector<string>& nums , vector<string> & b , string& s){
        if(s.size() == n){
            if ( find(nums.begin(), nums.end(), s) == nums.end() ){
                return s;
            }
            else return "";
        }

        for(int i = 0 ; i < 2 ; i++){
            s = s + b[i][0];
            string res = solve(n , nums , b , s);
            if(res != "") return res;
            else s.pop_back();
        }
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        vector<string>b = {"0" , "1"};
        string s = "";
        return solve(n , nums , b , s);
    }
};