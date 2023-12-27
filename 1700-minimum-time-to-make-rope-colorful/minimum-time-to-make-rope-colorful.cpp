class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int n = s.size();
        if(s.size() == 1) return 0;
        char prev = s[0]; int prevMin = 0;
        vector<int> dp(n+1 , 0);
        for(int i = 1 ; i <= n ; i++){
            if(s[i-1] == prev){
                dp[i] = dp[i-1] + min(v[i-1] , prevMin);
                prevMin = max(v[i-1] , prevMin);
            }else{
                dp[i] = dp[i-1];
                prevMin = v[i-1];
                prev = s[i-1];
            }
        }
        return dp[n];
    }
};