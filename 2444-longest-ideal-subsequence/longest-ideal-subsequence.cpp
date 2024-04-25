static auto _ = []() { std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans = 1 , n = s.size();
        vector<int> dp(n, 1) , mp(26,0);
        mp[s[0]-'a']++;
        for(int i = 1 ; i < n ; i++){
            int mn = max((s[i] - k) , 97) , mx = min((s[i] + k) ,122);
            for(int c = mn ; c <= mx ; c++){
                dp[i] = max(dp[i] , mp[c-97]+1);
            }
            mp[s[i]-'a'] = max(dp[i] , mp[s[i]-'a']);
            ans = max(ans , dp[i]);
        }

        return ans;
    }
};