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
            for(int j = 1 ; j <= sqrt(i) ; j++){
                if(v[j] <= i){
                    dp[i] = min(dp[i] , dp[i-v[j]]+1);
                }
                else break;
            }
        }
        return dp[n];
    }
};