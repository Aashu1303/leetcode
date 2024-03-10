class Solution {
    std::string compareStrings(const std::string& s1, const std::string& s2) {
        if (s1.length() < s2.length()) {
            return s1;
        } else if (s1.length() > s2.length()) {
            return s2;
        } else {
            return (s1 < s2) ? s1 : s2;
        }
    }
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        map<string,pair<int,int>> mp;
        vector<string> ans(n,"");
        for(int i = 0 ; i < n ; i++){
            string s = arr[i];
            for(int j = 1 ; j <= s.size() ; j++){
                for(int k = 0 ; k < j ; k++){
                    string temp = s.substr(k,j-k);
                    if(mp[temp].second != i+1){
                        mp[temp].first++;                                                
                        mp[temp].second = i+1;
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            string s = arr[i];
            for(int j = 1 ; j <= s.size() ; j++){
                for(int k = 0 ; k < j ; k++){
                    string temp = s.substr(k,j-k);
                    if(mp[temp].first == 1){
                        if(ans[i] == ""){
                            ans[i] = temp;
                        }else{
                            ans[i] = compareStrings(ans[i] , temp);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};