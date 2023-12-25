class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 1 || s[0] == '0') return (s[0] == '0') ? 0:1;
        vector<int> dp(n , 0);
        if(s[0] != '0'){
            dp[0] = 1;
        }
        int y = s[1] - '0' + (s[0] - '0') * 10;
        if(y >= 10 && y <= 26){
            dp[1]++;
        }
        if(s[1] > '0'){
            dp[1]++;
        }

        for(int i = 2 ; i < n ; i++){
            int op1 = s[i] - '0';
            int op2 = s[i] - '0' + (s[i-1] - '0') * 10;

            if(op1 != 0){
                dp[i] += dp[i-1];
            }
            if(op2 >= 10 && op2 <= 26)
                dp[i] += dp[i-2];
        }

        return dp[n-1];
    }
};