class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        for(int i = 0 ; i < num.size() ; i++){
            while(k > 0 && !s.empty() && (s.top() > (num[i]-'0'))){
                s.pop();
                k--;
            }
            s.push(num[i]-'0');
        }
        while(k > 0){
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()){
            ans.push_back(s.top() + '0');
            s.pop();
        }
        int j = ans.size()-1;
        while(!ans.empty() && ans[j] == '0'){
            ans.pop_back();
            j--;
        }
        if(ans.empty()) ans.push_back('0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};