int mod = 1e9+7;
class Solution {
    int solve(int zero , int one , int limit , int x , int prev , vector<vector<vector<vector<int>>>> &dp){
        if(zero < 0 || one < 0 || x > limit) return 0;
        if(zero == 0 && one == 0) return 1;
        if(dp[zero][one][prev+1][x] != -1) return dp[zero][one][prev+1][x];
        
        // take means 1 skip means 0
        int take = solve(zero , one-1 , limit , (prev == 1 ? x+1 : 1) , 1 , dp);
        int skip = solve(zero-1 , one , limit , (prev == 0 ? x+1 : 1)  , 0, dp);
        
        return dp[zero][one][prev+1][x] = (take+skip) % mod;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<vector<int>>>> dp(zero + 1 , vector<vector<vector<int>>>(one + 1 , vector<vector<int>>(3 , vector<int>(limit+1 , -1))));
        return solve(zero , one , limit, 0 ,-1 , dp);
    }
};