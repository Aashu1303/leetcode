#define mod 1000000007
class Solution {
    vector<vector<int>> dp;
    int solve(int i , int target , int k , int n){
        if(i == n){
            return (target == 0);
        }
        if(target < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];

        int ans = 0;
        for(int face = 1 ; face <= k ; face++){
            ans = (ans + solve(i+1, (target - face),k, n))%mod; 
        }

        dp[i][target] = ans;
        return dp[i][target];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1 , vector<int>(target+1 , -1));
        return solve(0,target,k,n);
    }
};