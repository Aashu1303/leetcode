class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        map<char,int> mp;
        for(int i = 0 ; i < s.length() ; i++){
            if(mp.count(s[i])){
                ans = max(ans , (i - mp[s[i]]));
            }
            else mp[s[i]] = i;
        }
        return ans == -1 ? -1 : ans-1;
    }
};