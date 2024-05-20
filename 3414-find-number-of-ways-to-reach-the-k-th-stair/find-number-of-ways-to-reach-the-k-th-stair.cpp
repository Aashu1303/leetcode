class Solution {
    int dp[50][50][2];
    long long solve(long long n, long long target , long long j , long long back ,int prev){
        if(n > target+1){
            return 0;
        }

        if(dp[j][back][prev] != -1) return dp[j][back][prev];
        long long ans = 0;
        
        if(n == target){
            ans = 1;
        }

        if(prev == 0){
            ans += solve(n-1,target,j,back+1,1);
            ans += solve(n+(1<<j),target,j+1,back,0);
        }else{
            ans += solve(n+(1<<j),target,j+1,back,0);
        }
        
        return dp[j][back][prev] = ans;
    }
public:
    int waysToReachStair(int k) {
        memset(dp,-1,sizeof(dp));
        return solve(1,k,0,0,0);
    }
};