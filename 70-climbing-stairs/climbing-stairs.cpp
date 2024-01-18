int dp[46][46];
class Solution {
    int solve(int i , int n){
        if(i == n) return 1;
        else if(i > n) return 0;

        if(dp[i][n] != -1) return dp[i][n];
        int one = solve(i+1 , n);
        int two = solve(i+2 , n);
        return dp[i][n] = one + two;
    }
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
    }
};