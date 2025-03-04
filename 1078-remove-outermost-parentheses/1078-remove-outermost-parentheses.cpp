class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string res = "";
        for(char i : s){
            if(st.empty()) st.push(i);
            else{
                if(i == '(') {
                    st.push(i);
                    res = res + i;
                }
                else{
                    
                    st.pop();
                    if(!st.empty()) res= res + ')';
                }
            }
        }
        return res;
    }
};