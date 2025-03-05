class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxi = 0;
        int cur = 0;
        for(char i : s){
            if(i == '('){
                st.push(i);
                cur = st.size();
                maxi = max(maxi , cur);
            }
            else if(i == ')'){
                st.pop();
                cur = st.size();
            }
        }
        return maxi;
    }
};