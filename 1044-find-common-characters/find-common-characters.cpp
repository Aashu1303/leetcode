class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        map<char,int> mp;
        for(auto &i : words[0]) mp[i]++;
        
        for(int i = 1 ; i < words.size() ; i++){
            string s = words[i];
            map<int,int> mp1;
            for(auto &j : s){
                mp1[j]++;
            }
            for(char j = 'a' ; j <= 'z' ; j++){
                mp[j] = min(mp1[j] , mp[j]);
            }
        }

        for(auto &i : mp){
            while(i.second > 0){
                string s; s += i.first;
                ans.push_back(s);
                i.second--;
            }
        }
        return ans;
    }
};