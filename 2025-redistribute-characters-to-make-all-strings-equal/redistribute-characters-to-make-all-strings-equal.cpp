class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<int,int> mp;
        for(string s : words){
            for(char c : s){
                mp[c-'a']++;
            }
        }

        for(auto i : mp){
            if(i.second % n != 0) return false;
        }
        return true;
    }
};