class Solution {
public:
    int numSquares(int n) {
        vector<int> v(101,0);
        for(int i = 0 ; i < 101 ; i++){
            v[i] = i*i;
        }
        vector<int> dp(n+1 , INT_MAX-1000);
        dp[0] = 0 , dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            for(auto j : v){
                if(j <= i){
                    dp[i] = min(dp[i] , dp[i-j]+1);
                }
                else break;
            }
        }
        return dp[n];
    }
};