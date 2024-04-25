class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans = 1;
        int n = s.size();
        vector<int> dp(n+1, 1);
        unordered_map<char,int> mp;
        mp[s[0]]++;
        for(int i = 1 ; i < n ; i++){
            int mn = (s[i] - k) , mx = (s[i] + k);
            for(char c = 'a' ; c <= 'z' ; c++){
                if((int)c >= mn && (int)c <= mx){
                    dp[i] = max(dp[i] , mp[c]+1);
                }
            }
            mp[s[i]] = max(dp[i] , mp[s[i]]);
            ans = max(ans , dp[i]);
        }

        return ans;
    }
};