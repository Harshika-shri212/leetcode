class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        if(s[0] != '#') st.push(s[0]);
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] == '#') {
                if(!st.empty())
                    st.pop();
            }
            else st.push(s[i]);
        }
        string new_s = "";
        while(!st.empty()){
            new_s = st.top() + new_s;
            st.pop();
        }

        if(t[0] != '#') st.push(t[0]);
        for(int i = 1 ; i < t.size() ; i++){
            if(t[i] == '#') {
                if(!st.empty())
                    st.pop();
            }
            else st.push(t[i]);
        }
        string new_tt = "";
        while(!st.empty()){
            new_tt = st.top() + new_tt;
            st.pop();
        }

        return new_s == new_tt;
    }
};