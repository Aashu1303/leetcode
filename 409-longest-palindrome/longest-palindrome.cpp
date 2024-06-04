class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0 , count = 0;
        unordered_map<char,int> mp;
        for(auto &i : s){
            mp[i]++;
            ans++;
        }

        for(auto &i : mp){
            if(i.second % 2) count++;
        }

        if(count != 0) ans -= (count-1);
        return ans;
    }
};