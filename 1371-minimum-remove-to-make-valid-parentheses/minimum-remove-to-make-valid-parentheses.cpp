class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int n = s.size();
        stack<int> st;
        set<int> se;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(!st.empty()){
                    se.insert(i);
                    se.insert(st.top());
                    st.pop();
                }
            }
        }
        //for(auto i : se) cout << i << " ";
        for(int i = 0; i < n ; i++){
            if(s[i] == '(' || s[i] == ')'){
                if(se.find(i) != se.end()){
                    ans += s[i];
                }
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};