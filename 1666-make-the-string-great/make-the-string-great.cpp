class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(!ans.empty() && (s[i] == ans.back()-32 || s[i] == ans.back() + 32)){
                ans.pop_back();
            } else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};