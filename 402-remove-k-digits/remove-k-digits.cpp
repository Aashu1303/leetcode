class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i = 0 ; i < num.size() ; i++){
            while(k > 0 && !s.empty() && (s.top() > num[i])){
                s.pop();
                k--;
            }
            if(num[i] == '0'){
                if(!s.empty()) s.push(num[i]);
            }else{
                s.push(num[i]);
            }
        }
        string ans = "";
        while(!s.empty() && k > 0){
            s.pop();
            k--;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans.empty() ? "0" : ans;
    }
};