class Solution {
    int n;
    
    int solve(vector<vector<int>> &v , int row , int col, vector<vector<int>> &dp){
        if(dp[row][col] != INT_MAX) 
            return dp[row][col];
        
        if(row == n-1) 
            return dp[row][col] = v[row][col];
        
        int left = INT_MAX , right = INT_MAX; 
        
        if(col > 0)
            left = solve(v,row+1,col-1,dp);
        
        int down = solve(v,row+1,col,dp);
        
        if(col < n-1)
            right = solve(v,row+1,col+1,dp);
        
        dp[row][col] = min(left , min(down,right)) + v[row][col];
        
        return dp[row][col];
    }
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        n = v[0].size();
        if(n == 1) return v[0][0]; 
        vector<vector<int>> dp(n , vector<int>(n , INT_MAX));
        int ans = INT_MAX;
        
        for(int col = 0 ; col < n ;  col++){
            ans = min(ans , solve(v, 0, col, dp)); 
        }

        return ans;
    }
};