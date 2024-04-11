class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(int i = 0 ; i < num.size() ; i++){
            while(k > 0 && !s.empty() && (s.back() > num[i])){
                s.pop_back();
                k--;
            }
            if(num[i] == '0'){
                if(!s.empty()) s.push_back(num[i]);
            }else{
                s.push_back(num[i]);
            }
        }
        while(!s.empty() && k > 0){
            s.pop_back();
            k--;
        }
        
        return s.empty() ? "0" : s;
    }
};