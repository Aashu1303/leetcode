int dp[1001][1001];
int mod = 1e9+7;
class Solution {
    int solve(int n , int k){
        if(k <= 0) return k == 0; // if k == 0 returns 1 else returns 0;
        if(dp[n][k] != -1) return dp[n][k];
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += solve(n-1 , k-i);
            ans = (ans % mod);
        }

        return dp[n][k] = (ans % mod);
    }
public:
    int kInversePairs(int n, int k) {
        memset(dp,-1 ,sizeof(dp));
        return solve(n , k);
    }
};