class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> mp(26,0);
        string ans = "";
        for(char i : s) mp[i-'a']++;

        for(char i : order){
            while(mp[i-'a']){
                ans += i;
                mp[i-'a']--;
            }
        }

        for(char i = 'a' ; i <= 'z' ; i++){
            while(mp[i-'a']){
                ans += i;
                mp[i-'a']--;
            }
        }

        return ans;
    }
};