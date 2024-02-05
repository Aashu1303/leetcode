class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX , n = s.size();
        unordered_map<char,vector<int>> mp;
        for(int i = 0 ; i < n ; i++){
            mp[s[i]].push_back(i);
        }
        for(auto i : mp){
            if(i.second.size() == 1){
                ans = min(ans , i.second[0]);
            }
        }

        return ans == INT_MAX ? -1: ans;
    }
};