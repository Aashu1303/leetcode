class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans = 1;
        int n = s.size();
        vector<int> dp(n, 1);
        vector<int> mp(26,0);
        mp[s[0]-'a']++;
        for(int i = 1 ; i < n ; i++){
            int mn = (s[i] - k) , mx = (s[i] + k);
            for(char c = 'a' ; c <= 'z' ; c++){
                if(c >= mn && c <= mx){
                    dp[i] = max(dp[i] , mp[c-'a']+1);
                }
            }
            mp[s[i]-'a'] = max(dp[i] , mp[s[i]-'a']);
            ans = max(ans , dp[i]);
        }

        return ans;
    }
};