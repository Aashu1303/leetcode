class Solution {
    int solve(string &s , char last , int i , int k , vector<vector<int>>&dp){
        if(i >= s.size()) return 0;
        if(dp[i][last - 'a'] != -1) return dp[i][last - 'a'];
        int take = INT_MIN;
        if(last == '{' || abs(s[i] - last) <= k){
            take = 1 + solve(s,s[i],i+1,k,dp);
        }
        int skip = solve(s,last,i+1,k,dp);
        return dp[i][last - 'a'] = max(take , skip);
    }
public:
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size()+1 , vector<int>(27 , -1));                  
        int ans =  solve(s , '{' , 0 , k , dp);

        return ans;
    }
};