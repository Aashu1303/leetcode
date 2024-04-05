class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> st;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(!st.empty() && (s[i] == st.top()-32 || s[i] == st.top() + 32)){
                st.pop();
            } else{
                st.push(s[i]);
            }
        }
        while(!st.empty()) ans += st.top() , st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};