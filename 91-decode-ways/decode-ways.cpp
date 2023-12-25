class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0 || s[0] == '0') return 0;
        vector<int> dp(2,1);

        for(int i = 1 ; i < n ; i++){
            int ways = 0;
            if(s[i] != '0'){
                ways += dp[1]; 
            }
            if(s[i-1] =='1' || (s[i-1] == '2' && s[i] <= '6')){
                ways += dp[0];
            }
            dp[0] = dp[1];
            dp[1] = ways;
        }
        return dp[1];
    }
};